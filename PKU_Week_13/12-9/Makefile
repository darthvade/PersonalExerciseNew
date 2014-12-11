a.out-O3:a.out-O2
	clang++ ./demo.cpp -std=c++11 -Wall -O3 -o a.out-O3
a.out-O2:a.out-O1
	clang++ ./demo.cpp -std=c++11 -Wall -O2 -o a.out-O2
a.out-O1:
	clang++ ./demo.cpp -std=c++11 -Wall -O1 -o a.out-O1
clean:
	rm ./a.out* ./outputfile-*
