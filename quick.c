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
void qqsort();
void quicksort();

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
        quicksort(codigo, linhas);

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

void qqsort(string lista[], int L, int R)
{
    int i, j;
    string x, w;
    i = L;
    j = R;
    x = lista[(L+R)/2];
    do
    {
        contadorComp = contadorComp+2;
        while(strcmp(lista[i].string, x.string) < 0)
        {
            i++;
            contadorComp++;
        }
        while(strcmp(x.string, lista[j].string) < 0)
        {
            j--;
            contadorComp++;
        }
        if(i <= j)
        {
            w = lista[i];
            lista[i] = lista[j];
            lista[j] = w;
            i++;
            j--;
            contador_movimentacao = contador_movimentacao + 3;
        }
    } while (i<=j);
    if(L < j)
    {
        qqsort(lista, L, j);
    }
    if(i < R)
    {
        qqsort(lista, i , R);
    }  
}

void quicksort(string lista[], int N)
{
    qqsort(lista, 1, N);
}