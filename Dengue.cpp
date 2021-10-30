#include <iostream> // Entrada e saida
#include <climits> // INT_MAX
#include <algorithm> // next_permutation
using namespace std;

int main()
{
	//#Declarando vari�veis
	int custo[100][100]; // 100 -> numero maximo de focos da dengue
	int n; // numero de focos da dengue
	int casa_joao; //auxiliar para designar ponto da casa do jo�o (ponto_inicial)
	int i, j, p; //contadores
	int f[100]; // vetor com os focos a serem permutados
	int menor_caminho; // menor caminho
	int custo_caminho; // custo do caminho
	//#Declarando vari�veis - End
	
	//lendo quantidade de focos da dengue
	cin >> n;
	
	//estrutura para ler distancias
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
		{
			//lendo discancias
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
		
	//lendo qual ponto � a casa do jo�o
	cin >> casa_joao;

	// colocando os focos a serem permutados no vetor (todas exceto a inicial)
	p = 0;
	for(i = 0; i < n; i++)
		if(i != casa_joao)
		{
			f[p] = i;
			p++;
		}

	//utilizando algor�tmo de forca bruta
	menor_caminho = INT_MAX; // inicializo o custo com infinito
	do
	{
		custo_caminho = custo[casa_joao][f[0]]; // distancia da casa_joao -> v[0]

		for(i = 0; i < n - 2; i++) // somar distancias de v[0]->v[1]->v[2]...v[n-3]->v[n-2]
			custo_caminho += custo[f[i]][f[i + 1]];

		custo_caminho += custo[f[n - 2]][casa_joao]; // distancia v[n-2] -> casa jo�o
		menor_caminho = min(menor_caminho, custo_caminho);

	}
	while(next_permutation(f, f + (n - 1))); // n-1 = numero de focos a serem permutados

	//mostrando menor caminho
	cout << menor_caminho << endl;
	return 0;
}


