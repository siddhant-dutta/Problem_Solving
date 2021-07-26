#include <bits/stdc++.h>
using namespace std ;
int dp[1001][1001];

int main(){
    
    for(int i=0; i<1001; i++){
        dp[0][i]=dp[i][0]=0; // base case initiallization 
    }
    int wt[1000], v[1000];
    int n, W; 
    cin>>n>>W;
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++) cin>>wt[i]; 
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(wt[i-1]<=j)
                dp[i][j] = max(v[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][W];
}