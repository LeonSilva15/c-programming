#include <stdio.h>
#include <string.h>
/*
 * string.h includes the string functions
 * https://en.wikibooks.org/wiki/C_Programming/string.h/Function_reference
 */

int main() {
    // Multiples ways to create strings using char
    // We need to specify the end of string '\0'
    char name[] = { 'L', 'e', 'o', 'n', '\0' };
    puts( name );

    // No need to specify the end of string when specifying it is a string with the double quotes
    char name2[] = "Leon 2";
    puts( name2 );

    // We can specify the string length
    char name3[ 10 ] = "Leon 3";
    puts( name3 );

    // We can create a string using pointers
    char *name4 = "Leon 4";
    puts( name4 ); // prints: Leon 4
    // When defining a string using a pointer, it points to the first character of the string
    printf( "name4: %s\n", name4 );  // prints: Leon 4
    printf( "*name4: %c\n", *name4 ); // prints: L

    // We can access every char in a string
    // as array:
    printf( "name[ 1 ]: %c\n", name[ 1 ] );
    // as pointer: (the pointer always points to the start of the string)
    printf( "*( name ): %c\n", *( name ) );
    printf( "*( name + 1 ): %c\n", *( name + 1 ) );

    puts( "\nSome sring methods" );
    printf( "strlen( \"ABC\" ): %i\n", strlen( "ABC" ) );
    // strcat won't work using pointer, we need an array as first parameter
    char str1[] = "ABC";
    printf( "strcat( str1, \"def\" ): %s\n", strcat( str1, "def" ) );

    char str2[] = "ABC";
    printf( "strcpy( str2, \"def\" ): %s\n", strcpy( str1, "def" ) );

    // strcmp returns 0 if str1 is same as str2. Returns <0 if strl < str2. Returns >0 if str1 > str2
    printf( "strcmp( \"Def\", \"def\" ): %i\n", strcmp( "Def", "def" ) );
    printf( "strcmp( \"def\", \"Def\" ): %i\n", strcmp( "def", "Def" ) );
    printf( "strcmp( \"def\", \"def\" ): %i\n", strcmp( "def", "def" ) );
    printf( "strcmp( \"defghi\", \"def\" ): %i\n", strcmp( "defghi", "def" ) );
    printf( "strcmp( \"def\", \"defghi\" ): %i\n", strcmp( "def", "defghi" ) );
    printf( "strcmp( str2, \"def\" ): %i\n", strcmp( str2, "def" ) );

    return 0;
}
