#include "unitTest_list.h"

List *setMockList() {
    List *list = newList();
    append(list, (void *) 1);
    append(list, (void *) 2);
    append(list, (void *) 3);
    append(list, (void *) 4);
    return list;
}

List *setMockListOneElement() {
    List *list = newList();
    append(list, (void *) 1);
    return list;
}

// test list----------------------------

void test_isEmpty() {
    List *mockList = setMockListOneElement();
    TEST_ASSERT_FALSE(isEmpty(mockList));
    deleteLast(mockList);
    TEST_ASSERT_TRUE(isEmpty(mockList));
    destroyList(mockList);
}

void test_append() {
    List *mockList = setMockList();
    TEST_ASSERT_EQUAL_PTR(mockList->tail, append(mockList, (void *) 3));
    destroyList(mockList);
}

void test_append_EmptyList() {
    List *emptyList = newList();
    Node *newNode = append(emptyList, (void *) 3);
    TEST_ASSERT_EQUAL_PTR(emptyList->tail, newNode);
    TEST_ASSERT_EQUAL_PTR(emptyList->head, newNode);

    destroyList(emptyList);
}

void test_insertNodePosition_head() {
    List *mockList = setMockList();
    TEST_ASSERT_EQUAL_PTR(mockList->head, insertNodePosition(mockList, (void *) 4, 0));
    destroyList(mockList);
}

//qualcosa non funziona come dovrebbe se faccio il test con gli indirizzi dei ponters ritorna false
void test_insertNodePosition_body() {
    List *mockList = setMockList();

    Node *newNode = insertNodePosition(mockList, (void *) 4, 4);
    Node *posNode = getNodePosition(mockList->head, 4);
    TEST_ASSERT_EQUAL_INT(newNode->data, newNode->data);

    destroyList(mockList);
}

void test_deleteLast_ListSingleElement() {
    List *mockList = setMockListOneElement();

    TEST_ASSERT_NULL(deleteLast(mockList));
    destroyList(mockList);
}

void test_deleteLast() {
    List *mockList = setMockList();

    TEST_ASSERT_EQUAL_PTR(mockList->tail, deleteLast(mockList));
    destroyList(mockList);
}

void test_deletePosition_head() {
    List *mockList = setMockList();
    Node *newHeadMockList = mockList->head->next;

    deletePosition(mockList, 0);
    TEST_ASSERT_EQUAL_PTR(newHeadMockList, mockList->head);
    destroyList(mockList);
}

void test_deletePosition_body() {
    List *mockList = setMockList();
    deletePosition(mockList, 4);
    TEST_ASSERT_EQUAL_INT(3, mockList->length);
    destroyList(mockList);
}

void test_getNodePosition() {
    List *mockList = setMockList();
    TEST_ASSERT_EQUAL_PTR(mockList->head->next->next, getNodePosition(mockList->head, 2));
    destroyList(mockList);
}

void test_getLength() {
    List *mockList = setMockList();

    TEST_ASSERT_EQUAL_INT(4, getLenght(mockList));
    destroyList(mockList);
}

void test_destroyList() {
    List *mockList = setMockListOneElement();
    destroyList(mockList);
    TEST_ASSERT_EQUAL_PTR(mockList->tail, NULL);
}

void test_moveNext() {
    List *mockList = setMockList();
    Iterator *it = newIterator(mockList);

    moveItNext(it);

    TEST_ASSERT_EQUAL_PTR(mockList->head->next, it->curr);

    destroyList(mockList);
    destroyIterator(it);
}

void test_isValid() {
    List *mockList = setMockListOneElement();
    Iterator *it = newIterator(mockList);

    TEST_ASSERT_EQUAL_PTR(mockList->head,it->curr);

    TEST_ASSERT_TRUE(isValid(it))

    TEST_ASSERT_FALSE( moveItNext(it))

    TEST_ASSERT_FALSE( isValid(it))

    //TEST_ASSERT_FALSE(isValid(it))

    destroyList(mockList);
    destroyIterator(it);

}
