#include<iostream>
#include <iomanip>

using namespace std;

// Estrutura de um nó da árvore
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;


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

// Usa um percurso em pre-ordem para somar os elementos da árvore
void MediaPreOrdem (treenodeptr arvore, double &s, double &c)
{
	if (arvore != NULL)
	{
		s = s + arvore->info;
		c = c + 1;
		MediaPreOrdem(arvore->esq, s, c);
		MediaPreOrdem(arvore->dir, s, c);
	}
}

// Retorna a media dos elementos da árvore
double media(treenodeptr arvore)
{
	double s = 0; // soma dos elementos da árvore
	double c = 0; // contador para média
	MediaPreOrdem(arvore, s, c);
	return s / c; //calcula média
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

	//mostrando média
	cout << fixed << setprecision(2); //definindo 2 casas decimais
	cout << "Media: " << media(arvore) << endl;

	return 0;
}
