#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode( int value );
Node* insertLeft( Node* root, int value );
Node* insertRight( Node* root, int value );
void inOrder( Node* root );
void preOrder( Node* root );
void postOrder( Node* root );

int main() {
    // Root node
    Node* root = createNode( 4 );

    // To the left
    insertLeft( root, 2 );
    insertLeft( root->left, 1 );
    insertRight( root->left, 3 );

    // To the right
    insertRight( root, 6 );
    insertLeft( root->right, 5 );
    insertRight( root->right, 7 );

    // Print
    printf( "\nIn-Order:  " );
    inOrder( root );

    printf( "\nPre-Order: " );
    preOrder( root );

    printf( "\nPost-Order:" );
    postOrder( root );

    printf( "\n\n" );
}

// Create node
Node* createNode( int value ) {
    Node* newNode = malloc( sizeof( Node ) );
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert node to the left
Node* insertLeft( Node* root, int value ) {
    root->left = createNode( value );

    return root->left;
}

// Insert node to the right
Node* insertRight( Node* root, int value ) {
    root->right = createNode( value );

    return root->right;
}

/*
 * Print in-order
 * Left - Root - Right
 */
void inOrder( Node* root ) {
    // Navigate to the left until finding NULL
    if( root == NULL ) {
        return;
    }
    inOrder( root->left );
    // Print the value when there's no more nodes to the left
    printf( " %i ", root->value );
    // Navigate to the right
    inOrder( root->right );
}

/*
 * Print pre-order
 * Root - Left - Right
 */
void preOrder( Node* root ) {
    if( root == NULL ) {
        return;
    }
    // Navigate to the left printing first
    printf( " %i ", root->value );
    preOrder( root->left );
    // After reaching left bottom navigate to the right
    preOrder( root->right );
}

/*
 * Print post-order
 * Left - Rigth - Root
 */
void postOrder( Node* root ) {
    if( root == NULL ) {
        return;
    }
    // Reach the bottom and print children nodes first
    postOrder( root->left );
    postOrder( root->right );
    printf( " %i ", root->value );
}
