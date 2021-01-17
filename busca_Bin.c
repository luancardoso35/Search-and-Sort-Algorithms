#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codigo[11];
} string;

void main()
{
    int contador();
    int busca_bin();

    int posicao;
    int tamanho;

    string chave;
    FILE* arq;
    char busca[11];
    printf("Insira o codigo a ser buscado: ");
    scanf("%s%*c", chave.codigo);

    for (int i = 1; i <= 5; i++)
    {
        char nomeArq[11];
        sprintf(nomeArq, "Ordenado_%d.txt", i);

        tamanho = contador(nomeArq);
        string codigos[tamanho+1];

        arq = fopen(nomeArq, "r");

        for (int j = 1; j <= tamanho; j++)
        {
            fscanf(arq, "%s%*c", codigos[j].codigo);
        }

        posicao = busca_bin(codigos, tamanho, chave.codigo);
        if (posicao > 0)
        {
            printf("O codigo foi encontrado no mes %i, na posicao %d.\n", i, posicao);
        } else {
            printf("O codigo nao foi encontrado no mes %i.\n", i);
        }

        fclose(arq);
    }
    system("pause");
}

int contador(char nome[])
{
    char x;
    int linhas = 0;
    FILE* arq;
    arq = fopen(nome, "r");
    
    while (!feof(arq))
    {
        x = fgetc(arq);
        if (x == '\n')
        {
            linhas++;
        }
    }

    fclose(arq);

    return linhas;
}

int busca_bin(string lista[], int nro, char busca[])
{
    int L = 0;
    int R = nro - 1;
    int m;

    while (L < R)
    {
        m = (L + R) / 2;
        if (strcmp (lista[m].codigo, busca) < 0)
        {
            L = m + 1;
        } else {
            R = m;
        }
    }

    if (strcmp (lista[R].codigo, busca) == 0)
    {
        return R;
    } else {
        return -1;
    }
}