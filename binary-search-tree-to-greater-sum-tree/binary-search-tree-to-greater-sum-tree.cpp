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
    int helper(TreeNode* root, int rightSum)
    {
        if(!root) return 0 + rightSum;
        if(!root->left && !root->right)
        {
            root->val = root->val + rightSum;
            return root->val;
        }
        int rightTreeSum = helper(root->right, rightSum);
        rightTreeSum = root->val = root->val + rightTreeSum;
        if(root->left)
        {
            int temp = root->left->val;
            int leftSum = helper(root->left, rightTreeSum);
            rightTreeSum = leftSum;
        }
        cout<<rightTreeSum<<' ';
        return rightTreeSum;
    }
    TreeNode* bstToGst(TreeNode* root)
    {
        if(!root) return root;
        helper(root, 0);
        return root;
    }
};