main: ./obj/stu_sort_def.o
	gcc -o demo main.c ./obj/stu_sort_def.o -I./include -g
./obj/stu_sort_def.o: ./src/stu_sort_def.c ./include/stu_sort.h
	gcc -c ./src/stu_sort_def.c -o ./obj/stu_sort_def.o -I./include
clean:
	rm ./obj/stu_sort_def.o demo
