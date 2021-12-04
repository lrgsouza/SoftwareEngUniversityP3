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


//pesquisa em arvre
int tPesq(treenodeptr arvore, int x)
{
	if (arvore == NULL)
		return 0;
	else if (x == arvore->info)
		return 1;
	else if (x < arvore->info)
		tPesq(arvore->esq, x);
	else
		tPesq(arvore->dir, x);
	return 0;
}

// Insere x na �rvore cuja raiz � p
void tInsere(treenodeptr &p, int x)
{
	//verifica se o elemento n�o esta na arvore para poder inserir
	if (tPesq(p, x) != 1){
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
}

// Percurso em pos-ordem
void posOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << " ";
	}
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a �rvore
	int x; // variavel para ler elementos a ser inserido

	// lendo elementos 
	cin >> x;
	while(x != -1)
	{
		//insere elementos na arvore (fun��o tinsere inclui pesquisa para verifica��o se h� o elemento na arvore)
		tInsere(arvore, x);
		cin >> x;
	}
	//Mostrando arvore em p�s ordem
	posOrdem(arvore);

	return 0;
}
