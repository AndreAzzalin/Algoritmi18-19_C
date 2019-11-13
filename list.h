#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "unity/unity.h"



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

Node *newNode(void *data);

List *newList();

int isEmpty(List *list);

Node *append(List *list, void *data);

Node *insertNodePosition(List *list, void *data, int pos);

Node *deleteLast(List *list);

void deletePosition(List *list, int pos);

Node *getNodePosition(Node *listHead, int pos);

int getLenght(List *list);

void destroyList(List *list);

//----- FUNZIONI ITERATORE -------

Iterator *newIterator(List *list);

int isValid(Iterator *it);

Node *getCurrent(Iterator *it);

void moveItNext(Iterator *it);

void destroyIterator(Iterator *it);


