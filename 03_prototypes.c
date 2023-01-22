#include <stdio.h>

void sayHi( void );
int getSum( int num1, int );

int main() {
    sayHi();
    printf( "%i\n", getSum( 1, 2 ) );

    puts("Prototypes do the next:");
    puts("1. It tells the compiler a function exists");
    puts("2. It specifies the parameters the function will receive (type, name [optional and only informative] )");
    puts("3. It specifies what type of data will the function retrieve");

    return 0;
}

void sayHi() {
    puts("Hi!");

    return;
}

/*
 * No need on naming the parameters as the prototype
 * If no data type is specified, the function will take the defined value from prototype
 * when doing so, the program will throw a warning
 */
int getSum( int num, int num2 ) {
    return num + num2;
}
