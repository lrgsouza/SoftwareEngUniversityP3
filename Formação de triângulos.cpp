#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

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

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

int main()
{
	int n; //entrada para quantidade de conjunto de pontos
	ponto A, B, C; //pontos para receber x, y.
	vetor AB, AC; //vetores principais
	// lendo n triangulos
	cin >> n;
	for(int i = 0;i<n;i++){
		//lendo pontos
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y ;
		//verificando triangulo
		if(area_triangulo(A,B,C)==0)
			cout << "Nao formam triangulo" << endl;
		else
			cout << fixed << setprecision(2) << area_triangulo(A,B,C) << endl;	
	}
	return 0;
}













