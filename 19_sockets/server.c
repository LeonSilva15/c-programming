#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SERVER_PORT 5001
#define END_CHAR "\0"
#define NEW_LINE "\n"
#define EXIT "EXIT"

char* menu[] = {
    "1. Learn the main keywords",
    "2. Evaluation",
    "3. Exit"
};
size_t menuSize = sizeof( menu ) / sizeof( menu[ 0 ] );

char info[ 4 ][ 100 ] = {
    "CREATE is used to CREATE objects in the data base",
    "SELECT is used to SELECT objects from the data base",
    "UPDATE is used to UPDATE objects in the data base",
    "DELETE is used to DELETE objects in the data base"
};

typedef struct {
    char* question;
    char* answer;

} EvaluationItem;

EvaluationItem createEvaluationItem( char* question, char* answer );
EvaluationItem* createEvaluation( EvaluationItem* );

int main () {
    int serverSocket;
    int clientSocket;
    struct sockaddr_in inputAddress;
    struct sockaddr clientAddress;
    socklen_t clientAddrLength;
    char bufferMsg[ 100 ];

    /*
     * Create connection
     */
    // Create server socket
    serverSocket = socket( AF_INET, SOCK_STREAM, 0 );
    if( serverSocket == -1 ) {
        exit( 1 );
    }

    // Open the server port for communication
    inputAddress.sin_family = AF_INET;
    inputAddress.sin_port = SERVER_PORT;
    inputAddress.sin_addr.s_addr = INADDR_ANY;
    if( bind( serverSocket, (struct sockaddr*) &inputAddress, sizeof( inputAddress ) ) == -1 ) {
        close( serverSocket );
        exit( 1 );
    }

    // Listen from the opened port
    if( listen ( serverSocket, 1 ) == -1 ) {
        close( serverSocket );
        exit( 1 );
    }
    puts( "Awaiting for client to connect" );

    // Accept the connection from the client
    clientSocket = accept( serverSocket, &clientAddress, &clientAddrLength );
    if( clientSocket == -1 ) {
        exit( 1 );
    }

    /*
     * Create evaluation content
     */
    EvaluationItem evaluation[ 4 ];
    createEvaluation( evaluation );

    /*
     * Main program
     */
    int closeProgram = 0;
    int option = 0;

    while( !closeProgram ) {
        // Send main menu
        for( int i = 0; i < menuSize; i++ ) {
            strcpy( bufferMsg, menu[ i ] );
            write( clientSocket, bufferMsg, sizeof( bufferMsg ) );
        }
        write( clientSocket, END_CHAR, sizeof( END_CHAR ) );

        // Read client selection
        read( clientSocket, bufferMsg, sizeof( bufferMsg ) );
        option = atoi( bufferMsg );

        switch( option ) {
            case 1:
                for( int i = 0; i < 4; i++ ) {
                    strcpy( bufferMsg, info[ i ] );
                    write( clientSocket, bufferMsg, sizeof( bufferMsg ) );
                }
                strcpy( bufferMsg, NEW_LINE );
                write( clientSocket, bufferMsg, sizeof( bufferMsg ) );
                break;
            case 2:
                int score = 0;
                for( int i = 0; i < 4; i++ ) {
                    strcpy( bufferMsg, evaluation[ i ].question );
                    write( clientSocket, bufferMsg, sizeof( bufferMsg ) );
                    write( clientSocket, END_CHAR, sizeof( END_CHAR ) );

                    read( clientSocket, bufferMsg, sizeof( bufferMsg ) );

                    if( strcmp( bufferMsg, evaluation[ i ].answer ) == 0 ) {
                        score += 25;
                    }
                }
                sprintf( bufferMsg, "Your score is: %i/100 pts", score );
                write( clientSocket, bufferMsg, sizeof( bufferMsg ) );
                break;
            case 3:
                // Terminar programa
                write( clientSocket, EXIT, sizeof( EXIT ) );
                closeProgram = 1;
                break;
            default:
                strcpy( bufferMsg, "Invalid option, please choose one of the following:" );
                write( clientSocket, bufferMsg, sizeof( bufferMsg ) );
        }

    }

    close( serverSocket );
    return 0;
}

EvaluationItem createEvaluationItem( char* question, char* answer ) {
    EvaluationItem newEvalItem;
    newEvalItem.question = question;
    newEvalItem.answer = answer;

    return newEvalItem;
}

EvaluationItem* createEvaluation( EvaluationItem* evaluation ) {
    evaluation[ 0 ] = createEvaluationItem( "_____ is used to CREATE objects in the data base", "CREATE" );
    evaluation[ 1 ] = createEvaluationItem( "_____ is used to SELECT objects from the data base", "SELECT" );
    evaluation[ 2 ] = createEvaluationItem( "_____ is used to UPDATE objects in the data base", "UPDATE" );
    evaluation[ 3 ] = createEvaluationItem( "_____ is used to DELETE objects in the data base", "DELETE" );

    return evaluation;
}
