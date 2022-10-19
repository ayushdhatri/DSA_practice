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
    bool approach1(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return true;
        string s="";
        ListNode* curr = head;
        while(curr!=NULL)
        {
            int data = curr->val;
            s+=to_string(data);
            curr = curr->next;
        }
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    bool isPalindrome(ListNode* head) {
        return approach1(head);
        
        
    }
};