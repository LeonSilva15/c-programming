// Exercise encrypt a word entered by the user
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Used for types validations

// Input validation constants
// https://stackoverflow.com/questions/8817098/how-validate-user-input-when-the-expected-value-is-of-type-int-and-the-entered-v
#define INPUT_DIGITS 1
#define OPTION_BUFFER_SIZE (INPUT_DIGITS) + 3 // Sign character, newline and end of string
char optionInput[ OPTION_BUFFER_SIZE ];

#define WORD_SIZE 20
#define WORD_BUFFER_SIZE (WORD_SIZE) + 2 // newline and end of string
char wordInput[ WORD_BUFFER_SIZE ];

// Encryption number used to modify the chars value
#define ENCRYPTION_DIGIT 5

typedef struct Option {
    char* description;
} Option;

Option options[] = {
    "Encrypt a word",
    "Decrypt a word",
    "Exit"
};
// Calculate the size of the options instead of just setting it to 3 so options can grow as needed refactoring only the options array
const int OPTIONS_SIZE = sizeof( options ) / sizeof( Option );
#define EXIT_OPTION OPTIONS_SIZE

void printMenu( void );
char* getValidInput( char* );
int getOption( void );
void encrypt( char* );
void decrypt( char* );

int main() {
    int option;

    do {
        printMenu();
        option = getOption();

        switch( option ) {
            case 1: // encrypt
                printf( "Word of maximum 20 characters: " );
                encrypt( getValidInput( wordInput ) );
                break;
            case 2: // decrypt
                printf( "Enter the word to be decrypted: " );
                decrypt( getValidInput( wordInput ) );
                break;
        }

    } while( option != EXIT_OPTION );

    return 0;
}

void printMenu() {
    Option *optionPtr;

    for( int i = 0; i < OPTIONS_SIZE; i++ ) {
        optionPtr = &options[ i ];
        printf( "%i) %s\n", (i + 1), optionPtr->description );
    }
}

char* getValidInput( char* input ) {
    if( !fgets( input, sizeof( input ), stdin ) ) {
            puts("Input error!");
            exit( -1 );
    } else if( !strchr( input, '\n' ) ) {
        // The input is longer than the buffer size we need to read the input until finding the enter or having an error
        while ( fgets( input, sizeof( input ), stdin ) && !strchr( input, '\n' ) );
        return "\0";
    }

    return input;
}

int getOption() {
    char* input = getValidInput( optionInput );

    int option = atoi( input );

    if( option > 0 && option <= OPTIONS_SIZE ) {
        return option;
    }

    puts( "Invalid input!" );
    return -1;
}

void encrypt( char* word ) {
    if( strcmp( word, "\0" ) != 0
        && strcmp( word, "\n" ) != 0
    ) {
        printf( "Encrypted word: \"" );

        for( int i = 0; i < strlen( word ); i++ ) {
            printf( "%c", word[ i ] + ENCRYPTION_DIGIT );
        }
        printf( "\"\n" );
    } else {
        puts( "Invalid input!" );
    }
}

void decrypt( char* word ) {
    if( strcmp( word, "\0" ) != 0
        && strcmp( word, "\n" ) != 0
    ) {
        printf( "Decrypted word: \"" );

        for( int i = 0; i < strlen( word ); i++ ) {
            printf( "%c", word[ i ] - ENCRYPTION_DIGIT );
        }
        printf( "\"\n" );
    } else {
        puts( "Invalid input!" );
    }
}
