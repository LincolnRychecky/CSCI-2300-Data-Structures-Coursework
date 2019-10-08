#include <iostream>
#include "BST.hpp"
using namespace std;

void doSomething(Node* root, int *sum)
  {
      if (!root)
         return;
     if(root->left)
     {
         if(!root->right)
             *sum+= root->key;
         doSomething(root->left, sum);
     }
     if(root->right)
     {
         if(!root->left)
             *sum+= root->key;
         doSomething(root->right, sum);
     }
  }


int main (){
  BST tree(49);
  tree.addNode(26);
  tree.addNode(51);
  tree.addNode(15);
  tree.addNode(7);
  tree.addNode(19);
  tree.addNode(20);
cout << "hello1" << endl;
int sum1 = 0;

cout << tree.getRoot() -> key;

doSomething(tree.getRoot(), &sum1);
cout << sum1;
}
