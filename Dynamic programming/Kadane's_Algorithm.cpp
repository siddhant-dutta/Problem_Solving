//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=1&query=category[]Dynamic%20Programmingpage1category[]Dynamic%20Programming#

#include <bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ll long long
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define nline "\n"

/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}

int dp[1000001];
int maxSubarraySum(int a[], int n){
    // base case initialization 
    for(int i=0; i<1000001; i++)
        dp[i] = 0;
    dp[0] = a[0];
    
    // choice tree
    int max_sum = dp[0];
    for(int i=1; i<n; i++){
        if(dp[i-1]<0)
            dp[i] = a[i];
        else
            dp[i] = dp[i-1] + a[i];
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum; 
}
/*
	HYPOTHESIS: 
		1) Here dp[i] represents the best sum we can make using the element a[i] , that means whether to include it in
			dp[i-1] or not 
			
	CHOICE TREE:
		1) if dp[i-1] is negative that means it will be better that we donot include a[i] in the sum till a[i-1]
			because a[i] by itself only will be give the best sum  
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t; 
	cin>>t; 
	while(t--){
		int n; cin>>n; 
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		cout<<maxSubarraySum(a, n)<<nline;
	}
}
