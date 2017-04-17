CPP = g++
CPPFLAGS = -std=c++11
SRC = delim_seperated_values.cpp
TARGET = dsv


$(TARGET): $(SRC)
	$(CPP) -o $(TARGET) $(CPPFLAGS) $(SRC)

clean:
	rm $(TARGET)
