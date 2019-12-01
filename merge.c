#include "list.h"

List *merge(List *l1, List *l2, int sort) {
	List *merged_list = new_list();

	if (l1 != NULL && l2 != NULL) {

		Iterator *it1 = new_iterator(l1);
		Iterator *it2 = new_iterator(l2);

		while (is_valid(it1) || is_valid(it2)) {

			if (is_valid(it1) && is_valid(it2)) {
				// both iterator is valid
				if (sort == INCREASING) {
					append(merged_list, get_current(it1));
					move_it_next(it1);
				} else if (sort == DECREASING) {
					append(merged_list, get_current(it2));
					move_it_next(it2);
				}
			} else if (is_valid(it1)) {
				// just it1 is valid
				append(merged_list, get_current(it1));
				move_it_next(it1);
			} else {
				//just it2 is valid
				append(merged_list, get_current(it2));
				move_it_next(it2);
			}
		}
	}
	return merged_list;
}

void print_int_list(List *list) {
	Iterator *it = new_iterator(list);
	printf("\n--------- Stampo lista ----------\n");

	while (is_valid(it)) {
		printf("[%d]  ", *(int *) get_current(it));
		move_it_next(it);
	}
	printf("\n---------------------------------\n\n");

	destroy_iterator(it);

}

