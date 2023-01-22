#include <stdio.h>
#include <string.h>

int main() {
    int arr1[ 3 ] = { 1, 2, 3 };

    // Get the size of the array by dividing the total size in memory by the size of each space in i
    // It is better if explicitly cast the result of sizeof to int
    int arrSize = (int) sizeof( arr1 ) / (int) sizeof( arr1[ 0 ] );

    for( int i = 0; i < arrSize; i++ ) {
        printf( "%i", arr1[ i ] );
    }

    puts( "" );

    char str[ 10 ] = "abcdefg";
    for( int i = 0; i < strlen( str ); i++ ) {
        printf( "%c", str[ i ] );
    }
    puts( "" );

    return 0;
}
