all: alloc memory

memory: memory.cpp
	g++ -o memory memory.cpp
alloc: alloc.cpp
	g++ -o alloc alloc.cpp
clean:
	rm -f memory alloc
memcheck:
	g++ -o memory memory.cpp
	valgrind --show-leak-kinds=all ./memory
allcheck:
	g++ -o alloc alloc.cpp
	valgrind --show-leak-kinds=all ./alloc


