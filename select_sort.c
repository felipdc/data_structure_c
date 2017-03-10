#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int export_to_file(int size, double time_spent){

	FILE *fp;

	fp = fopen("/home/metalm/Desktop/version-control/data_c/execute_time.csv", "a");

	if(!fp){

		printf("Could not open file \n\n\n");

	}

	//char file_line[200];

	//int sprintf(*file_line, "%d, %f", size, time_spent);

	fprintf(fp, "%d, %f \n", size, time_spent);	

	fclose(fp);





}



int selection_sort(int size, int *num){


	clock_t begin = clock();

	int i, j;

	int x;

	int y;

	for(j=0;j<=size-1;j++){

		for(i=size-1; i>=j || num[i] > num[i-1];i--){

			x = num[i];

			if(num[i] <= num[i-1]){

				x = num[i-1];

				num[i-1] = num[i];

				num[i] = x;

			}

		}

	}

	clock_t end = clock();

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Selection sort com %d numeros executado em %f segundos ",size, time_spent);

	printf(" \n \n");

	export_to_file(size, time_spent);


}

int main(){

	unsigned int *num;

	unsigned int size = 2000;

	int i;

	while(size<=20000){

		num = malloc(sizeof(int)*size);

		srand(time(NULL));	

		for(i=0;i<=size-1;i++){

			num[i] = rand() % 100;

		}

		printf("Sorting with selection sort.... \n");

		selection_sort(size, num);

		size = size + 100;

	}

	return 0;

}