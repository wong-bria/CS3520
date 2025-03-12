PROGRAMS=sum fizzbuzz rectangle calc lineno

CXXFLAGS=-std=c++17 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -pedantic-errors
LDFLAGS=-std=c++17



all: $(PROGRAMS)

$(PROGRAMS): %: %.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp Makefile
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.*
