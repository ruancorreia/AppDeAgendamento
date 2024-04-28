
#include <stdio.h>
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
    "\n\n\nDezembro"};

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
