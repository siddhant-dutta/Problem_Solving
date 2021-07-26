//https://www.geeksforgeeks.org/partition-problem-dp-18/
// it is a variation of the knapsack 1-0 problem 
#include<bits/stdc++.h>
using namespace std; 
int main(){
    // base case initiallization 
    bool dp[101][10000];
    int N, W=0; 
    cin>>N; 
    int a[N];
    for(int i=0; i<101; i++) dp[i][0]=true; // wt required = 0 so we can always make an empty subset
    for(int i=1; i<10000; i++) dp[0][i]=false;// no element in the set but non zero required wt therefore not possible 
    for(int i=0; i<N; i++) {cin>>a[i]; W+=a[i];}
    if(W%2==0) W/=2;
    else {cout<<"NO\n"; return 0;} 
    /* 
    here our hypothesis is that dp[n][w] tells us whether it is possible to make 
    total weight w by using the first n elements of the given array of items 
    */
    // implemeting the choice tree
    for(int n=1; n<N+1; n++){
        for(int w=1; w<W+1; w++){
            if(a[n-1]<=w)
                dp[n][w] = dp[n-1][w-a[n-1]] || dp[n-1][w];
            else dp[n][w] = dp[n-1][w];
        }
    }
    if(dp[N][W]) cout<<"YES\n";
    else cout<<"NO\n";
}