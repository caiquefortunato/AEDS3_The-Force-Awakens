guloso: guloso.o main.o
		gcc guloso.o main.o -o tp2
main.o: main.c guloso.h
		gcc -g -c main.c
guloso.o: guloso.h guloso.c
		gcc -g -c guloso.c
clean:
		rm *.o *.gch
		rm guloso
