#include "../inc/server.hpp"

using namespace std;

void TrataClienteTCP(int socketCliente) {
  char buffer[16];
  int tamanhoRecebido;

  if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
    cout << "Erro no rcv()" << endl;

  while (tamanhoRecebido > 0) {
    if (send(socketCliente, buffer, tamanhoRecebido, 0) != tamanhoRecebido)
      cout << "Erro no envio - send() " << endl;
    // printf("%s\n", buffer);
    if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
      cout << "Erro no rcv()" << endl;
  }
  buffer[2] = '\0';
  string message(buffer);
  printf("%s\n", buffer);
  // cout << message  << " " << tamanhoRecebido<< endl;

  if (message.compare(string("l1")) == 0) {
    if(lampada[0]) {
      lampada[0] = false;
    } else {
      lampada[0] = true;
    }
  } else if (message.compare(string("l2")) == 0) {
    if(lampada[1]) {
      lampada[1] = false;
    } else {
      lampada[1] = true;
    }
  } else if (message.compare(string("a1")) == 0) {
    if(arCondicionado[0]) {
      arCondicionado[0] = false;
    } else {
      arCondicionado[0] = true;
    }
  } else if (message.compare(string("a2")) == 0) {
    if(arCondicionado[1]) {
      arCondicionado[1] = false;
    } else {
      arCondicionado[1] = true;
    }
  } else if (buffer[0] == 'a') {
    if(alarme) {
      alarme = false;
    } else {
      alarme = true;
    }
  }
}

void server(unsigned short servidorPorta) {
  int servidorSocket;
  int socketCliente;
  struct sockaddr_in servidorAddr;
  struct sockaddr_in clienteAddr;
  // unsigned short servidorPorta;
  unsigned int clienteLength;

  if ((servidorSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    cout << "Falha no socket do servidor" << endl;

  memset(&servidorAddr, 0, sizeof(servidorAddr));
  servidorAddr.sin_family = AF_INET;
  servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servidorAddr.sin_port = htons(servidorPorta);

  if (bind(servidorSocket, (struct sockaddr *)&servidorAddr,
           sizeof(servidorAddr)) < 0)
    cout << "Falha no bind" << endl;

  if (listen(servidorSocket, 10) < 0) cout << "Falha no Listen" << endl;

  while (1) {
    clienteLength = sizeof(clienteAddr);
    if ((socketCliente = accept(servidorSocket, (struct sockaddr *)&clienteAddr,
                                &clienteLength)) < 0)
      cout << "Falha no accept" << endl;

    cout << "Conexão do Cliente " << inet_ntoa(clienteAddr.sin_addr) << endl;

    TrataClienteTCP(socketCliente);
    close(socketCliente);
  }
  close(servidorSocket);
}