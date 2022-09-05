for better explanation watch https://www.youtube.com/watch?v=-fOTdKKGpqg
​
​
```
class Solution {
public:
void helper(Node* root, vector<int>& ans){
if(root == NULL)
return;
for(auto i:root ->children){
helper(i, ans);
}
ans.push_back(root ->val);
}
vector<int> postorder(Node* root) {
vector<int> ans;
helper(root, ans);
return ans;
}
};
```