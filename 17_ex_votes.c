#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Input validation constants
// https://stackoverflow.com/questions/8817098/how-validate-user-input-when-the-expected-value-is-of-type-int-and-the-entered-v
#define INPUT_DIGITS 1
#define OPTION_BUFFER_SIZE (INPUT_DIGITS) + 3 // Sign character, newline and end of string
char optionInput[ OPTION_BUFFER_SIZE ];

#define WORD_SIZE 25
#define WORD_BUFFER_SIZE (WORD_SIZE) + 2 // newline and end of string
char wordInput[ WORD_BUFFER_SIZE ];

// Candidate struct
typedef struct Candidate {
    char* name;
    struct Candidate* next;
    struct Candidate* prev;
} Candidate;

// District struct
typedef struct District {
    char* name;
    Candidate* candidates;
    struct District* next;
    struct District* prev;
} District;

char* DISTRICTS[] = {
    "A",
    "B",
    "C",
    "D"
};

// Menu list
const char* MENU[] = {
    "List all",
    "List candidates",
    "Add district",
    "Add candidate",
    "Exit"
};
const int MENU_SIZE = (int) sizeof( MENU ) / sizeof( MENU[ 0 ] ); // No need to refactor when modifying the menu
const int EXIT_OPTION = MENU_SIZE; // Exit will always be the last option

// Internal functions
void _printMenu( void );
char* _getValidInput( char* );
int _getOption( void );
void _setBasicDistricts( District* );
void _setDistrict( char*, District* );
void addDistrict( District* );
void addCandidate( District* );
void list( District* );
void listCandidates( District* );

int main() {
    int option;
    District* districts = (District*) malloc( sizeof( District ) );
    _setBasicDistricts( districts );

    do {
        _printMenu();
        option = _getOption();
        if( option == MENU_SIZE ) {
            puts( "Bye bye!" );
            return 0;
        }
        switch( option ) {
            case 1:
                list( districts );
                break;
            case 2:
                listCandidates( districts );
                break;
            case 3:
                addDistrict( districts );
                break;
            case 4:
                addCandidate( districts );
                break;
        }

    } while( option != EXIT_OPTION );

    return 0;
}

void _printMenu() {
    for( int i = 0; i < MENU_SIZE; i++ ) {
        printf( "%i) %s\n", i + 1, MENU[ i ] );
    }
}

char* _getValidInput( char* input ) {
    if( !fgets( input, sizeof( input ), stdin ) ) {
            puts("Input error!");
            exit( -1 );
    } else if( !strchr( input, '\n' ) ) {
        // The input is longer than the buffer size we need to read the input until finding the enter or having an error
        while ( fgets( input, sizeof( input ), stdin ) && !strchr( input, '\n' ) );
        return "\0";
    }
    input[ strlen( input ) -1 ] = '\0'; // Specify the end of string

    return input;
}

int _getOption() {
    char* input = _getValidInput( optionInput );

    int option = atoi( input );

    if( option > 0 && option <= MENU_SIZE ) {
        return option;
    }

    puts( "Invalid input!" );
    return -1;
}

void _setBasicDistricts( District* districts ) {
    int districtsNum = (int) sizeof( DISTRICTS ) / sizeof( DISTRICTS[ 0 ] );
    districts->name = DISTRICTS[ 0 ];

    for( int i = 1; i < districtsNum; i++ ) {
        _setDistrict( DISTRICTS[ i ], districts );
    }
}

void _setDistrict( char* name, District* districts ) {
    District* temp = districts;

    District* newDistrict = (District*) malloc( sizeof( District ) );
    newDistrict->name = (char*) malloc( sizeof( strlen( name ) + 1 ) );
    strcpy( newDistrict->name, name );
    newDistrict->candidates = NULL;
    newDistrict->next = NULL;
    newDistrict->prev = NULL;

    while( temp->next ) {
        temp = temp->next;
    }
    temp->next = newDistrict;

    return;
}

void addDistrict( District* districts ) {
    printf( "Enter the district name: " );
    char* name = _getValidInput( wordInput );
    _setDistrict( name, districts );

    return;
}

void addCandidate( District* districts ) {
    printf( "Enter the district name: " );
    char* target = _getValidInput( wordInput );

    District* district = districts;

    while( district && strcmp( district->name, target ) != 0 ) {
        district = district->next;
    }
    if( district ) {
        printf( "Enter the candidate name: " );
        char* name = _getValidInput( wordInput );

        Candidate* newCandidate = (Candidate*) malloc( sizeof( Candidate ) );
        newCandidate->name = (char*) malloc( sizeof( strlen( name ) + 1 ) );
        newCandidate->next = NULL;
        newCandidate->prev = NULL;
        strcpy( newCandidate->name, name );

        if( !district->candidates ) {
            district->candidates = (Candidate*) malloc( sizeof( Candidate ) );
            district->candidates = newCandidate;
            return;
        }

        Candidate* ptrCandidate = district->candidates;
        while( ptrCandidate->next ) {
            ptrCandidate = ptrCandidate->next;
        }
        ptrCandidate->next = newCandidate;
        newCandidate->prev = ptrCandidate;

        return;
    }

    puts( "District not found!" );
    return;
}

void list( District* districts ) {
    District* ptrDistrict = districts;
    while( ptrDistrict ) {

        printf( "%s: ", ptrDistrict->name );
        Candidate* ptrCandidate = ptrDistrict->candidates;

        while( ptrCandidate ) {
            printf( "%s", ptrCandidate->name );
            if( ptrCandidate->next ) {
                printf( ", " );
            }
            ptrCandidate = ptrCandidate->next;
        }
        printf( "\n" );

        ptrDistrict = ptrDistrict->next;
    }

    return;
}

void listCandidates( District* districts ) {
    printf( "Enter the district name: " );
    char* districtName = _getValidInput( wordInput );

    District* ptrDistrict = districts;
    while( ptrDistrict && strcmp( ptrDistrict->name,districtName ) != 0 ) {
        ptrDistrict = ptrDistrict->next;
    }
    if( ptrDistrict ) {
        printf( "%s: ", ptrDistrict->name );
        Candidate* ptrCandidate = ptrDistrict->candidates;

        while( ptrCandidate ) {
            printf( "%s", ptrCandidate->name );
            if( ptrCandidate->next ) {
                printf( ", " );
            }
            ptrCandidate = ptrCandidate->next;
        }
        printf( "\n" );

        ptrDistrict = ptrDistrict->next;

        return;
    }

    puts( "District not found!" );
    return;
}
