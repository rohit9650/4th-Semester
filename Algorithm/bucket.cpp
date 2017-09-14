#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
        float data;
        node *next;

        node() {
            next = NULL;
        }
};

class SLList{
    public :
    node *head = NULL;

    void insert_At(float d){

        node *newnode = new node;
        newnode->data = d;

        if(head==NULL){
            head=newnode;
        }
        else{
            node *p=head;
            if(p->data>d){
                    head=newnode;
                    head->next=p;
            }
            else{
                     node *prev=head;
                     node *nextnode = head->next;
                    while(true){
                         if(nextnode==NULL||nextnode->data>d){
                            prev->next=newnode;
                            newnode->next=nextnode;
                            break;
                        }

                        prev=prev->next;
                        nextnode=nextnode->next;
                    }
            }
        }
    }

};


void BucketSort(float A[] ,int n){

	SLList *B=new SLList[n];

	for(int i=0;i<n;i++){
        int x=(int)n*A[i];
		B[x].insert_At(A[i]);
	}
	int k=0;
	for(int i=0;i<n;i++){
        node *p=B[i].head;
        while(p!=NULL){
	     	A[k]=p->data;
	     	k++;
	     	p=p->next;
        }
	}
};

int main(){
    int n;
	cout<<"Enter The number of elements      : ";
	cin>>n;
	cout<<"Enter number between zero and one : ";
	float *a=new float[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	BucketSort(a,n);
	cout<<endl;
    for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}

