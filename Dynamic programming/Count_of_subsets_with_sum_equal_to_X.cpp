//https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include <bits/stdc++.h>
using namespace std; 

int dp[101][10001];

int count_subsets(int N, int X, int a[]){
    /*
    HYPOTHESIS : here dp[n][w] keeps track of the number of subsets of the
        the first n numbers of the given array whose sum of the elements 
        is equal to w;
    */
    // base case initiallization
    for(int i=1; i<10001; i++) dp[0][i]=0;
    dp[0][0]=1;
    int count_zeros = 0;
    for(int i=1; i<N+1; i++) {
        if(a[i-1]==0) count_zeros++;
        dp[i][0]=1<<(count_zeros);
    } 
    // choice tree implementation 
    for(int n=1; n<N+1; n++){
        for(int w=1; w<X+1; w++){
            if(a[n-1]<=w) 
                dp[n][w] = dp[n-1][w-a[n-1]] + dp[n-1][w];
            else 
                dp[n][w] = dp[n-1][w];
        }
    }
    return dp[N][X];
}

int main(){
    int N, X; 
    cin>>N>>X;
    int a[N];
    for(int i=0; i<N; i++) cin>>a[i];
    cout<<count_subsets(N, X, a);
}