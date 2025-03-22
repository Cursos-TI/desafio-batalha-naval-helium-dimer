#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define NAVIO 3
#define ATINGIDO 1
#define AGUA 0

int tabuleiro[TAMANHO][TAMANHO];

void inicializarTabuleiro() 
{
    for (int i = 0; i < TAMANHO; i++) 
    {
        for (int j = 0; j < TAMANHO; j++) 
        {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavio(int x, int y, int tamanho, char direcao) 
{
    for (int i = 0; i < tamanho; i++) 
    {
        if (direcao == 'H') 
        {
            tabuleiro[x][y + i] = NAVIO;
        } 
        else if (direcao == 'V') 
        {
            tabuleiro[x + i][y] = NAVIO;
        } 
        else if (direcao == 'D') 
        {
            tabuleiro[x + i][y + i] = NAVIO;
        }
    }
}

void exibirTabuleiro() 
{
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) 
    {
        for (int j = 0; j < TAMANHO; j++) 
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(char tipo, int x, int y) 
{
    int impacto[TAMANHO][TAMANHO] = {0};
    
    if (tipo == 'C') 
    {
        for (int i = 0; i < TAMANHO; i++) 
        {
            impacto[x][i] = ATINGIDO;
            impacto[i][y] = ATINGIDO;
        }
    } 
    else if (tipo == 'O') 
    {
        if (x > 0) impacto[x-1][y] = ATINGIDO;
        if (x < TAMANHO-1) impacto[x+1][y] = ATINGIDO;
        if (y > 0) impacto[x][y-1] = ATINGIDO;
        if (y < TAMANHO-1) impacto[x][y+1] = ATINGIDO;
    } 
    else if (tipo == 'N') 
    {
        if (x > 0) impacto[x-1][y] = ATINGIDO;
        if (x > 1) impacto[x-2][y] = ATINGIDO;
        if (y > 0 && x > 0) impacto[x-1][y-1] = ATINGIDO;
        if (y < TAMANHO-1 && x > 0) impacto[x-1][y+1] = ATINGIDO;
    }
    
    printf("\nHabilidade aplicada (%c) no ponto (%d, %d):\n", tipo, x, y);
    for (int i = 0; i < TAMANHO; i++) 
    {
        for (int j = 0; j < TAMANHO; j++) 
        {
            printf("%d ", impacto[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    srand(time(NULL));
    inicializarTabuleiro();
    
    posicionarNavio(2, 2, 4, 'H');
    posicionarNavio(5, 3, 3, 'V');
    posicionarNavio(1, 1, 3, 'D');
    posicionarNavio(6, 6, 2, 'D');
    
    exibirTabuleiro();
    
    aplicarHabilidade('C', 5, 5);
    aplicarHabilidade('O', 3, 3);
    aplicarHabilidade('N', 7, 7);
    
    return 0;
}
