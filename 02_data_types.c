#include <stdio.h>

int main() {
    // puts: put string
    puts("Data Types:");
    puts("name      - bytes - specifier");
    puts("void      |   0   | NULL");
    puts("char      |   1   | \%c");
    puts("int       | 4 / 2 | \%d, \%i");
    puts("float     |   4   | \%f");
    puts("double    |   8   | \%lf");

    puts("Modifiers:");
    puts("name      -   size    - description");
    puts("short     |   half    | assigns the minum memory to int");
    puts("long      |   double  | doubles the memory size");
    puts("long long | cuadruple | quadruples the memory size");
    puts("unsigned  |   same    | removes space for the '-' only positives allowed");
    puts("signed    |   same    | allows '-' both positive and negatives allowed");

    /*
     * References:
     * https://byjus.com/gate/data-types-in-c/#:~:text=Types%20of%20Data%20Types%20in%20C,-Here%20are%20the&text=Floating%2Dpoint%2C%20integer%2C%20double%2C%20character.&text=Union%2C%20structure%2C%20array%2C%20etc.&text=The%20basic%20data%20types%20are,data%20types%20in%20C%20programming.
     * https://www.programiz.com/c-programming/c-data-types
     */
    return 0;
}
