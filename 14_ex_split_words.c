// Exercise spliting a sentence by words
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] ) {
    // Allocate the memory so the user can enter any size of sentence
    char *sentence = (char*) malloc( sizeof( char ) );

    printf( "Insert your sentence: " );
    // Store everything unless its a new line (Enter)
    scanf( "%[^\n]%*c", sentence );

    // Print the words char by char replacing the space with a new line
    for( int i = 0; i < strlen( sentence ); i++ ) {
        if( sentence[ i ] == ' ' ) {
            printf( "\n" );
        } else {
            printf( "%c", sentence[ i ] );
        }
    }
    printf( "\n" );

    return 0;
}
