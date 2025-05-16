#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
struct Node {
    int value; 
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = value;
    temp->left = NULL; 
    temp->right = NULL;
    return temp;
}

// Count how many nodes are in the tree
int getNodeCount(struct Node* root) {
    if (root == NULL) return 0;
    
    // Add 1 for the current node, then recurse for left and right
    return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}

// Compare three binary trees and print the one with the most nodes
void compareBinaryTree(struct Node* A, struct Node* B, struct Node* C) {

    int nodesA = getNodeCount(A);
    int nodesB = getNodeCount(B);
    int nodesC = getNodeCount(C);

    // Print the counts for each tree
    printf("Tree A has: %d nodes\n", nodesA);
    printf("Tree B has: %d nodes\n", nodesB);
    printf("Tree C has: %d nodes\n", nodesC);

    // Figure out which tree has the most nodes
    if (nodesA > nodesB && nodesA > nodesC) {
        printf("Tree A has the most nodes!\n");
    } else if (nodesB > nodesA && nodesB > nodesC) {
        printf("Tree B has the most nodes!\n");
    } else if (nodesC > nodesA && nodesC > nodesB) {
        printf("Tree C has the most nodes!\n");
    } else {
        printf("Some trees have equal nodes!\n");
    }
}

int main() {
	printf("Case 1:\n\n");
    // Building Tree A (4 nodes)
    struct Node* A = createNode(1);
    A->left = createNode(2);
    A->right = createNode(3);
    A->left->left = createNode(4);

    // Building Tree B (3 nodes)
    struct Node* B = createNode(10);
    B->left = createNode(20);
    B->right = createNode(30);

    // Building Tree C (6 nodes)
    struct Node* C = createNode(100);
    C->left = createNode(200);
    C->right = createNode(300);
    C->left->left = createNode(400);
    C->left->right = createNode(500); 
    C->right->left = createNode(600); 

	// call the comparison function 
    compareBinaryTree(A, B, C);

	printf("\n\nCase 2:\n\n");
    struct Node* A2 = createNode(1);
    // Building Tree A2 (1 nodes)
    
    // Building Tree B2 (5 nodes)
    struct Node* B2 = createNode(2);
    B2->left = createNode(3);
    B2->right = createNode(4);
    B2->right->left = createNode(5);
    B2->right->right = createNode(6);
    
	// Building Tree C2 (4 nodes)
    struct Node* C2 = createNode(7);
    C2->left = createNode(8);
    C2->right = createNode(9);
    C2->left->left = createNode(10);
   
	// call the comparison function
    compareBinaryTree(A2, B2, C2);

    return 0;
    
}
