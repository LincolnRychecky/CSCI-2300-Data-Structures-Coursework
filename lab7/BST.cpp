#include <iostream>
#include "BST.hpp"
using namespace std;

/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}

 /**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy. POSTORDER. or right-left-root
 **/

void BST:: destroyNode(Node *currNode)
{
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);
         delete currNode;
         currNode = NULL;
     }
 }

//--------------------------------------------INSERT NODE IN THE TREE--------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
NOTE: root is a private member of BST. Hence addNode function can not diretly access it.
      So we need this helper function. Implement your code for inserting a node in this function.
**/

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    
    else if(currNode -> key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode -> key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    
    return currNode;
}

 /**
 This function will insert the data in the tree. As this function can not access the rooted
 it will call the addNodeHelper function.
 **/

void BST:: addNode( int data)
{
    addNodeHelper(root,data);
}

//--------------------------------------------GET NUMBER OF NODES-------------------------------------------

int BST::getSizeHelper(Node* currNode)
{
    if(currNode == NULL){
        return 0;
    }
    int left_subtree = getSizeHelper(currNode -> left);
    int right_subtree = getSizeHelper(currNode -> right);
    return left_subtree + right_subtree + 1;
    
}

int BST::getSize()
{
    return getSizeHelper(root);
}
//-------------------------------------------GET MINIMUM VALUE FROM THE TREE---------------------------------

/**
Find the minimum in the subtree rooted ar currNode
Go to the left most node of this subtree.
**/

int BST::getMinValueHelper(Node* currNode)
{
    
    //iterative
    /*
    Node* temp = currNode;
    while(temp != NULL){
        temp = temp-> left;
    }
    return temp -> key;
    */
    //recursive
    if(currNode -> left != NULL){
        return currNode -> key;
    }
    return getMinValueHelper(currNode -> left);
    
}

int BST::getMinValue()
{
    if(root == NULL){
        cout << "Tree empty" << endl;
        return -1;
    }
    
return getMinValueHelper(root);

}

//--------------------------------------------GET MAXIMUM DEPTH OF THE TREE----------------------------------

int BST::getMaxDepthHelper(Node* currNode)
{
    //if tree is empty
    if(currNode == NULL){
        return -1;
    }
    
    int depth_left_subtree = getMaxDepthHelper(currNode -> left);
    int depth_right_subtree = getMaxDepthHelper(currNode -> right);
    if(depth_left_subtree > depth_right_subtree){
        return depth_left_subtree + 1;
    }
    else{
        return depth_right_subtree + 1;
    }
    
}

int BST::getMaxDepth()
{
    int depth = getMaxDepthHelper(root);
    if(depth == -1){
        cout << "Tree is empty" << endl;
    }
    return depth;
}

//--------------------------------------------PRINT THE TREE----------------------------------
void BST:: printTreeHelper(Node* curNode)
{
    if(curNode)
    {
           printTreeHelper( curNode->left);
           cout << " "<< curNode->key;
           printTreeHelper( curNode->right);
    }
}
void BST:: printTree(){
    printTreeHelper(root);
    cout<<endl;
}
