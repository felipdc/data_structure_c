#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{

	int idx;

	float x1;

	struct Node *next;

};

typedef struct Node cell;

void init_list(cell *List);

cell *alloc_for_node();

void append(cell *List, float value);

int len(cell *List);

int print_list(cell *List);

int print_content(cell *List, int pos);

int insert_cell(cell *List, float value, int pos);


int main(){

	cell *List = (cell*)malloc(sizeof(cell));

	init_list(List);

	//printf("%f\n", List->next->x1);

	append(List, 20);

	append(List, 30);

	//printf("%d\n", List->next->next->idx);

	//printf("%d\n",len(List));

	//insert_cell(List, 40, 1);

	insert_cell(List, 1, 3);

	//print_list(List);

	//print_content(List, 0);


}

void init_list(cell *List){

	List->next = NULL;

	List->idx = 0;

	List->x1 = 0;

}

cell *alloc_for_node(){

	cell *new = (cell*)malloc(sizeof(cell));

	if(new == NULL){

		printf("No memory avaliable \n");

		exit(0);

	}else{

		return new;
	}

}

void append(cell *List, float value){

	cell *new = alloc_for_node();

	new->next = NULL;

	if(List->next == NULL){

		List->next = new;

		new->idx = 1;

		new->x1 = value;

	}else{

		//run until finds the last cell

		cell *temp = List->next;

		while(temp->next != NULL){

			temp = temp->next;

		}

	temp->next = new;

	new->idx = temp->idx + 1;

	new->x1 = value;

	}

}

int len(cell *List){

	int len;

	if(List->next == NULL){

		len = 1;

		return len;

	}

	cell *temp = List->next;

	while(temp->next != NULL){

		temp = temp->next;

	}

	len = temp->idx + 1;

	free(temp);

	return len;

}

int print_list(cell *List){

	printf("[%f,", List->x1);

	if(List->next == NULL){

		printf("[ %f ]\n", List->x1);
		return 0;
	}

	cell *temp = List->next;

	while(temp->next != NULL){

		printf(" %f,", temp->x1);

		temp = temp->next;

	}

	printf(" %f]\n", temp->x1);

}

int print_content(cell *List, int pos){

	if(pos == 0){

	printf("Content of the %dth cell: %f\n", pos, List->x1);

	return 0;

	}

	cell *temp = List->next;

	while(pos != temp->idx){

		temp = temp->next;

		if(temp == NULL){

			printf("Element is out of range! \n");

			return -1;

		}

	}

	printf("Content of the %dth cell: %f\n", pos, temp->x1);

}

int insert_cell(cell *List, float value, int pos){

	if(pos+1 >= len(List)){

		printf("inserted here");

		append(List, value);

		return 0;

	}

	cell *temp = List->next;

	while(temp->idx != pos){

		temp = temp->next;

		printf("im here");

	}

	cell *new = alloc_for_node();

	new->x1 = value;

	cell *temp_old = temp->next;

	temp->next = new;

	new->next = temp_old;

	cell *temp_idx = new->next;

	while(temp->next !=NULL){

		temp->idx++;


	}




}




