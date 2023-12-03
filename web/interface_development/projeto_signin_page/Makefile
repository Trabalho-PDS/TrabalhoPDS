# CC and flags
CC = g++
CXXFLAGS = -std=c++17 -g -Wall -lstdc++fs

# folders
INCLUDE_FOLDER = ../include/
BIN_FOLDER = /usr/lib/cgi-bin/forum/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ../src/


# all sources, objs, and header files
MAIN = signin_page.cpp
TARGET = signin_page.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

# compile
$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: clean $(OBJ)
	$(CC) $(MAIN) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ) 

clean:
	@rm -rf $(OBJ_FOLDER)*

run:
	@$(BIN_FOLDER)$(TARGET)