#include "list.h"


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

    moveItNext(it);

    TEST_ASSERT_EQUAL_PTR(mockList->head->next->next, it->curr);

    destroyList(mockList);
    destroyIterator(it);
}

void test_isValid() {
    List *mockList = setMockListOneElement();
    Iterator *it = newIterator(mockList);

    TEST_ASSERT_EQUAL_PTR(mockList->head, it->curr);

    TEST_ASSERT_TRUE(isValid(it))

    moveItNext(it);

    TEST_ASSERT_FALSE(isValid(it))

    //TEST_ASSERT_FALSE(isValid(it))

    destroyList(mockList);
    destroyIterator(it);

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
    List *list = newList();
    Iterator *it = newIterator(list);

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
    //deleteLast(list);
    //destroyList(list);
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
    RUN_TEST(test_append_EmptyList);

    RUN_TEST(test_insertNodePosition_head);
    RUN_TEST(test_insertNodePosition_body);

    RUN_TEST(test_deleteLast);
    RUN_TEST(test_deleteLast_ListSingleElement);

    RUN_TEST(test_deletePosition_head);
    RUN_TEST(test_deletePosition_body);

    RUN_TEST(test_getNodePosition);

    RUN_TEST(test_getLength);

    RUN_TEST(test_destroyList);

    RUN_TEST(test_isEmpty);

    /*---- ITERATORE ------*/

    RUN_TEST(test_moveNext);

    RUN_TEST(test_isValid);

    return UNITY_END();
}

