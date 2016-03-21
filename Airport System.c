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

//          PROTOTIPOS            //

void adiciona_aero(void); //done
void encerra_aero(void); //done
void adiciona_voo_ida_volta(AEROPORTO aero); //done com falhas
void adiciona_rota(AEROPORTO aero); //done com falhas
void altera_capacidade(void); //done
listagem_aero(void);
void numero_voos(void); //done
void reabre_aero(void); //done
aero_mais_voos(void);
aero_mais_conectado(void);
remove_voo(AEROPORTO aero); //done com falhas
remove_voo_ida_volta(AEROPORTO aero); //done com falhas
popularidade_voo(void);
void exit(void); //done
void numero_voos_aeroporto(int index); //done
void getindex(void); //done

//           CODIGO               //

int main() {

    int AEROPORTO aero[MAX]; // vetor de indices
    int matriz [MAX][MAX]; // matriz dos voos
    char cmd;
    getchar(cmd);

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
        case 'X': exit();
    }
    return 0

}

void adiciona_aero(void) {

    char id[4];
    int capacidade;

    scanf("%s %d", &id, &capacidade);

    index = getindex('\0'); //estrutura vazia

    aero[index].id = id + '\0';

    aero[index].capacidade = capacidade;

    aero[index].estado = 1;

}

void encerra_aero(void) {

    char id[4];
    int index;

    scanf("%s", &id);

    index = getindex(char id);

    if (index == -1)

        printf("*Aeroporto %s inexistente", id);

    else {

        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {

                matriz[i][j] = 0;
                matriz[j][i] = 0;
        }
    }
}

    aero[index].estado == 0;

}

void adiciona_voo_ida_volta(void) { //falta conditions

    char id_partida[4], id_chegada[4];

    scanf("%s %s", &id_partida, &id_chegada);

    index_partida = getindex(char id_partida);
    index_chegada = getindex(char id_chegada);

    if (index_chegada != -1 || index_partida != -1 || aero[index_chegada].estado == 1 || aero[index_partida].estado == 1) {
        matriz[index_partida][index_chegada] += 1;
        matriz[index_chegada][index_partida] += 1; }
    else {

        printf("*Impossivel adicionar voo RT %s %s", id_partida, id_chegada);
    }
}

void adiciona_rota(void) {

    char id_partida[4], id_chegada[4];

    scanf("%s %s", &id_partida, &id_chegada);

    index_partida = getindex(char id_partida);
    index_chegada = getindex(char id_chegada);

    if (index_chegada != -1 || index_partida != -1 || aero[index_chegada].estado == 1 || aero[index_partida].estado == 1) {
        matriz[index_partida][index_chegada] += 1;
    else {

        printf("*Impossivel adicionar voo %s %s", id_partida, id_chegada);
    }
}

}

void altera_capacidade(void) {

    char id[4];
    int nova_capacidade;

    scanf("%s %d", &id, &nova_capacidade);

    index = getindex(char id);

    if (x == -1 || aero[index].estado == 0 || aero[index].capacidade + nova_capacidade < numero_voos_aeroporto(index))
        printf ("*Capacidade de %s inalterada", nome);
    else
        aero[index].capacidade += nova_capacidade;

}

listagem_aero() {


}

void numero_voos(void) {

    char id_partida[4], id_chegada[4];
    scanf("%s %s", &id_partida, &id_chegada);

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

        printf("%d:%d", voos_chegada, voos_partida); }

}

void reabre_aero(void) {

    char id[4];

    scanf("%s", &id);

    index = getindex(char id);

    if (index == -1)
        printf("*Aeroporto %s inexistente", id);
    else
        aero[index].estado = 1;

}

void aero_mais_voos(void) {

    int i, max = numero_voos_aeroporto(0);
    vazio = getindex('\0');
    for (i = 1; i < vazio; i++) {
        variavel = numero_voos_aeroporto(i);
        if (variavel > max)
            max = variavel; }
}

aero_mais_conectado() {


}

void remove_voo(void) { // falta conditions

    char id_partida[], id_chegada[];

    scanf("%s %s", &id_partida, &id_chegada);

    index_partida = getindex(char id_partida);
    index_chegada = getindex(char id_chegada);

    if (index_chegada != -1 || index_partida != -1 || aero[index_chegada].estado == 1 || aero[index_partida].estado == 1) {
        matriz[index_partida][index_chegada] -= 1;
    else {

        printf("*Impossivel remover voo %s %s", id_partida, id_chegada);
    }
}

}

void remove_voo_ida_volta(void) { //falta conditions

    char id_partida[], id_chegada[];

    scanf("%s %s", &id_partida, &id_chegada);

    index_partida = getindex(char id_partida);
    index_chegada = getindex(char id_chegada);

    if (index_chegada != -1 || index_partida != -1 || aero[index_chegada].estado == 1 || aero[index_partida].estado == 1) {
        matriz[index_partida][index_chegada] -= 1;
        matriz[index_chegada][index_partida] -= 1;
    else {

        printf("*Impossivel remover voo RT %s %s", id_partida, id_chegada);
    }
}

}

popularidade_voo() {


}

void exit(void) {

    int soma = 0, vazio, numero_aero_abertos = 0;

    vazio = getindex('\0')

    for (i = 0; i < vazio-1; i++) {

        if (aero[i].estado == 1)

            numero_aero_abertos += 1; }

    for (i = 0; i < vazio-1; i++)

        for (j = 0; j < vazio-1; j++) {

            soma += matriz[i][j]

    printf("%d:%d", numero_aero_abertos, soma); }

}

/* Funcoes Auxiliares */

int getindex(char aero) {

    for (i=0; i < MAX; i++){

        if (strcmp(aero, aero.id[i]) == 0)
            return i;

    return -1;
    }
}

int numero_voos_aeroporto(int index) {

    int vazio, soma=0;

    vazio = getindex('\0')

    for (i = 0; i < vazio-1 ; i++)

        soma += matriz[i][index] + matriz[i][index];

    return soma;
}
