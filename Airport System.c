//IST - TAGUSPARK
//PROJETO 1 IAED

//Ricardo Oliveira, 84759
//Ricardo Martins, 84761

//        BIBLIOTECAS             //

#include <stdio.h>
#include <string.h>

//        ESTRUTURAS              //

typedef struct aeroporto {

    char id[4];
    int  capacidade;
    int  estado;

} AEROPORTO;

//          VARIAVEIS             //

#define MAX 1000

AEROPORTO aero[MAX]; // vetor de indices
int matriz [MAX][MAX]; // matriz dos voos

//          PROTOTIPOS            //

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
int getindex(char id); //done
int conexoes(int index);//done

//           CODIGO               //

int main() {

    char cmd;



    getchar();

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
        case 'X': saida(); break;
        default : printf("*Comando Invalido");
    }
	return 0;

}

void adiciona_aero(void) {

    char id[4];
    int capacidade, index;

    scanf(" %s %d", &id, &capacidade);

    index = getindex('\0'); //estrutura vazia

    if (capacidade > 0) {

        aero[index].id = id + '\0';

        aero[index].capacidade = capacidade;

        aero[index].estado = 1; } }

void encerra_aero(void) {

    char id[4];
    int index , i, j;

    scanf(" %s", &id);

    index = getindex(id);

    if (index == -1)

        printf("*Aeroporto %s inexistente", id);

    else {

        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {

                matriz[i][j] = 0;
                matriz[j][i] = 0; } } }

    aero[index].estado == 0; }

void adiciona_voo_ida_volta(void) {

    char id_partida[4], id_chegada[4];
    int  index_partida, index_chegada;

    scanf(" %s %s", &id_partida, &id_chegada);

    index_partida = getindex(id_partida);
    index_chegada = getindex(id_chegada);

    if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && numero_voos_aeroporto_chegada(index_partida) + numero_voos_aeroporto_partida(index_partida) + 2 <= aero[index_partida].capacidade && numero_voos_aeroporto_chegada(index_chegada) + numero_voos_aeroporto_partida(index_chegada) + 2 <= aero[index_chegada].capacidade) {
        matriz[index_partida][index_chegada] += 1;
        matriz[index_chegada][index_partida] += 1; }
    else
        printf("*Impossivel adicionar voo RT %s %s", id_partida, id_chegada); }

void adiciona_rota(void) {

    char id_partida[4], id_chegada[4];
    int index_partida, index_chegada;

    scanf(" %s %s", &id_partida, &id_chegada);

    index_partida = getindex(id_partida);
    index_chegada = getindex(id_chegada);

    capacidade_partida = aero[index_partida].capacidade - numero_voos_aeroporto_chegada(index_partida); // verifica a capacidade atual para voos de partida do aeroporto de partida
    capacidade_chegada = aero[index_chegada].capacidade - numero_voos_aeroporto_partida(index_chegada); // verifica a capacidade atual para voos de chegada do aeroporto de chegada

    if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && numero_voos_aeroporto_partida(index_partida) + 1 <= capacidade_partida && numero_voos_aeroporto_chegada(index_chegada) + 1 <= capacidade_chegada)
        matriz[index_partida][index_chegada] += 1;
    else
        printf("*Impossivel adicionar voo %s %s", id_partida, id_chegada); }

void altera_capacidade(void) {

    char id[4];
    int index, nova_capacidade;

    scanf(" %s %d", &id, &nova_capacidade);

    index = getindex(id);

    if (index == -1 || aero[index].estado == 0 || aero[index].capacidade + nova_capacidade < numero_voos_aeroporto_partida(index) + numero_voos_aeroporto_chegada(index))
        printf ("*Capacidade de %s inalterada", nome);
    else
        aero[index].capacidade += nova_capacidade; }

void listagem_aero(void) {

    int variavel, i;

    scanf(" %d", &variavel);

    switch (variavel) {
        case 0 :

        for (i = 0; i < MAX; i++)

            printf("%s:%d:%d:%d\n", aero[i].id, aero[i].capacidade, numero_voos_aeroporto_partida(i), numero_voos_aeroporto_chegada(i));

        case 1 :

        int v[MAX];
	int i, j;
	for (i=0;i<MAX;i++){
		int aux,min=i;
		for(j=i+1;j<MAX;j++){
			if(strcmp(aero[min].id,aero[j].id)>0)
				min=j
		}
	v[i] = min 
	}
	
	int i;
	for(i=0;i<MAX;i++){
		printf("%s:%d:%d:%d\n", aero[v[i]].id, aero[v[i]].capacidade, voosdepartida[v[i]], voosdechegada[v[i]])
	}
        
        case 2 :

            int nvoos[MAX];

            for (i = 0; i < MAX; i++) {

                nvoos[i] = numero_voos_aeroporto_chegada[i] + numero_voos_aeroporto_partida[i]; }
    }

void numero_voos(void) {

    char id_partida[4], id_chegada[4];
    int index_partida, index_chegada;

    scanf(" %s %s", &id_partida, &id_chegada);

    index_partida = getindex(id_partida);
    index_chegada = getindex(id_chegada);

    if (index_partida == -1) {
        printf("*Aeroporto %s inexistente", id_partida); }

    else if (index_chegada == -1) {
        printf("*Aeroporto %s inexistente", id_chegada); }

    else if (index_partida == -1 && index_chegada == -1) {
        printf("*Aeroporto %s inexistente /n *Aeroporto %s inexistente", id_partida, id_chegada);}

    else {
        voos_chegada = matriz[index_partida][index_chegada];
        voos_partida = matriz[index_chegada][index_partida];

        printf("%d:%d", voos_partida, voos_chegada); } }

void reabre_aero(void) {

	int index;
    char id[4];

    scanf(" %s", &id);

    index = getindex(id);

    if (index == -1)
        printf("*Aeroporto %s inexistente", id);
    else
        aero[index].estado = 1; }

void aero_mais_voos(void) {

    int i, vazio, max_index, max = numero_voos_aeroporto_partida(0) + numero_voos_aeroporto_chegada(0);

    vazio = getindex('\0');

    for (i = 1; i < vazio; i++) {

        variavel = numero_voos_aeroporto_partida(i) + numero_voos_aeroporto_chegada(i);

        if (variavel > max){

            max = variavel;

            max_index = i; } }

    printf(" Aeroporto com mais rotas %s:%d:%d", aero[max_index].id, numero_voos_aeroporto_partida(max_index), numero_voos_aeroporto_partida(max_index)); }

void aero_mais_conectado(void) {

    int i, max = 0;

    for(i = 0; i < MAX; i++){

        if (conexoes(i) > conexoes(max))
            max = i; }

    printf(" Aeroporto com mais ligações %s:%d", aero[max].id, conexoes(max); }

void remove_voo(void) {

    char id_partida[4], id_chegada[4];
    int index_partida, index_chegada;

    scanf(" %s %s", &id_partida, &id_chegada);

    index_partida = getindex(id_partida);
    index_chegada = getindex(id_chegada);

    if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && matriz[index_partida][index_chegada] > 0)
        matriz[index_partida][index_chegada] -= 1;
    else
        printf("*Impossivel remover voo %s %s", id_partida, id_chegada); }

void remove_voo_ida_volta(void) {

    char id_partida[4], id_chegada[4];
    int index_partida, index_chegada;

    scanf(" %s %s", &id_partida, &id_chegada);

    index_partida = getindex(id_partida);
    index_chegada = getindex(id_chegada);

    if (index_chegada != -1 && index_partida != -1 && aero[index_chegada].estado == 1 && aero[index_partida].estado == 1 && matriz[index_partida][index_chegada] > 0 && matriz[index_chegada][index_partida > 0]) {
        matriz[index_partida][index_chegada] -= 1;
        matriz[index_chegada][index_partida] -= 1; }
    else
        printf("*Impossivel remover voo RT %s %s", id_partida, id_chegada); }

void popularidade_voo(void) {

    int i, j, vazio, max_partidas, max_chegadas, aero_partidas, aero_chegadas;

    vazio = getindex('\0');
    max_partidas = 0;
    max_chegadas = 0;

    for (i = 0; i < vazio; i++) {
        if (numero_voos_aeroporto_partida(i) > max_partidas) {
            max_partidas += numero_voos_aeroporto_partida(i);
            aero_partidas = i; } }

    for (j = 0; j < MAX; j++) {
        if (numero_voos_aeroporto_chegada(j) > max_chegadas) {
            max_chegadas += numero_voos_aeroporto_chegada(j);
            aero_chegadas = j; } }

    printf("%s:%s:%d:%d\n", aero[i].id, aero[j].id, numero_voos_aeroporto_partidas(i), numero_voos_aeroporto_chegada(j)); }

void saida(void) {

    int i, j, soma = 0, vazio, numero_aero_abertos = 0;

    vazio = getindex('\0');

    for (i = 0; i < vazio-1; i++) {

        if (aero[i].estado == 1)

            numero_aero_abertos += 1; }

    for (i = 0; i < vazio-1; i++) {

        for (j = 0; j < vazio-1; j++) {

            soma += matriz[i][j];

    printf("%d:%d", numero_aero_abertos, soma); } }

}

//              FUNCOES AUXILIARES        //

int getindex(char id) {

	int i;

	for (i=0; i < MAX; i++){

        if (strcmp(id, aero[i].id) == 0)
            return i;

    return -1; }
}

int numero_voos_aeroporto_partida(int index) {

    int vazio, soma=0;

    vazio = getindex('\0');

    for (i = 0; i < vazio-1 ; i++)

        soma += matriz[index][i];

    return soma; }

int numero_voos_aeroporto_chegada(int index) {

    int vazio, soma = 0;

    vazio = getindex('\0');

    for (i = 0; i < vazio-1 ; i++)

        soma += matriz[i][index];

    return soma; }

int conexoes(int index) {

    int soma = 0, i;

    for(i = 0; i < MAX; i++) {

        if (matriz[index][i] > 0)
            soma++;

        if (matriz[i][index] > 0)
            soma++; }

    return soma; }

void inicialização(char vetor) {

    int i;

    for (i = 0; i < MAX; i++)
        vetor[i].id = '\0'; }
