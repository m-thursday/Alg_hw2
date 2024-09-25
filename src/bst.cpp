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
   return find_help(key, value, this->root);
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
    return this->root = insert_help(key, value, this->root);
}

/*
 * Binary Search Tree Remove
*/


BSTNode* BST::remove(int key, int value) {
    
    return remove_help(key, value, this -> root);
        
}



/*
 * Binary Search Tree sum of all values
*/
int BST::sumValue() {
    return sum_helper(this->root);
}

int BST::sum_helper(BSTNode *node){

	if (node){
	
		return node->value + sum_helper(node->left) + sum_helper(node->right);
	
	}
	
	
	return 0;

}

void BST::deconstruct_helper(BSTNode *node) {

	if (node) {
		
		deconstruct_helper(node -> left);
		deconstruct_helper(node -> right);
		
		node = NULL;	
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
	
		return find_help(key, value, node->left);
	
	}
	else{
	
		return find_help(key,value,node->right);
	
	}

}

BSTNode* BST::insert_help(int key, int value, BSTNode *node){

	if (node == NULL){
	
		node = new BSTNode(key, 0, value, NULL, NULL);
		return node;
	}
	
	if ((key < node -> key) || ((key == node->key) && (value < node-> value))){
	
		node -> left = insert_help(key, value, node -> left);
	}
	else{
		
		node -> right = insert_help(key, value, node -> right);
	}
	
	return node;

}

BSTNode* BST::remove_help(int key, int value, BSTNode *node){

	if(node -> key == key && node -> value == value){
		if ((node -> left == NULL) && (node -> right == NULL)){
			delete node;
			return NULL;
		}
		else if ((node -> left != NULL) && (node -> right == NULL)){
			BSTNode* holder = node -> left;
			delete node;
			return holder;
		}
		else if ((node -> right != NULL) && (node -> left == NULL)){
			BSTNode* holder = node -> right;
			delete node;
			return holder;
		}
		else if((node -> left != NULL) && (node -> right != NULL)){
			BSTNode* maxLeft = node -> left;
			while (maxLeft -> right != NULL){
				maxLeft = maxLeft -> right;
			}
			node -> key = maxLeft -> key;
			node -> value = maxLeft -> value;
			node -> left = remove_help(maxLeft -> key, maxLeft -> value, node -> left);
		}
	}
	else if((key < node -> key) || ((key == node -> key) && (value < node -> value))){
		node -> left = remove_help(key, value, node -> left);	
	}
	else{
		node -> right = remove_help(key,value,node->right);
	}
	
	return node;

}



