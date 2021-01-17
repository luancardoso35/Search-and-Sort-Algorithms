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

void selecao();

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
        selecao(codigo, linhas);

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

void selecao(string lista[], int numero)
{
    string x;
    int indice_menor;

    for(int i = 1; i < numero; i++)
    {
        indice_menor = i;
        for( int j = i + 1; j <= numero; j++)
        {
            contadorComp++;
            if(strcmp(lista[j].string, lista[indice_menor].string) < 0)
            {
                indice_menor = j;
            }
        }
        x = lista[i];
        lista[i] = lista[indice_menor];
        lista[indice_menor] = x;
        contador_movimentacao = contador_movimentacao + 3;
    }
    
}
