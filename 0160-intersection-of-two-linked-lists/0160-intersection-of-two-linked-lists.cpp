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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>nodeadd;
        ListNode* temp = headA;
        while(temp!=NULL)
        {
            nodeadd.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp!=NULL)
        {
            if(nodeadd.find(temp)!=nodeadd.end())
                return temp;
            temp = temp->next;
        }
        return NULL;
        
        
    }
};