//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19
#include <bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ll long long
#define mp make_pair
#define pb push_back
#define MOD 1000000007

/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}

int solve(int n, int m, string x, string y){
	//base case 
	if(n==0 || m==0)
		return 0;
	//choice tree 
	if(x[n-1] == y[m-1]){
		return 1 + solve(n-1,m-1,x,y);
	}
	else{
		return max(solve(n-1,m,x,y), solve(n,m-1,x,y));
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
	int t; 
	cin>>t; 
	while(t--){
		int n, m; 
		cin>>n>>m;
		string x, y; 
		cin>>x>>y;
		cout<<solve(n,m,x,y)<<endl;
	}
}
