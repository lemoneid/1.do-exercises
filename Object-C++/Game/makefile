COMPLIER := g++
COMPLIER_FLAGS := -Wall -std=c++11

OUTPUT_FILE_NAME := TinyKai

LINK_FLAGS := -lncurses

all:$(OUTPUT_FILE_NAME):
	.PHONY :main cleanAll clean rebuildAll InterfaceManager PlatformSetting GameLibrary
main:
	@echo "正在编译main文件..."
	$(COMPLIER) $(COMPLIER_FLAGS) -c main.cpp

cleanAll:
	@echo "正在清除所有目标文件"
	rm -f *.o
clean:
	rm -f $(OUTPUT_FILE_NAME) 

rebuildAll: cleanAll clean all

InterfaceManager:


