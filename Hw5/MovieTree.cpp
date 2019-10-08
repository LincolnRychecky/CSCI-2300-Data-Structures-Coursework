#include <iostream>
#include "MovieTree.hpp"
using namespace std;

MovieTree::MovieTree(){
    root = NULL;
}

void MovieTree::destroyNode(MovieNode*currNode){
    
     if(currNode!=NULL)
     {
         destroyNode(currNode->leftChild);
         destroyNode(currNode->rightChild);
         delete currNode;
         currNode = NULL;
     }
}

MovieTree::~MovieTree(){
    destroyNode(root);
}


void MovieTree:: printTreeHelper(MovieNode* curNode)
{
    if(curNode)
    {
           printTreeHelper( curNode -> leftChild);
           cout << "Movie: " << curNode->title << " " << curNode->quantity << endl;
           printTreeHelper( curNode->rightChild);
    }
}

void MovieTree::printMovieInventory()
{
    printTreeHelper(root);
}

MovieNode* MovieTree:: addNodeHelper(MovieNode* currNode,int ranking, string title, int releaseYear, int quantity)
{
    if(currNode == NULL){
        MovieNode* newNode = new MovieNode;
        newNode->ranking = ranking;
        newNode->title = title;
        newNode->year = releaseYear;
        newNode->quantity = quantity;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
    else if((currNode -> title).compare(title) < 0){
        currNode->rightChild = addNodeHelper(currNode->rightChild,ranking, title, releaseYear,quantity);
    }
    else if((currNode -> title).compare(title) > 0){
        currNode->leftChild = addNodeHelper(currNode->leftChild,ranking, title, releaseYear,quantity);
    }
    
    return currNode;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
    
    if(root == NULL){
        MovieNode* newNode = new MovieNode;
        newNode->ranking = ranking;
        newNode->title = title;
        newNode->year = releaseYear;
        newNode->quantity = quantity;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        root = newNode;
        return;
    }
    
    addNodeHelper(root, ranking, title, releaseYear, quantity);
    
}

MovieNode* MovieTree::searchHelper(MovieNode *node, string title){
    
    // Base Cases: root is null or key is present at root 
    if (node == NULL || node->title == title) 
       return node; 
     
    // Key is greater than root's key 
    if ((node->title).compare(title) < 0){ 
       return searchHelper(node->rightChild, title); 
    }
    // Key is smaller than root's key 
    return searchHelper(node->leftChild, title); 
}

void MovieTree::rentMovie(string title){
    //if tree is empty
    if(root == NULL){
        cout << "Movie not found." << endl;
        return;
    }
    if((searchHelper(root, title) == NULL)){
        cout << "Movie not found." << endl;
        return;
    }
    //if movie is quantity 0
    if((searchHelper(root, title) -> quantity) == 0){
        cout << "Movie out of stock." << endl;
        return;
    }
    cout << "Movie has been rented." << endl;
    //update quantity after rental
    (searchHelper(root, title) -> quantity) = (searchHelper(root, title) -> quantity) - 1;
    
    if((searchHelper(root, title) -> quantity) == 0){
        cout << "Movie " << "'" << searchHelper(root, title) -> title << "'" << " Info:" << endl;
    cout << "================================" << endl;
    cout  << "Ranking : " << searchHelper(root, title) -> ranking << endl;
    cout <<  "Title   : " << searchHelper(root, title) -> title << endl;
    cout << "Year    : " << searchHelper(root, title) -> year << endl;
    cout << "Quantity: " << searchHelper(root, title) -> quantity << endl;
        deleteMovie(searchHelper(root, title) -> title);
    }else{
    
    cout << "Movie " << "'" << searchHelper(root, title) -> title << "'" << " Info:" << endl;
    cout << "================================" << endl;
    cout  << "Ranking : " << searchHelper(root, title) -> ranking << endl;
    cout <<  "Title   : " << searchHelper(root, title) -> title << endl;
    cout << "Year    : " << searchHelper(root, title) -> year << endl;
    cout << "Quantity: " << searchHelper(root, title) -> quantity << endl;
    }
}

void MovieTree::findMovie(std::string title){
    
    if(searchHelper(root, title) == NULL){
        cout << "Movie not found." << endl;
        return;
    }
    
    cout << "Movie " << "'"<< searchHelper(root, title)->title <<"' Info:"<< endl;
	cout << "================================" << endl;
	cout << "Ranking : " << searchHelper(root, title)->ranking << endl;
	cout << "Title   : " << searchHelper(root, title)->title << endl;
	cout << "Year    : " << searchHelper(root, title)->year << endl;
	cout << "Quantity: " << searchHelper(root, title)->quantity << endl;
    return;
    
}

int MovieTree::countMovieHelper(MovieNode *node, int& count){
    
   if(node != NULL)//if we are not at a leaf
    {
        count++;
        countMovieHelper(node->leftChild, count);//recurisvly call the function and increment the count
        countMovieHelper(node->rightChild, count);
    }

    return count;//return the count       
    
}

void MovieTree::countMovies(){
    int count = 0;
    countMovieHelper(root, count);
    cout << "Count = " << count << endl; 

}

MovieNode* MovieTree::getMinValueHelper(MovieNode* curNode){
    
    if(curNode == NULL){
        return curNode;
    }
    if(curNode->leftChild == NULL)
        return curNode;
        
    return getMinValueHelper(curNode->leftChild);
    
}

MovieNode* MovieTree::deleteMovieHelper(MovieNode* curNode, string title)
{
    //search key in tree
    if(curNode == NULL){
        cout <<  "Movie not found." << endl;
        return NULL;
    }
    else if((curNode -> title).compare(title) > 0){
        curNode -> leftChild = deleteMovieHelper(curNode->leftChild, title);
    }
    else if((curNode -> title).compare(title) < 0){
        curNode -> rightChild = deleteMovieHelper(curNode->rightChild, title);
    }
    else{
        //No children 
        if(curNode->leftChild == NULL && curNode->rightChild == NULL){
            delete curNode;
            curNode = NULL;
        }
        //check for only right subtree
        else if(curNode -> leftChild == NULL){
            MovieNode* temp = curNode -> rightChild;
            delete curNode;
            curNode = temp;
        }
        //check  for only left subtree
        else if(curNode -> rightChild == NULL){
            MovieNode* temp = curNode -> leftChild;
            delete curNode;
            curNode = temp;
        }
        else{
        //if both left and right subtree exist
        //replace deleted node with min value in right subtree
        
        MovieNode* minValue = getMinValueHelper(curNode -> rightChild); //int minval = getMinValue(curNode-> right);
        curNode -> title = minValue -> title;
        curNode -> quantity = minValue -> quantity;
        curNode -> rightChild = deleteMovieHelper(curNode-> rightChild, minValue -> title); //curNode-> right = deleteNodeHelper(curNode-> right, minValue);
        }
    }
    return curNode;
}

void MovieTree::deleteMovie(string title){
    
    if(root == NULL){
         cout<< "Movie not found." << endl;
         return;
     }
     
     root = deleteMovieHelper(root, title);
    
}