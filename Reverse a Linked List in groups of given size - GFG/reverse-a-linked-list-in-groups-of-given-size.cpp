//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    int countNodes(node* head){
        node* curr = head;
        int count = 0;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        return count;
        
    }
    struct node *reverse (struct node *head, int k)
    { 
        int totalnodes = countNodes(head);
        int times = totalnodes/k;
        
        node* prev_set_ele = head;
        bool first = true;
        node* curr = head;
        node* newhead = NULL;
        
        while(times--){
            
            int temp_count = k;
            node* prev = NULL;
            node* first_ele = curr;
            while(temp_count--){
                node* rem = curr->next;
                curr->next = prev;
                prev = curr;
                curr = rem;
            }
            if(first){
                newhead = prev;
                first = false;
            }
            else{
                prev_set_ele->next = prev;
                prev_set_ele = first_ele;
            }
        }
        
        node* prev = NULL;
        while(curr!=NULL){
           
            node* rem = curr->next;
            curr->next = prev;
            prev = curr;
            curr =rem;
        }
        prev_set_ele->next = prev;
        
        
        return newhead;
        
        
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends