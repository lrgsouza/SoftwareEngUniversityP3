#include <iostream> //mochila01

using namespace std;

struct item
{
	int nota; // tempo de duração em minutos. d -> nota
	int tempo; // nota de cada brinquedo. r -> tempo
};

int main()
{
	int pd[100][100]; 	// valor maximo
	int caminho[100][100]; 	// utilizado para recuperar quais brinquedos foram escolhidos
							// 0 -> nao escolher brinquedo
							// 1 -> escolher brinquedo
							
	int n; // quantidade de brinquedos
	int T; // tempo em minutos de permanencia no parque
	item v[100]; // vetor de brinquedos onde:
					//d = tempo de duração em minutos.
					//r =  nota de cada brinquedo.

	// ENTRADA:
	//tempo em minutos para permanencia no parque
	cin >> T; 	
	
	//quantidade de brinquedos do parque
	cin >> n;

	for(int i=0; i<n; i++)
	{
		//cout << "Entre com o valor e peso do item " << i << endl;
		cin >> v[i].tempo >> v[i].nota; 
	}
	
	// CASO BASE:
	// olhando do ultimo brinquedo para frente, val. maximo = 0
	for(int j = 0; j <= T; j++)
		pd[n][j] = 0;

	// olhando tendo permanencia = 0, o val. maximo=0
	for(int i = 0; i <= n; i++)
		pd[i][0] = 0;
	
	
	// CASO GERAL
	for(int i = n - 1; i >= 0; i--)
		for(int j = 1; j <= T; j++)
		{
			int pega, npega; // val. para caso eu escolher ou não escolher o brinquedo 'i'
			
			npega = pd[i + 1][j]; // olhar o proximo brinquedo, mantendo a permanencia 'j'

			if(j >= v[i].tempo) // se eu tiver tempo disponivel p/ escolher o brinquedo 'i'
				pega = pd[i + 1][j - v[i].tempo] + v[i].nota;
			// olho o proximo brinquedo, subtraio a o tempo da permanencia
			// disponivel, e somo o valor do item 'i'
			else
				pega = 0; // se nao posso escolher, o valor eh 0

			if(pega > npega) // se valer a pena escolher
			{
				pd[i][j] = pega;
				caminho[i][j] = 1;
			}
			
			else // se valer a pena nao escolher
			{
				pd[i][j] = npega;
				caminho[i][j] = 0;
			}
		}

	// Comeca na posicao final
	int i,j;
	i = 0; // do item 0->final
	j = T; // jogando valor de J o tempo maximo de permanencia
	int note = 0; //variavel para somar as notas
	
	while(i != n){ // enquanto eu nao chegar no ultimo brinquedo
		if(caminho[i][j] == 0) // se nesse momento a melhor opcao foi nao pegar eu nao pego
			i++; // avanco para o proximo i, mantendo o tempo
		
		else 
		{
			note += v[i].nota; // somando notas
			j-= v[i].tempo; // diminuo a tempo disponivel
			i++; // avanco para o proximo i
		}
	}
	
	//mostrando resultado
	cout << note << endl;
	
	return 0;
}