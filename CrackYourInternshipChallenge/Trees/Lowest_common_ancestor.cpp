/**
PROBLEM LINK : 
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) 
            return root;
        auto p1 = lowestCommonAncestor(root->left, p, q);
        auto p2 = lowestCommonAncestor(root->right, p, q);
        if(p1!=NULL && p2!=NULL){
            return root;
        }
        if(p1==NULL) return p2;
        else return p1;
    }
};
