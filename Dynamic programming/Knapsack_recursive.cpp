// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
/*
constraints:1 ≤ N ≤ 1000
            1 ≤ W ≤ 1000
            1 ≤ wt[i] ≤ 1000
            1 ≤ v[i] ≤ 1000
*/
#include<bits/stdc++.h>
using namespace std; 
int knapsack(int wt[],int v[], int W, int n){
    // base case
    if(n==0||W==0) return 0;
    // choice tree 
/*
            wt[n-1]<=W
              __|__
             |     |
       take w[n-1]  don't take w[n-1]
            wt[n-1]>W -> don't take w[n-1]
*/
    if(wt[n-1]<=W){
        return max(v[n-1]+knapsack(wt, v, W-wt[n-1], n-1), knapsack(wt, v, W, n-1));
    }
    else{
        return knapsack(wt, v, W, n-1);
    }
}
int main (){
    int wt[1000], v[1000];
    int n, W; 
    cin>>n>>W;
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++) cin>>wt[i];
    cout<<knapsack(wt, v, W, n);
}