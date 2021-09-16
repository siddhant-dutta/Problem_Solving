/*
LONGEST INCREASING SUBSEQUENCE :  
https://cses.fi/problemset/result/2855738/#test1
https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

O(N^2) soln 
#    length of the longest increasing subsequence ending at ith index be dp[i]
#    now we can recursively find the length of the longest increasing subsequence in the entire array 

O(NlogN) soln -> VIMP
#    now let dp[i] be the element at which an increasing subsequence terminates. 
#    now suppose we have two subsequences of length i then we will take the one whose terminating number is smaller 
this is because the subsequence ending at a smaller number will be more benefecial there is much more possibility of it being extended to a larger subsequence     
*/


#include <bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ll long long
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define nline "\n"
#define space " "

/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}
void precompute(){
    
}
void solve(){
    int n; 
    cin>>n;
    vector<int> a(n); 
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> dp(n+1, INT_MAX);
    dp[0] = INT_MIN; 

    for(int i=0; i<n; i++){
        int j = upper_bound(dp.begin(), dp.end(),a[i]) - dp.begin();
        if(dp[j-1]<a[i] && a[i]<dp[j])
            dp[j] = a[i];
    }
    for(int i=n; i>=0; i--){
        if(dp[i]<INT_MAX){
            cout<<i<<nline; 
            return ;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int t=1; 
    // cin>>t; 
    precompute();
    while(t--){
        solve();
    }
}

