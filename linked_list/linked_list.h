#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


#define TRUE 1
#define FALSE 0


/*
 * elementi di una lista con riferiment del precedente e successore
 */
typedef struct Node {
		void *data;
		struct Node *next, *prev;
} Node;

/*
 * insieme di nodi con riferimento a testa, coda e numero di nodi
 */
typedef struct List {
		struct Node *head, *tail;
		int length;
} List;

typedef struct Iterator {
		struct List *list;
		struct Node *curr;
		int valid;
		int pos;
} Iterator;

//il parametro linked_list fa riferimento alla head della linked_list


Node *new_node(void *data);

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




