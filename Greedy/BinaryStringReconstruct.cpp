/*
  PROBLEM LINK :
    https://codeforces.com/problemset/problem/1400/C
*/
/*
  Constructive algorithm type .. make carefull observations and implement efficiently to solve this problem 
  A greedy approach is sufficient to solve this problem 
*/

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
void precompute(){
    
}
void solve(){
    string s; cin>>s;
    int n = s.size();
    s = '0'+s; 
    int x; 
    cin>>x; 
    vector<char> w(n+1, '1');
    for(int i=1; i<=n; i++){
        if(s[i] == '0'){
            if(i>x){
                w[i-x] = '0';
            }
            if(i+x<=n){
                w[i+x] = '0';
            }
        }
    }
    char poss_value; 
    for(int i=1; i<=n; i++){
        if(s[i] == '1'){
            if(i>x && w[i-x] == '1'){
                poss_value = '1';
            } 
            else if(i+x<=n && w[i+x] == '1'){
                poss_value = '1';
            }
            else
                poss_value = '0';
            if(poss_value == '0'){
                cout<<-1<<nline;
                return; 
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout<<w[i];
    cout<<nline; 
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
        precompute();
        solve();
    }
}

