COMPLIER := g++
COMPLIER_FLAGS := -Wall -std=c++11

OUTPUT_FILE_NAME := TinyKai

LINK_FLAGS := -lncurses

all:$(OUTPUT_FILE_NAME)

SRC := main.cpp GameLibrary/*.cpp PlatformManager/*.cpp PlatformSettings/*.cpp InterfaceManager/*.cpp

$(OUTPUT_FILE_NAME) : $(SRC)
	@echo "****正在编译整个项目，请稍后****"
	$(COMPLIER) $(COMPLIER_FLAGS) $^ -o $@ $(LINK_FLAGS)
	@echo "****编译完成，请使用./"$(OUTPUT_FILE_NAME)"执行****"

.PHONY : main cleanAll clean rebuildAll InterfaceManager PlatformSettings GameLibrary PlatformManager

rebuildAll:cleanAll clean all

main:
	@echo "正在编译main文件……"
	$(COMPLIER) $(COMPLIER_FLAGS) -c main.cpp

cleanAll:
	@echo "正在清除所有目标文件……"
	rm -r *.o

clean:
	@echo "正在清除可执行文件……"
	rm $(OUTPUT_FILE_NAME)

InterfaceManager:
	@echo "正在编译界面模块……"
	$(COMPLIER) $(COMPLIER_FLAGS) -c InterfaceManager/*.cpp

GameLibrary:
	@echo "正在编译游戏库模块……"
	$(COMPLIER) $(COMPLIER_FLAGS) -c GameLibrary/*.cpp

PlatformManager:
	@echo "正在编译游戏管理模块……"
	$(COMPLIER) $(COMPLIER_FLAGS) -c PlatformManager/*.cpp

PlatformSettings:
	@echo "正在编译游戏设置模块……"

	$(COMPLIER) $(COMPLIER_FLAGS) -c PlatformSettings/*.cpp
