#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


#define TRUE 1
#define FALSE 0


//gli elementi sono inseriti per ogni slot dell'array
typedef struct List {
		void **array;
		size_t length; //lenght array
		size_t count_slot; //slot occupati dell'array
} List;


typedef struct Iterator {
		List *list;
		int current;
} Iterator;


/*=========COMMON=========*/
int is_empty(List *list);

void destroy_list(List *list);

void destroy_iterator(Iterator *it);

/*========================*/


List *new_list();

void *append(List *list, void *data);

void *insert_elem_position(List *list, void *data, int pos);

int *delete_last(List *list);

void delete_position(List *list, int pos);

//return value elem position pos
void *get_elem_position(List *list, int pos);

int get_lenght(List *list);

int get_count_slot(List *list);

void extend(List *list);

void reduce(List *list);

void shift_r(List *list, int pos);

void shift_l(List *list, int pos);









//----- FUNZIONI ITERATORE -------

Iterator *new_iterator(List *list);


int is_valid(Iterator *it);

void* get_current(Iterator *it);

void move_it_Next(Iterator *it);
