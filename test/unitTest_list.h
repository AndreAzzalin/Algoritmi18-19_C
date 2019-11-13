#include "../list.h"


List *setMockList();

List *setMockListOneElement();

// test list----------------------------

void test_isEmpty() ;

void test_append() ;

void test_append_EmptyList() ;

void test_insertNodePosition_head() ;

//qualcosa non funziona come dovrebbe se faccio il test con gli indirizzi dei ponters ritorna false
void test_insertNodePosition_body() ;

void test_deleteLast_ListSingleElement() ;

void test_deleteLast() ;

void test_deletePosition_head() ;

void test_deletePosition_body() ;

void test_getNodePosition() ;

void test_getLength() ;

void test_destroyList() ;

void test_moveNext() ;

void test_isValid() ;
