MAIN_SOURCE= main main.o list.o unity.o

all: main  run

main: main.o unity.o list.o
	gcc -o $(MAIN_SOURCE)

main.o : main.c list.h
	gcc -c main.c

list.o : list.c list.h
	gcc -c list.c

unitTest_list.o : ./test/unitTest_list.c ./test/unitTest_list.h lib.h
	gcc -c ./test/unitTest_list.c

unity.o: ./unity/unity.c ./unity/unity.h ./unity/unityinternals.h
	gcc -c ./unity/unity.c

run:main
	./main
