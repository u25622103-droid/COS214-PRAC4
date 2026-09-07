CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -g
TARGET = engine

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default target
#all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

valgrind:
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes ./engine
