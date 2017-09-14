#include<iostream>

using namespace std;

int randomized_partition(int *arr,int l, int r){

    int i=l-1;
    srand (time(NULL));
    int pivot = arr[rand()%(r-l+1) + l];
    for(int j=l; j<=r-1; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[r]);

    return i+1;
}

int randomized_select(int *arr,int p, int r, int i){

    if(p==r)
        return arr[p];
    int q = randomized_partition(arr,p,r);
    int k = q;
    if(k==i)
        return arr[k];
    else if(i<k)
            return randomized_select(arr,p,q-1,i);
         else
            return randomized_select(arr,q+1,r,i);

}



int main(){
    srand(time(0));
    int n,i,*arr;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    arr  =new int[n];
    for(i=0; i<n; i++)
        arr[i] = rand()%100;
    cout<<"\nEnter the value of i : ";
    cin>>i;
    cout<<"\n\n\tThe ith smallest element in    ";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"  is : "<<randomized_select(arr,0,n-1,i-1);
    //cout<<"  is : "<<order_statistics(arr,n,i);
    return 0;
}





/*int order_statistics(int a[], unsigned n, unsigned k){

	for (unsigned l = 1, r = n;;){

		if (r <= l + 1){
			// current portion consists of one or two elements -
			// can easily find the answer
			if (r == l + 1 && a[r] <a[l])
				swap (a[l], a[r]);
			return a [k];
		}

		// we order a [l], a [l + 1], a [r]
		unsigned mid = (l + r) >> 1;
		swap (a[mid], a[l + 1]);
		if (a[l]> a[r])
			swap (a[l], a[r]);
		if (a[l + 1]> a[r])
			swap (a[l + 1], a[r]);
		if (a[l]> a[l + 1])
			swap (a[l], a[l + 1]);

		// perform division
		// barrier is a [l + 1], i.e., median among a [l], a [l + 1], a [r]
		unsigned
			i = l + 1,
			j = r;

		int cur = a[l + 1];
		for (;;)
		{
			while (a[++i] <cur);
			while (a[--j]> cur);
			if (i>j)
				break;
			swap (a[i], a[j]);
		}

		// insert barrier
		a[l + 1] = a[j];
		a[j] = cur;

		// continue to work in that part,
		// which should contain the desired element
		if (j>= k)
			r = j-1;
		if (j <= k)
			l = i;
	}
}*/
