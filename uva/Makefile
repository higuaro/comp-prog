SOURCES := $(wildcard *.cpp)
EXECS := $(SOURCES:.cpp=)
BIN := bin
RELEASE := -O2
DEBUG := -g -Wall
CFLAGS := $(DEBUG) --std=c++11
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	STAT_OPTS := -c '%Y'
	CLEAN_FLAGS := -executable
endif
ifeq ($(UNAME_S),Darwin)
	STAT_OPTS := -f '%m'
	CLEAN_FLAGS :=
endif

% : %.cpp
	@if [ ! -e "$(BIN)" ]; then mkdir $(BIN); fi
	@if [ -e $(BIN)/$* ] && [ `stat $(STAT_OPTS) bin/$*` -gt `stat $(STAT_OPTS) $*.cpp` ]; then \
		echo "'$*' is up to date"; \
	else \
		echo "Compiling $<..." ;\
		echo "g++ $(CFLAGS) $< -o bin/$*" ;\
		g++ $(CFLAGS) $< -o bin/$* ;\
		echo `seq -s '-' 1 70 | tr -d '[0-9]'` ;\
		echo ;\
	fi

all : $(EXECS)
	

.PHONY : clean 

clean: 
	@echo "Cleaning executable files" 
	find $(BIN) $(CLEAN_FLAGS)= -type f -exec rm {} \;
