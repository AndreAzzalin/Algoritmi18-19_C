#include "list.h"

/*
https://www.geeksforgeeks.org/merge-two-sorted-arrays/
 */

/*
 * function complexity O(n1 + n2)
 * The idea is to use Merge function of Merge sort.
 * Pick smaller or bigger (depends on sort criteria) of current elements in l1 and l2 and append it to merged list.
 * If there are remaining elements in l1 or l2, copy them also in merged list.
 */
List *merge(List *l1, List *l2, int sort) {
    List *merged_list = new_list();

    if (l1 != NULL && l2 != NULL) {

        Iterator *it1 = new_iterator(l1);
        Iterator *it2 = new_iterator(l2);

        while (is_valid(it1) || is_valid(it2)) {

            //first element must be < or > of second element, depends on sort criteria
            if (sort == INCREASING) {
                if (*(int *) get_current(it1) < *(int *) get_current(it2)) {
                    append(merged_list, get_current(it1));
                    move_it_next(it1);

                } else if (*(int *) get_current(it1) == *(int *) get_current(it2)) {
                    //if elements are equals insert once to merged list
                    append(merged_list, get_current(it1));
                    move_it_next(it1);
                    move_it_next(it2);
                } else {
                    append(merged_list, get_current(it2));
                    move_it_next(it2);
                }
            } else {
                if (*(int *) get_current(it1) > *(int *) get_current(it2)) {
                    append(merged_list, get_current(it1));
                    move_it_next(it1);
                } else if (*(int *) get_current(it1) == *(int *) get_current(it2)) {
                    append(merged_list, get_current(it1));
                    move_it_next(it1);
                    move_it_next(it2);
                } else {
                    append(merged_list, get_current(it2));
                    move_it_next(it2);
                }
            }

            // append remaining elements of first list to merged list
            while (!is_valid(it2) && is_valid(it1)) {
                append(merged_list, get_current(it2));
                move_it_next(it1);
            }

            // append remaining elements of second list to merged list
            while (!is_valid(it1) && is_valid(it2)) {
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

