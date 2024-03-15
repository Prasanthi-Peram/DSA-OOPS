#include <bits/stdc++.h>
using namespace std;

//Hierachial Storage of data
/*1.Maximum nodes at level l=2^l
2.maximum nodes in a tree of height H is 2^H-1
3.For N nodes, minimum possible height or minimum number of levels are log2(N+1)
4. A binary tree with with L leaves has at least log2(N+1)+1 number of levels*/

struct Node{//Difference between class and structures
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right =new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    /*  1
       2 3
      4 5
    */
    return 0;
}

/*Traversal of a binary tree: 
1.Preorder traversal (Root->Left subtree->Right subtree)
2. Inorder traversal: Left subtree, Root, Right Subtree

*/