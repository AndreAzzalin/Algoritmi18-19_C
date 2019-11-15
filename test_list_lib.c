#include "list.h"
#include "unity/unity.h"

List *set_mock_list() {
	List *list = new_list();
	append(list, (void *) 1);
	append(list, (void *) 2);
	append(list, (void *) 3);
	append(list, (void *) 4);
	return list;
}

List *set_mock_list_single_element() {
	List *list = new_list();
	append(list, (void *) 1);
	return list;
}

// test list----------------------------

void test_is_empty() {
	List *mockList = set_mock_list_single_element();
	TEST_ASSERT_FALSE(is_empty(mockList));
	delete_last(mockList);
	TEST_ASSERT_TRUE(is_empty(mockList));
	destroy_list(mockList);
}

void test_append() {
	List *mockList = set_mock_list();
	TEST_ASSERT_EQUAL_PTR(mockList->tail, append(mockList, (void *) 3));
	destroy_list(mockList);
}

void test_append_empty_list() {
	List *emptyList = new_list();
	Node *newNode = append(emptyList, (void *) 3);
	TEST_ASSERT_EQUAL_PTR(emptyList->tail, newNode);
	TEST_ASSERT_EQUAL_PTR(emptyList->head, newNode);

	destroy_list(emptyList);
}

void test_insert_node_position_head() {
	List *mockList = set_mock_list();
	TEST_ASSERT_EQUAL_PTR(mockList->head, insert_node_position(mockList, (void *) 4, 0));
	destroy_list(mockList);
}

//qualcosa non funziona come dovrebbe se faccio il test con gli indirizzi dei ponters ritorna false
void test_insert_node_position_body() {
	List *mockList = set_mock_list();

	Node *newNode = insert_node_position(mockList, (void *) 4, 4);
	Node *posNode = get_node_position(mockList->head, 4);
	TEST_ASSERT_EQUAL_INT(newNode->data, newNode->data);

	destroy_list(mockList);
}

void test_delete_last_list_single_element() {
	List *mockList = set_mock_list_single_element();

	TEST_ASSERT_NULL(delete_last(mockList));
	destroy_list(mockList);
}

void test_deleteLast() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_PTR(mockList->tail, delete_last(mockList));
	destroy_list(mockList);
}

void test_delete_position_head() {
	List *mockList = set_mock_list();
	Node *newHeadMockList = mockList->head->next;

	delete_position(mockList, 0);
	TEST_ASSERT_EQUAL_PTR(newHeadMockList, mockList->head);
	destroy_list(mockList);
}

void test_delete_position_body() {
	List *mockList = set_mock_list();
	delete_position(mockList, 4);
	TEST_ASSERT_EQUAL_INT(3, mockList->length);
	destroy_list(mockList);
}

void test_get_node_position() {
	List *mockList = set_mock_list();
	TEST_ASSERT_EQUAL_PTR(mockList->head->next->next, get_node_position(mockList->head, 2));
	destroy_list(mockList);
}

void test_get_length() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(4, get_lenght(mockList));
	destroy_list(mockList);
}

void test_destroy_list() {
	List *mockList = set_mock_list_single_element();
	destroy_list(mockList);
	TEST_ASSERT_EQUAL_PTR(mockList->tail, NULL);
}

void test_move_next() {
	List *mockList = set_mock_list();
	Iterator *it = new_iterator(mockList);

	move_it_Next(it);

	TEST_ASSERT_EQUAL_PTR(mockList->head->next, it->curr);

	move_it_Next(it);

	TEST_ASSERT_EQUAL_PTR(mockList->head->next->next, it->curr);

	destroy_list(mockList);
	destroy_iterator(it);
}

void test_is_valid() {
	List *mockList = set_mock_list_single_element();
	Iterator *it = new_iterator(mockList);

	TEST_ASSERT_EQUAL_PTR(mockList->head, it->curr);

	TEST_ASSERT_TRUE(is_valid(it))

	move_it_Next(it);

	TEST_ASSERT_FALSE(is_valid(it))

	//TEST_ASSERT_FALSE(isValid(it))

	destroy_list(mockList);
	destroy_iterator(it);

}


/*
void test_returnFour() {
    TEST_ASSERT_EQUAL_INT(4, returnFour());
}*/

void printList_rec(Node *head) {
	if (head != NULL) {
		printf("[%d]->", *(int *) head->data);
		printList_rec(head->next);

	} else {
		printf(" EOL \n");
		return;
	}
}


void printList(List *l) {
/* Print all the elements in the linked list */
	printf("PRINTLIST:\n");
	Node *tmp = l->head;

	if (l->head == NULL) {    // myList->top == NULL || myList->size == 0
		printf("The List is Empty!\n");
		return;
	}

	while (tmp != NULL) {
		printf("%d ", *(int *) tmp->data);
		if (tmp->next != NULL)
			printf("-> ");
		tmp = tmp->next;
	}
	printf("\n");

}


int main(void) {

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int array2[] = {1};
	List *list = new_list();
	Iterator *it = new_iterator(list);

	printf("test starting\n");


	for (int i = 0; i < 10; ++i) {
		append(list, &array[i]);
	}


	printf("BEFORE:\n");

	printf("head: %d -- tail %d -- length %d\n\n", *(int *) list->head->data, *(int *) list->tail->data, list->length);

	printList_rec(list->head);

	//----------------TEST


	//  int x = 45;
	//insertNodePosition(list, &x, 2);
	//append(list, &x);
	// insertNodePosition(list, &x, 4);
	//insertNodePosition(list, &x, 8);
	//delete_last(list);
	//destroy_list(list);
	//deletePosition(list,0);
	//printf("isEmpty? %s\n", isEmpty(list) ? "true" : "false");

	// Node *tmp = getNodePosition(list->head, 4);
	//printf("getPosition 4 -> %d\n", *(int *) tmp->data);


	//---------------------------------------
	printf("\nAFTER:\n");

	if (list->head != NULL && list->tail != NULL) {
		printf("head: %d -- tail %d -- length %d\n\n", *(int *) list->head->data, *(int *) list->tail->data,
		       list->length);
	} else {
		printf("head: NULL -- tail NULL -- length %d\n\n", list->length);
	}

	//moveItNext(it);


	// printf("isvalid: %d -- %d\n", isValid(it),(int)it->curr->data);

	// printf("curr %d", *(int *) it->curr->data);

	printList_rec(list->head);
	//printList(list);


	printf("\n");
	UNITY_BEGIN();

	RUN_TEST(test_append);
	RUN_TEST(test_append_empty_list);

	RUN_TEST(test_insert_node_position_head);
	RUN_TEST(test_insert_node_position_body);

	RUN_TEST(test_deleteLast);
	RUN_TEST(test_delete_last_list_single_element);

	RUN_TEST(test_delete_position_head);
	RUN_TEST(test_delete_position_body);

	RUN_TEST(test_get_node_position);

	RUN_TEST(test_get_length);

	RUN_TEST(test_destroy_list);

	RUN_TEST(test_is_empty);

	/*---- ITERATORE ------*/

	RUN_TEST(test_move_next);

	RUN_TEST(test_is_valid);

	return UNITY_END();
}

