MAIN_SOURCE= test_dynamic_list test_dynamic_list.o dynamic_list.o unity.o

all: test_dynamic_list  run

test_dynamic_list: test_dynamic_list.o unity.o dynamic_list.o
	gcc -o $(MAIN_SOURCE)

test_dynamic_list.o : test_dynamic_list.c dynamic_list.h
	gcc -c test_dynamic_list.c

list.o : dynamic_list.c dynamic_list.h
	gcc -c dynamic_list.c


unity.o: ../unity/unity.c ../unity/unity.h ../unity/unityinternals.h
	gcc -c ../unity/unity.c

run:test_dynamic_list
	./test_dynamic_list
