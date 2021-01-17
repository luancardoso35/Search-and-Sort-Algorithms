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
void heapify();
void heapSort();

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
        heapSort(codigo, linhas);

        fclose(arq);
        //Cria arquivo ordenado:
        char nomeAux[10];
        sprintf(nomeAux , "Ordenado_%d.txt", i);
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

void heapify(string lista[], int L, int R)
{
    int i = L;
    int j = 2*L;
    string x = lista[L];
    contador_movimentacao++;

    contadorComp++;
    if((j<R) && (strcmp(lista[j].string , lista[j+1].string)<0))
    {
        j++;
    }

    contadorComp++;
    while((j<=R) && (strcmp(x.string, lista[j].string)<0))
    {
        contadorComp++;
        contador_movimentacao++;
        lista[i] = lista[j];
        i = j;
        j = 2*j;
        contadorComp++;
        if((j<R) && (strcmp(lista[j].string, lista[j+1].string)<0))
        {
            j++;
        }
    }
    lista[i] = x;
    contador_movimentacao++;
}

void heapSort(string lista[], int numero)
{
    string x;
    for(int L = (numero/2); L >= 1; L--)
    {
        heapify(lista, L, numero);
    }
    for(int R = numero; R >=2; R--)
    {
        x = lista[1];
        lista[1] = lista[R];
        lista[R] = x;
        heapify(lista, 1, R-1);
        contador_movimentacao += 3;
    }
}