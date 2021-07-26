// DP with bit masking 
// https://www.youtube.com/watch?v=685x-rzOIlY&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=3
/*

Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

Sample Output
13

Constraints
N <= 20

*/
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

int dp[21][(1<<21)];
vector<vector<int>>cost(21, vector<int>(21,0));

int solve(int i, int mask, int &n){
	//Base case 
	if(i==n) return 0;
	if(dp[i][mask]!=-1) return dp[i][mask];
/*
	Hypothesis: 
	1) Here we have used bitmasking with DP 
	
	2) mask stores the different subsets of {p1,p2,..pn} where pi is a worker 
		and {J1,J2,J3,..Jn} are the n different jobs 
	
	3) dp[i][mask] stores the minimum cost of doing jobs Ji -> Jn by workers 
		according to the subset mask
	
	4)							CHOICE TREE 
					(if pj is present in the subset mask)
								i=1, {p1,p2..pn}
		____________________________|____________________________
	   |                       |                                 |
i=2,{p2,p3,..pn}  ...... i=4,{p1,..p3,p5..pn} ......... i=n,{p1,p2,...pn-1}
	
	5) Time complexity analysis:  O(n^2 * 2^n)

*/
	int answer=INT_MAX; 
	for (int j = 0; j < n; ++j)
	{
		if(mask&(1<<j))
			answer = min(answer, cost[j][i] + solve(i + 1,(mask^(1<<j)),n));
	}
	return dp[i][mask] = answer ; 
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
	memset(dp, -1, sizeof dp);
	while(t--){
		int n; 
		cin>>n; 
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++)
				cin>>cost[i][j];
		}
		cout<<solve(0, (1<<n) - 1, n)<<endl;
		debug(cost)
	}
}
