CC:= g++
CCFLAGS := -std=c++14 

all: main


main: main.cpp
	$(CC) $(CCFLAGS) $< -o $@

.phony: clean

clean:
	rm main.o main 


