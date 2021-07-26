// https://leetcode.com/problems/target-sum/
// https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12

/**** Just a simple variation of the subset sum problem ****/
#include<bits/stdc++.h>
using namespace std;

int target_sum(vector<int> &a, int target){
    int N=a.size();
    int dp[21][1001];
    int arr_sum = 0;
    for(int i=0; i<N; i++) arr_sum+=a[i];
    int s1 = (arr_sum + target)/2;
    if((arr_sum + target)%2!=0) return 0;
    // now we can find the number of subsets with subset sum = s1
    /*
    HYPOTHESIS : here dp[n][w] keeps track of the number of subsets of the
        the first n numbers of the given array whose sum of the elements 
        is equal to w;
    */
    //base case initialization
    dp[0][0]=1;
    int count_zeros = 0;
    for(int i=1; i<N+1; i++) {
        if(a[i-1]==0) count_zeros++;
        dp[i][0]=1<<(count_zeros);
    } 
    for(int i=1; i<1001; i++) dp[0][i]=0;

    for(int n=1; n<N+1; n++){
        for(int s=1; s<s1+1; s++){
            if(a[n-1]<=s)
                dp[n][s]=dp[n-1][s-a[n-1]] + dp[n-1][s];
            else 
                dp[n][s]=dp[n-1][s];
        }
    }
    return dp[N][s1];
}

int main(){
    int n; cin>>n;
    vector<int> a(n,0); 
    for(int i=0; i<n; i++) cin>>a[i];
    int target; cin>>target;
    cout<<target_sum(a, target);
}