CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3

alphabetizer: main.o StringBST.o Alphabetizer.o
	${CXX} ${LDFLAGS} -o alphabetizer main.o StringBST.o Alphabetizer.o
main.o: main.cpp Alphabetizer.h
StringBST.o: StringBST.cpp StringBST.h
Alphabetizer.o: Alphabetizer.cpp Alphabetizer.h

clean:
	rm -rf alphabetizer *.o *.dSYM
