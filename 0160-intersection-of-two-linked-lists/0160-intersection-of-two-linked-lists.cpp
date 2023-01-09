/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int listsize(ListNode* head)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1= listsize(headA);
        int len2= listsize(headB);
        cout<<len1<<" "<<len2<<endl;
        if(len1>len2)
        {
            int d = len1-len2;
            int count=1;
            ListNode* temp = headA;
           for(int i =0;i<d;i++)
           {
               if(temp==NULL)
                   return NULL;
               temp = temp->next;
           }
            cout<<temp->val<<endl;
            ListNode* temp1 = headB;
            while(temp!=NULL&&temp1!=NULL)
            {
                if(temp==temp1)
                    return temp;
                temp = temp->next;
                temp1 = temp1->next;
            }
            return NULL;
        }
        else
        {
            int d = len2-len1;
            ListNode* temp = headB;
            int count = 1;
            for(int i =0;i<d;i++)
           {
               if(temp==NULL)
                   return NULL;
               temp = temp->next;
           }
            ListNode* temp1 = headA;
            while(temp1!=NULL&&temp!=NULL)
            {
                if(temp1==temp)
                    return temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
            return NULL;
        }
        return NULL;
        
        
        
        
    }
};