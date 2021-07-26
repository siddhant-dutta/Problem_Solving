//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
#include <bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ll long long
#define mp make_pair
#define pb push_back
#define MOD 1000000007

/****** DEBUGGER ******/
#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " : "; prt(x); cerr << endl;
#else
#define debug(x)
#endif

void prt(vector<int> v) { cerr << "[ "; for (auto i : v) { cerr << i << " "; } cerr << "]"; }
void prt(vector<ll> v) { cerr << "[ "; for (auto i : v) { cerr << i << " "; } cerr << "]"; }
void prt(vector<pair<int, int>> v) { for (auto i : v) {cerr << "\n[ " << i.first << " " << i.second << " ]";}}
void prt(vector<pair<ll , ll >> v) {for (auto i : v) {cerr << "\n[ " << i.first << " " << i.second << " ]";}}
void prt(vector<vector<int>>v) {cerr<<"\n";for (auto i : v) {cerr<<"[ "; for(auto j : i) {cerr<<j<<" ";} cerr<<"]\n";}}
void prt(vector<vector<ll>>v) {cerr<<"\n";for (auto i : v) {cerr<<"[ "; for(auto j : i) {cerr<<j<<" ";} cerr<<"]\n";}}

void prt(int a) {cerr << a;}
void prt(ll a) {cerr << a;}
void prt(double a) {cerr <<fixed<< setprecision(10) <<a;}
void prt(char a) {cerr << "'" << a << "'" ;}
void prt(string a) {cerr << """ << a << """;}
void prt(bool a) {cerr << a;}

/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}

vector<int> dp(10000001, -2);

int solve (vector<int>a, int idx){
	if(dp[idx]!=-2) return dp[idx];
	int n = a.size();
	if(idx==n-1) 
		return dp[idx] = 0;

	int ans = INT_MAX; 
	for(int i = idx+1; i<=idx+a[idx]; i++){
		if(i>=n) break; 
		if(solve(a,i)==-1) continue;
		ans = min(ans, 1+solve(a,i));
	}
	if(ans==INT_MAX) 
		return dp[idx] = -1;
	return dp[idx] = ans; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t = 1; 
	// cin>>t; 
	while(t--){
		int n ; 
		cin>>n; 
		vector<int>a(n);
		for(auto &ele : a) cin>>ele;
		cout<<solve(a,0);
	}
}
