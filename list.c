
#include "list.h"

#define TRUE 1
#define FALSE 0


List *newList() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

Node *newNode(void *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Iterator *newIterator(List *list) {
    Iterator *it = (Iterator *) malloc(sizeof(Iterator));
    it->list = list;
    it->curr = list->head;
    it->pos = 0;
    it->valid = TRUE;

    return it;
}


int isEmpty(List *list) {
    if (list->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Node *append(List *list, void *data) {
    Node *new = NULL;

    if (list != NULL) {
        new = newNode(data);
        list->length++;

        if (list->head == NULL) {
            list->head = new;
            list->tail = new;

        } else {
            list->tail->next = new;
            new->prev = list->tail;
            list->tail = new;

        }
    }

    return new;
}

Node *insertNodePosition(List *list, void *data, int pos) {

    Node *new = NULL;

    if (list != NULL) {
        new = newNode(data);

        //head
        if (pos <= 0) {
            list->head->prev = new;

            new->next = list->head;
            list->head = new;

            list->length++;
        }
            //tail
        else if (pos >= list->length) {
            append(list, data);

        }
            //body
        else {
            Node *tmp = getNodePosition(list->head, pos);

            tmp->prev->next = new;
            new->prev = tmp->prev;

            new->next = tmp;
            tmp->prev = new;

            list->length++;
        }
    }
    return new;
}

Node *deleteLast(List *list) {

    if (list->length == 0) {
        return NULL;
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

    return list->tail;
}

void deletePosition(List *list, int pos) {

    if (list != NULL) {
        //head
        if (pos <= 0) {
            Node *tmp = list->head;

            list->head = list->head->next;
            list->head->prev = NULL;

            list->length--;

            free(tmp);
        }
            //tail
        else if (pos == list->length) {
            deleteLast(list);

        }
            //body
        else {
            Node *nodePos = getNodePosition(list->head, pos);
            Node *tmpPrev = nodePos->prev;
            Node *tmpNext = nodePos->next;

            tmpPrev->next = tmpNext;
            tmpNext->prev = tmpPrev;

            free(nodePos);

            list->length--;
        }
    }

}

Node *getNodePosition(Node *listHead, int pos) {
    if (pos == 0) {
        return listHead;
    } else {
        getNodePosition(listHead->next, --pos);
    }
}

int getLenght(List *list) {
    return list->length;
}

void destroyList(List *list) {
    while (list->length > 0) {
        deleteLast(list);
    }

    list->tail = NULL;
    list->head = NULL;


    free(list);
}

//----- FUNZIONI ITERATORE -------

void destroyIterator(Iterator *it) {
    free(it);
}

int isValid(Iterator *it) {
    return it->valid;
}

Node *getCurrent(Iterator *it) {
    return it->curr;
}

void moveItNext(Iterator *it) {
    if (it->curr->next != NULL) {
        it->curr = it->curr->next;
    } else {
        it->valid = FALSE;
    }
    it->pos++;

}



