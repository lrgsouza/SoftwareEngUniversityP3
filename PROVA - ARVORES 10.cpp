#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

// Estrutura de um nó da árvore
struct treenode
{
	double info;
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

void calcMedia(treenodeptr t)
{
	//variaveis para calculo da media
	double s = 0; // soma dos elementos da árvore
	double c = 0; // contador para média
	list<treenodeptr> q; // fila auxiliar
	treenodeptr n = t; // ponteiro para varrer a árvore
	if (t != NULL)
	{
		q.push_front(n);
		while (!q.empty())
		{
			n = q.front();
			q.pop_front();
			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);
			if (n->esq == NULL && n->dir == NULL)
			{
				c++; //incrementando contador
				s += n->info; //somando valores das folhas
			}
		}
	}

	//mostrando média
	cout << fixed << setprecision(2); //definindo 2 casas decimais
	cout << "media = " << s / c << endl;

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

	//calculando e mostrando a média
	calcMedia(arvore);

	return 0;
}
