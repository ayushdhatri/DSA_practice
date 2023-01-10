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
    
    int pairSum(ListNode* head) {
        int ans = INT_MIN;
        vector<int>nodes;
        ListNode* temp = head;
        int len =0;
        while(temp!=NULL)
        {
            len++;
            nodes.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        int j=nodes.size()-1;
        while(i<j)
        {
            int sum = nodes[i]+nodes[j];
            ans = max(ans, sum);
            i++;
            j--;
        }
       return ans;
        
    }
};