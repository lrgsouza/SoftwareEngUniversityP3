#include<iostream>
#include <iomanip>
#include <climits>

using namespace std;

// Estrutura de um nó da árvore
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

struct nodes
{
	int no;
	
};

// Insere x na árvore cuja raiz é p
void tInsere(treenodeptr &p, int x)
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

// Usa um percurso em pre-ordem para verificar o maior e menor numero
void MaxMinPreOrdem (treenodeptr arvore, int &max, int &min)
{

	if (arvore != NULL)
	{
		if(arvore->info < min)
			min = arvore->info;
		
		if(arvore->info > max)
			max = arvore->info;		
		
		MaxMinPreOrdem(arvore->esq, max, min);
		MaxMinPreOrdem(arvore->dir, max, min);

	}

}

// Retorna maior e menor valor da arvore
int MaxMinTree(treenodeptr arvore)
{
	int max = INT_MIN;
	int min = INT_MAX;
	MaxMinPreOrdem(arvore, max, min);

	cout << min << " e " << max << endl;
	return 0; // vetor com elementos
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a árvore
	double x; // var aux para leitura dos elementos a serem inseridos na árvore

	// Inserindo elementos na árvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	//mostrando maior e menor valor
	MaxMinTree(arvore);

	return 0;
}
