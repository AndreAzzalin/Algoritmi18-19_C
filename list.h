#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>





//errno impostato di default a 0 quando vi è un eccezione il SO assegna a quest avariabile il codice di errore
#define TEST_ERROR(x)  if(errno){\
 printf("[%d] Errore %d (%s) -> %s\n",getpid(),errno, strerror(errno),x);};

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

//il parametro list fa riferimento alla head della list

Node *new_node(void *data);

List *new_list();

int is_empty(List *list);

Node *append(List *list, void *data);

Node *insert_node_position(List *list, void *data, int pos);

Node *delete_last(List *list);

void delete_position(List *list, int pos);

Node *get_node_position(Node *listHead, int pos);

int get_lenght(List *list);

void destroy_list(List *list);

//----- FUNZIONI ITERATORE -------

Iterator *new_iterator(List *list);

void destroy_iterator(Iterator *it);


int is_valid(Iterator *it);

Node *get_current(Iterator *it);

void move_it_Next(Iterator *it);




