#include <stdio.h>

int main() {
    puts("Loops:");
    puts("for, while and do-while");

    // int a; -- We can either define it in or out the for sentence
    for( int a = 0; a <= 3; a++ ) {
        printf( "%i", a );
    }
    puts( "" ); // New line
    // printf( "%i", a ); // Here a is undeclared

    int a = 3;
    while( a >= 0 ) {
        printf( "%i", a );
        --a;
    }
    puts( "" );

    do {
        puts( "Enters at least once" );
    } while( 0 ); // Evalutes to false: false, NULL, 0, \0 and EOF.

    // This is a valid infinte for:
    // for(;;);

    return 0;
}
