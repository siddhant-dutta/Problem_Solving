// https://codeforces.com/contest/16/problem/E
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
void prt(vector<vector<int>>v) {for (auto i : v) {for(auto j : i) {cerr<<"[ "<<j<<" "} cerr<<"]\n"}

void prt(int a) {cerr << a;}
void prt(ll a) {cerr << a;}
void prt(char a) {cerr << "'" << a << "'" ;}
void prt(string a) {cerr << """ << a << """;}
void prt(bool a) {cerr << a;}


/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}

double prob[20][20];
double dp[(1<<19)];

double prob_dying(int prev_mask, int j, int &n){
	int k = __builtin_popcount(prev_mask);
	ll denominator = (k*(k-1))/2;
	double move_prob = 0;
	for(int fish=0; fish<n; fish++){
		if(prev_mask & (1<<fish)){
			move_prob += prob[fish][j];
		}
	}
	return move_prob/denominator;
}

double solve(int mask, int& n){
	int alive = __builtin_popcount(mask); // counts the number of 1s in the binary form of mask
/*
	Hypothesis:
		1) mask is a bit mask for the set of the fishes alive at a given stage 
		2) solve(mask,n) gives us the probability of reaching the state corressponding to the mask 
	Choice tree: 
		1) if a fish say j is dead at the current state .. then we will calculate the probability 
			of j dying if it was alive in the previous state .. 
		2) then we will add all the probabilities corressponding to such dead fishes in the current state 
*/
	//base case
	if(alive==n) return 1;
	if(dp[mask] > -0.9) return dp[mask];

	double answer = 0;
	for(int fish=0; fish<n; fish++){
		if(!(mask & (1<<fish))){   // fish found dead in the current state
			int prev_mask = mask ^ (1<<fish);
			double prev_state = solve(prev_mask, n);
			answer += prob_dying(prev_mask, fish,n)*prev_state;
		}
	}
	return dp[mask] = answer; 
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
	while(t--){
		int n; cin>>n; 
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) 
				cin>>prob[i][j];
		}
		for(int i=0; i<n; i++){
			cout<<fixed<<setprecision(10)<<solve((1<<i),n)<<' ';
		}
	}
}



