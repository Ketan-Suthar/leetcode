/**
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
    void nodeAtKdistanceFromRoot(TreeNode* root, int k,vector<int> &res)
    {
        if(!root || k < 0) return;
        if(k==0)
        {
            res.push_back(root->val);
        }
        else
        {
            nodeAtKdistanceFromRoot(root->left, k-1, res);
            nodeAtKdistanceFromRoot(root->right, k-1, res);
        }
    }
    int helper(TreeNode* root, TreeNode* target, int k, vector<int> &res)
    {
        if(!root) return -1;
        if(root->val==target->val)
        {
            cout<<"found";
            nodeAtKdistanceFromRoot(target, k, res);
            return 0;
        }
        int dl = helper(root->left, target, k, res);
        if(dl != -1)
        {
            if(dl+1 == k)
                res.push_back(root->val);
            else
                nodeAtKdistanceFromRoot(root->right, k-dl-2, res);
            return dl+1;
        }
        int dr = helper(root->right, target, k, res);
        if(dr != -1)
        {
            if(dr+1 == k)
                res.push_back(root->val);
            else
                nodeAtKdistanceFromRoot(root->left, k-dr-2, res);
            return dr+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        vector<int> res;
        helper(root, target, k, res);
        return res;
    }
};