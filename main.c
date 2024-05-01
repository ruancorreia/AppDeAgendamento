#include <stdio.h>
#include <locale.h>

/*
Aqui foram definidas constantes que criarão a identidade visual do programa
para que a visualização do usuario seja mais facil na hora de procurar
*/

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"
#define BG_BLUE "\033[44;1m"
#define BG_GREEN "\033[42m"

/*
DECLARAÇÃO DE FUNÇÕES
*/
int inserir_dia_inicio(void);
int inserir_ano_bissexto(void);
int determinar_codigo_dia(int dia_inicio);
int determinar_ano_bissexto(int bissexto, int dias_no_mes[]);
void exibir_calendario(int dia_inicio, int bissexto, int compromissos[], int dias_no_mes[]);
void agendar_compromisso(int compromissos[], int ano, int dias_no_mes[]);


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

int main(void)
{
  setlocale(LC_ALL, " ");
  int dia_inicio, ano_bissexto;
  dia_inicio = inserir_dia_inicio();
  ano_bissexto = inserir_ano_bissexto();

  // Array para armazenar compromissos, um para cada dia do ano
  int compromissos[12 * 31] = {0}; // Inicializar todas as contagens para 0

  int escolha;
  do
  {
    printf("\n\t== FISIOGENDA ==\n");
    printf("MENU:\n");
    printf("1. Mostrar Calendário\n");
    printf("2. Agendar Tratamento\n");
    printf("3. Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      exibir_calendario(dia_inicio, ano_bissexto, compromissos, dias_no_mes);
      break;
    case 2:
      agendar_compromisso(compromissos, ano_bissexto, dias_no_mes);
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

/*
Esta funçao tem o objetivo de pedir ao usuario que insira o primeiro dia do ano indicando o dia da semana em que ele vai cair
Exemplo: ao selecionar 0, o primeiro dia da semana sera domingo, 1º de janeiro.
*/
int inserir_dia_inicio(void)
{
  int dia;
  printf("Por favor, insira o dia da semana em que cai o dia 1º de Janeiro (0 para Domingo, 1 para Segunda-feira, ..., 6 para Sábado): ");
  scanf("%d", &dia);
  return dia;
}

/*
Esta funçao irá perguntar ao usuário se o ano é bissexto ou nao
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
Função para determinar o código do dia, ou seja, se foi escolhido 0 apresenta domingo como dia inicial na agenda senão apresenta sabado
*/
int determinar_codigo_dia(int dia_inicio)
{
  return dia_inicio % 7;
}

/*
Esta funçao irá verificar se o ano foi definido como bissexto ou nao
e irá ajustar os dias de fevereiro de acordo
*/
int determinar_ano_bissexto(int bissexto, int dias_no_mes[])
{
  if (bissexto)
  {
    dias_no_mes[2] = 29;
    return 1;
  }
  else
  {
    dias_no_mes[2] = 28;
    return 0;
  }
}

/*
Esta funçao irá percorrer os arrays e exibir os calendários
Regular e de Compromissos Agendados.
*/
void exibir_calendario(int dia_inicio, int bissexto, int compromissos[], int dias_no_mes[])
{
  int mes, dia;
  int dias_no_mes_temp[13];
  int dia_inicio_mes = dia_inicio; // Dia de início para cada mês

  // Ajustar os dias de Fevereiro para ano bissexto
  determinar_ano_bissexto(bissexto, dias_no_mes);

  printf(BG_BLUE"\nCalendário Regular:\n"RESET);

  for (mes = 1; mes <= 12; mes++)
  {
    printf(GREEN"%s"RESET, meses[mes]);
    printf(RED "\n\nDom  Seg  Ter  Qua  Qui  Sex  Sáb\n" RESET);

    for (int i = 0; i < dia_inicio_mes; i++)
    {
      printf("     ");
    }

    for (dia = 1; dia <= dias_no_mes[mes]; dia++)
    {
      printf("%2d", dia);

      if ((dia + dia_inicio_mes) % 7 > 0)
        printf("   ");
      else
        printf("\n");
    }

    printf("\n\n");

    dia_inicio_mes = (dia_inicio_mes + dias_no_mes[mes]) % 7;
  }

  printf(BG_GREEN"Calendário de Compromissos:\n"RESET);

  // Exibir calendário de compromissos agendados
  dia_inicio_mes = dia_inicio; // Resetar dia de início
  for (mes = 1; mes <= 12; mes++)
  {
    printf("%s", meses[mes]);
    printf("\n\nDom  Seg  Ter  Qua  Qui  Sex  Sáb\n");

    // Imprimir o número correto de espaços para o dia de início
    for (int i = 0; i < dia_inicio_mes; i++)
    {
      printf("     ");
    }

    // Imprimir todos os compromissos para um mês
    for (dia = 1; dia <= dias_no_mes[mes]; dia++)
    {
      printf("%2d", compromissos[(mes - 1) * 31 + (dia - 1)]);

      // O dia é antes de Sáb? Se sim, começar na próxima linha com Dom.
      if ((dia + dia_inicio_mes) % 7 > 0)
        printf("   ");
      else
        printf("\n");
    }

    printf("\n\n");

    // Calcular o dia de início para o próximo mês
    dia_inicio_mes = (dia_inicio_mes + dias_no_mes[mes]) % 7;
  }
}
// Função para agendar um compromisso
/*
Função criada para fazer o agendamento dos procedimentos,
ela vai pegar o mes e o dia (validando se esta corretamente preenchido)
e validando se nao há mais do que 5 agendamentos naquele dia, caso haja, irá apresentar uma mensagem
informando que ja esta no limite.
*/
void agendar_compromisso(int compromissos[], int ano, int dias_no_mes[])
{
  int mes, dia, duracao;

  printf("Digite o mês (1-12) do compromisso: ");
  scanf("%d", &mes);
  printf("Digite o dia (1-%d) do compromisso: ", dias_no_mes[mes]);
  scanf("%d", &dia);

  // Validar a entrada do dia
  if (dia < 1 || dia > dias_no_mes[mes])
  {
    printf("Dia inserido inválido!\n");
    return;
  }

  // Calcular o índice no array de compromissos
  int indice = (mes - 1) * 31 + (dia - 1);

  // Verificar se já existem compromissos marcados para este dia, se houver retornar uma mensagem de erro
  if (compromissos[indice] >= 5)
  {
    printf("Desculpe, máximo de compromissos alcançado para este dia!\n");
    return;
  }

  printf("Digite a duração do tratamento (em dias): ");
  scanf("%d", &duracao);

  // Atualizar o array de compromissos para a duração especificada, caso exceda o ano, retornar uma mensagem de erro
  for (int i = 0; i < duracao; i++)
  {
    if (indice + i >= 12 * 31)
    {
      printf("Duração do tratamento excede o ano!\n");
      return;
    }
    compromissos[indice + i] += 1; // Incrementar contagem de compromissos para cada dia do tratamento e retornar uma mensagem de sucesso
  }

  printf("Compromisso agendado com sucesso!\n");
}
