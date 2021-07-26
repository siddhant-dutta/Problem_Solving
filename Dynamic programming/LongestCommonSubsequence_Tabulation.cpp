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

vector<vector<int>> dp(1000+1, vector<int> (1000+1,0));

int Len_LCS(int n, int m, string x, string y){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1]==y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

string Print_LCS(int n, int m, string x, string y){
	Len_LCS(n,m,x,y);
	// We will travel backwards int the table 'dp' from the point where we had got our length of the longest subsequence 
	// for the two given strings that is from the point dp[n][m]
	int i=n, j=m; 
	string LCS; 
	while(i>0 && j>0){
		if(x[i-1] == y[j-1]){
			LCS += x[i-1];
			i--; j--;
		}
		else{
			if(dp[i][j-1]>dp[i-1][j])
				j--;
			else
				i--;
		}
	}
	reverse(LCS.begin(),LCS.end());
	return LCS; 
}

string Print_Shortest_common_supersequence(int n, int m, string x, string y){
	Len_LCS(n,m,x,y);
	// We will travel backwards int the table 'dp' from the point where we had got our length of the longest subsequence 
	// for the two given strings that is from the point dp[n][m] and store the characters wherever necessary 
	int i=n, j=m; 
	string LCS; 
	while(i>0 && j>0){
		if(x[i-1] == y[j-1]){
			LCS += x[i-1];
			i--; j--;
		}
		else{
			if(dp[i][j-1]>dp[i-1][j])
			{
				LCS += y[j-1];
				j--;
			}
			else
			{
				LCS += x[i-1];
				i--;
			}
		}
	}
	while(i>0){
         LCS += x[i-1];
         i--;
     }
     while(j>0){
        LCS += y[j-1];
         j--;
     }
	reverse(LCS.begin(),LCS.end());
	return LCS; 
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
		for(int i=0; i<1001; i++){
			for(int j=0; j<1001; j++)
				dp[i][j]=0;
		}
		int n, m; 
		cin>>n>>m;
		string x, y; 
		cin>>x>>y;
		cout<<"Longest Common subsequence : "<<Print_LCS(n,m,x,y)<<endl; 
		cout<<"Length of LCS : "<<Len_LCS(n,m,x,y)<<endl;
		cout<<"Shortest Common supersequence : "<<Print_Shortest_common_supersequence(n,m,x,y)<<endl;
		cout<<"Length of Shortest common supersequence : "<< n+m-Len_LCS(n,m,x,y)<<endl; 
	}
}
