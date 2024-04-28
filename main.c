int main(void){
  /*
  Espaço para colocar as funções criadas 
  */


  int escolha;
  do{
    printf("\n\n\t== FIOSIOGENDA ==\n");
    printf("SELECIONE ABAIXO UMA DAS OPÇÕES:\n\n");
    printf("1 - Mostrar Calendário\n");
    printf("2 - Agendar Tratamento\n");
    printf("3 - Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha){
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