#include<iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int comparision = 0;

void Lsearch(int a[],int size,int ele){

    for(int i=0; i<size; i++)
        if(a[i]==ele)
            comparision++;
}

void Bsearch(int a[],int l,int r,int ele){
    int mid=0;
    while(l<r){
        mid=(r-l)/2;
        if(a[mid]==ele){
            comparision++;
            break;
        }
        else
            if(a[mid]>ele){
                comparision++;
                r=mid-1;
            }
            else{
                comparision++;
                l=mid+1;
            }
    }cout<<a[mid]<<" ";
}

int main(){
    int test=0,size=100;
    cout<<"\nLinear  ";
    cout<<"\nInput size\t\tComparision\n";
 do{
    comparision=0;
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 100;
    Lsearch(arr,size,rand()%100);
    cout<<"\n"<<size<<"\t\t         "<<comparision;
   // for(int i=0; i<size; ++i)
      //  cout<<arr[i]<<" ";
    test++;
    size +=100;
    }while(test<10);

    cout<<"\n\nBinary  ";
    cout<<"\nInput size\t\tComparision\n";
    test=0;size=100;

do{
    comparision=0;
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 100;
    //Bsearch(arr,0,size,rand()%100);
    cout<<"\n"<<size<<"\t\t         "<<comparision;
   // for(int i=0; i<size; ++i)
      //  cout<<arr[i]<<" ";
    test++;
    size +=100;
    }while(test<10);

    return 0;
}
