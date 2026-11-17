/**
- Definition for singly-linked list.
- struct ListNode {
-     int val;
-     ListNode *next;
-     ListNode() : val(0), next(nullptr) {}
-     ListNode(int x) : val(x), next(nullptr) {}
-     ListNode(int x, ListNode *next) : val(x), next(next) {}
- };
 */
/**
- Definition for a binary tree node.
- struct TreeNode {
-     int val;
-     TreeNode *left;
-     TreeNode *right;
-     TreeNode() : val(0), left(nullptr), right(nullptr) {}
-     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
-     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
- };
 */
class Solution {
public:
ListNode* getMid(ListNode* head){
    int n = 0;
    ListNode* curr = head;
    while(curr != NULL){
        n+=1;
        curr = curr->next;
    }
    int midNode = n/2;
    curr = head;
    while(midNode--){
        curr = curr->next;
    }
    return curr;
}

pair<ListNode*, ListNode*> getMidAdj(ListNode* head){
    ListNode* prevToMid = head;
    ListNode* nextToMid = head;
    ListNode* curr = head;
    ListNode* midNode = getMid(head);
    nextToMid = midNode->next;
    while(curr->next != midNode){
        curr = curr->next;
    }
    return {curr, nextToMid};
}
TreeNode* getBST(ListNode* head){
    if(head == NULL)return NULL;
    if(head->next == NULL){
        TreeNode* leafNode = new TreeNode(head->val);
        return leafNode;
    }
    ListNode* midNode = getMid(head);
    pair<ListNode*, ListNode*> adjNodes = getMidAdj(head);
    ListNode* prevNodeToMid = adjNodes.first;
    ListNode* nextNodeToMid = adjNodes.second;
    TreeNode* rootNode = new TreeNode(midNode->val);

    prevNodeToMid ->next = NULL;// we break the chain
    TreeNode* leftSubTree = getBST(head);

    TreeNode* rightSubTree = getBST(midNode->next);
    midNode->next = NULL;// we break the chain

    rootNode->left = leftSubTree;
    rootNode->right = rightSubTree;
    return rootNode;
    

}
    TreeNode* sortedListToBST(ListNode* head) {
        return getBST(head);
        
    }
};