#include "../list.h"


typedef struct Node {
    void *data;
    //reference to next node
    struct Node *next;
    //refence to previous node
    struct Node *prev;
} Node;

/*
 * insieme di nodi con riferimento a testa, coda e numero di nodi
 */
struct _List {
    //reference to list's head
    Node *head;
    //reference to list's tail
    Node *tail;
    int length;
};

struct _Iterator {
    List *list;
    Node *curr;
    int valid;
    int pos;
};


//----- UTIL -----

Node *get_node_position(Node *listHead, int pos) {
    if (pos == 0) {
        return listHead;
    } else {
        return get_node_position(listHead->next, --pos);
    }
}

//-----------------



Node *new_node(void *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

List *new_list() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

int is_empty(List *list) {
    if (list->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int append(List *list, void *data) {
    Node *new = NULL;

    if (list != NULL) {
        new = new_node(data);
        list->length++;

        if (list->head == NULL) {
            list->head = new;
            list->tail = new;

        } else {
            list->tail->next = new;
            new->prev = list->tail;
            list->tail = new;
        }
        return TRUE;
    }
    return FALSE;
}

int insert_data_position(List *list, void *data, int pos) {

    Node *new = NULL;

    if (list != NULL) {
        new = new_node(data);

        //pos is head
        if (pos <= 0) {
            list->head->prev = new;

            new->next = list->head;
            list->head = new;

            list->length++;
        }
            //pos is tail
        else if (pos >= list->length - 1) {
            append(list, data);

        }
            //pos is between head and tail
        else {
            Node *tmp = get_node_position(list->head, pos);

            tmp->prev->next = new;
            new->prev = tmp->prev;
            new->next = tmp;
            tmp->prev = new;

            list->length++;
        }
        return TRUE;
    }
    return FALSE;
}

int delete_last(List *list) {

    if (list->length < 1) {
        return FALSE;
    } else if (list->length == 1) {
        Node *tmp = list->tail;
        list->head = NULL;
        list->tail = NULL;
        free(tmp);
    } else {
        Node *tmp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(tmp);
    }
    list->length--;

    return TRUE;
}

int delete_data_position(List *list, int pos) {

    if (list != NULL) {
        //pos is head
        if (pos == 0) {
            Node *tmp = list->head;

            list->head = tmp->next;
            list->head->prev = NULL;

            list->length--;

            free(tmp);
        }
            //pos is tail
        else if (pos == list->length) {
            delete_last(list);

        }
            //pos is between head and tail
        else {
            Node *nodePos = get_node_position(list->head, pos);
            Node *tmpPrev = nodePos->prev;
            Node *tmpNext = nodePos->next;

            tmpPrev->next = tmpNext;
            tmpNext->prev = tmpPrev;

            free(nodePos);

            list->length--;
        }
        return TRUE;
    }

    return FALSE;

}

void *get_data_position(List *list, int pos) {
    Node *it = list->head;

    for (int i = 0; i < pos; ++i) {
        it = it->next;
    }
    return it->data;
}

int get_length(List *list) {
    return list->length;
}

void destroy_list(List *list) {
    while (list->length > 0) {
        delete_last(list);
    }

    list->tail = NULL;
    list->head = NULL;

    free(list);
}


//----- ITERATOR'S FUNCTIONS -------

Iterator *new_iterator(List *list) {
    Iterator *it = (Iterator *) malloc(sizeof(Iterator));

    it->list = list;
    it->curr = list->head;
    it->pos = 0;
    it->valid = TRUE;

    return it;
}

void destroy_iterator(Iterator *it) {
    free(it);
}

int is_valid(Iterator *it) {
    return it->valid;
}

void *get_current(Iterator *it) {
    return it->curr->data;
}

void move_it_next(Iterator *it) {
    if (it->curr->next != NULL) {
        it->curr = it->curr->next;
    } else {
        it->valid = FALSE;
    }
    it->pos++;

}



