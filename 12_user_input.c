#include <stdio.h>

/*
 * We can use the arguments in the main function
 * by convention we use: int main( int argc, char* argv[] )
 * which contains in argc the number of parameters and the parameters values in *argv
 */
void main( int argc, char *argv[] ) {
    printf( "Number of parameters: %i\n", argc );

    // Print all the parameters received
    for( int count = 0; count < argc; count++ ) {
        puts( *( argv + count ) );
    }

    char str[ 20 ];
    // We can read input from the user using the scanf:
    printf( "Enter your name: " );
    scanf( "%s", &str  );
    puts( str  );

    // Get the last automatic \n or \0
    getchar();

    int a = getchar();
    putchar( a );
    putchar( '\n' );

    return;
}
