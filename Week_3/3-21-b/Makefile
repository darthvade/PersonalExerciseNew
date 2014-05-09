matching: ./obj/main.o ./obj/matching_def.o
	g++ -o matching ./obj/main.o ./obj/matching_def.o
./obj/main.o: ./src/main.cpp ./include/matching.h
	g++ -c ./src/main.cpp -I./include -o ./obj/main.o
./obj/matching_def.o: ./src/matching_def.cpp ./include/matching.h
	g++ -c ./src/matching_def.cpp -I./include -o ./obj/matching_def.o
clean:
	rm matching ./obj/*
