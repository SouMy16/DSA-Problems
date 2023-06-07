//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*, Node*> m;
    unordered_map<Node*, int> vis;
    void helper(Node* root, Node* par)
    {
        if(root==NULL) return;
        m[root] = par;
        // if(root->data == target) cur = root;
        if(root->left!=NULL) helper(root->left, root);
        if(root->right!=NULL) helper(root->right, root);
        return;
    }
    void findTarget(Node* cur, Node* &p, int target)
    {
        if(!cur) return;
        if(cur->data == target)
        {
            p = cur;
            return;
        }
        if(cur->right) findTarget(cur->right, p, target);
        if(cur->left) findTarget(cur->left, p, target);
        return;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        helper(root, NULL);
        Node* cur = root;
        findTarget(root, cur, target);
        // cout<<cur->data<<'\n';
        queue<Node*> q;
        int d = -1;
        if(cur) q.push(cur);
        while(!q.empty())
        {
            d++;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                Node* c = q.front();
                q.pop();
                vis[c] = 1;
                if(c->left!=NULL && vis[c->left]!=1) q.push(c->left);
                if(c->right!=NULL && vis[c->right]!=1) q.push(c->right);
                if(m[c]!=NULL && vis[m[c]]!=1) q.push(m[c]);
            }
        }
        return d;
    }
    
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends