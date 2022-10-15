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
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        if(list1==NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        vector<int>arr;
        while(curr1!=NULL&&curr2!=NULL)
        {
            int d1 = curr1->val;
            int d2 = curr2->val;
            if(d1<d2)
            {
                arr.push_back(d1);
                curr1 = curr1->next;
                
            }
            else if(d1==d2)
            {
                arr.push_back(d1);
                arr.push_back(d1);
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            else
            {
                arr.push_back(d2);
                curr2 = curr2->next;
             }
                
        }
        while(curr1!=NULL)
        {
            arr.push_back(curr1->val);
            curr1 = curr1->next;
        }
        while(curr2!=NULL)
        {
            arr.push_back(curr2->val);
            curr2 = curr2->next;
        }
        ListNode* head=NULL;
       
        ListNode* newnode = new ListNode(arr[0]);
        head = newnode;
        ListNode* curr = newnode;
        for(int i=1;i<arr.size();i++)
        {
            ListNode* newnode = new ListNode(arr[i]);
            curr->next = newnode;
            curr = newnode;
            
        }
        return head;
        
        
        
     
        
    }
};