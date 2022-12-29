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
    int getsize(ListNode* head)
    {
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode* swapPairs(ListNode* head) {// lets do by swapiing nodes data
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        if(head->next->next==NULL)
        {
            ListNode* temp = head->next;
            head->next->next = head;
            head->next = NULL;
            return temp;
        }
        ListNode* first = head->next;
        ListNode* sec = head;
        int len = getsize(head);
        ListNode* temp =head;
        while(first!=NULL&&first->next!=NULL)
        {
            swap(first->val, sec->val);
            sec = first->next;
            first = first->next->next;
        }
        if(len%2==0)
        {
            swap(first->val, sec->val);
        }
       
    
        
        
        return head;
    }
};