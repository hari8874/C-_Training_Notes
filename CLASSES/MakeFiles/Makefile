CXX = g++
CXX_FLAGS= -Wall -std=c++17

all: main.o calc.o
$(CXX) main.o calc.o -o output

main.o: main.cpp
$(CXX) $(CXX_FLAGS) -c main.cpp 
calc.o: Calc.hpp Calc.cpp
$(CXX) $(CXX_FLAGS) -c Calc.hpp Calc.cpp

clean:
rm -r output *.o