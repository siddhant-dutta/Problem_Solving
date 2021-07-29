/*
    PROBLEM LINK : https://www.codechef.com/COOK131C/problems/MODEQUAL
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

void solve(){
    int n; 
    cin>>n; 
    vector<int> a(n);
    for(int i =0; i<n; i++)
        cin>>a[i];
    int mina = INT_MAX; 
    int min_count = 0;
    for(int i =0; i<n; i++)
    {
        if(a[i] < mina)
        {
            mina = a[i];
            min_count = 1;
            continue; 
        }
        if(a[i] == mina)
        {
            min_count ++;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(a[i] != mina)
        {
            if(a[i] - mina <= mina)
            {
                cout<<n<<nline; 
                return; 
            }
        }
    }
    cout<<n - min_count<<nline; 
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
        solve();
    }
}
