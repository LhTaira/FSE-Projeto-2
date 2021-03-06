#include "../inc/server.hpp"

using namespace std;

void TrataClienteTCP(int socketCliente) {
  char buffer[16];
  int tamanhoRecebido;
  // int j = 0;

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
  } else if (buffer[0] == 'A') {
    if (buffer[2] == 't') {
      abertura[int(buffer[1]) - '0' - 1] = "Ligado";
    } else {
      abertura[int(buffer[1]) - '0' - 1] = "Desligado";
    }
    verify_alarm();
  } else if (buffer[0] == 'P') {
    if (buffer[2] == 't') {
      // cout << int(buffer[1]) - '0' << " " << presenca[int(buffer[1]) - '0'] << endl;
      presenca[int(buffer[1]) - '0' - 1] = "Ligado";
    } else {
      presenca[int(buffer[1]) - '0' - 1] = "Desligado";
    }
    verify_alarm();
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
    // usleep(10000);
    clienteLength = sizeof(clienteAddr);
    if ((socketCliente = accept(servidorSocket, (struct sockaddr *)&clienteAddr,
                                &clienteLength)) < 0)
      cout << "Falha no accept" << endl;

    // cout << "Conex??o do Cliente " << inet_ntoa(clienteAddr.sin_addr) << endl;

    TrataClienteTCP(socketCliente);
    close(socketCliente);
    // kill(this_pid, SIGUSR1); 
  }
  close(servidorSocket);
}