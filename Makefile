TARGET=example
CXX=g++
OPT=-O2 -Wall

all: $(TARGET).o functools.o
	$(CXX) $^ -o $(TARGET) $(OPT)

$(TARGET).o: $(TARGET).cpp
	$(CXX) -c $^ -o $@ $(OPT)

functools.o: functools.cpp
	$(CXX) -c $^ -o $@ $(OPT)

clean:
	-rm *.o
	-rm $(TARGET)
