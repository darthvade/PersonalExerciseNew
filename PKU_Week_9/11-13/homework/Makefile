#compile
CC = clang++

#compile flags
CFLAGS = -std=c++11 -O3 -Wall 

task4-1: task5-1
	$(CC) $(CFLAGS) ./demoExpTree.cpp -o task4-1 

task5-1: task5-2
	$(CC) $(CFLAGS) ./demoBST.cpp -o task5-1

task5-2: task5-3
	$(CC) $(CFLAGS) ./demoCBT.cpp -o task5-2 

task5-3: task5-4
	$(CC) $(CFLAGS) ./demoBT.cpp -o task5-3 

task5-4:
	$(CC) $(CFLAGS) ./demoHFMT.cpp -o task5-4 

clean:
	rm ./task*	
