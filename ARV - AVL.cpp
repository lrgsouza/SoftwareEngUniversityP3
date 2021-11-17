#include <iostream>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
	int bal; // fator de balanceamento
};

typedef treenode* treenodeptr;

treenodeptr tPesq(treenodeptr p, int x, int &contador)
{
	contador++;
	if (p == NULL) // elemento nao encontrado
		return NULL;
	
	
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	
	
	else if (x < p->info) // procura na sub arvore esquerda
		return tPesq(p->esq, x,contador);
	
	
	
	else // procura na sub arvore direita
		return tPesq(p->dir, x,contador);
}


// Rotação simples à direita
void rot_dir(treenodeptr &r)
{
	treenodeptr b = r;
	treenodeptr a = b->esq;
	b->esq = a->dir;
	a->dir = b;
	a->bal = 0;
	b->bal = 0;
	r = a;
}

// Rotação simples à esquerda
void rot_esq (treenodeptr &r)
{
	treenodeptr a = r;
	treenodeptr b = a->dir;
	a->dir = b->esq;
	b->esq = a;
	a->bal = 0;
	b->bal = 0;
	r = b;
}

// Rotação dupla esquerda-direita
void rot_esq_dir (treenodeptr &r)
{
	treenodeptr c = r;
	treenodeptr a = c->esq;
	treenodeptr b = a->dir;
	c->esq = b->dir;
	a->dir = b->esq;
	b->esq = a;
	b->dir = c;

	switch (b->bal)
	{
	case -1:
		a->bal = 0;
		c->bal = 1;
		break;
	case 0:
		a->bal = 0;
		c->bal = 0;
		break;
	case 1:
		a->bal = -1;
		c->bal = 0;
		break;
	}
	b->bal = 0;
	r = b;
}

// Rotação dupla direita-esquerda
void rot_dir_esq(treenodeptr &r)
{
	treenodeptr a = r;
	treenodeptr c = a->dir;
	treenodeptr b = c->esq;
	c->esq = b->dir;
	a->dir = b->esq;
	b->esq = a;
	b->dir = c;
	switch (b->bal)
	{
	case -1:
		a->bal = 0;
		c->bal = 1;
		break;
	case 0:
		a->bal = 0;
		c->bal = 0;
		break;
	case 1:
		a->bal = -1;
		c->bal = 0;
		break;
	}
	b->bal = 0;
	r = b;
}

// Insere um nó na árvore, rotaciona se preciso e corrige os fatores de balanceamento
void tInsereAVL(treenodeptr &p, int x, int &cresceu)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->bal = 0;
		p->esq = NULL;
		p->dir = NULL;
		cresceu = 1;
	}
	else if (x < p->info) // insere na subarvore esquerda
	{
		tInsereAVL(p->esq, x, cresceu);

		if(cresceu == 1) // rotacionando e ajustando o fator de balanceamento, se necessário
		{
			switch (p->bal)
			{
			case -1: // bal(p) = -2

				if (p->esq->bal == -1) // sinais iguais – pendem para mesmo lado
					rot_dir(p); // p retorna balanceado
				else // sinais trocados: rotação dupla
					rot_dir_esq(p); // p retorna balanceado
				cresceu = 0; //interrompe propagação
				break;
			case 0:
				p->bal = -1; // ficou maior à esq.
				cresceu = 1; // propaga verificação
				break;
			case 1: // era maior à direita
				p->bal = 0; // balanceou com ins. esq
				cresceu = 0; //interrompe propagação
				break;
			}
		}
	}
	else // insere na subarvore direita
	{
		tInsereAVL(p->dir, x, cresceu);

		if(cresceu == 1) // rotacionando e ajustando o fator de balanceamento, se necessário
		{
			switch (p->bal)
			{
			case -1: // era mais alto à esq.
				p->bal = 0; ; // balanceou com ins. dir
				cresceu = 0; //interrompe propagação
				break;
			case 0: ; // direita fica maior
				p->bal = 1;
				cresceu = 1; // propaga verificação
				break;
			case 1: // bal(p) = 2
				if (p->dir->bal == 1) // sinais iguais – pendem para mesmo lado
					rot_esq(p); // p retorna balanceado
				else // sinais trocados: rotação dupla
					rot_dir_esq(p); // p retorna balanceado
				cresceu = 0; //interrompe propagação
				break;
			}
		}
	}
}

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

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a árvore
	treenodeptr arvoreAVL = NULL; // ponteiro para a árvore
	int cresceu = 1;
	int n; //variavel para ler numeros
	int contador = 0; //contador para tpesq
	int x; //variavel leitura do elemento a ser pesquisado

	//lendo elementos e inserindo
	cin >> n;
	while(n != 0){
		tInsere(arvore, n);
		tInsereAVL(arvoreAVL, n, cresceu);
		cin >> n;
		cresceu = 1;
	}
	
	//lendo elemento a ser pesquisado
	cin >> x;
	
	//saidas
	tPesq(arvore,x,contador); //contando recursividade arvore normal
	cout << "Arvore normal: " << contador << endl;
	contador = 0;
	tPesq(arvoreAVL,x,contador); //contando recursividade AVL
	cout << "AVL: " << contador << endl;

	//destruindo arvores
	tDestruir(arvore);
	tDestruir(arvoreAVL);

	return 0;
}
