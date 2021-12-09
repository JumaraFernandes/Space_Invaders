#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//estrutura do jogador
typedef struct jogador
{
	int x, y, pontos;
	char nome[50];
}Jogador;

//estrutura do inimigo
typedef struct inimigos
{
	int x, y;
}Inimigos;


//variavel auxiliar para controlar em qual sentido que muda
int muda = 1;

void Menu()
{
	printf("-----------------------------------------\n");
	printf("              Space Invaders             \n");
	printf("-----------------------------------------\n\n");
	printf("Escolha:\n");
	printf("  [1] -> Jogar \n  [2] -> Regras do Jogo \n  [3] -> Sair\n");
	printf("Sua Opção: ");
	int op;
	scanf("%d", &op);
	if(op == 1)
	{
		system("CLS");
		char nome[50];
		printf("Digite seu nome: ");
		scanf("%s", nome);
		printf("Seu nome e %s", nome);
	}
	else if(op == 2)
	{
		system("CLS");
		printf("Regras do jogo");
	}
	else
	{
		system("CLS");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("               FIM DO JOGO               \n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n\n\n\n");
	}
}

//função mostrar que mostra o inimigo e o jogador
void mostra(Jogador jogador, Inimigos inimigo[3][7], int tam, int compr, int larg, int alt)
{
	int i, j, c, k;
	for(i=0;i<tam;i++)
	{
		for(j=0;j<compr;j++)
		{
			int aux = 0;
			printf("| ");
			if(jogador.x == j && i == tam-1)
			{
				aux =1;
			}
			for(c = 0; c < alt; c++)
			{
				for(k = 0; k < larg; k++)
				{
					//se já estiver na posição do inimigo escreve um "*"
				if(j == inimigo[c][k].x && i == inimigo[c][k].y)
					{
						printf("*");
						//aux fica o valor de um para não colocar um espaço a mais
						aux = 1;
						//são do ciclo
						break;
					}
				}
			}
			//se não for a posição do inimigo escreva um " "
			if(aux == 0)
			{
				printf(" ");
			}
			//se for a posição do inimigo escreve um "O"
			if(jogador.x == j && i == tam-1)
			{
				printf("O");
			}
			printf(" ");
			//se for na ultima posição da linha escreve um "|"
			if(j == compr-1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}

//função que inicia a posição do inimigo e do jogador
void iniciar(Inimigos inimigo[3][7], Jogador jogador, int linha, int coluna,int larg, int compr) //inicia a posição do inimigo e do jogador
{
	int c, i, pos;
	for(c = 0; c < compr; c++)
	{
		for(i = 0; i < larg; i++)
		{
			//pos vai calcular a posição aonde que o inimigo vai ficar
			pos = ((linha-larg)/2+i);
			//cria um inimigo com a posição x e y
			Inimigos ini = {.x = pos, .y = c};
			//adiciona o inimigo na matriz de inimigo;
			inimigo[c][i] = ini;
		}
	}
	//iniciar posição do jogador no meio
	jogador.x = linha/2;
}
void mover(Inimigos inimigo[3][7], int linha, int coluna,int larg, int compr)
{
	int c, i, pos;
	//se o inimigo estiver na ultima columa muda o sentido, vira para a esquerda
	if(inimigo[0][6].x == 14)
	{
		muda = -1;
	}
	//se o inimigo estiver na primeira coluna muda o sentido, vira para e
	if(inimigo[0][0].x == 0)
	{
		muda = 1;
	}
	for(c = 0; c < compr; c++)
	{
		for(i = 0; i < larg; i++)
		{
			inimigo[c][i].x += muda;
		}
	}
}
int main(int argc, char *argv[]) {
	//declara a matriz de inimigo
	Inimigos ini[3][7];
	//declara o jogador
	Jogador j;
	j.x = 7;
	iniciar(&ini, j, 15, 15, 7, 3);
	while(1)//ciclo infinito
	{
		system("CLS");
		mostra(j, ini, 15, 15, 7, 3);
		mover(&ini, 15, 15, 7, 3);
		 if ( kbhit() ){
	        int key_code = getch();
			// do stuff depending on key_code
	        if (key_code==75)
	        {
	        	if(j.x != 0)
	        		j.x--;
			}	
	        else if (key_code==77)
	        {
	        	if(j.x != 14)
	        		j.x++;
			}
		}
	}
	return 0;
}
