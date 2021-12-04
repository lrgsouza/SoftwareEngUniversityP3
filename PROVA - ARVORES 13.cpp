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

int tPesq(treenodeptr arvore, int x, int &nChamadas)
{
	nChamadas++; //agregando recursividade
	if (arvore == NULL) // elemento nao encontrado
		return 0;
	else if (x == arvore->info) // elemento encontrado na raiz
		return 0;
	else if (x < arvore->info) // procura na sub arvore esquerda
		tPesq(arvore->esq, x, nChamadas);
	else // procura na sub arvore direita
		tPesq(arvore->dir, x, nChamadas);
	return 0;
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a árvore
	int x; // var aux para inserir elementos
	int f; // var para leitura do elemento a ser procurado
	int nCham = 0; //variavel para contar recursividade

	// Inserindo elementos na árvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	// lendo elemento a ser procurado.
	cin >> f;

	// contando recursividade para definir nivel
	tPesq(arvore, f, nCham);

	// mostrando profundidade se for encontrado
	if (nCham != 0)
		cout << f << " encontrado na profundidade " << nCham - 1 <<  endl; // mostrando profundidade (nRecursivdidade - 1)

	return 0;
}
