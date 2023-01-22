#include <stdio.h>
/*
 * Pointers in C are used to store/point the address of a variable in memory
 * the & symbol refers to the address
 * the * symbol refers to the value in that addess
 * so, we are using the pointer to store any value, could even be the addess of another variable
 */

// Function receiving a value as parameter
void modify( int n ) {
    n = 999; // Modify the received in that address
}

// Function receiving a reference (memory address) as parameter
void modify2( int *n ) {
    *n = 999; // Modify the value in that address
}

int main() {
    // *ptr is our pointer which will point to an int variable address
    // q is our int value
    int *ptr, q = 50;

    // Assign the q variable value address to the pointer value
    ptr = &q;

    // Print the q value using its address
    printf( "Access 'q' using the address stored in 'ptr' pointer: %i\n", *ptr );
    printf( "Actual 'q' memory address: %li\n", ptr );

    int n = 0;
    modify( n );
    printf( "Passed variable by value didn't modify the acutal value: %i\n", n );

    // When receiving an address as paramter, we need to send it sepecified with the & symbol
    modify2( &n );
    printf( "Passed variable by reference did modify the acutal value: %i\n", n );

    return 0;
}
