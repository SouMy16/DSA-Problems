//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<Node*> ans;
        map<char, int> m;
        for(int i=0; i<s.size(); i++) m[s[i]]++;
        Node* cur = head;
        while(cur)
        {
            if(m[cur->data] > 0)
            {
                map<char, int> mm;
                Node* ncur = cur;
                int f = 0;
                for(int i=0; i<s.size(); i++)
                {
                    if(!ncur)
                    {
                        f = 1;
                        break;
                    }
                    mm[ncur->data]++;
                    if(m[ncur->data] < mm[ncur->data])
                    {
                        f = 1;
                        break;
                    }
                    if(i!=s.size()-1) ncur = ncur->next;
                }
                if(f == 0){
                    ans.push_back(cur);
                    cur = ncur->next;
                    ncur->next = NULL;
                }
                else cur = cur->next;
            }
            else cur = cur->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends