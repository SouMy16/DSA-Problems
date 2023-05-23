//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        if(size == 0) return NULL;
        Node* head = new Node(pre[0]);
        // head->data = pre[0];
        int lpost[size/2], lpre[size/2];
        for(int i=1; i<=size/2; i++)
        {
            lpre[i-1] = pre[i];
            // rpost[i-1] = preMirror[i];
        }
        for(int i=size/2+1; i<size; i++)
        {
            lpost[i-size/2-1] = pre[i];
            // rpre[i-size/2-1] = preMirror[i];
        }
        size /= 2;
        head->left = constructBinaryTree(lpre, preMirror, size);
        head->right = constructBinaryTree(lpost, preMirror, size);
        return head;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends