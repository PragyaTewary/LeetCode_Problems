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
    ListNode* merge(ListNode* h1, ListNode* h2)
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* c1 = h1;
        ListNode* c2 = h2;
        
        while(c1 && c2)
        {
            if(c1->val < c2->val)
            {
                curr->next = c1;
                c1 = c1->next;
            }
            else
            {
                curr->next = c2;
                c2 = c2->next;
            }
             curr = curr->next;
        }
        
        if(c1)
        {
            curr->next = c1;
        }
        
        if(c2)
        {
            curr->next = c2;
        }
        
        return dummy->next;
    }
    ListNode* findPrevMid(ListNode* head)
    {
        if(!head)
        {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    ListNode* mergeSort(ListNode* node)
    {
        if(!node || !node->next)
        {
            return node;
        }
        ListNode* mid = findPrevMid(node);
        ListNode* second = mid->next;
        mid->next = NULL;
        //cout<<mid->val<<" "<<second->val<<endl;
        ListNode* h1 = mergeSort(node);
        ListNode* h2 = mergeSort(second);
        
        ListNode* h3 = merge(h1, h2);
        //cout<<h3->val<<endl;
        return h3;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        return mergeSort(curr);
        
    }
};