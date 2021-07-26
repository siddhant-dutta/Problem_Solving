//https://www.codechef.com/problems/DELISH
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

ll l_min_dp[1000004], l_max_dp[1000004], r_min_dp[1000004], r_max_dp[1000004];
ll solve(ll D[], int n){
/*	Hyposthesis : 
		1) Here we can prove that k = j+1 that is the two sub-arrays need to be consequent
		2) this is because if k!=j+1 and S = D[j+1]+..+D[k-1] , if S>=0 then we can add S to 
			the max (D[i]+..+D[j], D[k]+..+D[l])
		3) similarly if S<0 we can add it to the min (D[i]+..+D[j], D[k]+..+D[l])
		4) So we can find and store the maximum and minimum subarray sum starting from i 
			and then use it for further computation 
		5) Now, we can interate over j {0,1,..n-2} and find the 
			max (abs(l_min_dp[j] - r_max_dp[j+1]), abs(l_max_dp[j] - r_mix_dp[j+1]))
*/
	// base case 
	l_max_dp[0] = l_min_dp[0] = D[0];
	r_max_dp[n-1] = r_min_dp[n-1] = D[n-1];
	for(int i=000; i<n; i++){
		l_max_dp[i] = max(D[i], l_max_dp[i-1] + D[i]);
		l_min_dp[i] = min(D[i], l_min_dp[i-1] + D[i]);
	}
	for(int i=n-2; i>=0; i--){
		r_max_dp[i] = max(D[i], r_max_dp[i+1] + D[i]);
		r_min_dp[i] = min(D[i], r_min_dp[i+1] + D[i]);
	}
	ll answer = 0;
	for(int j=0; j<n-1; j++){
		answer = max(answer, abs(l_min_dp[j] - r_max_dp[j+1]));
		answer = max(answer, abs(l_max_dp[j] - r_min_dp[j+1]));
	}
	return answer; 
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
		int n; cin>>n; 
		ll D[n];
		for(int i=0; i<n; i++){
			cin>>D[i];
		}
		cout<<solve(D, n)<<"\n";
	}
}
