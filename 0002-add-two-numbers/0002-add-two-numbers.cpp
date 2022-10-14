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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry=0;
        ListNode* head=NULL;ListNode* curr = head;
        bool flag = true;
        while(curr1!=NULL&&curr2!=NULL)
        {
            int data = (curr1->val+curr2->val+carry);
            ListNode* newnode = new ListNode(data%10);
            if(data>9)
                carry=1;
            else
                carry=0;
            if(flag)
            {
                head=newnode;
                curr=newnode;
                flag=false;
            }
            else
            {
                curr->next = newnode;
                curr=newnode;
            }
            curr1= curr1->next;
            curr2=curr2->next;
            
            
        }
        while(curr1!=NULL)
        {
            int data= curr1->val+carry;
            ListNode* newnode = new ListNode(data%10);
            if(data>9)
                carry=1;
            else
                carry=0;
            curr->next=newnode;
            curr=newnode;
            curr1= curr1->next;
        }
        while(curr2!=NULL)
        {
            int data= curr2->val+carry;
            ListNode* newnode = new ListNode(data%10);
            if(data>9)
                carry=1;
            else
                carry=0;
            curr->next=newnode;
            curr=newnode;
            curr2=curr2->next;
        }
        if(carry==1)
        {
            curr->next = new ListNode(1);
            curr = curr->next;
        }
        
        return head;
        
        
    }
};