#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
//sort criteria macro
#define INCREASING 2
#define DECREASING 3


//element addresses stored foreach list slot
typedef struct _List List;
typedef struct _Iterator Iterator;

//return TRUE(1) if list is empty, FALSE(0) if not
int is_empty(List *list);

//deallocate and free all memory references of list
void destroy_list(List *list);

//return new list
List *new_list();

//add new element at the end of the list
int append(List *list, void *data);

//add new element at position pos of the list
int insert_data_position(List *list, void *data, int pos);

//delete last element from the list
int delete_last(List *list);

//delete element at position pos from list
int delete_data_position(List *list, int pos);

//return element at position pos from list
void *get_data_position(List *list, int pos);

//return size of list
int get_length(List *list);

//return not empty slot of list
int get_count_slot(List *list);

//extend slot of list, used by dynamic programming
void extend(List *list);

//reduce slot of list, used by dynamic programming
void reduce(List *list);



//----- ITERATOR'S FUNCTIONS -------

//return new iterator for list
Iterator *new_iterator(List *list);

//deallocate and free all memory references of iterator it
void destroy_iterator(Iterator *it);

//return TRUE(1) if iterator it is valid, FALSE(0) if not
int is_valid(Iterator *it);

//return current element point by iterator it
void *get_current(Iterator *it);

//move itertaor it to next element of list
void move_it_next(Iterator *it);


//---------- MERGE --------------

//return list merged by list l1 and list l2 with sort criteria
List *merge(List *l1, List *l2, int sort);

//print formatted list for terminal
void print_int_list(List *list);




