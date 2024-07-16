CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment


# Compile the main executable
bank.exe: main.cpp bank.cpp
	$(CXX) $(CXXFLAGS) main.cpp bank.cpp -o bank.exe

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
