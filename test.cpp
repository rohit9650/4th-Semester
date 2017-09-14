#include <iostream>
#include <math.h>
#define size 10

#define LEFT(i) ((i<<1) + 1)
#define RIGHT(i) ((i<<1) + 2)
#define PARENT(i) (i>>1)

using namespace std;

int heap_size=0,k=size;

class SLLnode{
    public : float key;
             SLLnode *next;
             SLLnode(float k=0, SLLnode *n = 0){
                key = k;
                next = n;
             }
};

class SLL{
    public : SLLnode *head,*tail;
             SLL(SLLnode *h=0, SLLnode *t=0){
                head=h;
                tail=t;
             }
             void addAt(float d){

             }
};

void selection_sort(int arr[]){

    for(int i=0; i<size-1; i++){
        int min=i;
        for(int j=i+1; j<size; j++){
            if(arr[min]>arr[j])
                min=j;
        }
        swap(arr[min],arr[i]);
    }
}

void bubble_sort(int arr[]){
    bool sort=false;
    for(int i=0; i<size-1 && !sort; i++){
        sort=true;
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                sort=false;
                swap(arr[i],arr[j]);
            }
        }
    }
}

void insertion_sort(int arr[]){
    int j=0,min=0;
    for(int i=1; i<size; i++){
        min = arr[i];
        for(j=i-1; j>=0 && min<arr[j]; j--)
            arr[j+1]=arr[j];
        arr[j+1]=min;
    }
}

int partition(int arr[],int l,int r){
    int pivot = arr[r],i=l-1,j=l;
    for(j=l; j<=r-1; j++)
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quicksort(int l, int r, int arr[]){                   //0,size-1
    if(l<r){
        int pivot = partition(arr,l,r);
        quicksort(l,pivot-1,arr);
        quicksort(pivot+1,r,arr);
    }
}

void merge(int l,int m,int r,int arr[]){
    int p=m-l+1,q=r-m,i=0,j=0,k=0;
    int A[p],B[q];

    for(i=0; i<p; i++)
        A[i]=arr[l+i];
    for(i=0; i<q; i++)
        B[i]=arr[m+i+1];

    i=0;j=0;k=l;

    while(i!=p && j!=q){
        if(A[i]>=B[j])
            arr[k++]=B[j++];
        else
            arr[k++]=A[i++];
    }

    while(i!=p)
        arr[k++]=A[i++];
    while(j!=q)
        arr[k++]=B[j++];
}

void merge_sort(int l, int r, int arr[]){                 //0,size-1
    if(l<r){
        int m = l + (r-l)/2;
        merge_sort(l,m,arr);
        merge_sort(m+1,r,arr);
        merge(l,m,r,arr);
    }
}

void MAX_HEAPIFY(int arr[],int i){
    int l = LEFT(i), r = RIGHT(i), largest=i;
    if(l<=heap_size && arr[l]>arr[i])
        largest = l;
    if(r<=heap_size && arr[r]>arr[largest])
        largest = r;
    if(largest != i){
        swap(arr[i],arr[largest]);
        MAX_HEAPIFY(arr,largest);
    }
}

void BUILD_MAX_HEAPIFY(int arr[]){
    heap_size=size-1;
    for(int i=size/2 - 1; i>=0; i--){
        MAX_HEAPIFY(arr,i);
    }
}

void heapsort(int arr[]){
    BUILD_MAX_HEAPIFY(arr);
    for(int i=size-1; i>=0; i--){
        swap(arr[0],arr[i]);
        heap_size-=1;
        MAX_HEAPIFY(arr,0);
    }
}

void counting_sort(int arr[],int k){
    int b[k]={0},c[size];
    for(int i=0; i<size; i++)
        c[i] = arr[i];
    for(int i=0; i<size; i++)
        b[arr[i]] += 1;
    b[0]-=1;
    for(int i=1; i<k; i++)
        b[i]+=b[i-1];
    for(int i=size-1; i>=0; i--){
        arr[b[c[i]]] = c[i];
        b[c[i]] -= 1;
    }
}

void counting_sort1(int arr[],int j){
    int b[k]={0},c[size];
    for(int i=0; i<size; i++)
        c[i] = arr[i];
    for(int i=0; i<size; i++)
        b[(arr[i]/j)%10] += 1;
    b[0]-=1;
    for(int i=1; i<k; i++)
        b[i]+=b[i-1];
    for(int i=size-1; i>=0; i--){
        arr[b[(c[i]/j)%10]] = c[i];
        b[(c[i]/j)%10] -= 1;
    }
}

void radix_sort(int arr[],int d){
    for(int i=1; i<pow(10,d); i*=10){
        counting_sort1(arr,i);
    }
}



int main(){
    int arr[size]={441,123,375,229,110,124,666,111,621,123};//{2,8,4,6,0,1,2,9,5,3};
    radix_sort(arr,3);
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    return 0;
}
