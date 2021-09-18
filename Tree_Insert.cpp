#include <iostream>

using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};

typedef treenode* treenodeptr;


void tInsere(treenodeptr &p, int x) {

if (p == NULL)// insere na raiz
{ 
    p = new treenode;
    p->info = x;
    p->esq = NULL;
    p->dir = NULL;
}
else if (x < p->info)  // insere na subarvore esquerda
 tInsere(p->esq,x); // insere na subarvore direita 
else 
tInsere(p->dir,x); 


}

int main() {
    treenodeptr arvore = NULL;
    
    tInsere(arvore,14);
    tInsere(arvore,15);
    tInsere(arvore,5);

    //CRIANDO RAIZ
    //arvore = new treenode;
    //arvore->info = 14;
    //arvore->esq = NULL;
    //arvore->dir = NULL;

    //CRIANDO FILHO DIREITO
    //arvore->dir = new treenode;
    //(arvore->dir)->info = 15;
    //(arvore->dir)->esq = NULL;
    //(arvore->dir)->dir = NULL;

    //CRIANDO FILHO ESQUERDO
    //arvore->esq = new treenode;
    //(arvore->esq)->info = 5;
    //(arvore->esq)->esq = NULL;
    //(arvore->esq)->dir = NULL;

    //mostrando arvore
    cout << "raiz: " << arvore->info << endl;
    cout << "filho direito: " << arvore->dir->info << endl;
    cout << "filho esquerdo: " << arvore->esq->info << endl;

    return 0;
}

