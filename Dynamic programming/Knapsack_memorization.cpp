// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
/*
constraints:1 ≤ N ≤ 1000
            1 ≤ W ≤ 1000
            1 ≤ wt[i] ≤ 1000
            1 ≤ v[i] ≤ 1000
*/

#include<bits/stdc++.h>
using namespace std ;

int dp[1001][1001]; // this is because there are two variables W and n 

int knapsack(int wt[], int v[], int W, int n){
    if(n==0||W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W]; 
    if(wt[n-1]<=W){
        return dp[n][W] = max(v[n-1]+knapsack(wt, v, W-wt[n-1], n-1), knapsack(wt, v, W, n-1));
    }
    else{
        return dp[n][W] = knapsack(wt, v, W, n-1); 
    }
}

int main (){
    int wt[1000], v[1000];
    int n, W; 
    cin>>n>>W;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++) cin>>wt[i];
    cout<<knapsack(wt, v, W, n);
}