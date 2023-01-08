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
    int listsize(ListNode*head)
    {
        int size=0;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            size++;
            curr = curr->next;
        }
        return size;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* newhead=NULL;
        ListNode* curr = head;
        ListNode* prevfirst = NULL;
        bool firsttime = true;
        int len = listsize(head);
        int times = len/k;
        while(curr!=NULL&&times--)
        {
                ListNode* first = curr;
                ListNode* prev = NULL;
                int count=0;
                while(count<k)
                {
                    ListNode* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    count++;
                }
            if(firsttime){
                newhead = prev;
                firsttime = false;
            }
            else
            {
                prevfirst->next = prev;
            }
            prevfirst = first;
        }
        if(len%k!=0)
            prevfirst->next = curr;
        return newhead;
    }
    
};