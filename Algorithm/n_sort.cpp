#include<iostream>
#include<cmath>
#define size 10

using namespace std;

void counting_sort(int arr[],int n,int j){
    int c[n];
    int i, b[10] = {0};

    for (i = 0; i < n; i++)
        b[(arr[i]/j)%10]++;

    for (i = 1; i < 10; i++)
        b[i] += b[i-1];

    for (i = n - 1; i >= 0; i--){
        c[b[(arr[i]/j)%10 ]-1] = arr[i];
        b[(arr[i]/j)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = c[i];
}

void radix(int a[],int d){

    for (int i=1; i<pow(10,d); i*=10)
        counting_sort(a,size,i);
}

int main(){
    int a[size]={441,123,375,229,110,124,666,111,621,123},d=3;
    radix(a,d);
    cout<<"\nSorted array : ";
    for(int i=0; i<size; i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
void counting_sort(int a[],int n,int ){
    int c[k+1];
    int temp[size];
    c[0]=-1;
    FOR1(i,k+1) c[i]=0;
    FOR(i,size) c[a[i]]++;
    FOR1(i,k+1) c[i] += c[i-1];
    for(int i=size-1; i>=0; --i){
        temp[c[a[i]]] = b[i];
        c[a[i]]-=1;
        FOR(i,size)
        cout<<b[i]<<" ";
        cout<<"\n";
    }

}
*/
