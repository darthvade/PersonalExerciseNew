edit: ./libo/main.o ./libo/quicksort_def.o ./libo/sort_def.o
	gcc -o demo ./libo/main.o ./libo/quicksort_def.o ./libo/sort_def.o
sort.o: ./src/main.c
	gcc -c ./src/main.c -o ./libo/main.o
quciksorti_def.o: ./src/quicksort_def.c ./src/quciksort.h
	gcc -c ./src/quicksort_def.c -o ./libo/quicksort_def.o
sort_def.o: ./src/sort_def.c ./src/sort.h
	gcc -c ./src/sort_def.c -o ./libo/sort_def.o
clean:
	rm demo ./libo/main.o ./libo/quicksort_def.o ./libo/sort_def.o
