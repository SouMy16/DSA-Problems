//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    void populatePar(Node* root, map<Node*, Node*> &m) {
        if(!root) return;
        if(root->left) {
            m[root->left] = root;
            populatePar(root->left, m);
        }
        if(root->right) {
            m[root->right] = root;
            populatePar(root->right, m);
        }
        return;
    }
    
    Node* find(int target, Node* root) {
        if(!root) return NULL;
        if(root->data == target) return root;
        Node* ll = find(target, root->left);
        Node* rr = find(target, root->right);
        if(ll) return ll;
        return rr;
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;
        map<Node*, Node*> par;
        map<Node*, int> vis;
        populatePar(root, par);
        par[root] = NULL;
        queue<pair<Node*, int>> q;
        Node* cur = find(target, root);
        q.push({cur, 0});
        while(!q.empty()) {
            Node* cur = q.front().first;
            int dis = q.front().second;
            q.pop();
            vis[cur] = 1;
            
            if(dis == k) {
                ans.push_back(cur->data);
            }
            
            // par
            if(par[cur] && !vis[par[cur]]) {
                vis[par[cur]] = 1;
                q.push({par[cur], dis+1});
            }
            // left
            if(cur->left && !vis[cur->left]) {
                vis[cur->left] = 1;
                q.push({cur->left, dis+1});
            }
            // right
            if(cur->right && !vis[cur->right]) {
                vis[cur->right] = 1;
                q.push({cur->right, dis+1});
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends