#include<bits/stdc++.h>

using namespace std;

struct BST
{
    int data;
    BST *left;
    BST *right;
};

BST* insert(BST *root, int n)
{
    BST *node=new BST();
    node->data=n;
    node->left=NULL;
    node->right=NULL;

    if(!root)
        root=node;
    else if(n<root->data)
        root->left = insert(root->left, n);
    else
        root->right = insert(root->right, n);

    return root;
}

void postorder(BST *root)
{
    if(!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

int main()
{
    BST *root;
    root=NULL;
    int n;
    while(cin>>n)
        root = insert(root, n);
    postorder(root);
    return 0;
}