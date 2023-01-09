/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*>freq;
        Node* prev = NULL;
        bool firsttime = true;
        Node* newhead=NULL;
        while(temp!=NULL)
        {
            int data = temp->val;
            Node* newnode = new Node(data);
            freq[temp]= newnode;
            if(firsttime)
            {
                newhead = newnode;
                prev = newnode;
                firsttime = false;
            }
            else
            {
                prev->next = newnode;
                prev = newnode;
            }
            temp = temp->next;
        }
        temp = head;
        Node* temp2 = newhead;
        while(temp!=NULL&&temp2!=NULL)
        {
            Node* rp = temp->random;
            temp2->random = freq[rp];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return newhead;
        
    }
};