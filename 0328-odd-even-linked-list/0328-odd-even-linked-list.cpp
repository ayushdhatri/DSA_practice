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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* tail = head;
        ListNode* prev=head;
        int count=0;
        while(tail->next!=NULL)
        {
            count++;
            tail = tail->next;
        }
        count++;
        if(head->next==tail)
            return head;
        
        ListNode* curr = head;
        bool odd=false;
        while(count!=0)
        {
            if(odd)
            {
               
                ListNode* temp = curr->next;
                curr->next=NULL;
                tail->next=curr;
                prev->next=temp;
                curr=temp;
                prev=curr;
                tail=tail->next;
                odd=false;
            }
            else
            {
                curr=curr->next;
                odd=true;
            }
            count--;
        }
        
        return head;
        
        
        
        
        
        
        
    }
};