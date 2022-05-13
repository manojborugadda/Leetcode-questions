/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution { // this is using QUEUES,BFS 
//                  // TC:O(N) SC:O(N)
// public:
//     Node* connect(Node* root) {
//         if(root==NULL) return NULL;
//         queue<Node*>q;
//         q.push(root);
        
//         while(q.empty() == false){
            
//             int n = q.size();
            
//             Node* dummy = NULL;  //  Next_Right_ELEMENT
            
//             for(int i = 0;i<n;i++){
                
//                auto top = q.front();
//                 q.pop();
//                 top->next = dummy;
//                 dummy = top;
//                 // in this problem we have to PUSH first Right element and Left element
//                 if(top->right){
//                     q.push(top->right);
//                 }
//                 if(top->left){
//                     q.push(top->left);
//                 }
                
//             }
//         }
        
//         return root;
        
//     }
// };




///////////// Using Constant Space and O(N) time complexity

class Solution { 
                                    // TC:O(N) SC:O(1)
public:
    Node* connect(Node* root) {
        Node* ans = root;
            while(root != NULL)
            {
                Node *temp = new Node(-1);
                Node* curr = temp;
                
                while(root!=NULL){
                    
                 if(root->left!=NULL){
                     curr->next = root->left;
                     curr = curr->next;
                    }
                    
                    if(root->right!=NULL){
                        curr->next = root->right;
                        curr = curr->next;
                    }
                    
                    root = root->next;
                }
                
                root = temp->next;
            }    
        return ans;
        
        }
};






