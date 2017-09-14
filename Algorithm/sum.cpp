#include<iostream>

using namespace std;

bool **backtrack;

bool subset_sum(int *set,int n,int sum){

    for(int i=0; i<n+1; i++)
        backtrack[i][0] = true;
    for(int i=0; i<sum+1; i++)
        backtrack[0][i] = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(set[i-1]>j)
                backtrack[i][j] = backtrack[i-1][j];
            else{
                backtrack[i][j] = max(set[i-1] + backtrack[i-1][j-set[i-1]],backtrack[i-1][j]);
            }
        }
    }

        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                cout<<backtrack[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=n; i>=0; i--){
            if(backtrack[i][sum] == sum){
                return true;
            }
            else if(i==0)
                return false;
        }
}

/*bool subset_sum(int *set,int n,int sum){
        static int i=0;
        if(sum == 0)
                return true;
        else if(sum<0 || n==0)
            return false;

        if(set[n-1]>sum)
            subset_sum(set,n-1,sum);
        else{
            //backtrack[i++] = set[n-1];
            return (subset_sum(set,n-1,sum-set[n-1])|| subset_sum(set,n-1,sum));
        }
}*/

int main(){
    int n = 0,*set, sum = 0, temp=0;
    cout<<"\nEnter the number of elements in the set : ";
    cin>>n;
    set = new int[n];

    cout<<"\nEnter the numbers      : ";
    for(int i=0; i<n; i++)
        cin>>set[i];
    cout<<"\nEnter the value of sum : ";
    cin>>sum;

    backtrack = new int*[n+1];
    for(int i=0; i<=n; i++)
        backtrack[i] = new int[sum+1];

    if(subset_sum(set,n,sum)){
        cout<<"\n\n\tThe solution is : ";
        for(int i=n; i>0 && temp!=sum; i--){
            if(backtrack[i][sum] == backtrack[i-1][sum])
                continue;
            else{
                cout<<set[i-1]<<" ";
                temp += set[i-1];
            }
        }
    }
    else{
        cout<<"\n\n\tNo solution exist.";
    }
    return 0;
}
/*
int **M;
    M = new int*[n];
    for(int i=0; i<n; i++)
        M = new int[sum];

    for(int i=0; i<n; i++)
        M[i][0] = 0;
    for(int i=0; i<sum; i++)
        M[0][i] = 0;

    for(int i=1; i<n; i++){
        for(int j=1; j<sum; j++){
            if(M[i][j] > j)
                M[i][j]
        }
    }

    int **M;
        M = new int*[n];
        for(int i=0; i<n; i++)
            M = new int[sum];

        for(int i=0; i<n; i++)
            M[i][0] = 0;
        for(int i=0; i<sum; i++)
            M[0][i] = 0;

        for(int i=1; i<n; i++){
            for(int j=1; j<sum; j++){
                if(M[i][j] > j)
                    M[i][j] = M[i-1][j];
                else{
                    M[i][j] = set[i] + M[i-1][j];
                }
            }
        }
*/
