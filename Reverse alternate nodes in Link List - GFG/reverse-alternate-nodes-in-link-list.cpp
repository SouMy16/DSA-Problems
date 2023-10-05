//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev=NULL, *cur=head, *next=head->next;
        while(next) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    void rearrange(struct Node *odd)
    {
        //add code here
        if(!odd || !odd->next) return;
        Node* cur1 = odd;
        Node* head2 = odd->next;
        Node* cur2 = head2;
        while(cur1 && cur1->next) {
            if(cur1->next) {
                cur1->next = cur1->next->next;
                cur1 = cur1->next;
                if(cur2->next) {
                    cur2->next = cur2->next->next;
                    cur2 = cur2->next;
                }
            }
        }
        head2 = reverse(head2);
        cur1 = odd;
        while(cur1->next) cur1 = cur1->next;
        cur1->next = head2;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends