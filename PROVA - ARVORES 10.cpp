#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

// Estrutura de um n� da �rvore
struct treenode
{
	double info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

// Insere x na �rvore cuja raiz � p
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
	double s = 0; // soma dos elementos da �rvore
	double c = 0; // contador para m�dia
	list<treenodeptr> q; // fila auxiliar
	treenodeptr n = t; // ponteiro para varrer a �rvore
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

	//mostrando m�dia
	cout << fixed << setprecision(2); //definindo 2 casas decimais
	cout << "media = " << s / c << endl;

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

	//calculando e mostrando a m�dia
	calcMedia(arvore);

	return 0;
}
