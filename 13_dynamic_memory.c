#include <stdio.h>
// Dynamic memory functions are located in stdlib.h
#include <stdlib.h>

/*
 * Dynamic memory allocation can be defined as a procedure where the memory of a data structure, like an array,
 * is modified during runtime.
 * We can find two main cases:
 *  1. An array created for 9 elements is using only 5 spaces and the other 4 are just being wasted
 *  2. An array created for 9 elements needs to store 5 more items
 */

int main() {
    int size;
    int *numsArr;
    /*
     * We have 4 memory methods:
     *  1. malloc - Memory allocation. Allocates a large block of memory.
     *  2. calloc - Contiguos allocation. Allocates a set of memory blocks.
     *  3. realloc - Re-allocation. Changes the memory allocation.
     *  4. free - De-allocation. Frees the allocated memory.
     */
    printf( "Number of elements: " );
    scanf( "%i", &size );

    numsArr = (int*) malloc( size * sizeof( int ) );

    for( int i = 0; i < size; i++ ) {
        numsArr[ i ] = i + 1;
    }

    for( int i = 0; i < size; i++ ) {
        printf( "%i\n", numsArr[ i ] );
    }

    printf( "New number of elements: " );
    scanf( "%i", &size );

    // Reallocate the memory
    numsArr = realloc( numsArr, size * sizeof( int ) );

    for( int i = 0; i < size; i++ ) {
        numsArr[ i ] = i + 1;
    }

    for( int i = 0; i < size; i++ ) {
        printf( "%i\n", numsArr[ i ] );
    }

    // Free the allocated memory
    free( numsArr );

    return 0;
}