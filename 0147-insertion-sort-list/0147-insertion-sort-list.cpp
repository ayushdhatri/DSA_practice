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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>ele;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            ele.push_back(temp->val);
            temp = temp->next;
        }
        sort(ele.begin(), ele.end());
        int i=0;
        temp = head;
        while(temp!=NULL)
        {
            temp->val = ele[i++];
            temp = temp->next;
        }
        return head;
        
        
    }
};