#include "dynamic_list.h"
#include "../unity/unity.h"


void printList(List *list) {
	for (int i = 0; i < list->length; ++i) {
		printf("[%d]->", &list->array[i]);
	}
}

int main() {

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	List *list = new_list();

	for (int i = 0; i < 10; ++i) {
		append(list, &array[i]);
	}





}