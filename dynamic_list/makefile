MAIN_SOURCE= test_list test_list.o list.o unity.o

all: test_list  run

test_list: test_list.o unity.o list.o
	gcc -o $(MAIN_SOURCE)

test_list.o : test_list.c list.h
	gcc -c test_list.c

list.o : list.c list.h
	gcc -c list.c


unity.o: ../unity/unity.c ../unity/unity.h ../unity/unityinternals.h
	gcc -c ../unity/unity.c

run:test_list
	./test_list
