#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q)
{

	int h; // valor utilizado para calculo de hash
	int p = 0; // padrao convertido para inteiro
	int t = 0; // texto convertido para inteiro

	//novas variaveis
	int v[100]; //recebe as posições
	int contador = 0; //recebe quantas vezes
	
	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i]-'0')) % q; // converte o padrao
		t = (d * t + (T[i]-'0')) % q; // converte o texto para o primeiro valor (t0)
	}
	
	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash
	
	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) // Se encontrei um valor de hash valido
		{
			// Verifico se ha diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
				{
					break;
				}
			}

			if(j == tamP){
				v[contador] = i;
				contador++;
			}
			
		}

		if(i < tamT - tamP) // se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i]-'0') * h ) + (T[i + tamP]-'0')) % q; // atualizo o ti para ti+1
			if(t < 0) t += q;
		}
	}

	if(contador != 0){
		cout << "Ultima ocorrencia: " << v[contador - 1] << endl;
		cout << contador << " ocorrencia(s)" << endl;
	}
	else
	{
		cout << contador << " ocorrencia(s)" << endl;
	}

}

int main()
{

	//variaveis
	char texto[100];
	char padrao[100];
	int m; //tamanho do texto
	int n; //tamanho do padrão
	int q = 13; // numero primo grande, para calcular os valores no hash
	
	//lendo tamanhos
	cin >> m >> n;
	
	//cout << "Digite o texto: ";
	cin >> texto;
	
	//cout << "Agora, digite o padrao a ser buscado: ";
	cin >> padrao;

	//chamando função rabin karp
	rabin_karp(texto, padrao, m, n, m, q);

	
	return 0;
}





