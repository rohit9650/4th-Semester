#include<iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int selection_sort(int a[],int size){
    int min=0,temp=0,comparision = 0;
    for(int i=0; i<size-1; i++){
        min = i;
        for(int j=i+1; j<size; j++)
            if(a[min]>a[j]){
                min=j;
                comparision++;
            }
            else
                comparision++;
        if(min != i){
            temp = a[i];
            a[i] = a[min];
            a[min]=temp;
        }
    }
    return comparision;
}

int bubble_sort(int a[], int size){
    int temp=0,comparision=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i; j++)
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                comparision++;
            }
            else
                comparision++;
    }
    return comparision;
}

int insertion_sort(int a[],int size){
    int comparision=0,min=0,j=0;
    for(int i=1; i<size; i++){
        min = a[i];
        for(j=i-1; j>=0; j--){
            if(a[j]>min){
                comparision++;
                a[j+1]=a[j];
            }
            else{
                comparision++;
                break;
            }
        }
        a[j+1]=min;
    }

    return comparision;
}

int main(){
    int test=0,size=100;
    cout<<"\nSelection sort  ";
    cout<<"\nInput size\t\tComparision\n";
 do{
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 10;
    cout<<"\n"<<size<<"\t\t         "<<selection_sort(arr,size);
   // for(int i=0; i<size; ++i)
      //  cout<<arr[i]<<" ";
    test++;
    size +=100;
    }while(test<10);

    cout<<"\n\nBubble sort  ";
    cout<<"\nInput size\t\tComparision\n";
    test=0;size=100;
 do{
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 10;
    cout<<"\n"<<size<<"\t\t         "<<bubble_sort(arr,size);

    test++;
    size +=100;
    }while(test<10);

    cout<<"\n\nInsertion sort  ";
    cout<<"\nInput size\t\tComparision\n";
    test=0;size=100;
 do{
    int arr[size];
    srand ( time(NULL) );
    for(int i=0; i<size; i++)
        arr[i] = rand() % 10;
    cout<<"\n"<<size<<"\t\t         "<<insertion_sort(arr,size);

    test++;
    size +=100;
    }while(test<10);
    return 0;
}
