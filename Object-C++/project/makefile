COMPLIER := g++
COMPLIER_FLAGS := -Wall -std=C++11

SRC :=main.cpp
SRC += platform_manager/*.cpp

LINK_FLAGS := -lncurses

all:

.PHONY : snake

EXEC_FILE := snake
snake:
$(EXEC_FILE_NAME) : $(SRC)
		$(COMPLIER) $(COMPLIER_FLAGS) $^ -o $@ $(LINK_FLAGS)
