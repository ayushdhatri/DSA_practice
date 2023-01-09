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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2== NULL)
            return list1;
        int a = list1->val;
        int b = list2->val;
        ListNode* head=NULL;
        ListNode* tail = NULL;
        if(a<=b)
        {
            head = tail = list1;
            list1 = list1->next;
        }
        else
        {
            head = tail = list2;
            list2 = list2->next;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1!=NULL&&temp2!=NULL)
        {
            int a = temp1->val;
            int b = temp2->val;
            if(a<=b)
            {
                tail->next = temp1;
                tail = temp1;
                temp1 = temp1->next;
                
            }
            else
            {
                tail->next = temp2;
                tail = temp2;
                temp2 = temp2->next;
                
            }
        }
        if(temp1==NULL)
            tail->next = temp2;
        else 
            tail->next = temp1;
        return head;
        
    }
};