/*
    PROBLEM LINK : 
        https://codeforces.com/problemset/problem/1374/D
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
/*
    1) ai and aj be two elements.. if (ai+ci) % k == 0 and (aj+cj) % k ==0
    2) if ci = cj then we will not be able to add ci and cj to ai and aj 
    3) we will have to somehow make all the ci's distinct ... 
    4) ci = (k - ai % k) % k   when ci's become equal the only thing we can do is to increment 
        ci = ci + k 
        
*/
void solve(){
    ll n, k; 
    cin>>n>>k;
    ll ans = 0;
    vector<ll> a(n,0);
    map<ll, ll> freq;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ll temp; 
        temp = (k - (a[i]%k))%k; 
        freq[temp] ++;
        // cout<<temp<<" "<<freq[temp]<<nline;
        a[i] = temp; 
        if(freq[temp] > 1 && temp!=0){
            a[i] += freq[temp]*k - k; 
        }
    }
    sort(a.begin(), a.end());
    if(a[n-1] != 0)
        ans = a[n-1] + 1;
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
    precompute();
    int t; 
    cin>>t; 
    while(t--){
        solve();
    }
}
