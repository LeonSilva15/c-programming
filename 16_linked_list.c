#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int main() {
    Node* first;
    Node* second;

    first = (Node*) malloc( sizeof( Node ) );
    second = (Node*) malloc( sizeof( Node ) );

    first->value = 2;
    second->value = 4;
    first->next = second;

    printf( "%i\n", first->value );
    printf( "%i\n", first->next->value );

    return 0;
}
