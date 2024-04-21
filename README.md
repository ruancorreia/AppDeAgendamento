# AppDeAgendamento
Agenda de compromissos

Caso:
Um fisioterapeuta está precisando da sua ajuda para melhorar sua agenda. O fisioterapeuta trata de pacientes com dores urgentes de todos os tipos, para isso ele trabalha todos os dias. Ele faz planos de pacotes de atendimentos diários para cada paciente. Ou seja, um paciente pode solicitar 10 dias de tratamento, 15 dias, etc… O fisioterapeuta só consegue atender 5 pacientes por dia. O problema é que ele está se perdendo ao fazer agendamentos de pacientes para ao longo do ano, eventualmente ele acaba com mais de 5 pacientes por dia e precisa cancelar. Para resolver esse problema ele precisa que você crie uma agenda que que cadastre agendamentos e indique quantos pacientes ele deve atender em cada dia do ano.


**A Tarefa:**

Escreva um programa em C que exiba um calendário de um ano e gerencie agendamentos. Ao iniciar, o programa deve solicitar ao usuário o dia da semana em que 1º de janeiro cai e se o ano é bissexto ou não. Com essas informações pode-se montar todo o calendário. Depois disso, o programa deve permitir em um menu: 

(i) mostrar o calendário.

(ii) inserir agendamentos.  Esta função deve solicitar ao usuário a data de início e a duração do agendamento. Em um dado dia, não se pode ter mais do que 5 pacientes agendados. Caso ocorra um conflito, deve-se dizer que não pode agendar naquele dia.  

(iii) mostrar o calendário com agendamentos.

No `main()`, você deve ter um array de agendamentos que vai controlar quais dias tem quantos agendamentos. O array deve ter o tamanho do ano. Este array deve ser acessado pelas funções.

Exemplo de formas de mostrar o calendário:

 *** CALENDÁRIO ***
Janeiro
Dom Seg Ter Qua Qui Sex Sab
                  1   2   3
  4   5   6   7   8   9  10
 11  12  13  14  15  16  17
 18  19  20  21  22  23  24
 25  26  27  28  29  30  31

Fevereiro
Dom Seg Ter Qua Qui Sex Sab
  1   2   3   4   5   6   7
  8   9  10  11  12  13  14
 .
 .
 .
	
	
*** CALENDÁRIO DE AGENDAMENTOS ***
Janeiro
Dom Seg Ter Qua Qui Sex Sab
                  0   0   0
  1   1   2   2   2   2   1
  1   2   3   3   3   4   4
  3   3   2   2   2   2   2
  1   0   0   0   0   0   0
	.
	.
	.
