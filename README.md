# Projeto 2 - 2020/2

Projeto 2 da disciplina de Fundamentos de Sistemas Embarcados (2020/2)

Este trabalho faz parte da atividade proposta no seguinte repositório:
https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2

## Instruções de uso

### Rodando o programa

* O projeto precisa de duas portas. Uma será usada pelo servidor distribuído se comunicar com o central e outra para o central se comunicar com o distribuído.
<br>
* Tenha certeza que o servidor central esteja rodando antes de iniciar o distribuído.
<br>
* Certifique-se que as seguintes variáveis variáveis estão atribuídas com os valores corretos em ambos os makefiles
`IP_CENTRAL` = IP da raspberry que rodará o servidor central.
`IP_DISTRIBUIDO` = Valor do IP da raspberry que rodará o servidor distribuído.
`PORTA1` = 10029
`PORTA2` = 10129
<br>
1. Servidor Central
Na pasta `/central` do projeto

* Para compilar rode o comando:
`make`
<br>

* Para executar rode o comando:
`make run`
<br>
2. Servidor Central
Na pasta `/distribuido` do projeto
* Para compilar rode o comando:
`make`
<br>
* Para executar rode o comando:
`make run`

### Usando o programa

Ao executar, o servidor central mostrará uma interface que, ao mesmo tempo, oferece um menu com opções de ações para o usuário e mostra o estado dos sensores.

* Utilize as setas para cima e para baixo para navegar no menu e enter para selecionar uma opção. Selecione `sair` ou pressione ESC para fechar o servidor central.

* Os sensores de presença e abertura são atualizados quando uma borda é identificada.

* A temperatura e umidade são atualizadas a cada segundo.


## Log

* O arquivo de log do sistema é gerado na pasta `/central` com o nome de `log.csv` e as iformações são guardadas linha a linha no formato `"d-m-yyyy h:m:s,tipo_de_evento`.
<br>
* Quando o servidor central se inicia, cria o arquivo de log, se não existente, e escreve registros no final do arquivo sem apagar o log de execuções passadas.


## 9. Referências

[PID - Wikipedia](https://pt.wikipedia.org/wiki/Controlador_proporcional_integral_derivativo)  
[Driver da Bosh para o sensor BME280](https://github.com/BoschSensortec/BME280_driver)  
[Biblioteca BCM2835 - GPIO](http://www.airspayce.com/mikem/bcm2835/) 
[Biblioteca WiringPi GPIO](http://wiringpi.com)

