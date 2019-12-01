MAIN_SOURCE= test_dynamic_list test_dynamic_list.o dynamic_list.o unity.o merge.o

all: test_dynamic_list  run

test_dynamic_list: test_dynamic_list.o unity.o dynamic_list.o merge.o
	gcc -o $(MAIN_SOURCE)

test_dynamic_list.o : test_dynamic_list.c ../list.h
	gcc -c test_dynamic_list.c

list.o : dynamic_list.c ../list.h
	gcc -c dynamic_list.c

merge.o : ../merge.c ../list.h
	gcc -c ../merge.c

unity.o: ../unity/unity.c ../unity/unity.h ../unity/unityinternals.h
	gcc -c ../unity/unity.c

run:test_dynamic_list
	./test_dynamic_list
