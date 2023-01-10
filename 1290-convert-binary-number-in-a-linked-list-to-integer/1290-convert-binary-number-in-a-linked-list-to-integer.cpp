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

        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            ListNode* rem = curr->next;
            curr->next = prev;
            prev = curr;
            curr = rem;
        }
        return prev;
    }        

    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        ListNode* newhead = reverse(head);
        int index=0;
        ListNode* temp = newhead;
        int ans = 0;
        while(temp!=NULL)
        {
            int digit = temp->val;
            temp = temp->next;
            ans+=(pow(2,index)*digit);
            index++;
        }
        return ans;
    }
};