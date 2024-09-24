#include <bst.hpp>
#include <stack.hpp>

BSTNode::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

BSTNode::BSTNode(int key, int height, int value, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->value = value;
    this->left = left;
    this->right = right;
}


BSTNode::~BSTNode() {
    this->left = this->right = NULL;
}

/*
 * Binary Search Tree Constructor
*/

BST::BST() {
    this->root = NULL;
}

/*
 * Binary Search Tree Deconstructor
*/

// YOUR CODE HERE

BST::~BST() {
    deconstruct_helper(this->root);
}



/*
 * Binary Search Tree Search
*/


BSTNode* BST::find(int key, int value) {
    find_help(key, value, this->root);
}


/*
 * Binary Search Tree Pop Maximum and Minimum  
*/

BSTNode* BST::popMaximum() {
    if (this -> root == NULL){
    	return NULL;
    }
    BSTNode *p = this -> root;
    BSTNode *q = NULL;
    
    bool done = false;
    
    while (!done){ 
    	if (p -> right != NULL){
    		q = p;
    		p = p -> right;
    	}
    	else{
    		done = true;
    	}
    }
   
    if (p == this -> root){
	   	this -> root = p -> left; 
    }
    else{
    	q -> right  = p -> left;
    }
    
    p -> left = p -> right = NULL;
    
    return p;
}

BSTNode* BST::popMinimum() {
	if (this -> root == NULL){
    	return NULL;
    }
    BSTNode *p = this -> root;
    BSTNode *q = NULL;
    
    bool done = false;
    
    while (!done){ 
    	if (p -> left != NULL){
    		q = p;
    		p = p -> left;
    	}
    	else{
    		done = true;
    	}
    }
   
    if (p == this -> root){
	   	this -> root = p -> right; 
    }
    else{
    	q -> left  = p -> right;
    }
    
    p -> left = p -> right = NULL;
    
    return p;
}

/*
 * Binary Search Tree Insert
*/


BSTNode* BST::insert(int key, int value) {
    // YOUR CODE HERE
}

/*
 * Binary Search Tree Remove
*/


BSTNode* BST::remove(int key, int value) {
    // YOUR CODE HERE
}


/*
 * Binary Search Tree sum of all values
*/
int BST::sumValue() {
    sum_helper(this->root);
}

int BST::sum_helper(BSTNode *node){

	if (node){
	
		return this->value + sum_helper(this->left) + sum_helper(this->right);
	
	}
	else{
		return 0;
	}

}

void BST::deconstruct_helper(BSTNode *node) {

	if (node) {
	
		deconstruct_helper(node -> left);
		deconstruct_helper(node -> right);
		delete node;
	
	}

}

BSTNode* BST::find_help(int key, int value, BSTNode *node){

	if (node == NULL){
		return (NULL);
	}
	if ((node -> key == key) && (node -> value == value)){
	
		return node;
	
	}
	if ((key < node -> key) || ((key == node -> key) && (value < node -> value))){
	
		return find_help(key, value, this->left);
	
	}
	else{
	
		return find_help(key,value,this->right);
	
	}

}

BSTNode* BST::insert_help(int key, int value, BSTNode *node){

	

}
BSTNode* BST::remove_help(int key, int value, BSTNode *node){

	

}



