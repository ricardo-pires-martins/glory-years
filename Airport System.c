//IST - TAGUSPARK
//PROJETO 1 IAED

//Ricardo Oliveira, 84759
//Ricardo Martins, 84761

////////////////////////////////////
//        BIBLIOTECAS             //
////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////////////////////////////////////
//        ESTRUTURAS              //
////////////////////////////////////

typedef struct aeroporto {

	char id[4];
	int  capacidade;
	int  estado;

} AEROPORTO;

typedef struct lista_voos {

	int voos;
	int aeros;

} LST_VOO;

////////////////////////////////////
//          VARIAVEIS             //
////////////////////////////////////

#define MAX 1000

AEROPORTO aero[MAX]; // vetor de indices
int matriz[MAX][MAX]; // matriz dos voos
LST_VOO nvoos[MAX];

int N_AEROPORTOS = 0;

////////////////////////////////////
//          PROTOTIPOS            //
////////////////////////////////////

void adiciona_aero(void); //done
void encerra_aero(void); //done
void adiciona_voo_ida_volta(void); //done
void adiciona_rota(void); //done
void altera_capacidade(void); //done
void listagem_aero(void);
void numero_voos(void); //done
void reabre_aero(void); //done
void aero_mais_voos(void);//done
void aero_mais_conectado(void);//done
void remove_voo(void); //done
void remove_voo_ida_volta(void); //done
void popularidade_voo(void); //done
void saida(void); //done
int numero_voos_aeroporto_partida(int index); //done
int numero_voos_aeroporto_chegada(int index); //done
int get_index(char id[]); //done
int conexoes(int index);//done

//////////////////////////////
//			CODIGO			//
//////////////////////////////

int main() {

	char cmd;
	while (1) {
		printf("Introduza um comando (X para sair) : ");
		cmd = getchar();
		switch (cmd) {
			case 'A': adiciona_aero(); break;
			case 'C': encerra_aero(); break;
			case 'F': adiciona_voo_ida_volta(); break;
			case 'G': adiciona_rota(); break;
			case 'I': altera_capacidade(); break;
			case 'L': listagem_aero(); break;
			case 'N': numero_voos(); break;
			case 'O': reabre_aero(); break;
			case 'P': aero_mais_voos(); break;
			case 'Q': aero_mais_conectado(); break;
			case 'R': remove_voo(); break;
			case 'S': remove_voo_ida_volta(); break;
			case 'V': popularidade_voo(); break;
			case 'X': 
				saida();
				return EXIT_SUCCESS;
				break;
			default: printf("*Comando Invalido");
		}
		getchar();
	}
	return EXIT_FAILURE;
}

//////////////////////////////////////////
//			FUNCOES AUXILIARES			//
//////////////////////////////////////////

/*
	get_index :
		devolve o indice do vector de aeroportos cujo identificador
		é passado como parametro
	parametros :
		id - identificador de aeroporto
	retorna  :
		um inteiro que representa um indice do vector de aeroportos
		caso não exista o identificador devolve -1
*/
int get_index(char id[]) { //corrigida

	int i;

	for (i = 0; i < N_AEROPORTOS; i++) {

		if (strcmp(id, aero[i].id) == 0)
			return i;
	}

	return -1;
}

/*
	numero_voos_aeroporto_partida :
		devolve o numero de voos que partem de um aeroporto
	parametros:
		indice do aeroportos
	retorna:
		numero de voos de partida
*/
int numero_voos_aeroporto_partida(int index) { //corrigida

	int i, soma = 0;

	for (i = 0; i < N_AEROPORTOS; i++)
		soma += matriz[index][i];

	return soma;
}

/*
	numero_voos_aeroporto_chegada :
		devolve o numero de voos que chegam a um aeroporto
	parametros:
		indice do aeroporto
	retorna:
		numero de voos de chegada
*/
int numero_voos_aeroporto_chegada(int index) { //corrigida

	int i, soma = 0;

	for (i = 0; i < N_AEROPORTOS; i++)
		soma += matriz[i][index];

	return soma;
}

/*
	conexoes : 
		devolve o numero de ligacoes de um aeroporto
	parametros:
		indice do aeroporto
	retorna:
		numero de ligacoes
		
*/
int conexoes(int index) {

	int soma = 0, i;

	for (i = 0; i < N_AEROPORTOS; i++) {

		if (matriz[index][i] > 0)
			soma++;
		else {
			if (matriz[i][index] > 0)
				soma++;
		}
	}

	return soma;
}

//////////////////////////////////
//			COMANDOS			//
//////////////////////////////////

void adiciona_aero(void) { //corrigida

	char id[4];
	int capacidade, index;

	scanf(" %s %d", id, &capacidade);
	index = N_AEROPORTOS; // proximo indice

	if (capacidade > 0) {
		strcpy(aero[index].id, strcat(id, "\0"));
		aero[index].capacidade = capacidade;
		aero[index].estado = 1;
		N_AEROPORTOS++;
	}
}

void encerra_aero(void) { //corrigida

	char id[4];
	int index, i, j;

	scanf(" %s", id);

	index = get_index(id);

	if (index == -1)

		printf("*Aeroporto %s inexistente", id);

	else {

		aero[index].estado = 0;

		for (i = 0; i < N_AEROPORTOS; i++) {
			for (j = 0; j < N_AEROPORTOS; j++) {

				matriz[i][j] = 0;
				matriz[j][i] = 0;
			}
		}
	}
}

void adiciona_voo_ida_volta(void) { //corrigida

	char id_partida[4], id_chegada[4];
	int  index_partida, index_chegada;

	scanf(" %s %s", id_partida, id_chegada);

	index_partida = get_index(id_partida);
	index_chegada = get_index(id_chegada);

	if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && numero_voos_aeroporto_chegada(index_partida) + numero_voos_aeroporto_partida(index_partida) + 2 <= aero[index_partida].capacidade && numero_voos_aeroporto_chegada(index_chegada) + numero_voos_aeroporto_partida(index_chegada) + 2 <= aero[index_chegada].capacidade) {
		matriz[index_partida][index_chegada] += 1;
		matriz[index_chegada][index_partida] += 1;
	}
	else
		printf("*Impossivel adicionar voo RT %s %s", id_partida, id_chegada);
}

void adiciona_rota(void) { //corrigida

	char id_partida[4], id_chegada[4];
	int index_partida, index_chegada, capacidade_partida, capacidade_chegada;

	scanf(" %s %s", id_partida, id_chegada);

	index_partida = get_index(id_partida);
	index_chegada = get_index(id_chegada);

	capacidade_partida = aero[index_partida].capacidade - numero_voos_aeroporto_chegada(index_partida); // verifica a capacidade atual para voos de partida do aeroporto de partida
	capacidade_chegada = aero[index_chegada].capacidade - numero_voos_aeroporto_partida(index_chegada); // verifica a capacidade atual para voos de chegada do aeroporto de chegada

	if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && numero_voos_aeroporto_partida(index_partida) + 1 <= capacidade_partida && numero_voos_aeroporto_chegada(index_chegada) + 1 <= capacidade_chegada)
		matriz[index_partida][index_chegada] += 1;
	else
		printf("*Impossivel adicionar voo %s %s", id_partida, id_chegada);
}

void altera_capacidade(void) { //corrigida

	char id[4];
	int index, nova_capacidade;

	scanf(" %s %d", id, &nova_capacidade);

	index = get_index(id);

	if (index == -1 || aero[index].estado == 0 || aero[index].capacidade + nova_capacidade < numero_voos_aeroporto_partida(index) + numero_voos_aeroporto_chegada(index))
		printf("*Capacidade de %s inalterada", id);
	else
		aero[index].capacidade += nova_capacidade;
}

void listagem_aero(void) {

	int variavel, i;


	scanf(" %d", &variavel);

	switch (variavel) {

	case 0:

		for (i = 0; i < N_AEROPORTOS; i++)

			printf("%s:%d:%d:%d\n", aero[i].id, aero[i].capacidade, numero_voos_aeroporto_partida(i), numero_voos_aeroporto_chegada(i)); break;

	case 1:

		int v[MAX], i, j;

		for (i = 0; i < N_AEROPORTOS; i++) {

			int min = i;

			for (j = i + 1; j < N_AEROPORTOS; j++) {

				if (strcmp(aero[min].id, aero[j].id) > 0)

					min = j;
			}

			v[i] = min;
		}

		for (i = 0; i < N_AEROPORTOS; i++) {

			printf("%s:%d:%d:%d\n", aero[v[i]].id, aero[v[i]].capacidade, numero_voos_aeroporto_partida(v[i]), numero_voos_aeroporto_chegada(v[i]));
		}

	case 2:

		for (i = 0; i < MAX; i++) {

			nvoos[i].voos = numero_voos_aeroporto_partida(i) + numero_voos_aeroporto_chegada(i);
			nvoos[i].aeros += 1;

			for (j = 0; j < MAX; j++) {

				if (nvoos[i].voos == nvoos[j].voos) {

					nvoos[j].voos = -1;
					nvoos[i].aeros += nvoos[j].aeros;
				}

				printf("%d:%d\n", nvoos[i].voos, nvoos[i].aeros);
			}
		}
	}
}

void numero_voos(void) { //corrigida

	char id_partida[4], id_chegada[4];
	int index_partida, index_chegada, voos_partida, voos_chegada;

	scanf(" %s %s", id_partida, id_chegada);

	index_partida = get_index(id_partida);
	index_chegada = get_index(id_chegada);

	if (index_partida == -1) {
		printf("*Aeroporto %s inexistente", id_partida);
	}

	else if (index_chegada == -1) {
		printf("*Aeroporto %s inexistente", id_chegada);
	}

	else if (index_partida == -1 && index_chegada == -1) {
		printf("*Aeroporto %s inexistente /n *Aeroporto %s inexistente", id_partida, id_chegada);
	}

	else {
		voos_chegada = matriz[index_partida][index_chegada];
		voos_partida = matriz[index_chegada][index_partida];

		printf("%d:%d", voos_partida, voos_chegada);
	}
}

void reabre_aero() { //corrigida

	int index;
	char id[4];

	scanf(" %s", id);

	index = get_index(id);

	if (index == -1)
		printf("*Aeroporto %s inexistente", id);
	else
		aero[index].estado = 1;
}

void aero_mais_voos(void) { //corrigida

	int i, variavel, max_index, max = numero_voos_aeroporto_partida(0) + numero_voos_aeroporto_chegada(0);

	for (i = 1; i < N_AEROPORTOS; i++) {

		variavel = numero_voos_aeroporto_partida(i) + numero_voos_aeroporto_chegada(i);

		if (variavel > max) {

			max = variavel;

			max_index = i;
		}
	}

	printf(" Aeroporto com mais rotas %s:%d:%d", aero[max_index].id, numero_voos_aeroporto_partida(max_index), numero_voos_aeroporto_partida(max_index));
}

void aero_mais_conectado(void) { //corrigida

	int i, max = 0;

	for (i = 0; i < N_AEROPORTOS; i++) {

		if (conexoes(i) > conexoes(max))
			max = i;
	}

	printf(" Aeroporto com mais ligações %s:%d", aero[max].id, conexoes(max));
}

void remove_voo(void) { //corrigida

	char id_partida[4], id_chegada[4];
	int index_partida, index_chegada;

	scanf(" %s %s", id_partida, id_chegada);

	index_partida = get_index(id_partida);
	index_chegada = get_index(id_chegada);

	if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && matriz[index_partida][index_chegada] > 0)
		matriz[index_partida][index_chegada] -= 1;
	else
		printf("*Impossivel remover voo %s %s", id_partida, id_chegada);
}

void remove_voo_ida_volta(void) { //corrigida

	char id_partida[4], id_chegada[4];
	int index_partida, index_chegada;

	scanf(" %s %s", id_partida, id_chegada);

	index_partida = get_index(id_partida);
	index_chegada = get_index(id_chegada);

	if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && matriz[index_partida][index_chegada] > 0 && matriz[index_chegada][index_partida > 0]) {
		matriz[index_partida][index_chegada] -= 1;
		matriz[index_chegada][index_partida] -= 1;
	}
	else
		printf("*Impossivel remover voo RT %s %s", id_partida, id_chegada);
}

void popularidade_voo(void) { //corrigida

	int i, j, max_partidas, max_chegadas, aero_partidas, aero_chegadas;

	max_partidas = 0;
	max_chegadas = 0;

	for (i = 0; i < N_AEROPORTOS; i++) {
		if (numero_voos_aeroporto_partida(i) > max_partidas) {
			max_partidas += numero_voos_aeroporto_partida(i);
			aero_partidas = i;
		}
	}

	for (j = 0; j < N_AEROPORTOS; j++) {
		if (numero_voos_aeroporto_chegada(j) > max_chegadas) {
			max_chegadas += numero_voos_aeroporto_chegada(j);
			aero_chegadas = j;
		}
	}

	printf("%s:%s:%d:%d\n", aero[aero_partidas].id, aero[aero_chegadas].id, numero_voos_aeroporto_partida(i), numero_voos_aeroporto_chegada(j));
}

void saida(void) {

	int i, j, numero_voos = 0, numero_aero_abertos = 0;

	for (i = 0; i < N_AEROPORTOS; i++) {

		if (aero[i].estado == 1)

			numero_aero_abertos += 1;
	}

	for (i = 0; i < N_AEROPORTOS; i++) {

		for (j = 0; j < N_AEROPORTOS; j++) {

			numero_voos += matriz[i][j];
		}
	}

	printf("%d:%d", numero_aero_abertos, numero_voos);
}
