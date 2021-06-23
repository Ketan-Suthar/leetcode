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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set <int> m ;
        ListNode* p = nullptr, *q = head;
        for(int x: nums)
        {
            m.insert(x);
        }
        q = head;
        int res = 0;
        while(q != nullptr)
        {
            if(p != nullptr)
            {
                if(m.find(p->val) == m.end() && m.find(q->val) != m.end())
                    ++res;
            }
            else
            {
                if(m.find(q->val) != m.end())
                    ++res;
            }
            p = q;
            q = q->next;
        }
        
        return res;
    }
};