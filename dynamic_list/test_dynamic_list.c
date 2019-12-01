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
	List *mockList = set_mock_list_single_element();
	int x = -1;
	append(mockList, &x);

	TEST_ASSERT_EQUAL_INT(-1, *(int *) get_data_position(mockList, get_count_slot(mockList) - 1));
	destroy_list(mockList);

}

void test_insert_data_position() {
	List *mockList = set_mock_list();
	int x = -1;
	insert_data_position(mockList, &x, 3);

	TEST_ASSERT_EQUAL_INT(-1, *(int *) get_data_position(mockList, 3));
	destroy_list(mockList);

}

void test_delete_last() {
	List *mockList = set_mock_list();
	delete_last(mockList);

	TEST_ASSERT_EQUAL_INT(9, *(int *) get_data_position(mockList, 8));
	destroy_list(mockList);
}

void test_delete_data_position() {
	List *mockList = set_mock_list();


	int *old = get_data_position(mockList, 5);
	delete_data_position(mockList, 4);
	TEST_ASSERT_EQUAL_PTR(old, get_data_position(mockList, 4));
	destroy_list(mockList);
}

void test_get_data_position() {
	List *mockList = set_mock_list();
	TEST_ASSERT_EQUAL_INT(4, *(int *) get_data_position(mockList, 3));
	destroy_list(mockList);

}

void test_get_length() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(10, get_length(mockList));
	destroy_list(mockList);
}

void test_get_count_slot() {
	List *mockList = set_mock_list();

	TEST_ASSERT_EQUAL_INT(16, get_count_slot(mockList));
	destroy_list(mockList);
}

void test_extend() {
	List *mockList = set_mock_list_single_element();
	int x = 1;
	TEST_ASSERT_EQUAL_INT(2, get_count_slot(mockList));
	append(mockList, &x);
	append(mockList, &x);
	TEST_ASSERT_EQUAL_INT(4, get_count_slot(mockList));
	destroy_list(mockList);
}

void test_reduce() {
	List *mockList = set_mock_list();

	for (int i = 0; i < 7; ++i) {
		delete_last(mockList);
	}
	TEST_ASSERT_EQUAL_INT(8, get_count_slot(mockList));
}

void test_move_next() {
	List *mockList = set_mock_list();
	Iterator *it = new_iterator(mockList);
	move_it_next(it);
	TEST_ASSERT_EQUAL_PTR(get_data_position(mockList, 1), get_current(it));
	destroy_list(mockList);
	destroy_iterator(it);
}

void test_is_valid() {
	List *mockList = set_mock_list_single_element();
	Iterator *it = new_iterator(mockList);

	TEST_ASSERT_TRUE(is_valid(it))

	move_it_next(it);

	TEST_ASSERT_FALSE(is_valid(it))

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

	RUN_TEST(test_is_empty);
	RUN_TEST(test_append);
	RUN_TEST(test_insert_data_position);
	RUN_TEST(test_delete_last);
	RUN_TEST(test_delete_data_position);
	RUN_TEST(test_get_data_position);
	RUN_TEST(test_get_length);
	RUN_TEST(test_get_count_slot);
	RUN_TEST(test_extend);
	RUN_TEST(test_reduce);
	RUN_TEST(test_move_next);
	RUN_TEST(test_is_valid);
	RUN_TEST(test_merge);

	return UNITY_END();

}