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
    ListNode* removeElements(ListNode* head, int val)
    {
        if(!head) return head;
        
        ListNode* temp = head, *prev = nullptr;
        while(temp)
        {
            if(temp->val == val)
            {
                ListNode* del = temp;
                if(!prev)
                {
                    temp = temp->next;
                    head = temp;
                }
                else
                {
                    prev->next = temp->next;
                    temp = prev->next;
                }
                delete del;
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