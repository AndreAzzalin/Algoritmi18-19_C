#include "dynamic_list.h"






List *new_list() {
	List *list = (List *) malloc(sizeof(List));
	list->array = (void **) malloc(2 * sizeof(void *));
	list->length = 2;
	list->count_slot = 0;
	return list;
}


/*===UTIL===*/

void shift_forward(List *list, int pos) {
	for (int i = list->count_slot; pos < i; i--) {
		list->array[i] = list->array[i - 1];
	}
}

void shift_backward(List *list, int pos) {
	int length = list->count_slot - 1;
	for (int i = pos; i < length; i++)
		list->array[i] = list->array[i + 1];
}

/*=========*/



void destroy_list(List *list) {
	if (list) {
		free(list->array);
		free(list);
	}
}

int is_empty(List *list) {
	if (list->count_slot > 0)
		return FALSE;
	else
		return TRUE;
}

int insert_data_position(List *list, void *data, int pos) {
	if (pos < 0) {
		return FALSE;
	} else if (pos > list->count_slot) {
		return FALSE;
	}

	shift_forward(list, pos);

	list->array[pos] = data;
	list->count_slot++;
	extend(list);

	return TRUE;
}

int delete_last(List *list) {
	if (list->count_slot > 0) {
		list->array[list->count_slot - 1] = NULL;
		list->count_slot--;
		reduce(list);
		return TRUE;
	}
	return FALSE;
}

int delete_data_position(List *list, int pos) {

	if (pos < 0) {
		return FALSE;
	} else if (pos > list->count_slot) {
		return FALSE;
	}

	shift_backward(list, pos);
	delete_last(list);
	reduce(list);

	return TRUE;
}

//return value elem position pos
void *get_data_position(List *list, int pos) {
	if (list && pos > 0 && pos < list->count_slot)
		return list->array[pos];
	else
		return NULL;
}

int get_lenght(List *list) {
	return list->length;
}

int get_count_slot(List *list) {
	return list->count_slot;
}


int append(List *list, void *data) {
	if (list) {

		extend(list);// extend if full

		list->array[list->count_slot] = data;
		list->count_slot++;
		return TRUE;
	} else {
		return FALSE;
	}
}

void extend(List *list) {
	if (list && (list->count_slot == list->length)) {
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

//----- FUNZIONI ITERATORE -------

Iterator *new_iterator(List *list) {
	Iterator *it = (Iterator *) malloc(sizeof(Iterator));
	it->list = list;
	it->pos = 0;
	it->curr = list->array[0];

	return it;
}


int is_valid(Iterator *it) {
	if (it->pos < it->list->count_slot)
		return TRUE;
	else
		return FALSE;
}

void *get_current(Iterator *it) {
	return it->curr;
}

void move_it_Next(Iterator *it) {
	if (it->pos < it->list->count_slot) {
		it->pos++;
		it->curr = it->list->array[it->pos];
	}
}


void destroy_iterator(Iterator *it) {
	free(it);
}




