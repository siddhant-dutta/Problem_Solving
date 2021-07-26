// https://www.codechef.com/problems/ALTARAY
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
		int n; 
		cin>>n ; 
		vector<int> dp(n,1);
		ll a[n];
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=n-2; i>=0; i--){
			if(a[i]*a[i+1]<0) {
				dp[i] = dp[i+1] + 1; 
			}
		}
		for(auto ele : dp) cout<<ele<<" ";
		cout<<endl;
	}
}
