
#include "list.h"

#define TRUE 1
#define FALSE 0

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

Node *append(List *list, void *data) {
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
	}

	return new;
}

Node *insert_node_position(List *list, void *data, int pos) {

	Node *new = NULL;

	if (list != NULL) {
		new = new_node(data);

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
			Node *tmp = get_node_position(list->head, pos);

			tmp->prev->next = new;
			new->prev = tmp->prev;

			new->next = tmp;
			tmp->prev = new;

			list->length++;
		}
	}
	return new;
}

Node *delete_last(List *list) {

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

void delete_position(List *list, int pos) {

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
			delete_last(list);

		}
			//body
		else {
			Node *nodePos = get_node_position(list->head, pos);
			Node *tmpPrev = nodePos->prev;
			Node *tmpNext = nodePos->next;

			tmpPrev->next = tmpNext;
			tmpNext->prev = tmpPrev;

			free(nodePos);

			list->length--;
		}
	}

}

Node *get_node_position(Node *listHead, int pos) {
	if (pos == 0) {
		return listHead;
	} else {
		get_node_position(listHead->next, --pos);
	}
}

int get_lenght(List *list) {
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

//----- FUNZIONI ITERATORE -------

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

Node *get_current(Iterator *it) {
	return it->curr;
}

void move_it_Next(Iterator *it) {
	if (it->curr->next != NULL) {
		it->curr = it->curr->next;
	} else {
		it->valid = FALSE;
	}
	it->pos++;

}



