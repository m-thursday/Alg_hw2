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
    // YOUR CODE HERE
}


/*
 * Binary Search Tree Pop Maximum and Minimum  
*/

BSTNode* BST::popMaximum() {
    // YOUR CODE HERE
}

BSTNode* BST::popMinimum() {
    // YOUR CODE HERE
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

void BST::sum_helper(BSTNode *node){

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
