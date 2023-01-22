#include <stdio.h>
/*
 * Pointers in C are used to store/point the address of a variable in memory
 * the & symbol refers to the address
 * the * symbol refers to the value in that addess
 * so, we are using the pointer to store any value, could even be the addess of another variable
 */

int main() {
    // *ptr is our pointer which will point to an int variable address
    // q is our int value
    int *ptr, q = 50;

    // Assign the q variable value address to the pointer value
    ptr = &q;

    // Print the q value using its address
    printf( "Access 'q' using the address stored in 'ptr' pointer: %i\n", *ptr );
    printf( "Actual 'q' memory address: %li\n", ptr );

    return 0;
}
