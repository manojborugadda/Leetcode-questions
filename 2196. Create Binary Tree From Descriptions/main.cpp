/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {//SC:O(N) TC:O(N+N)
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>map;
        unordered_set<int>childset;//they can never be root of the tree
        for(auto description : descriptions) {//TC:O(N)
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];
            //if we dont find any PARENT NODE in the map, we will create that node
            if(!map.count(parent)) {//map.find(parent) == map.end()
                map[parent] = new TreeNode(parent);
            }
            if(!map.count(child)) {//if we dont find any child NODE in the map, we will create that node
                map[child] = new TreeNode(child);
            }

            if(isLeft == 1) {//we link the parent node with child node
                map[parent]->left = map[child];
            }else {
                map[parent]->right = map[child];
            }
            childset.insert(child);// inserting the child nodes into the SET
        }
        //TC:O(N)
        for(auto vec:descriptions) {//checking the parent node which not appear in the SET which consists of All child nodes. so that the node which is not present in the SET will become the ROOT
            if(!childset.count(vec[0])) {
                return map[vec[0]];
            }
        }
        return nullptr;
    }
};
