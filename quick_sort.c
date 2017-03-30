#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int spare();

int spare_random_pivot();

void quick_sort();

int main(){

	srand(time(NULL));

	int *v, i;

	int v_size = 20;

	v = malloc(sizeof(int)*v_size);

	for(i=0;i<v_size;i++){

		v[i] = rand() % 100;

	}

	quick_sort(0, v_size-1, v);

	for(i=0;i<v_size;i++){

		printf("%d ", v[i]);

	}

	return 0;

}


void quick_sort(int p, int r, int v[]){

	int j;

	if (p < r){

		j = spare_random_pivot(p, r, v);

		quick_sort(p, j-1, v);

		quick_sort(j+1, r, v);

	}

}

int spare_random_pivot(int p, int r, int v[]){

	int i, t;

	//random position in vector

	i = (rand() % r) + p;

	t = v[p];
	
	v[p] = v[i];

	v[i] = t;

	return spare(p, r, v);

}


int spare(int p, int r, int v[]){

	int c, j, k, t;

	//pivo sera atribuido ao ultimo vetor

	c = v[r];

	j = p;

	for(k=p;k<r;k++){

		if(v[k] <= c){	

			t = v[j];

			v[j] = v[k];

			v[k] = t;

			j++;

		}

	}

	v[r] = v[j];

	v[j] = c;

	return j;

}