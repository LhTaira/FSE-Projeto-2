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
    if (lampada[0]) {
      write_pin(PIN_LAMPADA_1, 0);
      lampada[0] = false;
    } else {
      write_pin(PIN_LAMPADA_1, 1);
      lampada[0] = true;
    }
  } else if (message.compare(string("l2")) == 0) {
    if (lampada[1]) {
      write_pin(PIN_LAMPADA_2, 0);
      lampada[1] = false;
    } else {
      write_pin(PIN_LAMPADA_2, 1);
      lampada[1] = true;
    }
  } else if (message.compare(string("l3")) == 0) {
    if (lampada[2]) {
      write_pin(PIN_LAMPADA_3, 0);
      lampada[2] = false;
    } else {
      write_pin(PIN_LAMPADA_3, 1);
      lampada[2] = true;
    }
  } else if (message.compare(string("l4")) == 0) {
    if (lampada[3]) {
      write_pin(PIN_LAMPADA_4, 0);
      lampada[3] = false;
    } else {
      write_pin(PIN_LAMPADA_4, 1);
      lampada[3] = true;
    }
  } else if (message.compare(string("a1")) == 0) {
    if (arCondicionado[0]) {
      write_pin(PIN_AR_CONDICIONADO_1, 0);
      arCondicionado[0] = false;
    } else {
      write_pin(PIN_AR_CONDICIONADO_1, 1);
      arCondicionado[0] = true;
    }
  } else if (message.compare(string("a2")) == 0) {
    if (arCondicionado[1]) {
      write_pin(PIN_AR_CONDICIONADO_2, 0);
      arCondicionado[1] = false;
    } else {
      write_pin(PIN_AR_CONDICIONADO_2, 1);
      arCondicionado[1] = true;
    }
  }else{
    cout << "wrong\n";
  }
  //  else if (buffer[0] == 'a') {
  //   if (alarme) {
  //     alarme = false;
  //   } else {
  //     alarme = true;
  //   }
  // }
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
    // usleep(10000);
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