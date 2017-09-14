#include<iostream>
#include<queue>

#define MAX 999

using namespace std;

enum COLOR{WHITE,BLACK};

template<class T>
class SLLnode{
    public:
            T info;
            SLLnode *next;
            SLLnode(){
                next = 0;
            }
            SLLnode(T a, SLLnode *b = NULL){
                info = a;
                next = b;
            }
};

template<class T>
class SLLlist{
    private:
            SLLnode<T> *tail;
    public :
            SLLnode<T> *head;
            SLLlist(){
                head = NULL;
                tail = NULL;
            }
            ~SLLlist();

            bool isEmpty(){
                return head == NULL;
            }

            void addToTail(T a);

            T deleteFromHead();

            bool searchInfo(T a);

};

template<class T>
SLLlist<T>::~SLLlist() {
    for (SLLnode<T> *p; !isEmpty(); ) {
        p = head->next;
    delete head;
    head = p;
    }
}

/*template<class T>
void SLLlist<T>::addToHead(T a){
    if(!isEmpty()){
        head = new SLLnode<T>(a,head);
    }
    else
        head = tail = new SLLnode<T>(a);
}*/
template<class T>
void SLLlist<T>::addToTail(T a){
    if(!isEmpty()){
        tail->next = new SLLnode<T>(a);
        tail = tail->next;
    }
    else
        head = tail = new SLLnode<T>(a);
}


template<class T>
T SLLlist<T>::deleteFromHead(){
    T ele = head->info;
    SLLnode<T> *tmp = head->next;

    if(isEmpty())
        throw "List is Empty";
    else if(head == tail)
        head = tail = 0;
    else
        head = head->next;
    delete tmp;
    return ele;
}

template<class T>
bool SLLlist<T>::searchInfo(T a){
    SLLnode<T> *tmp = head;
    if(isEmpty)
        throw "List is Empty";
    else
        for( ; !(tmp->info==a) && tmp!=0 ; tmp=tmp->next);
    return tmp != 0;
}


class Graph{
    public :
                int v;
                SLLlist<int> *adjList;
                Graph(){
                    int j;
                    cout<<"\nEnter the number of vertices : ";
                    cin>>v;
                    //cout<<"\nEnter the number of edges    : ";
                    //cin>>e;
                    adjList = new SLLlist<int>[v];
                    for(int i=0; i<v; ++i){
                        cout<<"\nenter the vertices adjacent to vertex "<<i<<" : ";
                        do{
                            cin>>j;
                            adjList[i].addToTail(j);
                        }while(j!=-1);

                    }

                }

                void BFS(int s){;
                    queue<int> Q;
                    COLOR color[v];
                    int dist[v],parent[v],temp;
                    for(int i=0; i<v; i++){
                            color[i]=WHITE;
                            //dist[i]=MAX;
                    }
                    color[s]=BLACK;
                    //dist[s]=0;
                    Q.push(s);
                    while(!Q.empty()){
                        temp = Q.front();
                        cout<<temp<<" ";
                        Q.pop();
                        for(SLLnode<int> *i = adjList[temp].head;  i->info != -1; i=i->next){
                            if(color[i->info]==WHITE){
                                color[i->info]=BLACK;
                                //dist[i->info]=dist[temp]+1;
                                Q.push(i->info);

                            }
                        }
                        color[temp]=BLACK;
                    }
                }

                void DFS(int s){
                    COLOR color[v];
                    for(int i=0; i<v; i++)
                        color[i]=WHITE;
                    DFS(s,color);
                }

                void DFS(int s,COLOR color[]){
                    color[s]=BLACK;
                    cout<<s<<" ";
                    for(SLLnode<int> *i = adjList[s].head;  i->info != -1; i=i->next){
                            if(color[i->info]==WHITE)
                                DFS(i->info);
                    }
                }

};


int main(){
    Graph g;
    g.BFS(2);
    cout<<endl;
    g.DFS(1);
    return 0;
}
