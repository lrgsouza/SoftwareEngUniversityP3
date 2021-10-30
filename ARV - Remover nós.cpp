#include<iostream>

using namespace std;

// Estrutura de um nó da árvore
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

// Usa um percurso em Em-ordem para mostrar nós
void MostrarEmOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		MostrarEmOrdem(arvore->esq);
		cout << arvore->info << endl;
		MostrarEmOrdem(arvore->dir);
	}
}

//encontra menor valor
treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else // continua a busca na sub´arvore esquerda
		return tMenor(raiz->esq);
}

// deletando nós
int tRemove(treenodeptr &raiz, int x)
{
	treenodeptr p;
	if (raiz == NULL) // ´arvore vazia
		return 1;
	if (x == raiz->info)
	{
		p = raiz;
		if (raiz->esq == NULL) // a raiz n~ao tem filho esquerdo
			raiz = raiz->dir;
		else if (raiz->dir == NULL) // a raiz n~ao tem filho direito
			raiz = raiz->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
}

// Insere x na árvore cuja raiz é p
void tInsere(treenodeptr &p, double x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}

	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a árvore
	int e; // var aux para leitura dos elementos a serem inseridos na árvore
	int x; // variável para receber elemento a ser deletado

	// Inserindo elementos na árvore
	cin >> e;
	while(e != 0)
	{
		tInsere(arvore, e);
		cin >> e;
	}

	//lendo nó a ser deletado
	cin >> x;

	//removendo nó
	int check = 0; //variavel auxiliar para deletar todos os nós x
	do{
		check = tRemove(arvore, x);
	}while(check != 1);
	
	//mostrando elementos
	MostrarEmOrdem(arvore);

	return 0;
}
