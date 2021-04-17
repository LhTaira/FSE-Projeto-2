#include "../inc/client.hpp"

#include "../inc/global.hpp"

using namespace std;

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
      tamanhoMensagem)
    cout << "Erro no envio: numero de bytes enviados diferente do esperado"
         << endl;

  totalBytesRecebidos = 0;

  while (totalBytesRecebidos < (int)tamanhoMensagem) {
    // cout << "Fronk\n";
    if ((bytesRecebidos = recv(clienteSocket, buffer, 16 - 1, 0)) <= 0)
      cout << "Não recebeu o total de bytes enviados" << endl;
    totalBytesRecebidos += bytesRecebidos;
    buffer[totalBytesRecebidos] = '\0';
    // cout << string(buffer) << endl;
    // printf("%s\n", buffer);
  }

  close(clienteSocket);
  return true;
}