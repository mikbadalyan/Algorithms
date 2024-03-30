#include<stdio.h>
#include<stdlib.h>

// We define the structure for a binary tree node.
struct Node
{
	int value;
	struct Node *left, *right;
};

/**
 * @brief This function to create a new node with the given value.
 * 
 * @param value is the value of the new node in the binary tree.
 * @return struct Node* is a pointer (tree). 
 */
struct Node *newNode(int value)
{
	struct Node * tree = (struct Node*)malloc(sizeof(struct Node));
	tree->value = value;
	tree->right = NULL;
	tree->left = NULL;
	return tree;
}

/**
 * @brief This function frees all allocated memory to prevent memory leak.
 *
 * @param root is the given binary search tree.
 * @return int The function returns 0 when all binary search tree nodes are
 * freed.
 */
int free_bt(struct Node *root) {
	// Base case: If root is NULL, return.
	if(root == NULL){
		return 0;
	}
	// Recursively free the left subtree.
	if (0 != root->left) {
		free_bt(root->left);
	}
	// Recursively free the right subtree.
	if (0 != root->right) {
		free_bt(root->right);
	}
	// Free the memory allocated for the current node.
	free(root);
	return 0;
}

/**
 * @brief Function to count the total number of nodes in the binary tree.
 * 
 * @param root is the given binary search tree.
 * @return int The function returns 0 when all nodes are counted.
 */
int countNodes(struct Node* root)
{
	if (root == NULL){
		return (0);
	}
	return (1 + countNodes(root->left) + countNodes(root->right));
}

/**
 * @brief Function to check if the binary tree is complete.
 * 
 * @param root is the given binary search tree.
 * @param index to check whether it is complete or not.
 * @param number_nodes the total number of nodes in the binary tree.
 * @return int returns 1 if the binary tree is complete.
 */
int isComplete (struct Node* root, int index, int number_nodes)
{
	// Base case: If root is NULL, it is complete
	if (root == NULL){
		return 1;
	}
	// If index exceeds the total number of nodes, tree is not complete
	if (index >= number_nodes){
		return 0;
	}
	// Recursively check left and right subtrees for completeness
	return (isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes));
}

void printTree(struct Node* root, int level) {
    // Base case: If root is NULL, it is printed
	if (root == NULL) {
        return;
    }
    // Print right child recursively
    printTree(root->right, level + 1);

    // Print indentation based on the level
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    // Print node data
    printf("%d\n", root->value);

    // Print left child recursively
    printTree(root->left, level + 1);
}

// Main function
int main()
{
	struct Node* root = NULL;
	
	// Construct the binary tree
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	
	
	// Count the total number of nodes in the tree
	int node_count = countNodes(root);
	int index = 0;

	// Check if the binary tree is complete
	if (1 == isComplete(root, index, node_count)){
		printf("The Binary Tree is complete\n");
		
	}
	else{
		printf("The Binary Tree is not complete\n");
	}
	// Print the binary tree
	printf("-------------------------------------\n");
	printTree(root, 0);
	printf("-------------------------------------");
	printf("\nThe root is %d\n", root->value);
	printf("\nNOTE!!!: The binary tree starts and branches out from left to right in this visualisation.\n");
	// Free memory allocated for the binary tree nodes
	free_bt(root);
	
	return 0;

}
