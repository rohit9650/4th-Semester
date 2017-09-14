#include<iostream>
#define PARENT(i) i>>1
#define LEFT(i) (i<<1)
#define RIGHT(i) ((i<<1) + 1)
#define size 10

using namespace std;

int heap_size=0;

void MAX_HEAPIFY(int a[], int i){

    int l=LEFT(i),r=RIGHT(i),largest=i;
    if(l<=heap_size && a[l]>a[i])
        largest=l;
    if(r<=heap_size && a[r]>a[largest])
        largest=r;
    if(largest != i){
        swap(a[i],a[largest]);
        MAX_HEAPIFY(a,largest);
    }

}

void BUILD_MAX_HEAPIFY(int a[]){
    heap_size=size;
    heap_size-=1;
    for(int i=size/2 -1; i>=0; --i)
        MAX_HEAPIFY(a,i);
}

void HEAPSORT(int a[]){
    BUILD_MAX_HEAPIFY(a);
    for(int i=size-1; i>0; --i){
        swap(a[0],a[i]);
        heap_size-=1;
        MAX_HEAPIFY(a,0);
    }
}

int main(){
    int a[size]={4,1,3,2,16,9,10,14,8,16};
    HEAPSORT(a);
    for(int i=0; i<size; ++i)
        cout<<a[i]<<" ";
    return 0;
}
