CXX = g++
TARGET = obj
SRC = main.cpp

build: $(TARGET)

$(TARGET): $(SRC)
	@$(CXX)  $(SRC) -o $(TARGET)

exec: 
	@./$(TARGET)

clean:
	@rm -f $(TARGET)

run: build exec clean