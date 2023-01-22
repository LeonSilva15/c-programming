// keywords starting with # are called directives, these are used to preprocess the text before compiling
// https://www.ibm.com/docs/en/zos/2.4.0?topic=reference-preprocessor-directives
#include <stdio.h>
#include <string.h>

// We can define constants using the directive #define
#define PI 3.1416

// We can also define constants using the keyword const
const int MY_NUM = 4;

int main() {
    printf( "%f, %i\n", PI, MY_NUM );

    return 0;
}
