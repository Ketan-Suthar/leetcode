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
    TreeNode* helper(TreeNode* root)
    {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        TreeNode* left = helper(root->left);
        TreeNode* right = helper(root->right);
        
        if(left)
        {
            root->right = left;
            root->left = nullptr;
            while(left->right){
                if(left->left)
                    left->left = nullptr;
                left = left->right;
            }
            left->right = right;
            left->left = nullptr;
        }
        else
        {
            root->right = right;
        }
        
        return root;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};