#include "../list.h"


struct _Iterator {
    //reference to list
    List *list;
    //reference to current element
    void *curr;
    //reference to current position of iterator on list
    int pos;
};

struct _List {
    void **array;
    //lenght array
    size_t length;
    //not empty slot of array
    size_t count_slot;
};


List *new_list() {
    List *list = (List *) malloc(sizeof(List));
    list->array = (void **) malloc(2 * sizeof(void *));
    list->length = 0;
    list->count_slot = 2;
    return list;
}


//----- UTIL -----

void shift_forward(List *list, int pos) {
    for (int i = list->length; pos < i; i--) {
        list->array[i] = list->array[i - 1];
    }
}

void shift_backward(List *list, int pos) {
    int length = list->length - 1;
    for (int i = pos; i < length; i++)
        list->array[i] = list->array[i + 1];
}

//-----------------


void destroy_list(List *list) {
    if (list) {
        free(list->array);
        free(list);
    }
}

int is_empty(List *list) {
    if (list->length == 0)
        return TRUE;
    else
        return FALSE;
}

int insert_data_position(List *list, void *data, int pos) {
    if (pos < 0) {
        return FALSE;
    } else if (pos > list->length) {
        return FALSE;
    }

    shift_forward(list, pos);

    list->array[pos] = data;
    list->length++;
    extend(list);

    return TRUE;
}

int delete_last(List *list) {
    if (list->length > 0) {
        list->array[list->length - 1] = NULL;
        list->length--;
        reduce(list);
        return TRUE;
    }
    return FALSE;
}

int delete_data_position(List *list, int pos) {

    if (pos < 0) {
        return FALSE;
    } else if (pos > list->length) {
        return FALSE;
    }

    shift_backward(list, pos);
    delete_last(list);
    reduce(list);

    return TRUE;
}

void *get_data_position(List *list, int pos) {
    if (list != NULL && pos < list->length)
        return list->array[pos];
    else
        return NULL;
}

int get_length(List *list) {
    return list->length;
}

int get_count_slot(List *list) {
    return list->count_slot;
}

int append(List *list, void *data) {
    if (list) {

        extend(list);// extend if full

        list->array[list->length] = data;
        list->length++;
        return TRUE;
    } else {
        return FALSE;
    }
}

void extend(List *list) {
    //check if slot need to be extended
    if (list && (list->count_slot == list->length)) {
        list->array = (void **) realloc(list->array, (list->count_slot * 2) * sizeof(void *));
        list->count_slot *= 2;
    }
}

void reduce(List *list) {
        //check if slot need to be reduced
        if (list->length < list->count_slot / 3) {
            list->array = (void **) realloc(list->array, (list->count_slot / 2) * sizeof(void *));
            list->count_slot /= 2;
    }
}

//----- ITERATOR'S FUNCTIONS -------

Iterator *new_iterator(List *list) {
    Iterator *it = (Iterator *) malloc(sizeof(Iterator));
    it->list = list;
    it->pos = 0;
    it->curr = list->array[0];
    return it;

}

int is_valid(Iterator *it) {
    if (it->pos < it->list->length)
        return TRUE;
    else
        return FALSE;
}

void *get_current(Iterator *it) {
    return it->curr;
}

void move_it_next(Iterator *it) {
    if (it->pos < it->list->length) {

        it->pos = it->pos+1;
        it->curr = it->list->array[it->pos];
    }
}

void destroy_iterator(Iterator *it) {
    free(it);
}




