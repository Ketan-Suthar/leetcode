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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(!head || !head->next) return head;
        
        ListNode* temp = head, *prev = nullptr;
        while(temp)
        {
            ListNode* next = temp->next;
            while(next && next->val == temp->val)
                next = next->next;
            if(temp->next != next)
            {
                if(!prev)
                {
                    head = next;
                }
                else
                    prev->next = next;
                temp = next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};