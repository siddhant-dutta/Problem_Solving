// https://practice.geeksforgeeks.org/problems/rotation4723/1#
#include<bits/stdc++.h>
using namespace std; 

int findKrotations(int arr[], int n){
    int l=0, h=n-1, mid;
    while(l<=h){
        mid= l + (h-l)/2;
        if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n]) //very imp
        // here we are finding the minima 
            break;
        else if(arr[mid]<=arr[h]) h=mid-1;
        /* 18 2 |3| 6 11 15  -> the minima will exist in the unsorted array 
           unsorted sorted
           1 2 |3| 4 5 6  -> this is an important corner case 
        */
       else if(arr[mid]>=arr[l]) l=mid+1;
       /* 15 11 |18| 2 3 6
           sorted unsorted  
       */
      return mid; 
    }
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<findKrotations(arr, n);
}