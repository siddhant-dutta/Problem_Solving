/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> recurse(int start, int end){
        if(end < start) return {NULL};
        vector<TreeNode*> left_subtrees, right_subtrees, all_trees;
        
        for(int curRootval=start; curRootval<=end; curRootval++){
            left_subtrees = recurse(start, curRootval-1);
            right_subtrees = recurse(curRootval+1, end);
            for(auto left_subtree: left_subtrees){
                for(auto right_subtree: right_subtrees){
                    TreeNode* curRoot = new TreeNode(curRootval);
                    curRoot->left = left_subtree;
                    curRoot->right = right_subtree;
                    all_trees.push_back(curRoot);
                }
            }
        }
        return all_trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return recurse(1,n);
    }
};
