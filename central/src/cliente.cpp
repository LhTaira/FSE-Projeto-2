#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int clienteSocket;
  struct sockaddr_in servidorAddr;
  unsigned short servidorPorta;
  char *IP_servidor;
  char *mensagem;
  char buffer[16];
  unsigned int tamanhoMensagem;
  int bytesRecebidos;
  int totalBytesRecebidos;

  if ((argc < 4) || (argc > 4)) {
    cout << "Uso " << argv[0] << "<IP do Servidor> <Porta> <Mensagem>" << endl;
    exit(1);
  }

  IP_servidor = argv[1];
  servidorPorta = atoi(argv[2]);
  mensagem = argv[3];

  if ((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    cout << "Erro no socket()" << endl;

  memset(&servidorAddr, 0, sizeof(servidorAddr));
  servidorAddr.sin_family = AF_INET;
  servidorAddr.sin_addr.s_addr = inet_addr(IP_servidor);
  servidorAddr.sin_port = htons(servidorPorta);

  if (connect(clienteSocket, (struct sockaddr *)&servidorAddr,
              sizeof(servidorAddr)) < 0)
    cout << "Erro no connect()" << endl;

  tamanhoMensagem = strlen(mensagem);

  if (send(clienteSocket, mensagem, tamanhoMensagem, 0) != tamanhoMensagem)
    cout << "Erro no envio: numero de bytes enviados diferente do esperado"
         << endl;

  totalBytesRecebidos = 0;

  while(totalBytesRecebidos < tamanhoMensagem) {
  // cout << "Fronk\n";
    if((bytesRecebidos = recv(clienteSocket, buffer, 16-1, 0)) <= 0)
      cout << "Não recebeu o total de bytes enviados" << endl;
    totalBytesRecebidos += bytesRecebidos;
    buffer[totalBytesRecebidos] = '\0';
    cout << string(buffer) << endl;
    // printf("%s\n", buffer);
  }

  close(clienteSocket);
  exit(0);
}