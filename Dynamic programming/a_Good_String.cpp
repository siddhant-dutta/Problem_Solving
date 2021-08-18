/*
  PROBLEM LINK:
    https://codeforces.com/contest/1385/problem/D
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

int solve(const string &s, char c){
  //base case  
  if(s.size()==1){
        return s[0]!=c;  
    }
  int mid = s.size()/2;
  //choice tree implementation 
  /*  1) either n/2 a's will be present in the first half or the other half similarly for all the other c's 
      2) recursive implementation 
      3) BONUS!!  here you learned about the C++ String STL -> count() and also and alternative method to form a substring
  */
  int cnt1 = solve(string(s.begin(),s.begin()+mid), c+1) + mid - count(s.begin()+mid,s.end(),c);
  int cnt2 = solve(string(s.begin()+mid, s.end()), c+1) + mid - count(s.begin(), s.begin()+mid,c);
  return min(cnt1,cnt2);
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
        int n; 
        cin>>n; 
        string s; 
        cin>>s;
        precompute();
        cout<<solve(s,'a')<<nline;
    }
}

