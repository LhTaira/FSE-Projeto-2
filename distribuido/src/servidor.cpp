// #include <arpa/inet.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <unistd.h>

// #include <iostream>

// using namespace std;

// void TrataClienteTCP(int socketCliente) {
//   char buffer[16];
//   int tamanhoRecebido;

//   if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
//     cout << "Erro no rcv()" << endl;

//   while (tamanhoRecebido > 0) {
//     if (send(socketCliente, buffer, tamanhoRecebido, 0) != tamanhoRecebido)
//       cout << "Erro no envio - send() " << endl;
//     // printf("%s\n", buffer);
//     if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
//       cout << "Erro no rcv()" << endl;
//   }
// }

// int main(int argc, char* argv[]) {
//   int servidorSocket;
//   int socketCliente;
//   struct sockaddr_in servidorAddr;
//   struct sockaddr_in clienteAddr;
//   unsigned short servidorPorta;
//   unsigned int clienteLength;

//   if (argc != 2) {
//     cout << "Uso: " << argv[0] << "<Porta>" << endl;
//     exit(1);
//   }

//   servidorPorta = atoi(argv[1]);

//   if ((servidorSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
//     cout << "Falha no socket do servidor" << endl;

//   memset(&servidorAddr, 0, sizeof(servidorAddr));
//   servidorAddr.sin_family = AF_INET;
//   servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
//   servidorAddr.sin_port = htons(servidorPorta);

//   if(bind(servidorSocket, (struct sockaddr*) &servidorAddr, sizeof(servidorAddr)) < 0)
//     cout << "Falha no bind" << endl;

//   if(listen(servidorSocket, 10) < 0)
//     cout << "Falha no Listen" << endl;

//   while(1) {
//     clienteLength = sizeof(clienteAddr);
//     if((socketCliente = accept(servidorSocket, (struct sockaddr *) &clienteAddr, &clienteLength)) < 0)
//       cout << "Falha no accept" << endl;
    
//     cout << "Conexão do Cliente " << inet_ntoa(clienteAddr.sin_addr) << endl;

//     TrataClienteTCP(socketCliente);
//     close(socketCliente);
//   }
//   close(servidorSocket);
// }