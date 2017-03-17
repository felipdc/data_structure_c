#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){

	srand(time(NULL));

	FILE *fp;

	fp = fopen("/home/metalm/Desktop/version-control/data_c/random_numbers.txt", "w");

	if (!fp){

		printf("Could not open file \n");

	}

	int i;
	unsigned int num;
	

	for(i=0;i<=100;i++){

		num = rand() % 100;

		fprintf(fp, "%d\n", num);

	}

	fclose(fp);

}