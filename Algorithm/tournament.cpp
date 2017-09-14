#include<iostream>
using namespace std;

int tournament(int *a, int n){
    int *heap = new int[2*n-1]{0};
    for(int i=0;i<n;i++){
        heap[i+n-1] = a[i];
    }

    for(int i=2*n-2;i>0;i=i-2){
        if(heap[i]<heap[i-1])
            heap[(i-1)/2] = heap[i];
        else
            heap[(i-1)/2] = heap[i-1];
    }

    int index = 0, min=999999;

    while(index<(2*n-2)){

        if(2*index+1<=(2*n-1) && heap[2*index+1] == heap[index]){
            if(heap[2*index+2]<min)
                min = heap[2*index+2];
                index = 2*index+1;
        }
        else{
            if(2*index+2<=(2*n-1) && heap[2*index+1]<min)
                min = heap[2*index+1];
                index = 2*index+2;
        }
    }

    return min;
}

int main(){

    int *arr = new int[13];
    for(int i=0;i<13;i++)
        arr[i] = i+1;

    cout<<tournament(arr,13);

    return 0;
}
