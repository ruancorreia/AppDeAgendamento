#include <stdio.h>

int dias_no_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char meses[][20] = {
    "",
    "\n\n\nJaneiro",
    "\n\n\nFevereiro",
    "\n\n\nMarço",
    "\n\n\nAbril",
    "\n\n\nMaio",
    "\n\n\nJunho",
    "\n\n\nJulho",
    "\n\n\nAgosto",
    "\n\n\nSetembro",
    "\n\n\nOutubro",
    "\n\n\nNovembro",
    "\n\n\nDezembro"
};

int main(void)
{
  /*
  Espaço para colocar as funções criadas
  */

  int escolha;
  do
  {
    printf("\n\n\t== FIOSIOGENDA ==\n");
    printf("SELECIONE ABAIXO UMA DAS OPÇÕES:\n\n");
    printf("1 - Mostrar Calendário\n");
    printf("2 - Agendar Tratamento\n");
    printf("3 - Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      printf("Função exibir_calendario()");
      break;
    case 2:
      printf("Função agendar_compromisso()");
      break;
    case 3:
      printf("Programa finalizado com sucesso...\n");
      break;
    default:
      printf("Escolha inválida! Por favor, tente novamente.\n");
    }
  } while (escolha != 3);

  return 0;
}

/*Esta funçao tem o objetivo de pedir ao usuario que insira o primeiro dia do ano indicando o dia da semana em que ele vai cair
Exemplo: ao selecionar 0, o primeiro dia da semana sera domingo, 1º de janeiro.
*/
int inserir_dia_inicio(void)
{
  int dia;
  printf("Por favor, insira o dia da semana em que cai o dia 1º de Janeiro (0 para Domingo, 1 para Segunda-feira, ..., 6 para Sábado): ");
  scanf("%d", &dia);
  return dia;
}


/*Esta funçao irá perguntar ao usuário se o ano é bissexto ou nao
retornando 1 para caso positivo e 0 para caso negativo.
*/
int inserir_ano_bissexto(void)
{
  int bissexto;
  printf("O ano é bissexto? (1 para Sim, 0 para Não): ");
  scanf("%d", &bissexto);
  return bissexto;
}


/*
Função para determinar o código do dia
*/
int determinar_codigo_dia(int dia_inicio)
{
  return dia_inicio % 7;
}


/*Esta funçao irá verificar se o ano foi definido como bissexto ou nao
e irá ajustar os dias de fevereiro de acordo
*/
int determinar_ano_bissexto(int bissexto, int dias_no_mes[]) {
    if (bissexto) {
        dias_no_mes[2] = 29;
        return 1;
    } else {
        dias_no_mes[2] = 28;
        return 0;
    }
}


// Esta funçao irá exibir os calendários - Regular e de Compromissos Agendados.
void exibir_calendario(int dia_inicio, int bissexto, int compromissos[], int dias_no_mes[]) {
    int mes, dia;
    int dias_no_mes_temp[13];
    int dia_inicio_mes = dia_inicio; // Dia de início para cada mês

    // Ajustar os dias de Fevereiro para ano bissexto
    determinar_ano_bissexto(bissexto, dias_no_mes);

    printf("Calendário Regular:\n");

    for (mes = 1; mes <= 12; mes++) {
        printf("%s", meses[mes]);
        printf("\n\nDom  Seg  Ter  Qua  Qui  Sex  Sáb\n");

        for (int i = 0; i < dia_inicio_mes; i++) {
            printf("     ");
        }


        for (dia = 1; dia <= dias_no_mes[mes]; dia++) {
            printf("%2d", dia);


            if ((dia + dia_inicio_mes) % 7 > 0)
                printf("   ");
            else
                printf("\n ");
        }

        printf("\n\n");

        dia_inicio_mes = (dia_inicio_mes + dias_no_mes[mes]) % 7;
    }

    printf("Calendário de Compromissos:\n");

    // Exibir calendário de compromissos
    dia_inicio_mes = dia_inicio; // Resetar dia de início
    for (mes = 1; mes <= 12; mes++) {
        printf("%s", meses[mes]);
        printf("\n\nDom  Seg  Ter  Qua  Qui  Sex  Sáb\n");

        // Imprimir o número correto de espaços para o dia de início
        for (int i = 0; i < dia_inicio_mes; i++) {
            printf("     ");
        }

        // Imprimir todos os compromissos para um mês
        for (dia = 1; dia <= dias_no_mes[mes]; dia++) {
            printf("%2d", compromissos[(mes - 1) * 31 + (dia - 1)]);

            // O dia é antes de Sáb? Se sim, começar na próxima linha com Dom.
            if ((dia + dia_inicio_mes) % 7 > 0)
                printf("   ");
            else
                printf("\n ");
        }

        printf("\n\n");

        // Calcular o dia de início para o próximo mês
        dia_inicio_mes = (dia_inicio_mes + dias_no_mes[mes]) % 7;
    }
}
