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
    
    ListNode* kthfrombeg(ListNode*head, int k)
    {
        ListNode* temp = head;
        int pos = 1;
        while(pos!=k)
        {
            temp = temp->next;
            pos++;
        }
        return temp;
    } 
    ListNode* kthfromend(ListNode* head, int k)
    {
        ListNode* ptr1 = kthfrombeg(head, k);
        ListNode* ptr2 = head;
        while(ptr1->next!=NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr2;
        
        
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next == NULL)
            return head;
        ListNode* beg = kthfrombeg(head, k);
        ListNode* end = kthfromend(head, k);
        swap(beg->val, end->val);
        return head;
        
        
        
    }
};