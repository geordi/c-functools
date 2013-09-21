TARGET=example
TARGET_LIB=libcfunctools.so
CXX=g++
OPT=-O2 -Wall -fpic

all: $(TARGET).o functools.o
	$(CXX) $^ -o $(TARGET) $(OPT)

$(TARGET).o: $(TARGET).cpp
	$(CXX) -c $^ -o $@ $(OPT)

functools.o: functools.cpp
	$(CXX) -c $^ -o $@ $(OPT)

lib: functools.o
	$(CXX) -shared -o $(TARGET_LIB) functools.o

clean:
	-rm *.o
	-rm *.so
	-rm $(TARGET)
