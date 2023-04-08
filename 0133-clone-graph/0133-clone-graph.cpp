/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(m.find(node) != m.end()) return m[node];
        Node *ans = new Node(node->val);
        m[node] = ans;
        for(int i=0; i<node->neighbors.size(); i++) 
            ans->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return ans;
    }
};