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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prevzero = head;
        ListNode* currzero  = head;
        ListNode* curr = head->next;
        
        while(curr!=NULL)
        {
            int sum = 0;
            while(curr->val!=0)
            {
                sum+=curr->val;
                curr = curr->next;
            }
            currzero = curr;
            prevzero->val = sum;
            prevzero->next = currzero;
            prevzero = currzero;
            curr = curr->next;
        }
        curr = head;
        while(curr->next->next!=NULL)
        {
            curr = curr->next;
        }
        curr->next =NULL;
        return head;
        
        
    }
};