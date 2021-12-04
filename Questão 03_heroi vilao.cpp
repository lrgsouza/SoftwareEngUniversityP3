#include <iostream>
#include <cmath> // operacoes matematicas
#include <algorithm> // sort
#include <list> // para a pilha 
#include <iomanip>
using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

struct reta
{
	ponto A;
	ponto B;
};
typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

/*
Posicao de C em relacao ao segmento AB
1 -> esquerda
-1 -> direita
0 -> colinear
*/
int sentido(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float vet;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	vet = vetorial(AB, AC);
	if(vet > 0)
		return 1;
	else if(vet < 0)
		return -1;
	else
		return 0;
}

int main()
{
	ponto h; //vetor recebe pontos
	ponto v; //vetor recebe pontos
	ponto p1; //vetor recebe pontos
	ponto p2; //vetor recebe pontos
	int HP1, HP2; //variavel recebe quantidade de pontos

	//lendo heroi
	cin >> h.x >> h.y;
	//lendo vilão
	cin >> v.x >> v.y;	
	//lendo p1
	cin >> p1.x >> p1.y;		
	//lendo p2
	cin >> p2.x >> p2.y;		
	

	//verificando
	HP1 = sentido(h, p1, v);
	HP2 = sentido(h, p2, v);
	
	if (HP1 == -1 && HP2 == 1)
		cout << "Vilao derrotado" << endl;
	else
		cout << "Chame reforcos" << endl;

	return 0;
}
