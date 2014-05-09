finder: ./obj/main.o ./obj/finder_def.o
	g++ -o finder ./obj/main.o ./obj/finder_def.o
./obj/main.o: ./src/main.c ./include/finder.h
	g++ -c ./src/main.c -I./include -o ./obj/main.o
./obj/finder_def.o: ./src/finder_def.c ./include/finder.h
	g++ -c ./src/finder_def.c -I./include -o ./obj/finder_def.o
clean:
	rm finder ./obj/*
