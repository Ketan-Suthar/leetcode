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
    pair<int,int> helper(TreeNode* root, int &res)
    {
        if(!root) return {INT_MAX, INT_MIN};
        if(!root->left && !root->right)
            return {root->val, root->val};
        pair<int,int> left = helper(root->left, res);
        pair<int,int> right = helper(root->right, res);
        
        int minimum = min(left.first, right.first);
        res = max(res, abs(root->val-minimum));
        
        int maximum = max(left.second, right.second);
        res = max(res, abs(root->val-maximum));
        
        return {min(minimum, root->val), max(maximum, root->val)};
    }
    int maxAncestorDiff(TreeNode* root)
    {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};