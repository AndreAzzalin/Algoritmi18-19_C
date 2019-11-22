#include "dynamic_list.h"


List *new_list() {
	List *list = (List *) malloc(sizeof(List));
	list->array = (void **) malloc(2 * sizeof(void *));
	list->length = 2;
	list->count_slot = 0;
	return list;
}


void destroy_list(List *list) {
	if (list) {
		free(list->array);
		free(list);
	}
}

int is_empty(List*list){
	if(list->count_slot)
		return TRUE;
	else
		return FALSE;
}


void *insert_elem_position(List *list, void *data, int pos);

int *delete_last(List *list);

void delete_position(List *list, int pos);

//return value elem position pos
void *get_elem_position(List *list, int pos);

int get_lenght(List *list);

int get_count_slot(List *list);

void shift_r(List *list, int pos);

void shift_l(List *list, int pos);


void *append(List *list, void *data) {
	if (list) {
		if (list->count_slot == list->length) {  //is full
			extend(list);
		}
		list->array[list->count_slot] = data;
		list->count_slot++;
	} else {
		printf("\nError! List is null");
	}
}


void extend(List *list) {
	if (list) {
		list->array = (void **) realloc(list->array, (list->length * 2) * sizeof(void *));
		list->length *= 2;
	}
}


void reduce(List *list) {
	if (list) {
		if (list->count_slot < list->length / 3) {
			list->array = (void **) realloc(list->array, (list->length / 2) * sizeof(void *));
			list->length /= 2;
		}
	}
}






