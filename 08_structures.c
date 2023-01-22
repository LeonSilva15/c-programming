#include <stdio.h>

struct Person {
    char name[ 10 ];
    int age;
};

int main() {
    struct Person p = {
        "Leon S.",
        26
    };

    printf( "%s, %i\n", p.name, p.age );

    return 0;
}