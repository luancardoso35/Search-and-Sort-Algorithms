#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define tamanhoMax 10

typedef struct  
{
    char string[11];
}string;

//para contar o numero de linhas
int contador();
void insercao();

int contador_movimentacao = 0;
int contadorComp = 0;

void main ()
{
    FILE *arq;
    FILE *aux;
    for(int i = 1; i <= 5; i++)
    {
        //essa tres linhas são para converter int em string
        char nomeArq[10];
        sprintf(nomeArq , "mes_%d.txt", i); 
        printf("%s", nomeArq);
        
        int linhas = contador(nomeArq);
        arq = fopen(nomeArq, "r");
        string codigo[linhas + 1];

        for(int i = 1; i <= linhas; i++)
        {
            fscanf(arq, "%s%*c", codigo[i].string);
        }
        
        //coloca o alg de ordenação aqui
        insercao(codigo, linhas);

        fclose(arq);
        char nomeAux[10];
        sprintf(nomeAux, "Ordenado_%d.txt", i);
        aux = fopen(nomeAux, "w");
        
        for( int i = 1; i <= linhas; i++)
        {
            fprintf(aux,"%s\n", codigo[i].string); 
        }
        fclose(aux);
        printf("\nComparacoes: %d\nMovimentacoes: %d\nCodigos: %d\n", contadorComp, contador_movimentacao, linhas);
    }



}

int contador(char *nome)
{                                   
    FILE *arq = fopen(nome,"r");
    int linhas = 0;
    char ch;
    while(!feof(arq))
    {
        ch = fgetc(arq);
        if(ch == '\n')
        {   
            linhas++;
        }
    }
    return linhas;
}

void insercao(string lista[], int numero)
{
    string x;
    int j;
    for (int i = 2; i < numero; i++)
    {
        x =  lista[i];
        lista[0] =  x;
        j = i;
        contador_movimentacao = contador_movimentacao + 2;
        contadorComp++;
        while( strcmp(x.string, lista[j-1].string) < 0)
        {
            contadorComp++;
            lista[j] = lista[j-1];
            j = j - 1;
            contador_movimentacao++;
        }
        lista[j]= x;
        contador_movimentacao++;
    }
}