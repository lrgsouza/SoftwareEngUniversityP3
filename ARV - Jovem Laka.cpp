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


// Percurso em pre-ordem
void preOrdem (treenodeptr arvore, int x, int &preCnt, int &preRes)
{
	if (arvore != NULL)
	{
		if(arvore->info != x)
			preCnt++;
		else
			preRes = preCnt;

		preOrdem(arvore->esq, x, preCnt, preRes);
		preOrdem(arvore->dir, x, preCnt, preRes);
	}
}
// Percurso em ordem
void emOrdem (treenodeptr arvore, int x, int &emCnt, int &emRes)
{
	if (arvore != NULL)
	{

		emOrdem(arvore->esq, x, emCnt, emRes);
		if(arvore->info != x)
			emCnt++;
		else
			emRes = emCnt;

		emOrdem(arvore->dir, x, emCnt, emRes);
	}
}
// Percurso em pos-ordem
void posOrdem (treenodeptr arvore, int x, int & posCnt, int & posRes)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq, x, posCnt, posRes);
		posOrdem(arvore->dir, x, posCnt, posRes);
		if(arvore->info != x)
			posCnt++;
		else
			posRes = posCnt;
	}
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a árvore
	int n; // var aux para leitura dos elementos a serem inseridos na árvore
	int x; // var aux para leitura do elemento a ser procurado

	//contadores para auxiliar posição
	int preCnt = 0;
	int emCnt = 0;
	int posCnt = 0;

	//auxiliares para salvar posição
	int preRes = 0;
	int emRes = 0;
	int posRes = 0;

	cin >> n;
	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
	}

	cin >> x;

	// Mostrando os percursos
	//cout << "Pre-ordem:" << endl;
	preOrdem(arvore, x, preCnt, preRes);

	//cout << "Em-ordem" << endl;
	emOrdem(arvore, x, emCnt, emRes);

	//cout << "Pos-ordem" << endl;
	posOrdem(arvore, x, posCnt, posRes);

	//mostrando melhor escolha
	if(preRes < emRes && preRes < posRes)
		cout << "Pre" << endl;
	if(emRes < preRes && emRes < posRes)
		cout << "Em" << endl;
	if(posRes < emRes && posRes < preRes)
		cout << "Pos" << endl;


	return 0;
}
