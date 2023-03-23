//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    Node* findTarget(Node *root, int target, int &ans)
    {
        if(!root) return NULL;
        if(root->data == target) return root;
        ans += root->data;
        if(target < root->data) return findTarget(root->left, target, ans);
        return findTarget(root->right, target, ans);
    }

    int findMinSum(Node* root, int s)
    {
        if(!root) return 0;
        int ans = INT_MAX;
        if(root->left)
        {
            ans = min(ans, findMinSum(root->left, 0));
        }
        if(root->right)
        {
            ans = min(ans, findMinSum(root->right, 0));
        }
        if(ans == INT_MAX) return root->data;
        return ans+root->data;
    }

    int maxDifferenceBST(Node *root,int target){
        // Code here
        int ans = 0;
        Node* t = findTarget(root, target, ans);
        if(!t) return -1;
        ans -= findMinSum(t, 0);
        ans += t->data;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends