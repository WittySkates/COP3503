all: Project

Project: src/main.o
	g++ src/main.o -o Project

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm -f *o Project
