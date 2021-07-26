// https://codeforces.com/contest/1480/problem/C
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100002;
int n;
int a[MAXN];

void query(int x){
    if(x>=1 && x<=n){
        cout<<"? "<<x<<endl;
        cout.flush();
        cin>>a[x];
    }
}
/*
    1)  0   1   2   3   4   5
        *                   * 
            *   
                    * 
                *   
                        *   
        note that when you are at mid = L+R/2 just roll down with the slope to get to the 
        minima 

    2)  this is because when you are at idx = mid and look to the right and if you see a down
        slope then you move to the right of mid and forget about moving to the left in search of a 
        minima as you are guaranteed that there will surely be a climb to get to a[n+1]

    3)  similarly when you are at idx = mid and look to right and find that there is an
        upward slope then you forget about moving to the right as there is no guarantee
        that you will encounter a minima to the right .. rather you are guaranteed to get 
        a minima to your left or at the place you currently are. 
        This is because it is guaranteed that you will surely have a climb to reach a[0]
*/
int main(){
    cin>>n; 
    a[0]=a[n+1]=n+1;
    int L=1, R=n;
    while(L<R){
        int mid = L + (R-L)/2;
        query(mid); query(mid+1);
        if(a[mid]<a[mid+1]) R=mid; 
        else L=mid+1;
    }
    cout<<"! "<<L;
    cout.flush();
}