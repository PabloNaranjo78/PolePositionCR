#include "Cliente.h"

static int MAX_ATTEMPTS =5;

static char UserIp[20];


/**
 * @def makeRequest realiza una peticion al servidor, el cual le respondera con un Json
 * @param printState : este parametro indica si queremos que se impriman los estados
 * @return  bool : en caso que la peticion fracase, se retorna un false
 */
char* makeRequest(bool printState,char* message){
    int state;
    WSADATA wsa;
    SOCKET mySocket;
    bool connected=false;
    struct sockaddr_in server;
    char server_reply[6000];
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");//"25.2.144.151"
   //  server.sin_addr.s_addr = inet_addr("25.2.146.186");//"25.2.144.151"

    server.sin_port = htons( 5000 );

    // INICIO WINSOCK------------------------------------------------------------------------------------------>
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0){
        printf("Failed. Error Code : %d",WSAGetLastError());
        return false;}
    if(printState)printf("@: Cliente iniciado.\n");

    // CREO EL SOCKET------------------------------------------------------------------------------------------>
    if((mySocket = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET) {
        printf("!!: No se pudo crear el socket  : %d", WSAGetLastError());
        return false;
    }
    //INTENTO CONECTAR AL SERVER------------------------------------------------------------------------------->
    while(!connected){
        if(MAX_ATTEMPTS!=0) {
            if (connect(mySocket, (struct sockaddr *) &server, sizeof(server)) < 0) {
                if(printState) puts("buscando...\n");
                MAX_ATTEMPTS--;
            }
            else  connected = true;
        }
        else {if(printState) puts("!!: No se logro realizar la conexion\n"); return false; }
    }if(printState) puts("@: Socket iniciado...");


//    //ENVIO LA PETICION---------------------------------------------------------------------------------------->
    if(send(mySocket , message , strlen(message) , 0) < 0){
        puts("!!: envio fallido");
        return false;
    }
    if(printState)puts("@: Informacion enviada correctamente\n");


    //ANALIZO SI RECIBO UNA RESPUESTA DEL SERVIDOR, LUEGO CIERRO-------------------------------------------------->
    if((state=recv(mySocket , server_reply , 6000 , 0)) == SOCKET_ERROR){//guarda la respuesta en server_reply[state]
        printf("!!: No se recibio respuesta \n!!: Error %i",state);
        return false;
    }
    server_reply[state]='\0';
    if(printState)printf("@: Respuesta obtenida: %s \n", server_reply);

  //  printf("%s\n", server_reply);
    closesocket(mySocket);
    return server_reply;
}