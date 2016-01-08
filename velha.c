#include <stdio.h>
#include <time.h>
 
#define DIM 3
#define ESPACO ' '
 
void inic(char s[DIM][DIM])
{
    int i, j;
 
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            s[i][j] = ESPACO;
        }
    }
}
 
void mostra(char s[DIM][DIM])
{
    int i, j;
    putchar('\n');
 
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf(" %c %c",s[i][j],j==DIM-1?' ':'|');
            if (j==DIM-1)
                if (i!=DIM-1)
                    printf("\n-----------");
                else
                    putchar('\n');
        }
        putchar('\n');
    }
}
 
int check(char s[DIM][DIM])
{
    if (s[0][0] == 'X' && s[0][1] == 'X' && s[0][2] == 'X' ||
        s[1][0] == 'X' && s[1][1] == 'X' && s[1][2] == 'X' ||
        s[2][0] == 'X' && s[2][1] == 'X' && s[2][2] == 'X' ||
        s[0][0] == 'X' && s[1][0] == 'X' && s[2][0] == 'X' ||
        s[0][1] == 'X' && s[1][1] == 'X' && s[2][1] == 'X' ||
        s[0][2] == 'X' && s[1][2] == 'X' && s[2][2] == 'X' ||
        s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X' ||
        s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X')
        return 1;
 
    if (s[0][0] == 'O' && s[0][1] == 'O' && s[0][2] == 'O' ||
        s[1][0] == 'O' && s[1][1] == 'O' && s[1][2] == 'O' ||
        s[2][0] == 'O' && s[2][1] == 'O' && s[2][2] == 'O' ||
        s[0][0] == 'O' && s[1][0] == 'O' && s[2][0] == 'O' ||
        s[0][1] == 'O' && s[1][1] == 'O' && s[2][1] == 'O' ||
        s[0][2] == 'O' && s[1][2] == 'O' && s[2][2] == 'O' ||
        s[0][0] == 'O' && s[1][1] == 'O' && s[2][2] == 'O' ||
        s[0][2] == 'O' && s[1][1] == 'O' && s[2][0] == 'O')
        return 2;
    else
        return 0;
}
 
void inic_random()
{
    long ultime;
    time(&ultime);
    srand((unsigned) ultime);
}
 
void clear()
{
    int linhas = 0;
    while (linhas < 40)
    {
        putchar('\n');
        linhas++;
    }
}
 
void jogar()
{
    int i, j, posx, posy, advx, advy, ocupada, empate = 0, jogadas = 0;
    char vet[DIM][DIM];
 
    inic(vet);
 
    while(1)
    {
        clear();
        mostra(vet);
        putchar('\n');
 
        while (check(vet) == 0)
        {
        advx = 1 + rand()%3; advy = 1 + rand()%3;
        printf("Digite o numero da COLUNA e LINHA (Ex.: %d %d): ", advx, advy); scanf("%d%d",&posx,&posy);
        posx--; posy--;
        advx = rand()%3; advy = rand()%3;
        ocupada = 0;
 
            if (vet[posx][posy] == ' ')
            {
                vet[posx][posy] = 'X';
                while (vet[advx][advy] != ' ' && jogadas < 4)
                {
                    advx = rand()%3; advy = rand()%3;
                }
                if (vet[advx][advy] == ' ')
                    vet[advx][advy] = 'O';
                jogadas++;
            }
            else
                ocupada = 1;
            if (jogadas == 5)
                break;
            clear();
            mostra(vet);
            if (ocupada)
                printf("\nCasa ocupada, tente novamente!\n");
            printf("\nJogadas feitas: %d\n\n",jogadas);
        }
        break;
    }
    clear();
    mostra(vet);
    if (check(vet) == 1)
        printf("\nFim do jogo!\n\nParabens, voce GANHOU!\n");
    if (check(vet) == 2)
        printf("\nFim do jogo!\n\nQue pena, voce PERDEU!\n");
    if (jogadas == 5 && check(vet) == 0)
        printf("\nFim do jogo!\n\nParece que deu EMPATE!\n");
}
 
void main()
{
    inic_random();
    jogar();
}
