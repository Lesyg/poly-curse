#code from lab pa2 @radek.husek
#https://gitlab.fit.cvut.cz/husekrad/pa2-cvika-2022/blob/master/cv10/semestralka/Makefile

NAME = gyseldom
CXX = g++
FLAGS = -std=c++17 -Wall -g -pedantic -O2

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.o)
TESTS = $(wildcard tests/*.cpp)
DEPS = $(patsubst src/%.cpp, build/%.dep, ${SOURCES})

ZIP = Makefile Doxyfile DOCUMENTATION.md zadani.txt prohlaseni.txt \
  .gitignore $(wildcard examples/*) $(wildcard src/*)

.PHONY: all
all: compile doc

.PHONY: compile
compile: ${NAME}

${NAME}: ${OBJECTS}
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS} $^ -lncurses -lstdc++fs -o $@

build/%.o: src/%.cpp
	@mkdir -p build/
	${CXX} ${FLAGS} -c -lncurses -lstdc++fs $< -o $@


.PHONY: run
run: compile
	./${NAME}

.PHONY: valgrind
valgrind: compile
	valgrind ./${NAME}

.PHONY: doc
doc: Doxyfile DOCUMENTATION.md $(wildcard src/*)
	doxygen Doxyfile

.PHONY: count
count:
	wc -l src/*

.PHONY: clean
clean:
	rm -rf build doc
	rm -f ${NAME} ${NAME}.zip

.PHONY: zip
zip: ${NAME}.zip

${NAME}.zip: ${ZIP}
	rm -rf tmp/
	rm -f $@
	mkdir -p tmp/${NAME}/
	cp --parents -r $^ tmp/${NAME}/
	cd tmp/ && zip -r ../$@ ${NAME}/
	rm -rf tmp/

build/%.dep: src/%.cpp src/*
	@mkdir -p build/
	${CXX} -MM -MT $(patsubst src/%.cpp, build/%.o, $<) $< > $@

include ${DEPS}