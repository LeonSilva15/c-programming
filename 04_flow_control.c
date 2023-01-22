#include <stdio.h>
#include <stdbool.h> // Required to use booleans

int main() {
    puts( "Conditionals:" );
    puts( "if, else and switch" );

    if( false ) {
        puts( "Entered if!" );
    } else if( 5 == 'd' ) {
        puts( "Entered else if!" );
    } else {
        puts( "Entered else!" );
    }

    /*
     * Switch can only evaluate char and int values
     */
    switch( 'd' ) {
        case 1:
        case 2:
        case 3:
            puts( "Number between 1 and 3!" );
            break;
        case 'a':
        case 'b':
        case 'c':
            puts( "Letter between a and c!" );
            break;
        case 'd':
            puts( "It's a d!" );
        default:
            puts( "Default case enter beacuse case 'd' didn't have a break sentence" );
            break; // break isn't required but can be added
    }

    return 0;
}