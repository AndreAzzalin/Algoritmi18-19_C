#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


#define TRUE 1
#define FALSE 0

typedef struct _List List;

typedef struct _Iterator Iterator;


//il parametro linked_list fa riferimento alla head della linked_list


List *new_list();

int is_empty(List *list);


int append(List *list, void *data);

int insert_data_position(List *list, void *data, int pos);

//return last element updated
int delete_last(List *list);

int delete_data_position(List *list, int pos);

void *get_data_position(List *list, int pos);

int get_lenght(List *list);

void destroy_list(List *list);

//----- FUNZIONI ITERATORE -------

Iterator *new_iterator(List *list);

void destroy_iterator(Iterator *it);

int is_valid(Iterator *it);

void *get_current(Iterator *it);

void move_it_Next(Iterator *it);




