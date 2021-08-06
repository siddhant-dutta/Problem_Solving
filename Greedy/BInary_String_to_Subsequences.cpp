/*
    PROBLEM LINK :
        https://codeforces.com/contest/1399/problem/D
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
    1) Store number of the sequence in two groups .. ending with 0 and with 1
    2) when you are on s[i] and if s[i] == '0' then add it to any sequence from the grp
        ending with 1 and then swap the number of that seq from ending with 1 to ending with 0
    3) if now seq ending with 1 is present then just start a new sequence ending with 0 
    4) Do the same thing when s[i] == '1'
*/
void solve(){
    int n; 
    cin>>n; 
    string s; 
    cin>>s;
    vector<int> endw0; 
    vector<int> endw1;
    vector<int> ans(n);

    for(int i=0; i<n; i++)
    {
        int new_pos = endw1.size() + endw0.size() + 1;
        if(s[i] == '0')
        {
            if(endw1.size() == 0)
            {
                endw0.push_back(new_pos);
            }
            else
            {
                new_pos = endw1.back();
                endw1.pop_back();
                endw0.push_back(new_pos);
            }
        }
        else
        {
            if(endw0.size() == 0)
            {
                endw1.push_back(new_pos);
            }
            else
            {
                new_pos = endw0.back();
                endw0.pop_back();
                endw1.push_back(new_pos);
            }   
        }
        ans[i] = new_pos;
    } 
    cout<<endw0.size()+endw1.size()<<nline;
    for(auto seq_no: ans) cout<<seq_no<<" ";
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
    precompute();
    int t; 
    cin>>t; 
    while(t--){
        solve();
    }
}
