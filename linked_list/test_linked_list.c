#include "../list.h"
#include "../unity/unity.h"

List *set_mock_list() {
	List *list = new_list();
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < 10; ++i) {
		append(list, &array[i]);
	}
	return list;
}

List *set_mock_list_single_element() {
	List *list = new_list();
	int x = 1;
	append(list, &x);
	return list;
}



void test_is_empty() {
	List *mockList = set_mock_list_single_element();
	TEST_ASSERT_FALSE(is_empty(mockList));
	delete_last(mockList);
	TEST_ASSERT_TRUE(is_empty(mockList));
	destroy_list(mockList);
}

void test_append() {

	List *mockList = set_mock_list();
	int x = 3;
	append(mockList, &x);

	TEST_ASSERT_EQUAL_INT(3, *(int *) get_data_position(mockList, 10));
	destroy_list(mockList);
}

void test_append_empty_list() {
	List *emptyList = new_list();
	int x = 3;
	append(emptyList, &x);
	TEST_ASSERT_EQUAL_INT(3, *(int *) get_data_position(emptyList, 0));
	destroy_list(emptyList);
}

void test_insert_data_position_head() {
	List *mockList = set_mock_list();
	//insert element 4 to index 0
	insert_data_position(mockList, (void *) 4, 0);
	TEST_ASSERT_EQUAL_INT(4, get_data_position(mockList, 0));

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

void test_delete_last() {
	List *mockList = set_mock_list();
	delete_last(mockList);

	TEST_ASSERT_EQUAL_INT(9, *(int *) get_data_position(mockList, 8));
	destroy_list(mockList);
}

void test_delete_data_position_head() {
	List *mockList = set_mock_list();

	delete_data_position(mockList, 0);

	TEST_ASSERT_EQUAL_INT(0, *(int *) get_data_position(mockList, 0));
	destroy_list(mockList);
}

void test_delete_data_position_body() {

	List *mockList = set_mock_list();
	delete_data_position(mockList, 3);
	TEST_ASSERT_EQUAL_INT(9, get_length(mockList));
	destroy_list(mockList);
}

void test_get_data_position() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(3, *(int *) get_data_position(mockList, 2));

	destroy_list(mockList);
}

void test_get_length() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(10, get_length(mockList));
	destroy_list(mockList);
}

void test_move_next() {
	List *mockList = set_mock_list();
	Iterator *it = new_iterator(mockList);

	move_it_next(it);

	TEST_ASSERT_EQUAL_PTR(get_data_position(mockList, 1), get_current(it));

	move_it_next(it);

	TEST_ASSERT_EQUAL_PTR(get_data_position(mockList, 2), get_current(it));

	destroy_list(mockList);
	destroy_iterator(it);
}

void test_is_valid() {
	List *mockList = set_mock_list_single_element();
	Iterator *it = new_iterator(mockList);

	TEST_ASSERT_EQUAL_PTR(get_data_position(mockList, 0), get_current(it));

	TEST_ASSERT_TRUE(is_valid(it))

	move_it_next(it);

	TEST_ASSERT_FALSE(is_valid(it))

	destroy_list(mockList);
	destroy_iterator(it);

}

void test_merge() {

	List *mock_l1 = new_list();
	List *mock_l2 = new_list();

	int a[] = {1, 2, 3};
	int b[] = {4, 5, 6};

	for (int i = 0; i < 3; ++i) {
		append(mock_l1, &a[i]);
		append(mock_l2, &b[i]);
	}

	List *merged_list = merge(mock_l1, mock_l2, INCREASING);

	print_int_list(mock_l1);
	print_int_list(mock_l2);
	print_int_list(merged_list);

	int i = 0;
	int j = 3;
	while (i < 3 && j < 6) {
		TEST_ASSERT_EQUAL_INT(*(int *) get_data_position(mock_l1, i), *(int *) get_data_position(merged_list, i));
		TEST_ASSERT_EQUAL_INT(get_data_position(mock_l2, i), get_data_position(merged_list, j));
		i++, j++;
	}
}


int main() {


	UNITY_BEGIN();

	RUN_TEST(test_append);
	RUN_TEST(test_append_empty_list);

	RUN_TEST(test_insert_data_position_head);
	RUN_TEST(test_insert_data_position_body);

	RUN_TEST(test_delete_last);
	RUN_TEST(test_delete_last_list_single_element);

	RUN_TEST(test_delete_data_position_head);
	RUN_TEST(test_delete_data_position_body);

	RUN_TEST(test_get_data_position);

	RUN_TEST(test_get_length);

	RUN_TEST(test_is_empty);

	/*---- ITERATORE ------*/

	RUN_TEST(test_move_next);

	RUN_TEST(test_is_valid);

	return UNITY_END();
}

