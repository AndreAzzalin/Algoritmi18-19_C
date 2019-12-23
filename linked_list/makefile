MAIN_SOURCE= test_linked_list test_linked_list.o linked_list.o unity.o merge.o

all: test_linked_list  run

test_linked_list: test_linked_list.o unity.o linked_list.o merge.o
	gcc -o $(MAIN_SOURCE)

test_linked_list.o : test_linked_list.c ../list.h
	gcc -c test_linked_list.c

linked_list.o : linked_list.c ../list.h
	gcc -c linked_list.c

merge.o : ../merge.c ../list.h
	gcc -c ../merge.c



unity.o: ../unity/unity.c ../unity/unity.h ../unity/unityinternals.h
	gcc -c ../unity/unity.c

run:test_linked_list
	./test_linked_list
