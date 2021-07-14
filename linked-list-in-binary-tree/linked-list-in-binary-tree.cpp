/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(ListNode* head, TreeNode* root) {
        if(!head && !root) return true;
        
        if(!root) return false;
        if(!head) return true;
        
        if(root->val != head->val) return false;
        return helper(head->next, root->left) ||
                    helper(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head && !root) return true;
        
        if(!root) return false;
        if(!head) return true;
        
        if(root->val == head->val)
        {
            bool res = helper(head->next, root->left) ||
                    helper(head->next, root->right);
            if(res) return res;
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
            
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};