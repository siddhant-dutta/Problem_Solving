class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<long long> left(n), right(n);
        stack<int> nle, ple;
        for(int i=0; i<n; i++) left[i] = i+1; 
        for(int i=0; i<n; i++) right[i] = n-i;
        for(int i=0; i<n; i++){
            // NLE - Next Less Element
            while(!nle.empty() && arr[nle.top()]>arr[i]){
                right[nle.top()] = i-nle.top();
                nle.pop();
            }
            nle.push(i);
            // PLE - Previous Less Element
            while(!ple.empty() && arr[ple.top()]>arr[i])
                ple.pop();
            if(ple.empty()) left[i] = i+1;
            else left[i] = i-ple.top();
            ple.push(i);
        }
        long long ans = 0;
        long long m = 1e9 + 7;
        for(int i=0; i<n; i++){
            // long long x = (arr[i]*left[i]*right[i]);
            ans = (ans + arr[i]*left[i]*right[i])%m;
        }
        return ans;
    }
};

// 11 81 94 43 3
// 11*(1*4)+
// 81*(1*2)+
// 94*(1*1)+
// 43*()+
// 3*(15-10)
// 2 3 4 5 2 6 2
