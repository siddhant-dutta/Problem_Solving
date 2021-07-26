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

int solve(vector<int> a, int n){
	int max_range = min(a[0], n-1);
	int curr_end = min(a[0], n-1);
	int jumps = 0;
	for(int i=1; i<n; i++){
		max_range = min(max(max_range, i+a[i]), n-1);
		if(i==curr_end) {
			if(max_range==i && i!=n-1) break;
			jumps++;
			curr_end = max_range;
		}
	}
	if(max_range != n-1 || jumps == 0) return -1;
	return jumps; 
}
/*
	ANALYSIS: 
		HERE THE TIME COMPLEXITY IS O(N) 
		ON THE OTHER HAND FOR THE DYNAMIC PROGRAMMING APPROACH IT IS O(N^2)

	CONCLUSION: 
		THE GREEDY APPROACH IS BETTER AND EASY TO UNDERSTAND FOR THIS PROBLEM 
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
		vector<int> a(n);
		for(int i=0; i<n; i++) cin>>a[i];
		cout<<solve(a,n)<<endl;
	}
}
