project5mkfile: project5.o DynamicStack.o
	g++ -o a.out project5.o DynamicStack.o
project5.o: project5.cpp DynamicStack.h
	g++ -g -c project5.cpp
DynamicStack.o: DynamicStack.cpp DynamicStack.h
	g++ -g -c DynamicStack.cpp
