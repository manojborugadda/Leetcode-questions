#include<bits/stdc++.h>  ///Mirror image of a binary tree is also called as Inversion of a binary tree
#include<queue>
using namespace std;
 struct Node{
    int data;
    struct Node *left;
     struct Node *right;
};

Node* addNode(int data)  ///function to create a new tree node
{
    Node*temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inverse(Node *curr)
{
    if(!curr)              /// checking root node is empty or not
        return;
    inverse(curr->left);  /// here we use PreOrder traversal
    inverse(curr->right);

    Node *temp1 = curr->left;         /// swapping left and right nodes
    curr->left = curr->right;
    curr->right = temp1;

}
Node *mirrorView(Node *root)    /// MirrorView Function
{
    inverse(root);
    return root;
}

void preorder(Node *root)      ///preorder traversal function
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}


int main()
{
    Node* root = addNode(10);
	root->left = addNode(2);
	root->right = addNode(3);
	root->left->left = addNode(7);
	root->left->right = addNode(8);
	root->right->right = addNode(15);
	root->right->left = addNode(12);
	root->right->right->left = addNode(14);
    preorder(root);
    cout<<"\n";
	mirrorView(root);
	cout<<endl;
	preorder(root);
	return 0;
}
