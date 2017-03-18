#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int intercala();

int merge_sort();

int main(){

	int i, size;

	int *num;

	printf("Choose size: \n");

	scanf("%d", &size);

	num = malloc(sizeof(int)*size);

	for(i=0; i<=size-1; i++){

		num[i] = rand() % 100;

	}

	for(i=0;i<size;i++){

		printf("%d ", num[i]);

	}

	printf("\n");

	merge_sort(0,size,num);

	for(i=0;i<size;i++){

		printf("%d ", num[i]);

	}

	printf("\n");

}


int intercala(int p, int q, int r, int num[]){

	int k = 0;

	int i = p;

	int j = q;

	int *num_;

	num_ = malloc(sizeof(int)*(r-p));

	while(i < q && j < r){

		if(num[i] > num[j]){

			num_[k] = num[j];

			k++;

			j++;

		}else{

			num_[k] = num[i];

			k++;

			i++;

		}

	}

	while(i<q){

		num_[k] = num[i];

		k++;

		i++;

	}

	while(j<r){

		num_[k] = num[j];

		k++;

		j++;

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


