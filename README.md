# Projeto 2 - 2020/2

Projeto 2 da disciplina de Fundamentos de Sistemas Embarcados (2020/2)

Este trabalho faz parte da atividade proposta no seguinte repositório:
https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2

## Instruções de uso

### Rodando o programa

* O projeto precisa de duas portas. Uma será usada pelo servidor distribuído se comunicar com o central e outra para o central se comunicar com o distribuído.
* Tenha certeza que o servidor central esteja rodando antes de iniciar o distribuído.

1. Servidor Central
Na pasta `/central` do projeto

* Para compilar rode o comando:

`make`
<br>
* Para executar rode o comando:

`./bin/bin <Porta 1> <IP do servidor distribuído> <Porta 2>`

2. Servidor Central
Na pasta `/distribuido` do projeto

* Para compilar rode o comando:

`make`
<br>
* Para executar rode o comando:

`./bin/bin <Porta 2> <IP do servidor central> <Porta 1>`

### Usando o programa



## Parâmetros de PID


## Log


## 9. Referências

[PID - Wikipedia](https://pt.wikipedia.org/wiki/Controlador_proporcional_integral_derivativo)  
[Driver da Bosh para o sensor BME280](https://github.com/BoschSensortec/BME280_driver)  
[Biblioteca BCM2835 - GPIO](http://www.airspayce.com/mikem/bcm2835/) 
[Biblioteca WiringPi GPIO](http://wiringpi.com)

