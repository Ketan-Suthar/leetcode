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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        if(!list2) return list1;
        
        ListNode* ath = list1, *bth=list1, *temp = list1, *last = list2;
        while(last->next)
            last = last->next;
        
        int ind = 1;
        if(a==0)
        {
            list1 = list2;
            temp = list1;
        }
        else
        {
            for(;ind<a;++ind)
            {
                if(ath)
                {
                    ath = ath->next;
                    bth = bth->next;
                }
            }
            temp = ath->next;
        }
        
        if(b==0)
        {
            list1 = list2;
            last->next = list1;
            return list1;
        }
        else
        {
            cout<<bth->val<<' ';
            for(;ind<=b;++ind)
            {
                if(bth)
                    bth = bth->next;
            }
            cout<<bth->val<<' ';
            ath->next = list2;
            if(bth)
                last->next = bth->next;
            else
                last->next = nullptr;
        }
        // ListNode *del = temp;
        // while(temp)
        // {
        //     temp = del->next;
        //     if(del)
        //         delete del;
        //     del = temp;
        // }
        return list1;
    }
};