/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            ++count;
            temp = temp->next;
        }
        return count;
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int s1, int s2)
    {
        int diff = s1 - s2;
        ListNode* fast = l1;
        while(diff--)
            fast = fast->next;
        
        ListNode* slow = l2;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int s1 = count(headA);
        int s2 = count(headB);
        
        if(s2 > s1)
            return helper(headB, headA, s2, s1);
        return helper(headA, headB, s1, s2);
    }
};