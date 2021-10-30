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

// Usa um percurso em pre-ordem para verificar a quantidade de folhas
void FolhasPreOrdem (treenodeptr arvore, int &c, int &f)
{
	int dir = 0;
	int esq = 0;
	if (arvore != NULL)
	{
		FolhasPreOrdem(arvore->esq, esq, f);
		FolhasPreOrdem(arvore->dir, dir, f);
		if(esq == 1 && dir == 1) // verifica se não existe nós abaixo
			f = f + 1; // caso não houver nós soma 1 na folha
	}
	else
		c = c + 1; //soma 1 no auxiliar se não houver nó

}

// Retorna a quantidade de folhas na arvore
int folhas(treenodeptr arvore)
{
	int f = 0; // var para calcular folhas
	int c = 0; //var auxliar para procurar nós
	FolhasPreOrdem(arvore, c, f);
	return f; // quantidade de folhas
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

	//mostrando quantidade de folhas
	cout << folhas(arvore) << endl;

	return 0;
}
