/*
--------------------------------------------------------------------------------------------------------------
SysTICKET........: Sistema de venda de passagens
Desenvolvido por.: Alberto Primo - PA1713127 - Unidade Cremação - Belém-PA
Objetivo.........: Demonstrar o uso da linguagem C para fins acadêmicos do PIM IV UNIP 2017 / Segundo semestre
Data da criação..: Quinta, 31 de Agosto de 2017
Última alteração.: 02/10/2017
--------------------------------------------------------------------------------------------------------------
*/

//-> BIBLIOTECAS...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//-> NÚMERO MÁXIMO DE PASSAGENS...
#define MAX_LUGARES 26
//-> NÚMERO MÁXIMO DE GRATUIDADES...
#define MAX_GRATIS 2
//-> NÚMERO MÁXIMO DE MEIA PASSAGEM...
#define MAX_MEIA 24

//-> DECLARAÇÃO DE VARIÁVEIS...
char wtipo[3][30] = {"Inteira", "Meia passagem", "Gratuidade"};
float wvalor_passagem = 0;
      wsum_busao1 = 0;
      wsum_inteira1;
      wsum_meia1 = 0;

      wsum_busao2 = 0;
      wsum_inteira2;
      wsum_meia2 = 0;

int wmontamenu = 1; wmenu = 0; wbilhete = 0;
    wonibus = 0; wtipo_pass = 0;

    //-> ÔNIBUS 1...
    wtot_busao1 = 0;
    wtot_inteira1 = 0;
    wtot_gratis1 = 0;
    wtot_meia1 = 0;
    wpoltrona_busao1 = 0;

    //-> ÔNIBUS 2...
    wtot_busao2 = 0;
    wtot_inteira2 = 0;
    wtot_gratis2 = 0;
    wtot_meia2 = 0;
    wpoltrona_busao2 = 0;

    //-> NÚMERO MÁXIMO DE LUGARES
    wpoltronas_busao1[MAX_LUGARES];
    wpoltronas_busao2[MAX_LUGARES];

/*
------------------------------------------------------------------------------------------------------------------
Função..: main
Objetivo: método principal
------------------------------------------------------------------------------------------------------------------
*/
int main(){
   menuPrincipal();
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: menuPrincipal
Objetivo: montagem do menu principal
------------------------------------------------------------------------------------------------------------------
*/
void menuPrincipal(){
   wmontamenu = 1;
   wmenu      = 0;

   if (wmontamenu != 0){
      while (wmenu != 5){
         topoTela();

         //---------------
         //-> MENU...
         //---------------
         printf("\n");
         printf("\n[1] Tarifação");
         printf("\n[2] Venda de passagem");
         printf("\n[3] Relatório financeiro");
         printf("\n[4] Sair");
         printf("\n");
         printf("\nOpção-> ");
         scanf("%d", &wmenu);
         system("clear");

         switch (wmenu){
            //---------------
            //-> TARIFAÇÃO...
            //---------------
            case 1:
               wmontamenu = 0;
               wmenu = 5;
               tarifaPassagem();
               break;

            //-----------------------
            //-> VENDA DE PASSAGEM...
            //-----------------------
            case 2:
               topoTela();

               printf("\n");
               printf("\nVENDA DE PASSAGEM");
               printf("\n+--------+--------+---------+----------+------------+-----------+");
               printf("\n| CÓDIGO | ORIGEM | DESTINO | VALOR    | GRATUIDADE | ESTUDANTE |");
               printf("\n+--------+--------+---------+----------+------------+-----------+");
               printf("\n|  [1]   | Belém  | Salinas | R$ 30,55 | R$ 0,00    | R$ 15,27  |");
               printf("\n|  [2]   | Belém  | Marudá  | R$ 23,63 | R$ 0,00    | R$ 11,81  |");
               printf("\n+--------+--------+---------+----------+------------+-----------+");
               printf("\nOpção-> ");
               scanf("%d", &wonibus);

               switch (wonibus){
                  //----------------------
                  //-> BELÉM -> SALINAS...
                  //----------------------
                  case 1:
                     wtot_busao1++;
                     wbilhete++;

                     //-> TOTAL ATINGIDO DE PASSAGENS...
                     if (wtot_busao1 > MAX_LUGARES) {
                       	printf("\n* * * LIMITE DE PASSAGENS ESGOTADO * * *\n");
                       	break;
					 }
					 //-> TIPO DE PASSAGEM...
					 printf("\nTIPO DE PASSAGEM:");
					 printf("\n-----------------");
                     printf("\n[1] Inteira");
                     printf("\n[2] Meia passagem");
                     printf("\n[3] Gratuidade");
                     printf("\nOpção-> ");
                     scanf("%d", &wtipo_pass);

                     //-> INTEIRA...
                     if (wtipo_pass == 1){
                        wtot_inteira1++;
                        wvalor_passagem = 30.55;
                        wsum_inteira1 = wsum_inteira1 + wvalor_passagem;
                     }
                     //-> MEIA PASSAGEM...
                     if (wtipo_pass == 2){
                        wtot_meia1++;
                        wvalor_passagem = 15.27;
                        wsum_meia1 = wsum_meia1 + wvalor_passagem;
                     }
                     //-> GRATUIDADE...
                     if (wtipo_pass == 3){
                        wtot_gratis1++;
                        wvalor_passagem = 0;
                     }

                     if(wtot_gratis1 >= MAX_GRATIS){
                        printf("\n* * * LIMITE DE GRATUIDADE EXCEDIDO * * *\n");
                        break;
                     }

                     //-> ORIGEM / DESINO
                     printf("\nPOLTRONA:");
                     printf("\n--------");
                     printf("\nOpção-> ");
                     scanf("%d", &wpoltrona_busao1);

                     //-> VERIFICO SE A POLTRONA JÁ ESTÁ OCUPADA...
                     while (wpoltronas_busao1[wpoltrona_busao1] == 1) {
                        printf("\n* * * ESTA POLTRONA JÁ ESTÁ OCUPADA * * *\n");
                        printf("\nPOLTRONA:");
                        printf("\n--------");
                        printf("\nOpção-> ");
                        scanf("%d", &wpoltrona_busao1);
                     }

                     //-> POLTRONA...
                     wpoltronas_busao1[wpoltrona_busao1] = 1;

                     //-> TOTAL GERAL...
                     wsum_busao1 = wsum_inteira1 + wsum_meia1;

                     //-> IMPRESSÃO DO COMPROVANTE...
                     imprimeComprovante(wpoltrona_busao1,"Salinas", wbilhete, wtipo[wtipo_pass-1]);

                     break;

                  //---------------------
                  //-> BELÉM -> MARUDÁ...
                  //---------------------
                  case 2:
                     wtot_busao2++;
                     wbilhete++;

                     //-> TOTAL ATINGIDO DE PASSAGENS...
                     if (wtot_busao2 > MAX_LUGARES) {
                       	printf("\n* * * LIMITE DE PASSAGENS ESGOTADO * * *\n");
                       	break;
					 }
					 //-> TIPO DE PASSAGEM...
					 printf("\nTIPO DE PASSAGEM:");
					 printf("\n-----------------");
                     printf("\n[1] Inteira");
                     printf("\n[2] Meia passagem");
                     printf("\n[3] Gratuidade");
                     printf("\nOpção-> ");
                     scanf("%d", &wtipo_pass);

                     //-> INTEIRA...
                     if (wtipo_pass == 1){
                        wtot_inteira2++;
                        wvalor_passagem = 23.63;
                        wsum_inteira2 = wsum_inteira1 + wvalor_passagem;
                     }
                     //-> MEIA PASSAGEM...
                     if (wtipo_pass == 2){
                        wtot_meia2++;
                        wvalor_passagem = 11.81;
                        wsum_meia2 = wsum_meia1 + wvalor_passagem;
                     }
                     //-> GRATUIDADE...
                     if (wtipo_pass == 3){
                        wtot_gratis2++;
                        wvalor_passagem = 0;
                     }

                     if(wtot_gratis2 >= MAX_GRATIS){
                        printf("\n* * * LIMITE DE GRATUIDADE EXCEDIDO * * *\n");
                        break;
                     }

                     //-> ORIGEM / DESINO
                     printf("\nPOLTRONA:");
                     printf("\n--------");
                     printf("\nOpção-> ");
                     scanf("%d", &wpoltrona_busao2);

                     //-> VERIFICO SE A POLTRONA JÁ ESTÁ OCUPADA...
                     while (wpoltronas_busao2[wpoltrona_busao2] == 1) {
                        printf("\n* * * ESTA POLTRONA JÁ ESTÁ OCUPADA * * *\n");
                        printf("\nPOLTRONA:");
                        printf("\n--------");
                        printf("\nOpção-> ");
                        scanf("%d", &wpoltrona_busao1);
                     }

                     //-> POLTRONA...
                     wpoltronas_busao2[wpoltrona_busao2] = 1;

                     //-> TOTAL GERAL...
                     wsum_busao2 = wsum_inteira2 + wsum_meia2;

                     //-> IMPRESSÃO DO COMPROVANTE...
                     imprimeComprovante(wpoltrona_busao2,"Marudá", wbilhete, wtipo[wtipo_pass-1]);

                     break;
               }

               break;

            case 3:
               relatorioFinanceiro(wsum_inteira1);
               break;

            //-> SAIR...
            case 4:
               sairSistema();
               break;

            default:
               opcaoValida();
               break;
         }
      }
   }
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: menuVolta
Objetivo: monta o menu secundário
------------------------------------------------------------------------------------------------------------------
*/
void menuVolta(){
   int menuvolta = 0;

   while (menuvolta != 2){
      printf("\n");
      printf("--------------------------------------------------------------------------------");
      printf("\n[1] Voltar para o menu principal");
      printf("\n[2] Sair do sistema");
      printf("\n");
      printf("\nOpção-> ");
      scanf("%d", &menuvolta);
      system("clear");

      switch (menuvolta){
         //-> VOLTA PARA O MENU PRINCIPAL...
         case 1:
            menuPrincipal();
            break;

         //-> SAIR...
         case 2:
            sairSistema();
            break;

         default:
            opcaoValida();
            break;
      }
   }
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: relatorioFinanceiro
Objetivo: Relatório analítico financeiro
------------------------------------------------------------------------------------------------------------------
*/
void relatorioFinanceiro(){
   int menuvoltafin = 0;

   system("clear");
   topoTela();

   //-> VALOR TOTAL DOS ÔNIBUS...
   float wvaltot_busao1 = ( (wtot_meia1 * 15.27) + (wtot_inteira1 * 30.55) );
   float wvaltot_busao2 = ( (wtot_meia2 * 11.81) + (wtot_inteira2 * 23.63) );

   while (menuvoltafin != 4){
      printf("\n");
      printf("\n[1] Relatório financeiro BELÉM - SALINAS");
      printf("\n[2] Relatório financeiro BELÉM - MARUDÁ");
      printf("\n[3] Voltar para o menu principal");
      printf("\n[4] Sair do sistema");
      printf("\n");
      printf("\nOpção-> ");
      scanf("%d", &menuvoltafin);
      system("clear");

      switch (menuvoltafin){
         //-> SALINAS...
         case 1:
            printf("\n");
            printf("\nRELATÓRIO FINANCEIRO ONIBUS 01 - Belém/Salinas");
            printf("\n");
            printf("\n===========[ CONTAGEM ]===========");
            printf("\nInteiras..........: %d", wtot_inteira1);
            printf("\nMeia..............: %d", wtot_meia1);
            printf("\nGratuidade........: %d", wtot_gratis1);
            printf("\nPassagens vendidas: %d", wtot_inteira1+wtot_meia1+wtot_gratis1);
            printf("\n");
            printf("\n==========[ ARRECADADO ]==========");
            printf("\nTOTAL INTEIRA.....: %.2f", wtot_inteira1 * 30.55);
            printf("\nTOTA MEIA.........: %.2f", wtot_meia1 * 15.27);
            printf("\nTOTAL ARRECADADO..: %.2f", wvaltot_busao1);
            printf("\n");

            menuVolta();
            break;

         //-> MARUDÁ...
         case 2:
            printf("\n");
            printf("\nRELATÓRIO FINANCEIRO ONIBUS 01 - Belém/Marudá");
            printf("\n");
            printf("\n===========[ CONTAGEM ]===========");
            printf("\nInteiras..........: %d", wtot_inteira2);
            printf("\nMeia..............: %d", wtot_meia2);
            printf("\nGratuidade........: %d", wtot_gratis2);
            printf("\nPassagens vendidas: %d", wtot_inteira2+wtot_meia2+wtot_gratis2);
            printf("\n");
            printf("\n==========[ ARRECADADO ]==========");
            printf("\nTOTAL INTEIRA.....: %.2f", wtot_inteira2 * 23.63);
            printf("\nTOTA MEIA.........: %.2f", wtot_meia2 * 11.81);
            printf("\nTOTAL ARRECADADO..: %.2f", wvaltot_busao2);
            printf("\n");

            menuVolta();
            break;

         //-> VOLTA PARA O MENU PRINCIPAL...
         case 3:
            menuPrincipal();
            break;

         //-> SAIR...
         case 4:
            sairSistema();
            break;

         default:
            opcaoValida();
            break;
      }
   }
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: imprimeComprovante
Objetivo: Impressão do comprovante de embarque
------------------------------------------------------------------------------------------------------------------
*/
void imprimeComprovante(int wimp_poltrona, char wimp_des[20], int wimp_bilhete,
                        char wimp_tipo[20], float wimp_valor){

   float wtaxa = 0;

   printf("\n             ADS UNIP TRANSPORTES ");
   printf("\n            Rua dos Alfeneiros,303 ");
   printf("\n           CNPJ: 31.313.313/0001-31 ");
   printf("\n-------------------------------------------------");
   printf("\n           COMPROVANTE DE EMBARQUE ");
   printf("\n-------------------------------------------------");
   printf("\nData: %s - Hora: %s - Controle: %i",__DATE__,__TIME__,wimp_bilhete);
   printf("\nOrigem..: Belém   -   Destino.: %s",wimp_des);
   printf("\nPoltrona....: %i", wimp_poltrona);
   printf("\nTipo........: %s", wimp_tipo);
   printf("\nTarifa......: %.2f", wvalor_passagem);

   //-> APLICAÇÃO DE TAXA...
   if (wvalor_passagem > 0){
      wtaxa = 1.65;
   }

   printf("\nTx. Embarque: %.2f", wtaxa);
   printf("\nVALOR TOTAL.: %.2f", wvalor_passagem + wtaxa);
   printf("\n-------------------------------------------------");
   printf("\nÉ obrigatório a apresentação deste cupom e do");
   printf("\nbilhete de passagem para embarcar ou remarcar");
   printf("\nnova viagem. Aceito com documento com foto.");

   printf("\n");

   menuVolta();
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: sairSistema
Objetivo: Sair do sistema
------------------------------------------------------------------------------------------------------------------
*/
void sairSistema(){
   system("clear");
   printf("\n================================");
   printf("\nOBRIGADO POR UTILIZAR O SISTEMA.");
   printf("\n================================\n");
   exit(0);
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: opcaoValida
Objetivo: Opção inválida nos menus
------------------------------------------------------------------------------------------------------------------
*/
void opcaoValida(){
   system("clear");
   printf("\n==================================");
   printf("\nPOR FAVOR, DIGITE UMA OPÇÃO VÁLIDA");
   printf("\n==================================\n");
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: topoTela
Objetivo: monta o topo da tela
------------------------------------------------------------------------------------------------------------------
*/
void topoTela(){
   printf("+------------------------------------------------------------------------------+");
   printf("\n|          SysTICKET - Sistema de venda de passagens (Versão 1.0)              |");
   printf("\n|                            ADS UNIP TRANSPORTES                              |");
   printf("\n+------------------------------------------------------------------------------+");
}

/*
------------------------------------------------------------------------------------------------------------------
Função..: tarifaPassagem
Objetivo: Listagem de tarifação
------------------------------------------------------------------------------------------------------------------
*/
void tarifaPassagem(){
   wmontamenu = 0;
   system("clear");
   topoTela();
   printf("\n");
   printf("\nTarifas de passagem:");
   printf("\n+--------+---------+----------+------------+-----------+");
   printf("\n| ORIGEM | DESTINO | VALOR    | GRATUIDADE | ESTUDANTE |");
   printf("\n+--------+---------+----------+------------+-----------+");
   printf("\n| Belém  | Cametá  | R$ 39,60 | R$ 0,00    | R$ 19,80  |");
   printf("\n| Belém  | Marudá  | R$ 23,63 | R$ 0,00    | R$ 11,81  |");
   printf("\n+--------+---------+----------+------------+-----------+");
   printf("\n");
   printf("\nObservações:");
   printf("\n- Somente 2 passagem em gratuidade por ônibus;");
   printf("\n- Estudantes pagam meia com documento comprobatório;");
   printf("\n");

   //-> MENU DE VOLTA...
   menuVolta();
}
