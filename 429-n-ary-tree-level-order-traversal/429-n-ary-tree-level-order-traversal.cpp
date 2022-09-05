/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {  //BFS traversal 
public: //TC = O(N), SC = O(N)
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<Node*>q;
        q.push(root);
        while(q.empty()==false) {
            int n = q.size();
            vector<int>vec;
            for(int i = 0;i<n;i++) {  //for each level we push the nodes into the temporary vector
                Node* temp  = q.front();
                q.pop();
                for(auto &it:temp->children) {
                    q.push(it);
                }
                vec.push_back(temp->val);
            }
            ans.push_back(vec);
        }
        return ans;
    }//just like BINARY LEVEL ORDER TRAVERSAL 
};