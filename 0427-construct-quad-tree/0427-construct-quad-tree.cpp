/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node *root;
        int x = grid[0][0];
        int f = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] != x)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
        {
            root = new Node(x,1);
        }
        else{
            root = new Node(0,0);
            int n = grid.size();
            vector<vector<int>> tl(n/2, vector<int>(n/2)), tr(n/2, vector<int>(n/2));
            vector<vector<int>> bl(n/2, vector<int>(n/2)), br(n/2, vector<int>(n/2));
            for(int i=0; i<n/2; i++)
            {
                for(int j=0; j<n/2; j++)
                {
                    tl[i][j] = grid[i][j];
                }
            }
            for(int i=0; i<n/2; i++)
            {
                for(int j=n/2; j<n; j++)
                {
                    tr[i][j-n/2] = grid[i][j]; 
                }
            }
            for(int i=n/2; i<n; i++)
            {
                for(int j=0; j<n/2; j++)
                {
                    bl[i-n/2][j] = grid[i][j];
                }
            }
            for(int i=n/2; i<n; i++)
            {
                for(int j=n/2; j<n; j++)
                {
                    br[i-n/2][j-n/2] = grid[i][j];
                }
            }
            root->topLeft = construct(tl);
            root->topRight = construct(tr);
            root->bottomLeft = construct(bl);
            root->bottomRight = construct(br);
        }
        return root;
    }
};