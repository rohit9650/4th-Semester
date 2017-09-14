#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int partition(int *a, int start, int last){
    int x = rand()%(last-start+1)+start;
    swap(a[last],a[x]);

    int j = start;
    for(int i=start;i<last;i++){
        if(a[i]<=a[last]){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[last]);

    return j;
}

int search(int *a, int start, int last, int i){
    int part = partition(a,start,last);
    if(part == i)
        return a[i];
    else{
        if(i<part){
            search(a,start,part-1,i);
        }
        else{
            search(a,part+1,last,i);
        }
    }
}

int main(){
    srand(time(0));
    int n;
    cout<<"Number of element : ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        arr[i] = rand()%100;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    int i;
    cout<<"\nEnter i : ";
    cin>>i;

    cout<<i<<" smallest number is : "<<search(arr,0,n-1,i-1);;
    return 0;
}
