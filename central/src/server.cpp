#include "../inc/server.hpp"

using namespace std;

void TrataClienteTCP(int socketCliente) {
  char buffer[16];
  int tamanhoRecebido;
  int j = 0;

  if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
    cout << "Erro no rcv()" << endl;

  while (tamanhoRecebido > 0) {
    if (send(socketCliente, buffer, tamanhoRecebido, 0) != tamanhoRecebido)
      cout << "Erro no envio - send() " << endl;
    // printf("%s\n", buffer);
    if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
      cout << "Erro no rcv()" << endl;
  }

  if (buffer[0] == 'e') {
    buffer[6] = '\0';
    temperatura = string(&buffer[1]);
  } else if (buffer[0] == 'u') {
    buffer[6] = '\0';
    umidade = string(&buffer[1]);
  } else {
    for (int i = 0; i < 2; i++) {
      if (buffer[j++] == 't') {
        arCondicionado[i] = "Ligado";
      } else {
        arCondicionado[i] = "Desligado";
      }
    }

    for (int i = 0; i < 4; i++) {
      if (buffer[j++] == 't') {
        lampada[i] = "Ligado";
      } else {
        lampada[i] = "Desligado";
      }
    }

    for (int i = 0; i < 2; i++) {
      if (buffer[j++] == 't') {
        presenca[i] = "Ligado";
      } else {
        presenca[i] = "Desligado";
      }
    }

    for (int i = 0; i < 6; i++) {
      if (buffer[j++] == 't') {
        abertura[i] = "Ligado";
      } else {
        abertura[i] = "Desligado";
      }
    }

    // if (buffer[j] == 't') {
    //   alarme = "Ligado";
    // } else {
    //   alarme = "Desligado";
    // }
  }
}

void server(unsigned short servidorPorta) {
  signal(SIGUSR1, SIG_IGN);
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

    // cout << "Conexão do Cliente " << inet_ntoa(clienteAddr.sin_addr) << endl;

    TrataClienteTCP(socketCliente);
    close(socketCliente);
    kill(this_pid, SIGUSR1);
  }
  close(servidorSocket);
}