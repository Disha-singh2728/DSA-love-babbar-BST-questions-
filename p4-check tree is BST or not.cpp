//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
class Solution
{
    public:
    void func(Node* root,Node* &prev,int&f){
    if(!root) return;
    // inorder traversal of tree is done
    // we know inorder traversal of tree gives nodes in sorted ascending order
    //hence we always check at each node its prev node is smaller tha current
    // if its current node smaller than previous i.e its not following bst property
    //so we make flag =0
    func(root->left,prev,f);
    if(prev!=NULL && root->data<=prev->data)
    {
     f=0;
     return;
    }
    prev=root; // if current root satisfies bst property increment prev to current
    func(root->right,prev,f);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
     Node* prev=NULL;
     int f=1; // intially take a flag =1 i.e tree is bst
     func(root,prev,f);
     return f;
     
    }
};
