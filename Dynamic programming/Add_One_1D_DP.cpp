//https://codeforces.com/problemset/problem/1513/C

#include <bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ll long long
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define nline "\n"

/****** Template of some basic operations *****/
template<typename T, typename U, typename R> inline R amin(T x, U y) { if(y < x) return y; return x;}
template<typename T, typename U, typename R> inline R amax(T x, U y) { if(x < y) return y; return x;}
template<typename T, typename U, typename R> inline R binpow(T a, U n){a%=MOD; R res=1; while (n>0){ if(n & 1) res = res * a % MOD; a = a * a % MOD; n>>=1;} return res;}

int dp[200001];

/*
    1) We will pre compute the length 10 after i operations 

    2) this is because we find that every single digit number always starts from 10 after just a 
        few operations 

    3) dp[i] = 2 , ∀ i in [0,8]
       dp[i] = 3, if i=9
        (The final number after applying 9 operations to the number 10 is 109.)

    4) dp[i] = dp[i−9] + dp[i] − 10, Otherwise.
        (length would be the sum of i−9 operations and i−10 operations.)
        We can precalculate the above table until m (Note: 1≤m<2⋅105).
*/

void precompute(){
    for(int i=0; i<200001; i++){
        if(i<9) dp[i] = 2; 

        else if(i==9) dp[i] = 3;
        
        else
            dp[i] = (dp[i-9] + dp[i-10]) %MOD;
        // cout<<dp[i]<<" ";
    }
    // cout<<0<<nline;
}

void solve(){
    string n;
    int m; 
    cin>>n;
    cin>>m;
    int ans = 0;
    for(int i=0; i<n.size(); i++)
    {
        int digit = int(n[i]) - 48;
        int m_ = m - min(9-digit, m);
        // cout<<digit<<" "<<m_<<" \n";
        if(m_ >= 1){
            ans = (ans + dp[m_-1])%MOD ;
        }
        else{
            ans = (ans + 1)%MOD;
        }
    }
    cout<<ans<<nline; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    memset(dp, 0, sizeof dp);
    precompute();

    int t; 
    cin>>t; 
    while(t--){
        solve();
    }
}
