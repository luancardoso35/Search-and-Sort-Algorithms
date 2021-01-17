#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define tamanhoMax 10

typedef struct  
{
    char string[11];
}string;


int contador();         //para contar o numero de linhas
void merge();
void mPass();
void mergeSort();

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
        mergeSort(codigo, linhas);

        fclose(arq);
        char nomeAux[11];
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
    fclose(arq);
    return linhas;
}

void merge(string lista[], int L, int h, int R, string c[])
{
    int i, j, k;
    i = L; 
    j = h + 1;
    k = L-1;
    while( i <= h && j <= R)
    {
        k++;
        contadorComp++;
        if(strcmp(lista[i].string, lista[j].string) < 0)
        {
            c[k] = lista[i];
            i++;
            contador_movimentacao++;
        } else
        {
            c[k] = lista[j];
            j++;
            contador_movimentacao++;
        }
    }
        while(i <= h)
        {
            k++;
            c[k] = lista[i];
            i++;
            contador_movimentacao++;
        }
        while(j <= R)
        {
            k++;
            c[k] = lista[j];
            j++;
            contador_movimentacao++;
        } 
}

void mPass(string lista[], int N, int p, string c[])
{
    int i = 1;
    while(i <= N-2*p+1)
    {     
        merge(lista, i, i+p-1, i+2*p-1, c);
        i = i + 2*p;
    }
    if((i+p-1) < N)
    {
        merge(lista, i, i+p-1, N, c);
    } else{
        for( int j = i; j <= N; j++)
        {
            c[j] = lista[j];
            contador_movimentacao++;
        }
    }
}

void mergeSort(string lista[], int N)
{
    int p = 1;
    string c[N + 1];   
    while(p < N)
    {
        mPass(lista, N, p, c);
        p = 2*p;
        mPass(c, N, p, lista);
        p = 2*p;
    }
}
