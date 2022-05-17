/*
https://leetcode.com/problems/next-greater-element-i/
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        stack<int> s; 
        map<int,int> temp;
        for(int i=0; i<m; i++) temp[nums2[i]]=-1;
        for(int i=0; i<m; i++){
            while(!s.empty() && s.top()<nums2[i]){
                temp[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            res.push_back(temp[nums1[i]]);
        }
        return res;
    }
};
