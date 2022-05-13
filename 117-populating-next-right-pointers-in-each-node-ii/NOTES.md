Node* connect(Node* root) {
if(root == NULL)
return NULL;
queue<Node*> q;
q.push(root);
while(!q.empty()){
int n=q.size();
Node*prev=NULL;
for(int i=0;i<n;i++){
auto top=q.front();
q.pop();
top->next=prev;
prev=top;
if(top->right)
q.push(top->right);
if(top->left)
q.push(top->left);
}
}
return root;
}