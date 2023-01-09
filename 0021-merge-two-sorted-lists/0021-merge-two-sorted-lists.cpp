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
        if(list2 == NULL)
            return list1;
        ListNode* temp = list1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = list2;
        vector<int>ml;
        temp = list1;
        while(temp!=NULL)
        {
            ml.push_back(temp->val);
            temp = temp->next;
        }
        sort(ml.begin(), ml.end());
        temp = list1;
        for(int i = 0;i<ml.size();i++)
        {
            temp->val = ml[i];
            temp = temp->next;
        }
        return list1;
        
    }
};