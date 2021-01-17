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
void insercaoBin();

int contadorComp = 0;
int contadorMov =0;

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
        
        //coloca o alg de ordenaçaõ aqui
        insercaoBin(codigo, linhas);
    
        fclose(arq);
        //escreve o ordenado
        char nomeAux[10];
        sprintf(nomeAux, "Ordenado_%d.txt", i);
        aux = fopen(nomeAux, "w");
        
        for( int i = 1; i <= linhas; i++)
        {
            fprintf(aux,"%s\n", codigo[i].string); 
        }
        fclose(aux);
          fclose(arq);
        printf("\nComparacoes: %d\nMovimentacoes: %d\nCodigos: %d\n", contadorComp, contadorMov, linhas);
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

void insercaoBin(string lista[], int numero)
{
    string x;
    int l, r, m, j;
    for (int i = 2; i < numero; i++)
    {
        x =  lista[i];
        contadorMov++;
        l = 1;
        r = i;
        while(l < r)
        {
            m = (l+r)/2;
            contadorComp++;
            if(strcmp(lista[m].string, x.string)<=0)
            {
                l = m+1;
            }else
            {
                r = m;
            }            
        }
        j = i;
        while(j > r)
        {
            lista[j] = lista[j-1];
            j = j-1;
            contadorMov++;
        }
        lista[r] = x;   
        contadorMov++;
    }
}