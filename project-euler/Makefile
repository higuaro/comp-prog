SOURCES := $(wildcard *.cpp)
EXECS := $(SOURCES:.cpp=)
BIN := bin
RELEASE := -O2
WARNINGS := -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
	-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op \
	-Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls \
	-Wsign-promo -Wstrict-null-sentinel \
	-Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Weffc++
DEBUG := -g $(WARNINGS) -pedantic
CFLAGS := $(DEBUG) --std=c++11

% : %.cpp
	@if [ ! -e "$(BIN)" ]; then mkdir $(BIN); fi
	@if [ -e $(BIN)/$* ] && [ `stat -c %Y bin/$*` -gt `stat -c %Y $*.cpp` ]; then \
		echo "'$*' is up to date"; \
	else \
		echo "Compilling $<..." ;\
		echo "g++ $(CFLAGS) $< -o bin/$*" ;\
		g++ $(CFLAGS) $< -o bin/$* ;\
		echo `seq -s '-' 1 70 | tr -d '[0-9]'` ;\
		echo ;\
	fi

all : $(EXECS)
	

.PHONY : clean 

clean: 
	@echo "Cleaning executable files" 
	find . -executable -type f -exec rm {} \;
