#include<iostream>
#include <iomanip>

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

//verifica se � primo
int primo(int N)
{
	int i; //contador e auxiliar de divis�o
	int div = 0; //contador para definir primo

	for (i = 1; i <= N; i++)
	{
		//verifica se foi dividido.
		if (N % i == 0)
		{
			div++; //caso for dividido soma 1.
		}
	}
	if (div == 2)
		return 0; //caso seja divisivel somente por 1 e ele mesmo = 2 (� primo)
	else
		return 1; //caso seja divisivel por mais de 2 numeros (n�o � primo)

}

// Usa um percurso em pre-ordem para verificar a quantidade de numeros primos
void PrimosPreOrdem (treenodeptr arvore, int &c)
{
	if (arvore != NULL)
	{
		if(primo(arvore->info) == 0)
			c++;
		PrimosPreOrdem(arvore->esq, c);
		PrimosPreOrdem(arvore->dir, c);
	}
}

// Retorna a quantidade de numeros primos na arvore
int contaPrimos(treenodeptr arvore)
{
	int c = 0; //var auxliar para contar numeros primos
	PrimosPreOrdem(arvore, c);
	return c; // quantidade de numeros primos
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

	//mostrando quantidade de numeros primos
	cout << contaPrimos(arvore) << " numeros primos" << endl;

	return 0;
}
