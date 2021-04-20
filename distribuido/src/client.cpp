#include "../inc/client.hpp"

#include "../inc/global.hpp"

using namespace std;

void make_temperature_humidity_message(string IP_servidor,
                                       unsigned short servidorPorta) {
  string temperature_message, humidity_message;
  if (temperatura >= 10.0) {
    stringstream stream;
    stream << fixed << setprecision(2) << temperatura;
    temperature_message = "e" + stream.str();
  } else {
    stringstream stream;
    stream << fixed << setprecision(2) << temperatura;
    temperature_message = "e0" + stream.str();
  }

  send_message(IP_servidor, servidorPorta, temperature_message);

  if (umidade >= 10.0) {
    stringstream stream;
    stream << fixed << setprecision(2) << umidade;
    humidity_message = "u" + stream.str();
  } else {
    stringstream stream;
    stream << fixed << setprecision(2) << umidade;
    humidity_message = "u0" + stream.str();
  }

  send_message(IP_servidor, servidorPorta, humidity_message);
}

void make_and_send_message(string IP_servidor, unsigned short servidorPorta) {
  char code[14];
  int j = 0;
  for (int i = 0; i < 2; i++) {
    if (arCondicionado[i]) {
      code[j++] = 't';
    } else {
      code[j++] = 'f';
    }
  }

  for (int i = 0; i < 4; i++) {
    if (lampada[i]) {
      code[j++] = 't';
    } else {
      code[j++] = 'f';
    }
  }

  // for (int i = 0; i < 2; i++) {
  //   if (presenca[i]) {
  //     code[j++] = 't';
  //   } else {
  //     code[j++] = 'f';
  //   }
  // }

  // for (int i = 0; i < 6; i++) {
  //   if (abertura[i]) {
  //     code[j++] = 't';
  //   } else {
  //     code[j++] = 'f';
  //   }
  // }

  // if (alarme) {
  //   code[j++] = 't';
  // } else {
  //   code[j++] = 'f';
  // }

  code[j] = '\0';

  send_message(IP_servidor, servidorPorta, string(code));
}

bool send_message(string IP_servidor, unsigned short servidorPorta,
                  string mensagem) {
  int clienteSocket;
  struct sockaddr_in servidorAddr;
  //   unsigned short servidorPorta;
  //   char *IP_servidor;
  //   char *mensagem;
  char buffer[16];
  unsigned int tamanhoMensagem;
  int bytesRecebidos;
  int totalBytesRecebidos;

  //   if ((argc < 4) || (argc > 4)) {
  //     cout << "Uso " << argv[0] << "<IP do Servidor> <Porta> <Mensagem>" <<
  //     endl; exit(1);
  //   }

  //   IP_servidor = argv[1];
  //   servidorPorta = atoi(argv[2]);
  //   mensagem = argv[3];

  if ((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    cout << "Erro no socket()" << endl;

  memset(&servidorAddr, 0, sizeof(servidorAddr));
  servidorAddr.sin_family = AF_INET;
  servidorAddr.sin_addr.s_addr = inet_addr(IP_servidor.c_str());
  servidorAddr.sin_port = htons(servidorPorta);

  if (connect(clienteSocket, (struct sockaddr *)&servidorAddr,
              sizeof(servidorAddr)) < 0)
    cout << "Erro no connect()" << endl;

  tamanhoMensagem = mensagem.size();

  if (send(clienteSocket, mensagem.c_str(), tamanhoMensagem, 0) !=
      (int) tamanhoMensagem)
    cout << "Erro no envio: numero de bytes enviados diferente do esperado"
         << endl;

  totalBytesRecebidos = 0;

  while (totalBytesRecebidos < (int)tamanhoMensagem) {
    // cout << "Fronk\n";
    if ((bytesRecebidos = recv(clienteSocket, buffer, 16 - 1, 0)) <= 0)
      cout << "Não recebeu o total de bytes enviados" << endl;
    totalBytesRecebidos += bytesRecebidos;
    buffer[totalBytesRecebidos] = '\0';
    cout << string(buffer) << endl;
    // printf("%s\n", buffer);
  }

  close(clienteSocket);
  return true;
}