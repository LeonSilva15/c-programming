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

#define HOST_IP "172.17.0.3"
#define SERVER_PORT 5001
#define END_CHAR "\0"
#define EXIT "EXIT"

int readFromServer( int serverSocket );

int main() {
    int serverSocket;
    struct sockaddr_in inputAddress;
    char bufferMsg[ 100 ];

    /*
     * Create connection
     */
    // Look for the server IP
    struct hostent* Host = gethostbyname( HOST_IP );
    if( Host == NULL ) {
        exit( 1 );
    }

    inputAddress.sin_family = AF_INET;
    inputAddress.sin_port = SERVER_PORT;
    inputAddress.sin_addr.s_addr = ( (struct in_addr*) ( Host->h_addr ) )->s_addr;

    // create the socket to connect to the server
    serverSocket = socket( AF_INET, SOCK_STREAM, 0 );
    if( serverSocket == -1 ){
        exit(1);
    }

    // Connect to the server
    if( connect( serverSocket, (struct sockaddr*) &inputAddress, sizeof( inputAddress ) ) == -1 ) {
        close (serverSocket);
        exit( 1 );
    }
    puts( "Successful connection" );

    // Main program
    while( readFromServer( serverSocket ) ) {
        printf( "> " );
        scanf( "%s", &bufferMsg );
        write( serverSocket, bufferMsg, sizeof( bufferMsg ) );
    }

    // Last write must be from client to server so it knows it can be closed
    write( serverSocket, bufferMsg, sizeof(bufferMsg) );
    close( serverSocket );
    return 0;
}

int readFromServer( int serverSocket ) {
    char bufferMsg[ 100 ];

    printf( "\n" );
    do {
        read( serverSocket, bufferMsg, sizeof( bufferMsg ) );
        if( strcmp( bufferMsg, EXIT ) == 0 ) {
            return 0;
        }
        printf( "%s\n", bufferMsg );
    } while( strcmp( bufferMsg, END_CHAR ) );

    return 1;
}
