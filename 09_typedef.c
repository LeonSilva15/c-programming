#include <stdio.h>

struct Person {
    char name[ 20 ];
    int age;
};

// typedef creates a new type definition, working like an alias
typedef struct Person Person;

// We can create a shortcut as bellow:
typedef struct Animal {
    int legs;
} Animal;

int main () {
    Person leon = {
        "Leon S.",
        26
    };

    printf( "%s, %i\n", leon.name, leon.age );

    Animal dog = {
        4
    };

    printf( "A dog has %i legs\n", dog.legs );

    return 0;
}