//IST - TAGUSPARK
//PROJETO 1 IAED

//Ricardo Oliveira, 84759
//Ricardo Martins, 84761

//        BIBLIOTECAS             //

#include <stdio.h>
#include <string.h>

//        ESTRUTURAS              //

typedef struct aeroporto {

    char nome[4], chegada[4];
    int  capacidade;

}; AEROPORTO

//          PROTOTIPOS            //

adiciona_aero(AEROPORTO aero);
encerra_aero(AEROPORTO aero);
adiciona_voo(AEROPORTO aero);
adiciona_rota(AEROPORTO aero)
altera_capacidade(AEROPORTO aero);
altera_capacidade(AEROPORTO aero);
listagem_aero(void);
numero_voos(AEROPORTO aero);
abre_aero(AEROPORTO aero);
aero_mais_voos(void);
aero_mais_conectado(void);
remove_voo(AEROPORTO aero);
remove_voo_ida_volta(AEROPORTO aero);
popularidade_voo(void);
exit(void);

//           CODIGO               //

int main() {

    char cmd;
    getchar(cmd);

    switch (cmd) {
        case 'A': adiciona_aero(); break;
        case 'C': encerra_aero(); break;
        case 'F': adiciona_voo(); break;
        case 'G': adiciona_rota(); break;
        case 'I': altera_capacidade(); break;
        case 'L': listagem_aero(); break;
        case 'N': numero_voos(); break;
        case 'O': abre_aero(); break;
        case 'P': aero_mais_voos(); break;
        case 'Q': aero_mais_conectado(); break;
        case 'R': remove_voo(); break;
        case 'S': remove_voo_ida_volta(); break;
        case 'V': popularidade_voo(); break;
        case 'X': exit();
    }
    return 0

}

adiciona_aero(AEROPORTO aero) {

    scanf("%s %d", &aero.nome, &aero.capacidade);
}

encerra_aero(AEROPORTO aero) {

    scanf("%s", &aero.nome);

}

adiciona_voo(AEROPORTO aero) {

    scanf("%s %s", &aero.nome, &aero.chegada);

}

adiciona_rota(AEROPORTO aero) {

    scanf("%s %s", &aero.nome, &aero.chegada);

}

altera_capacidade(AEROPORTO aero) {

    scanf("%s %d", &aero.nome, &aero.capacidade);

}

listagem_aero() {


}

numero_voos(AEROPORTO aero) {

    scanf("%s %s", &aero.nome, &aero.chegada);

}

abre_aero(AEROPORTO aero) {

    scanf("%s", &aero.nome);

}

aero_mais_voos() {


}

aero_mais_conectado() {


}

remove_voo(AEROPORTO aero) {

    scanf("%s %s", &aero.nome, &aero.chegada);

}

remove_voo_ida_volta(AEROPORTO aero) {

    scanf("%s %s", &aero.nome, &aero.chegada);

}

popularidade_voo() {


}

exit() {


}
