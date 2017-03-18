#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int intercala();

int merge_sort();

int export_time_to_csv();

int main(){

	int i, size;

	int j = 0;
	
	int count = 1;

	int *num;

	while(count<=(pow(10,9))){

		size = count;

		num = malloc(sizeof(int)*size);

		for(i=0; i<=size-1; i++){

			num[i] = rand() % 100;

		}

		clock_t begin = clock(); //INICIANDO CONTAGEM DO TEMPO

		merge_sort(0,size,num); //INICIAR MERGE SORT

		clock_t end = clock(); // FIM DA CONTAGEM DO TEMPO

		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		printf("Merge sort com %d numeros executado em %f segundos ",size, time_spent);

		printf(" \n \n");

		export_time_to_csv(size, time_spent);

		free(num);

		count = pow(10, j);

		j++;

	}



}


int intercala(int p, int q, int r, int num[]){

	int k = 0;

	int i = p;

	int j = q;

	int *num_;

	num_ = malloc(sizeof(int)*(r-p));

	while(i < q && j < r){

		if(num[i] > num[j]){

			num_[k++] = num[j++];

		}else{

			num_[k++] = num[i++];

		}

	}

	while(i<q){

		num_[k++] = num[i++];

	}

	while(j<r){

		num_[k++] = num[j++];

	}

	for(i = p; i < r; i++){

		num[i] = num_[i-p];

	}

	free(num_);



}

int merge_sort(int p, int r, int num[]){


	if (p < r-1) {

		int q  = (p + r) / 2; //trunca valor automaticamente

		merge_sort(p, q, num); //recursao com a primeira metade

		merge_sort(q, r, num); //recursao com a segunda metade

		intercala(p, q, r, num); //chama intercala

	}



}


int export_time_to_csv(int size, double time_spent){

	FILE *fp;

	fp = fopen("execute_time_merge_sort.csv", "a");

	if(!fp){

		printf("Could not open file \n\n\n");

	}

	fprintf(fp, "%d, %f \n", size, time_spent);	

	fclose(fp);

}


