#include<iostream>

using namespace std;

int **a;

void lcs(string X, string Y, int m, int n){
    for(int i=0; i<=m; i++)
        a[i][0] = 0;
    for(int i=0; i<=n; i++)
        a[0][i] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(X[i-1] == Y[j-1])
                a[i][j] += a[i-1][j-1] + 1;
            else
                if(a[i-1][j] >= a[i][j-1])
                    a[i][j] = a[i-1][j];
            else
                    a[i][j] = a[i][j-1];

        }
    }
}

void print_lcs(string X, string Y,int i, int j){
    if(i == 0 || j == 0)
        return ;
    if(X[i-1] == Y[j-1]){
        print_lcs(X,Y,i-1,j-1);
        cout<<X[i-1];
    }
    else
        if(a[i-1][j] >= a[i][j-1])
            print_lcs(X,Y,i-1,j);
        else
            print_lcs(X,Y,i,j-1);
}

int main(){
    //string X = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA",Y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    string X,Y;
    int m=0, n=0;
    cout<<"\tEnter first sequence  : ";
    cin>>X;
    cout<<"\n\tEnter second sequence : ";
    cin>>Y;

    while(X[m]!='\0')
        m++;
    while(Y[n]!='\0')
        n++;

    a = new int*[m+1];
    for(int i=0; i<m+1; i++)
        a[i] = new int[n+1];

    lcs(X,Y,m,n);

    cout<<"\n The longest common subsequence is : ";
    print_lcs(X,Y,m,n);

    /*for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}
