all: connections main.o my_mat.o

connections: my_mat.o main.o
	gcc -Wall -lm -o connections my_mat.o main.o

main.o: main.c
	gcc -Wall -c -lm main.c
	
my_mat.o: my_mat.c
	gcc -Wall -c -lm my_mat.c

clean:
	rm *.o connections