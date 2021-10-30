#include<iostream>

using namespace std;

// Estrutura de um n� da �rvore
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

// Insere x na �rvore cuja raiz � p
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

// Usa um percurso em-ordem para mostrar n�s em ordem decrescente
void OrdemDescArvore(treenodeptr &arvore)
{
	if (arvore != NULL)
	{	
		OrdemDescArvore(arvore->dir);
		cout << arvore->info << " ";
		OrdemDescArvore(arvore->esq);
	}
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a �rvore
	double x; // var aux para leitura dos elementos a serem inseridos na �rvore

	// Inserindo elementos na �rvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	//mostrando folhas em ordem decrescente
	OrdemDescArvore(arvore);

	return 0;
}
