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

treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento nao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub arvore esquerda
		return tPesq(p->esq, x);
	else // procura na sub arvore direita
		return tPesq(p->dir, x);
}


int main()
{
	treenodeptr arvore = NULL; // ponteiro para a árvore
	int x; // var aux para inserir elementos
	int n; // var para leitura da quantidade de elementos
	int i = 0; // contador
	int f; // var para leitura do elemento a ser procurado
	
	//lendo quantidade de numeros a serem inseridos
	cin >> n;

	// Inserindo elementos na árvore
	for(i = 0; i < n; i++)
	{
		cin >> x;
		tInsere(arvore, x);
	}
	
	//lendo elemento a ser procurado.
	cin >> f;

	// procurando elemento
	if (tPesq(arvore,f) != NULL)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;


	return 0;
}
