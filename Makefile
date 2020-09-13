.default: all

all: fcfs Process

clean:
	rm -rf -Wall *.o *.dSYM

fcfs: FCFS.o FileHandler.o Process.o
	g++ -Wall -Werror -std=c++14 -O -o $@ $^


	
# sjf: SJF.o FileHandler.o Process.o
# 	g++ -Wall -Werror -std=c++14 -O -o $@ $^

# rr: RR.o FileHandler.o Process.o
# 	g++ -Wall -Werror -std=c++14 -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
