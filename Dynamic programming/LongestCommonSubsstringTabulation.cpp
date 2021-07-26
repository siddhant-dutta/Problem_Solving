//https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22
//https://www.geeksforgeeks.org/longest-common-substring-dp-29/

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

int dp[1001][1001];
int solve(int n, int m, string x, string y){
/*
	Hypothesis :  
		1) Here dp[i][j] represents the longest substring ending at posn i in string x and posn j
			in string y.

		2) If x[i-1] != y[j-1]  {i and j are in 1 based indexing} then dp[i][j] = 0
		
		3) If x[i-1] == y[j-1] then dp[i][j] = 1 + dp[i-1][j-1]   
*/
	// base case initialization 
	for(int i=0; i<n+1; i++){
		for(int j=0; j<m+1; j++)
			dp[i][j]=0;
	}
	// choice tree 
	int max_len = 0;
	int max_x = 0, max_y = 0;
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1] == y[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				if(dp[i][j]>max_len){
					max_x = i;
					max_y = j;
				}
				max_len = max(max_len, dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	// this is only requried if we want to print the longest common substring
	string longest_common_substring;
	while(max_x>0 && max_y>0){
		if(dp[max_x][max_y]==0)
			break;
		longest_common_substring = x[max_x-1] + longest_common_substring;
		max_x -= 1;
		max_y -= 1; 
	} 
	// cout<<longest_common_substring<<endl;
	return max_len;
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
