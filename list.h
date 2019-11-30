#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


#define TRUE 1
#define FALSE 0

//gli indirizzi degli elementi sono inseriti per ogni slot dell'array
typedef struct _List List;

typedef struct _Iterator Iterator;

typedef struct _Node Node;


int is_empty(List *list);

void destroy_list(List *list);

List *new_list();

int append(List *list, void *data);

int insert_data_position(List *list, void *data, int pos);

int delete_last(List *list);

int delete_data_position(List *list, int pos);

//return value elem position pos
void *get_data_position(List *list, int pos);

int get_lenght(List *list);

int get_count_slot(List *list);

void extend(List *list);

void reduce(List *list);





//----- FUNZIONI ITERATORE -------

Iterator *new_iterator(List *list);

void destroy_iterator(Iterator *it);

int is_valid(Iterator *it);

void *get_current(Iterator *it);

void move_it_next(Iterator *it);


