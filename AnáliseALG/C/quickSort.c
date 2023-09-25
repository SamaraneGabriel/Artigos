#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE_10 10000 

	//Definção do algoritmo QuickSort
//==========================================================//
	void swap(int* a, int* b) {
	    int t = *a;
	    *a = *b;
	    *b = t;
	}
	
	int partition(int* arr, int low, int high) {
	    int pivot = arr[high];
	    int i = (low - 1);
	
	    for (int j = low; j <= high - 1; j++) {
	        if (arr[j] < pivot) {
	            i++;
	            swap(arr + i, arr + j);
	        }
	    }
	    swap(arr + (i + 1), arr + high);
	    return (i + 1);
	}
	
	void quickSort(int* arr, int low, int high) {
	    if (low < high) {
	        int pi = partition(arr, low, high);
	
	        quickSort(arr, low, pi - 1);
	        quickSort(arr, pi + 1, high);
	    }
	}

 //==========================================================//

	//Funções e Procedimentos usados no código

 //==========================================================//
 
	 /*Procedimento que popula o vetor com elementos aleatórios, relativos a uma seed específica
	  *@params: Apontador para primeira posicao de vetor de inteiros, inteiro "seed" contendo o valor da semente, inteiro relativo ao tamanho do vetor 
	  */
	 
	 void randomFillArray(int* arr, int seed, int arr_size){
	     srand(seed);
	     for(int i = 0 ; i < arr_size; i++){
	         arr[i] = rand() % 100;    
	     }
	 }
		
		/*Função que calcula a média de todos os valores de um vetor de doubles
		 *@params: Apontador para primeira posicao de vetor de reais longos (double), inteiro relativo ao tamanho do vetor
		 *@return: A media entre todos os elementos do vetor
		 */
	 
	double media(double* arr, int arr_size){
	    double media = 0;
	    if(arr != NULL && arr_size >= 0){
	        for(int i = 0; i < arr_size; i++){
	            media += arr[i];
	        }
	    }
	    else{
	        printf("ERRO");
	        media = -1;
	    }
	    return media/arr_size;
	}

	/*Procedimento que popula vetor com sequencia [0,arr_size-1]
	 *@params: Apontador para primeira posicao de vetor de inteiros, inteiro relativo ao tamanho do vetor
	 */

	void populaCrescente(int* arr, int arr_size){
		if(arr != NULL && arr_size >=0){
			for(int i = 0; i < arr_size; i++){
				arr[i] = i;
			}
		}
	}
 //=========================================================//

	int main(){

		int* arr = (int*) malloc(sizeof(int)*ARR_SIZE_10);

		double* tempo_desordenado = (double*) malloc(sizeof(double)*50);

		double* tempo_ordenado = (double*) malloc(sizeof(double)*50);

		int inicio, fim;

		double tempo;

		//Teste de tempo para array desordenado

		for(int i = 0; i < 50; i++){
			randomFillArray(arr,i,ARR_SIZE_10);
			
			inicio = clock();
        	quickSort(arr, 0, ARR_SIZE_10);
        	fim = clock();

		    tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        	tempo_desordenado[i] = tempo;
        	
		}

		printf("A média de tempo por ordenação do QuickSort em um array desordenado foi de: %lf\n",media(tempo_desordenado,50));

		free(arr);
		arr = NULL;

		arr = (int*) malloc(sizeof(int)*ARR_SIZE_10);

		for(int i = 0; i < 50; i++){
			populaCrescente(arr,ARR_SIZE_10);
			
			inicio = clock();
        	quickSort(arr, 0, ARR_SIZE_10);
        	fim = clock();

		    tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        	tempo_ordenado[i] = tempo;
        	
		}

		printf("A média de tempo por ordenação do QuickSort em um array ordenado foi de: %lf\n",media(tempo_ordenado,50));

		
	}
