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
    ListNode* mergeKListsHelper(ListNode* l1, ListNode* l2)
    {
        ListNode *p=l1,*q=l2,*next, *head;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val)
        {
            head = l1;
            p = l1->next;
        }
        else
        {
            head = l2;
            q = l2->next;
        }
        next=head;
        while(p && q)
        {
            if(q->val <= p->val)
            {
                next->next = q;
                q = q->next;
            }
            else
            {
                next->next = p;
                p = p->next;
            }
            next = next->next;
        }
        if(p)
            next->next = p;
        if(q)
            next->next = q;
        next=head; cout<<'\n';
        while(next){
            cout<<next->val<<' ';
            next = next->next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int last = lists.size()-1;
        cout<<last<<' ';
        if(last<0) return nullptr;
        while(last)
        {
            int start = 0, end = last;
            while(start<end)
            {
                cout<<"in loop";
                lists[start] = mergeKListsHelper(lists[start], lists[end]);
                ++start;
                --end;
                if(start>=end)
                    last=end;
            }
        }
        return lists[0];
    }
};