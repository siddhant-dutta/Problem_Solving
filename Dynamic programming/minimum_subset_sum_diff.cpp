#include <bits/stdc++.h>
using namespace std; 

int subset_sum(int a[], int N){
    int rng=0;
    for(int i=0; i<N; i++) rng+=a[i];

    //base case initialization 
    bool dp[N+1][rng+1];
    for(int i=0; i<N+1; i++) dp[i][0]=true; 
    for(int i=1; i<rng+1; i++) dp[0][i]=false;

    //choice tree implementation of subset sum 
    for(int n=1; n<N+1; n++){
        for(int s1=1; s1<rng+1; s1++){
            if(a[n-1]<=s1)
                dp[n][s1] = dp[n-1][s1-a[n-1]] || dp[n-1][s1];
            else 
                dp[n][s1] = dp[n-1][s1];
        }
    }
/*
    1) here we find that the last row of the matrix dp gives us the whether the sums 
        in the range [0, rng] is possible or not using all the N elements 

    2) also the absolute subset sum diff = s2-s1 .. provided s1<=rng/2
        here s2 = rng - s1 .. therefore abs subset sum diff = rng - 2*s1

    3) if a particular subset sum is possible using all the N elements we keep the 
        track of the minimum abs subset sum diff 
*/
    int mn=INT_MAX;
    for(int i=0; i<=rng/2; i++) {
        if(dp[N][i])
            mn = min (mn, rng - 2*i);
    }
    return mn; 
}

int main (){
    int n; 
    cin>>n; 
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i]; 
    cout<<subset_sum(a, n)<<"\n";
}