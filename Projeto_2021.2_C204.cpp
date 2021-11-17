#include <iostream> //mochila01
#include <iomanip>

using namespace std;

struct Arquivo
{
	int nivelImportancia; //nivel de importancia do arquivo
	int tamanho; // tamanho do arquivo em bytes
	int disponivel; // false para arquivo indisponível, true para disponível
};

int main() //complexidade O(n³)
{
	//Variaveis de entrada - linha de produção =========================================================================================
	int nPcs; // numero de computadores por linha
	int tProcessamento[2][100]; // a[i][j]: tempo de processamento do computador j da linha i -> a[0,4] = 8
	int tMudaLinha[2][100]; //t[i][j]: tempo pra ir do computador j da linha i para a outra linha -> t[0,4] = 4
	int tEntraLinha[2]; // e[i]: tempo de entrar na linha i
	int tSaiLinha[2]; // x[i]: tempo para sair da linha i

	////Variaveis que serao calculadas - linha de produção =============================================================================
	int TempoMin[2][100]; // menor tempo para levar um pacote desde a entrada ate o computador da linha "i" e computador "j"(acumulativo)
	int cLinha[2][100]; // salva o caminho de qual linha que o pacote chegou no computador 'j' da linha 'i'(sempre o caminho mais rapido)
	int MenorTempo; // f* -> menor tempo total
	int LinhaSaida; // l* -> linha cuja ultima estacao eh usada como o caminho mais rapido atraves de toda a rede

	//Variaveis - algoritimo mochila (pacotes)==========================================================================================
	int capacidade = 1460; // capacidade máxima do pacote
	int pd[100][1500]; // auxiliar pesquisa dinânica
	int caminho[100][1500]; // auxiliar caminho
	int pacote = 1; // auxiliar para criar pacotes
	int qdtArq; // quantidade de arquivos
	int disponiveis; // auxiliar para verificar arquvios disponiveis

	//ENTRADAS: =========================================================================================================================

	//quantidade de arquivos
	cin >> qdtArq;

	Arquivo arquivos[qdtArq]; // criando struct vetor de arquivos

	// lendo Número de computadores em cada linha
	cin >> nPcs;

	// Custo para entrar em cada linha
	for(int i = 0; i < 2; i++) // --> O(n) [análise assintótica]
		cin >> tEntraLinha[i];

	// Tempo de operação dos computadores em cada linha
	for(int i = 0; i < 2; i++) // --> O(n²) [análise assintótica]
		for(int j = 0; j < nPcs; j++)
			cin >> tProcessamento[i][j];

	// Tempo para mudar para a linha
	for(int i = 0; i < 2; i++) // --> O(n²) [análise assintótica]
		for(int j = 0; j < nPcs - 1; j++)
			cin >> tMudaLinha[i][j];

	// Custo para sair de cada linha
	for(int i = 0; i < 2; i++) // --> O(n²) [análise assintótica]
		cin >> tSaiLinha[i];

	//lendo informações dos arquivos
	for(int i = 0; i < qdtArq; i++) // --> O(n) [análise assintótica]
	{
		//entrando com importancia
		cin >> arquivos[i].nivelImportancia;
		//entrando com tamanho
		cin >> arquivos[i].tamanho;
		//definindo disponibilidade
		arquivos[i].disponivel = false;
	}

	//calculando menor custo atravez do algorítimo de linha de produção ============================================================START
	// inicializacao
	int custoFica, custoMuda; //Vars para salvar os dois possiveis custos, de ficar na linha e de mudar de linha

	// caso base
	TempoMin[0][0] = tEntraLinha[0] + tProcessamento[0][0]; //caso base
	TempoMin[1][0] = tEntraLinha[1] + tProcessamento[1][0]; //case base
	cLinha[0][0] = -1;
	cLinha[1][0] = -1;

	// caso geral
	for (int pc = 1; pc < nPcs; pc++) // --> O(n²) [análise assintótica]
	{
		for(int linha = 0; linha < 2; linha++)
		{
			// calculo os custos para continuar na linha ou mudar
			// O(n)
			if(linha == 0) //analisando possibilidades de chegar na computador [pc] da linha 0
			{
				//f[pc-1] porque deve se considerar o que ja foi gasto até o ponto anterior.
				custoFica = TempoMin[0][pc - 1] + tProcessamento[0][pc]; //mantive na linha 0
				custoMuda = TempoMin[1][pc - 1] + tMudaLinha[1][pc - 1] + tProcessamento[0][pc]; //troquei da linha 1 para 0
			}
			else //analisando possibilidades de chegar na computador [pc] da linha 1
			{
				custoFica = TempoMin[1][pc - 1] + tProcessamento[1][pc]; //mantive na linha 1
				custoMuda = TempoMin[0][pc - 1] + tMudaLinha[0][pc - 1] + tProcessamento[1][pc]; //troquei da linha 0 para 1
			}

			// avalio qual eh melhor
			if(custoFica < custoMuda) // chegar pela propria linha
			{
				TempoMin[linha][pc] = custoFica;
				cLinha[linha][pc] = linha;
			}
			else // (cussto2 < custo 1) chegar pela outra linha
			{
				TempoMin[linha][pc] = custoMuda;
				if(linha == 0)
					cLinha[linha][pc] = 1;
				else
					cLinha[linha][pc] = 0;
			}
		}
	}

	// calculo para sair da linha
	TempoMin[0][nPcs] = TempoMin[0][nPcs - 1] + tSaiLinha[0]; //(0,6)
	cLinha[0][nPcs] = 0;
	TempoMin[1][nPcs] = TempoMin[1][nPcs - 1] + tSaiLinha[1]; //(1,6)
	cLinha[1][nPcs] = 1;

	// analise do menor tempo total
	if(TempoMin[0][nPcs] < TempoMin[1][nPcs])
	{
		MenorTempo = TempoMin[0][nPcs];
		LinhaSaida = 0;
	}
	else
	{
		MenorTempo = TempoMin[1][nPcs];
		LinhaSaida = 1;
	}

	// Recuperacao do caminho ---- output
	// Caminho contrario
	int p; // auxiliar para salvar qual a linha final
	p = LinhaSaida;
	cout << "Melhor rota: " << endl;
	cout << "linha " << LinhaSaida << " computador " << nPcs - 1 << endl;
	for(int j = nPcs - 1; j > 0; j--) // --> O(n) [análise assintótica]
	{
		p = cLinha[p][j];
		cout << "linha " << p << " computador " << j - 1 << endl;
	}
	cout << endl;
	//calculando menor custo atravez do algorítimo de linha de produção ============================================================END

	//mostrando menor tempo --- output
	cout << "Menor tempo de processamento para 100 bytes: " << MenorTempo << endl;

	//definindo pacotes e mostrando pacotes + tempo de processamento - algotítimo da mochila adaptado =============================START
	double tempototal = 0; //auxiliar para salvar o tempo total gasto
	do // --> O(n³) [análise assintótica]
	{
		disponiveis = 0;
		// CASO BASE:
		// olhando do ultimo item para frente, val. maximo = 0
		for(int j = 0; j <= capacidade; j++) // --> O(n) [análise assintótica]
			pd[qdtArq][j] = 0;

		// olhando tendo uma mochila de capacidade 0, o val. maximo=0
		for(int i = 0; i <= qdtArq; i++) // --> O(n) [análise assintótica]
			pd[i][0] = 0;

		// CASO GERAL
		for(int i = qdtArq - 1; i >= 0; i--) // --> O(n²) [análise assintótica]
			for(int j = 1; j <= capacidade; j++)
			{
				int pega, npega; // val. para caso eu pegar ou nao pegar o item 'i'
				npega = pd[i + 1][j]; // olhar o proximo item, mantendo a capacidade 'j'
				if(j >= arquivos[i].tamanho && !arquivos[i].disponivel) // se eu tiver capacidade disponivel p/ pegar o item 'i'
					pega = pd[i + 1][j - arquivos[i].tamanho] + arquivos[i].nivelImportancia;
				// olho o proximo item, subtraio o peso da capacidade
				// disponivel, e somo o valor do item 'i'
				else
					pega = 0; // se nao posso pegar, o valor eh 0
				if(pega > npega) // se valer a pena pegar
				{
					pd[i][j] = pega;
					caminho[i][j] = 1;
				}
				else // se valer a pena nao pegar
				{
					pd[i][j] = npega;
					caminho[i][j] = 0;
				}
			}

		// RECUPERACAO
		// Comeca na posicao final
		int i, j;
		i = 0; // do item 0->final
		j = capacidade; // para uma mochila de capacidade max
		double packsize = 0;

		//cabeçalho do pacote atual
		cout << endl << "Pacote " << pacote << ":" << endl;
		while (i != qdtArq) // --> O(n) [análise assintótica]
		{
			if (caminho[i][j] == 0)
				i++;
			else //if(caminho [i][j] == 1)
			{
				cout << i << " ";
				j -= arquivos[i].tamanho;
				packsize += arquivos[i].tamanho;
				arquivos[i].disponivel = true;
				i++;
			}
		}

		//tempo de processamento --- output
		float packtime = (packsize / 100.0) * MenorTempo; // auxuliar para calcular tempo de processamento do pacote
		cout << endl;
		if(packtime != (int)packtime) // se tiver casa decimal
		{
			cout << fixed << setprecision(1); //definindo casas decimais
			cout << "Tempo para processar pacote: " << packtime << endl; // calculo do tempo de processamento por pacote considerando pacotes de 100 bytes.
		}
		else //se não tiver casa decimal
			cout << "Tempo para processar pacote: " << (int)packtime << endl;

		tempototal += packtime; //soma do tempo total

		//verificando o que ja foi utilizado
		for(int i = 0; i < qdtArq ; i++) // --> O(n) [análise assintótica]
		{
			if(arquivos[i].disponivel == false) //se ainda houver arquivos sem processar
				disponiveis++;
		}
		pacote++; //muda de pacote
	}
	while(disponiveis != 0); //verifica se todos os pacotes foram utilizados
	//definindo pacotes e mostrando pacotes + tempo de processamento - algotítimo da mochila adaptado ===============================END	
	
	//mostrando tempo total --- output
	cout << endl;
	if(tempototal != (int)tempototal) // se tiver casa decimal
	{
		cout << fixed << setprecision(1);
		cout << "Tempo total para processar todos os pacotes: " << tempototal << endl;
	}
	else //se não tiver casa decimal
		cout << "Tempo total para processar todos os pacotes: " << (int)tempototal << endl;

	return 0;
}






