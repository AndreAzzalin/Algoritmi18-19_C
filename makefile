MAIN_SOURCE= test_list_lib test_list_lib.o list.o unity.o

all: test_list_lib  run

test_list_lib: test_list_lib.o unity.o list.o
	gcc -o $(MAIN_SOURCE)

test_list_lib.o : test_list_lib.c list.h
	gcc -c test_list_lib.c

list.o : list.c list.h
	gcc -c list.c


unity.o: ./unity/unity.c ./unity/unity.h ./unity/unityinternals.h
	gcc -c ./unity/unity.c

run:test_list_lib
	./test_list_lib
