#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inserction_sort();


int main(){

	unsigned int *num;

	unsigned int size;

	int i;

	printf("Choose size: \n");

	scanf("%d", &size);

	num = malloc(sizeof(int)*size);

	for(i=0; i<=size-1; i++){

		num[i] = rand() % 100;

	}

	inserction_sort(size, num);


}


int inserction_sort(int size, int *num){

	int i, j, x, y;
	int min = 101;

	for(j=0;j<=size-1;j++){

		min = 101;

		for(i=j;i<=size-1;i++){

			if(num[i] < min){

				min = num[i];

				y = i;

			}	

		}

		x = num[j];

		num[j] = min;

		num[y] = x;

	}

	for(i=0;i<=size-1;i++){

		printf("%d ", num[i]);

	}

}