#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "factorial.h"
#include "fibonacci.h"

// definicoes de operacoes a serem testadas
#define OPFACTORIALITERATIVE 1
#define OPFACTORIALRECURSIVE 2
#define OPFIBONACCIITERATIVE 3
#define OPFIBONACCIRECURSIVE 4

// variaveis globais para opcoes
static int opescolhida;
int optin;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"matop\n");
  fprintf(stderr,"\t-i \t(iterative factorial) \n");
  fprintf(stderr,"\t-j \t(recursive factorial) \n");
  fprintf(stderr,"\t-k \t(iterative fibonacci)\n");
  fprintf(stderr,"\t-s \t(recursive fibonacci)\n");
  fprintf(stderr,"\t-n <int>\t(chosen index)\n");
}


void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: opescolhida
{
    extern char * optarg;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opescolhida = -1;
     optin = -1;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "ijksm:p:n:lh")) != EOF){
       switch(c) {
        case 'i':
          opescolhida = OPFACTORIALITERATIVE;
          break;
        case 'j':
          opescolhida = OPFACTORIALRECURSIVE;
          break;
        case 'k':
          opescolhida = OPFIBONACCIITERATIVE;
          break;
        case 's':
          opescolhida = OPFIBONACCIRECURSIVE;
          break;
        case 'n': 
          optin = atoi(optarg);
          break;
        case 'h':
        default:
          uso();
          exit(1);
       }
     }
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao das operacoes definidas 
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{

  // avaliar linha de comando
  parse_args(argc,argv);

  // execucao dependente da operacao escolhida
    switch (opescolhida){
        case OPFACTORIALITERATIVE:
            printf("%d\n", recursiveFactorial(optin));
            break;
        case OPFACTORIALRECURSIVE:
            printf("%d\n", recursiveFactorial(optin));
            break;
        case OPFIBONACCIITERATIVE:
            printf("%d\n", iterativeFibonacci(optin));
            break;
        case OPFIBONACCIRECURSIVE:
            printf("%d\n", recursiveFibonacci(optin));
            break;
        default:
            // nao deve ser executado, pois ha um erroAssert em parse_args
            uso();
        exit(1);
    }

  // conclui registro de acesso
  return 0;
}

