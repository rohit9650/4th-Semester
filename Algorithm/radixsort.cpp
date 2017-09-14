#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int s;
int *b=new int[s+1];

void countsort(int *a,int *temp2,int s)
{
	int *c;
	c=new int[10];
	for(int j=0;j<10;j++)
	{
		c[j]=0;
	}
	for(int i=1;i<=s;i++)
		c[temp2[i]]++;
	cout<<"\n Count of occurence of each element is: \n";
	for(int j=0;j<10;j++)
		cout<<" "<<c[j];
	for(int k=1;k<10;k++)
		c[k]+=c[k-1];
	cout<<"\n The cumulative sum is: \n";
	for(int j=0;j<10;j++)
		cout<<" "<<c[j];
	for(int i=s;i>=1;i--)
	{
		b[c[temp2[i]]]=a[i];
		c[temp2[i]]--;
	}
	cout<<"\n The sorted array  is: \n";
	for(int l=1;l<=s;l++)
	{
		cout<<" "<<b[l];
	}
}


void radixsort(int *a,int s)
{
	int *temp1=new int[s+1];
	int *temp2=new int[s+1];
	for(int j=1;j<=3;j++)
	{
		for(int i=1;i<=s;i++)
		temp1[i]=a[i];
		for(int k=1;k<=j;k++)
		{
			for(int i=1;i<=s;i++)
			{
				temp2[i]=temp1[i]%10;
				temp1[i]=temp1[i]/10;
			}
		}
		cout<<"\n \n \n FOR "<<j<<" DIGIT : ";
		countsort(a,temp2,s);
		for(int l=1;l<=s;l++)
			a[l]=b[l];
	}
}

void input()
{
	int *a;
	cout<<"\n Enter size of array : ";
	cin>>s;
	cout<<"\n The array is : \n";
	a=new int[s+1];
	for(int i=1;i<=s;i++){
		a[i]=(rand()%800)+100;
	}
	for(int i=1;i<=s;i++)
	cout<<" "<<a[i];
	radixsort(a,s);
}

int main()
{
	srand(time(0));
	input();
	return 0;
}

