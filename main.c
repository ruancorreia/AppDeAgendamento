#include <stdio.h>

int main()
{
  int menu = 1; 

  printf("== FISIOGENDA AGENDAMENTO INTELIGENTE ==\n");
  while (menu != 0) 
  {
    printf("Selecione uma opção para prosseguir:\n");
    printf("1 - Mostrar Calendário\n2 - Inserir Agendamento\n3 - Mostrar Calendário com agendamentos\n0 - Sair\n");


    scanf("%d", &menu);

    switch (menu) 
    {
    case 1:
      printf("Mostrar Calendário\n");
      break;
    case 2:
      printf("Inserir Agendamento\n");
      break;
    case 3:
      printf("Mostrar Calendário com agendamentos\n");
      break;
    case 0:
      printf("Saindo do programa\n");
      break;
    default:
      printf("Opção inválida\n");
      break;
    }
  }

  return 0;
}
