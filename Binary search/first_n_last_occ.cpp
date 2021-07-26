// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
#include<bits/stdc++.h>
using namespace std; 

int first_occ(int arr[], int n, int x){
    int l=0, h=n-1, mid, mid_;
    bool found=false; 
    while(l<=h){
        mid = l + (h-l)/2; // we do this to avoid int overflow
        if(arr[mid]==x){found=true; h=mid-1; mid_=mid;}
        if(arr[mid]<x) l=mid+1;
        if(arr[mid]>x) h=mid-1;
    }
    if(found) return mid_;
    return -1;
}

int last_occ(int arr[], int n, int x){
    int l=0, h=n-1, mid, mid_;
    bool found=false; 
    while(l<=h){
        mid = l + (h-l)/2; // we do this to avoid int overflow
        if(arr[mid]==x){found=true; l=mid+1; mid_=mid;}
        if(arr[mid]<x) l=mid+1;
        if(arr[mid]>x) h=mid-1;
    }
    if(found) return mid_;
    return -1;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int x; cin>>x; 
    if(first_occ(arr,n,x)!=-1)
    {cout<<"First occurence: "<<first_occ(arr, n, x)<<endl;
    cout<<"Last occurence: "<<last_occ(arr, n, x)<<endl;
    cout<<"No. of occurences: "<<last_occ(arr,n,x)-first_occ(arr,n,x)+1;} 
    else cout<<x<<" not found!!";
}

