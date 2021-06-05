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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* temp = head->next;
        ListNode* newHead = reverse(head->next);
        temp->next = head;
        head->next = nullptr;
        return newHead;
        
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head || !head->next || k ==0)
            return head;
        
        ListNode* temp = head, *last = head;
        int len = 0;
        while(temp)
        {
            ++len;
            if(!temp->next)
                last = temp;
            temp = temp->next;
        }
        k = k % len;
        if(!k)
            return head;
        
        temp = head;
        int diff = len - k - 1;
        while(diff--)
            temp = temp->next;
        ListNode* next = temp->next;
        temp->next = nullptr;
        
        // reverse(next);
        // temp = next;
        // while(temp)
        // {
        //     cout<<temp->val<<' ';
        //     temp = temp->next;
        // }
        
        last->next = head;
        head = next;
        
        return head;
    }
};