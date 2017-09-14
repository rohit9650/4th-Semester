#include<iostream>

using namespace std;

enum COLOR{BLACK,RED};

class rbNode{
    public :
             int info;
             rbNode *left,*right,*parent;
             COLOR color;
             rbNode(int i=0, rbNode *l=0, rbNode *r=0, rbNode *p=0, COLOR c = RED){
                left=l;
                right=r;
                parent=p;
                color = c;
                info = i;
             }
};

class rbTree{
    protected :
                rbNode *NIL,*root;
    public    :
                rbTree(){
                    NIL = new rbNode(0,0,0,0,BLACK);
                    root = NIL;
                }

                void LeftRotate(rbNode *x);
                void RightRotate(rbNode *x);

                void rbInsert(int i);
                void rbInsertFixup(rbNode *);

                void rbDelete(int i){
                    rbNode *y = NIL,*x = root;
                    while(x!=NIL){
                    y=x;
                    if(x->info == i)
                        break;
                    else
                        if(i < x->info)
                            x = x->left;
                    else
                        x = x->right;
                    }
                    if(x == NIL)
                        cout<<"\nElement isn't found in tree.\n";
                    else
                        rbDelete(y);
                }

                void rbTransplant(rbNode *u,rbNode *v){
                    if(u->parent == NIL)
                        root = v;
                    else
                        if(u == u->parent->left)
                            u->parent->left = v;
                        else
                            u->parent->right = v;
                    v->parent = u->parent;
                }

                void rbDelete(rbNode *);
                void rbDeleteFixup(rbNode *);

                void inorder(){
                cout<<"root : "<<root->info<<"\n";
                    recursiveInorder(root);
                }
                void recursiveInorder(rbNode *);

                void visit(rbNode *p){
                    cout<<p->info<<" { "<<p->color<<" } "<<" ";
                }
};

void rbTree::LeftRotate(rbNode *x){
    rbNode *y = x->right;
    x->right = y->left;
    if(y->left != NIL)
            y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NIL)
        root = y;
    else
        if(x = x->parent->right)
            x->parent->right = y;
    else
        x->parent->left = y;
    y->left = x;
    x->parent = y;
}

void rbTree::RightRotate(rbNode *x){
    rbNode *y = x->left;
    x->left = y->right;
    if(y->right != NIL)
            y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == NIL)
        root = y;
    else
        if(x = x->parent->right)
            x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void rbTree::rbInsert(int key){
    rbNode *y = NIL,*x = root,*z = new rbNode(key,NIL,NIL,NIL);

    while(x!=NIL){
        y=x;
        if(z->info < x->info)
            x = x->left;
        else
            x = x->right;
    }
    z->parent=y;
    if(y == NIL)
        root = z;
    else
        if(z->info < y->info)
            y->left = z;
    else
        y->right = z;
    rbInsertFixup(z);
}

void rbTree::rbInsertFixup(rbNode *z){
    while( z!=root && z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            rbNode *y = z->parent->parent->right;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->right){
                    z = z->parent;
                    LeftRotate(z);
                }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                RightRotate(z->parent->parent);
            }
        }
        else{
            rbNode *y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    RightRotate(z);
                }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                LeftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void rbTree::rbDelete(rbNode *z){
    rbNode *y = z,*x;
    COLOR c = y->color;
    if(z->left == NIL){
        x = z->right;
        rbTransplant(z,z->right);
    }
    else
        if(z->right == NIL){
            x = z->left;
            rbTransplant(z,z->left);
        }
    else{
        rbNode *tmp = z->right;
        while(tmp->left != NIL || tmp->right != NIL){
            y=tmp;
            tmp=tmp->left;
        }
        c = y->color;
        if(y->parent == z)
            x->parent = y;
        else{
            rbTransplant(y,y->right);
            y->right=z->right;
            y->right->parent=y;
        }
        rbTransplant(z,y);
        y->left=z->left;
        y->left->parent=y;
        y->color=z->color;
    }
    if(c == BLACK)
        rbDeleteFixup(x);
}

void rbTree::rbDeleteFixup(rbNode *x){
    rbNode *w;
    while(x != root && x->color==BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color == RED){                                     //x's siblinh w is red
                w->color = BLACK;
                x->parent->color = RED;
                LeftRotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color==BLACK){  //x's sibling w is black and both of w's children are black
                w->color=RED;
                x=x->parent;
            }
            else{                                                   //x's sibling w is black and w's right child is black and left red
                if(w->right->color == BLACK){
                    w->left->color=BLACK;
                    w->color=RED;
                    RightRotate(w);
                    w=x->parent->right;
                }
                w->color = x->parent->color;                        //x's sibling w is black and both of w's children are red
                x->parent->color = BLACK;
                w->right->color = BLACK;
                LeftRotate(x->parent);
                x = root;
            }

        }
        else{
             w = x->parent->left;
            if(w->color == RED){                                     //x's siblinh w is red
                w->color = BLACK;
                x->parent->color = RED;
                LeftRotate(x->parent);
                w = x->parent->left;
            }
            if(w->left->color == BLACK && w->right->color==BLACK){  //x's sibling w is black and both of w's children are black
                w->color=RED;
                x=x->parent;
            }
            else{                                                   //x's sibling w is black and w's right child is black and left red
                if(w->left->color == BLACK){
                    w->right->color=BLACK;
                    w->color=RED;
                    LeftRotate(w);
                    w=x->parent->left;
                }
                w->color = x->parent->color;                        //x's sibling w is black and both of w's children are red
                x->parent->color = BLACK;
                w->left->color = BLACK;
                RightRotate(x->parent);
                x = root;
            }

        }
    }
    x->color=BLACK;
}

void rbTree::recursiveInorder(rbNode *p){
    if(p != 0){
        recursiveInorder(p->left);
        visit(p);
        recursiveInorder(p->right);
    }
}

int main(){
    rbTree t;
    char ch,c;
    int key;
    cout<<"1) Inserting element ------ \n";
    cout<<"2) Deleting element  ------ \n";
    cout<<"3) Traverse                 \n";
  do{
    cin>>ch;
    switch(ch){
        case '1' : {
                        cout<<"\nEnter the key value : ";
                        cin>>key;
                        t.rbInsert(key);
                        break;
        }
        case '2' : {
                        cout<<"\nEnter the key value to be deleted : ";
                        cin>>key;
                        t.rbDelete(key);
                        break;
        }
        case '3' : {
                        cout<<"\nTree is -----------\n";
                        t.inorder();
                        break;
        }
        default  : {    cout<<"\n !!!!!!! Wrong Choice !!!!!!! ";
                        break;
        }
    }
    cout<<"\nMore ? ";
    cin>>c;
  }while(c == 'Y' || c == 'y');
    return 0;
}
