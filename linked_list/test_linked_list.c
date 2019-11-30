#include "linked_list.h"
#include "../unity/unity.h"

List *set_mock_list() {
	List *list = new_list();
	append(list, (void *) 1);
	append(list, (void *) 2);
	append(list, (void *) 3);
	append(list, (void *) 4);
	append(list, (void *) 5);
	append(list, (void *) 6);
	append(list, (void *) 7);
	append(list, (void *) 8);
	append(list, (void *) 9);
	append(list, (void *) 10);
	return list;
}

List *set_mock_list_single_element() {
	List *list = new_list();
	append(list, (void *) 1);
	return list;
}

// test linked_list----------------------------

void test_is_empty() {
	List *mockList = set_mock_list_single_element();
	TEST_ASSERT_FALSE(is_empty(mockList));
	delete_last(mockList);
	TEST_ASSERT_TRUE(is_empty(mockList));
	destroy_list(mockList);
}

void test_append() {

	List *mockList = set_mock_list();
	append(mockList, (void *) 3);
	TEST_ASSERT_EQUAL_INT(3, mockList->tail->data);
	destroy_list(mockList);
}

void test_append_empty_list() {
	List *emptyList = new_list();
	append(emptyList, (void *) 3);

	TEST_ASSERT_EQUAL_INT(3, emptyList->tail->data);
	TEST_ASSERT_EQUAL_INT(3, emptyList->head->data);

	destroy_list(emptyList);
}

void test_insert_data_position_head() {
	List *mockList = set_mock_list();
	//insert element 4 to index 0
	insert_data_position(mockList, (void *) 4, 0);
	TEST_ASSERT_EQUAL_INT(4, mockList->head->data);

	destroy_list(mockList);
}

void test_insert_data_position_body() {
	List *mockList = set_mock_list();

	insert_data_position(mockList, (void *) 4, 4);

	TEST_ASSERT_EQUAL_INT(4, get_data_position(mockList, 4));

	destroy_list(mockList);
}

void test_delete_last_list_single_element() {
	List *mockList = set_mock_list_single_element();
	List *emptyList = new_list();


	TEST_ASSERT_EQUAL_INT(TRUE, delete_last(mockList));
	TEST_ASSERT_EQUAL_INT(FALSE, delete_last(emptyList));

	destroy_list(mockList);
}

void test_deleteLast() {
	List *mockList = set_mock_list();
	delete_last(mockList);

	TEST_ASSERT_EQUAL_INT(9, mockList->tail->data);
	destroy_list(mockList);
}

void test_delete_data_position_head() {
	List *mockList = set_mock_list();

	delete_data_position(mockList, 0);
	TEST_ASSERT_EQUAL_INT(2, mockList->head->data);
	destroy_list(mockList);
}

void test_delete_data_position_body() {

	List *mockList = set_mock_list();
	delete_data_position(mockList, 3);
	TEST_ASSERT_EQUAL_INT(9, mockList->length);
	destroy_list(mockList);
}

void test_get_data_position() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(3, get_data_position(mockList, 2));

	destroy_list(mockList);
}

void test_get_length() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(10, get_lenght(mockList));
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
/* Print all the elements in the linked linked_list */
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


int main() {

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


	// int x = 45;
	//insert_data_position(list, &x, 4);
	//append(linked_list, &x);
	// insertNodePosition(linked_list, &x, 4);
	//insertNodePosition(linked_list, &x, 8);
	//delete_last(linked_list);
	//destroy_list(linked_list);
	//deletePosition(linked_list,0);
	//printf("isEmpty? %s\n", isEmpty(linked_list) ? "true" : "false");

	// Node *tmp = getNodePosition(linked_list->head, 4);
	printf("getPosition 9 -> %d\n", *(int *) get_data_position(list, 9));


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


	printf("\n");
	UNITY_BEGIN();

	RUN_TEST(test_append);
	RUN_TEST(test_append_empty_list);

	RUN_TEST(test_insert_data_position_head);
	RUN_TEST(test_insert_data_position_body);

	RUN_TEST(test_deleteLast);
	RUN_TEST(test_delete_last_list_single_element);

	RUN_TEST(test_delete_data_position_head);
	RUN_TEST(test_delete_data_position_body);

	RUN_TEST(test_get_data_position);

	RUN_TEST(test_get_length);

	RUN_TEST(test_destroy_list);

	RUN_TEST(test_is_empty);

	/*---- ITERATORE ------*/

	RUN_TEST(test_move_next);

	RUN_TEST(test_is_valid);

	return UNITY_END();
}

