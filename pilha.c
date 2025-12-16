#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

// ---------------------- Funções ----------------------

// -- Função inicializarPila() --
void inicializarPilha(Pilha *p) {
    p->topo = - 1;
}

// -- Função pilhaVazia() --
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// -- Função pilhaCheia() --
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// -- Função push() --
void push(Pilha *p, Pessoa nova) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia. Não é possivel inserir.\n");
        return;
    }

    p->topo++;
    p->itens[p->topo] = nova;
}

// -- Função pop() --
void pop(Pilha *p, Pessoa *removida) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Não é possivel remover.\n");
        return;
    }

    *removida = p->itens[p->topo];
    p->topo--;
}

// -- Função peek() --
void peek(Pilha *p, Pessoa *visualizada) {
    if(pilhaVazia(p)) {
        printf("Pilha vazia. Nada para espiar.\n");
        return;
    }

    *visualizada = p->itens[p->topo];
}

// -- Função mostrarPilha() --
void mostrarPilha(Pilha *p) {
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0;  i--) {
        printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
    }
    
    printf("\n");
}

// ================= FUNÇÃO PRINCIPAL (MAIN) =================

int main() {
    Pilha p;
    inicializarPilha(&p);

    Pessoa a = {"Anna", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};

    push(&p, a);
    push(&p, b);
    push(&p, c);

    mostrarPilha(&p);

    Pessoa removida;
    pop(&p, &removida);
    printf("Removida: %s, %d\n", removida.nome, removida.idade);

    mostrarPilha(&p);

    Pessoa topo;
    peek(&p, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);



    return 0;
}
