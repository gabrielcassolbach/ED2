#include "Arvore.h"
 
Arvore *cria_arv_vazia(void)
{
    return NULL;
}

Arvore *constroi_arv(char c, Arvore *e, Arvore *d)
{
    Arvore *no = (Arvore *)malloc(sizeof(Arvore));
    no->info = c;
    no->esq = e;
    no->dir = d;
    return no;
}

int verifica_arv_vazia(Arvore *a)
{
    return (a == NULL);
}

void arv_libera(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
}

//========= Exercício 1 ================
/*
   - Output pre-order: {a, b, d, c, e, f};   
   - Output in-order: {b, d, a, e, c, f};
   - Output pos-order: {d, b, e, f, c, a}.
*/

//========= Exercício 2 - pré-ordem ====
void PreOrderSearch(Arvore* a){
    if(!verifica_arv_vazia(a)){
        printf("%c ", a->info);
        if(a -> esq != NULL)
            PreOrderSearch(a -> esq);
        if(a -> dir != NULL);
            PreOrderSearch(a -> dir);
    }
}

//========= Exercício 2 - in-ordem ====
void InOrderSearch(Arvore* a){
    if(!verifica_arv_vazia(a)){
        if(a -> esq != NULL)
            InOrderSearch(a -> esq);
        printf("%c ", a->info);
        if(a -> dir != NULL);
            InOrderSearch(a -> esq);
    }
}

//========= Exercício 2 - pós-ordem ====
void PosOrderSearch(Arvore* a){
     if(!verifica_arv_vazia(a)){ 
        if(a -> esq != NULL)
            PosOrderSearch(a -> esq);
        if(a -> dir != NULL);
            PosOrderSearch(a -> dir);
        printf("%c ", a->info);  
     }
}

//========= Exercício 3 - pertence ====
int pertence_arv(Arvore* a, char c){}

//========= Exercício 4 - conta nós ====
int conta_nos(Arvore* a){
    if(!verifica_arv_vazia(a))
        return conta_nos(a -> dir) + conta_nos(a -> esq) + 1;
    else
        return 0;
}

//========= Exercício 5 - calcula altura ====

//========= Exercício 6 - conta folhas ====

int main(int argc, char *argv[])
{
    Arvore *a = cria_arv_vazia();
    printf("Quantidade de Nós: %d\n", conta_nos(a));
    arv_libera(a);
    return 0;
}
