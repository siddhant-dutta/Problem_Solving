/*
COIN COMBINATIONS II
https://cses.fi/problemset/task/1636/
HELP: https://www.youtube.com/watch?v=-pXjopzMVrE&list=PLb3g_Z8nEv1h1w6MI8vNMuL_wrI0FtqE7&index=5

3 9
2 3 5

x=5 : 2 3 , 3 2 , 5
here we can see repetative solns appearing
to avoid them we can do as follows

if suppose we are choosing 2 
we will not give any other option at the currect moment to choose any other coin since that will generate repetative cases

So if we choose 2 now we will have to make sum 5-2 and we still choose 2 one more time... but if we donot choose 2 we will not be able to choose 2 any more so the option left is just 3 or 5
*/

#include <bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ll long long
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define nline "\n"
#define space " "

/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}

void precompute(){
    
}
// coins : {c1, c2, .... cn}
void solve(){
    int n, x; 
    cin>>n>>x;
    vector<int> coins(n+1); 
    for(int i=1; i<n+1; i++){
        cin>>coins[i];
    }
    // make sum x using coins : {c1,...cn}
    vector<vector<int>>dp(n+1, vector<int>(x+1));
    // base case initialization 
    for(int i=1; i<=n; i++){
        dp[i][0] = 1; 
    }
    // choice tree implementation 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            if(j-coins[i]>=0){
                // make j-coins[i] using coins:{c1,..ci} + make j using coins: {c1,..ci-1}
                // that means either take the jth coin atleast once or don't take the jth coin at all
                dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
            dp[i][j] %= MOD; 
        }
    }
    cout<<dp[n][x];
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
    precompute();
    while(t--){
        solve();
    }
}

