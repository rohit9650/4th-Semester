#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

int size = 100;
clock_t Time = clock();

using namespace std;

int comparision = 0;

void merge(int l, int m, int r, int arr[]){

    int n1 = m-l+1 , n2 = r-m;
    int Larr[n1],Rarr[n2];

    for(int i=0; i<n1; i++)
        Larr[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        Rarr[i] = arr[m+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){

        if(Larr[i]<=Rarr[j]){
            comparision++;
            arr[k++] = Larr[i++];
        }
        else{
            comparision++;
            arr[k++] = Rarr[j++];

        }
    }

    while(i<n1)
            arr[k++] = Larr[i++];

    while(j<n2)
            arr[k++] = Rarr[j++];
}

void mergesort(int l, int r, int arr[]){

    if(l<r){
        int m = l + (r-l)/2;
        mergesort(l,m,arr);
        mergesort(m+1,r,arr);
        merge(l,m,r,arr);
    }
}

int main(){
    int test = 0,size=100;
    cout<<"\nMerge : ";
    cout<<"\nInput size\t\tComparision\n";
 do{
    comparision=0;
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 100;

    mergesort(0,size-1,arr);

    cout<<"\n"<<size<<"\t\t         "<<comparision;
    test++;
    size += 100;
    }while(test<10);

    size=100;test=0;
    cout<<"\nQuick : ";
    cout<<"\nInput size\t\tComparision\n";
 do{
    comparision=0;
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 100;

    quicksort(0,size-1,arr);

    cout<<"\n"<<size<<"\t\t         "<<comparision;
    test++;
    size += 100;
    }while(test<10);
    return 0;
}
