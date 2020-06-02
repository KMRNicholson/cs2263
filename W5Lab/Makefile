#########################################
# 
# Makefile for compiling fputString.c and Strings.c functions
#
# Created by Kohdy Nicholson
#
##########################################

# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -Wall -g

# valgring tool
VAL = valgrind 
VAL_OPTIONS = --tool=memcheck --leak-check=full --verbose --log-file=

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make all                    (build drivers and tests them)\n"
	@printf "	make stringTest1            (to build driver test program for stringTest1)\n"
	@printf "	make stringListTest         (to build driver test program for stringListTest)\n"
	@printf "	make stringListSortTest     (to build driver test program for stringListSortTest)\n"
	@printf "	make valgrind               (run memory leak tests)\n"

# build executables and run tests on them
all: stringTest1 stringListTest stringListSortTest valgrind

# link our .o files to make executables
stringTest1: stringTest1.o Strings.o
	$(COMPILER) $(C_FLAGS) -o stringTest1 stringTest1.o Strings.o

stringListTest: stringListTest.o Strings.o
	$(COMPILER) $(C_FLAGS) -o stringListTest stringListTest.o Strings.o

stringListSortTest: stringListSortTest.o Strings.o
	$(COMPILER) $(C_FLAGS) -o stringListSortTest stringListSortTest.o Strings.o

# compile the .o files
stringTest1.o: stringTest1.c
	$(COMPILER) $(C_FLAGS) -c stringTest1.c

stringListTest.o: stringListTest.c
	$(COMPILER) $(C_FLAGS) -c stringListTest.c

stringListSortTest.o: stringListSortTest.c
	$(COMPILER) $(C_FLAGS) -c stringListSortTest.c

Strings.o: Strings.c
	$(COMPILER) $(C_FLAGS) -c Strings.c

#########################################
# MEMORY LEAK TESTS
#########################################

valgrind: valgrind1 valgrind2 valgrind3

valgrind1: stringTest1
	$(VAL) ./stringTest1 $(VAL_OPTIONS)vg_stringTest1_log.txt

valgrind2: stringListTest
	$(VAL) ./stringListTest One Two Three Arguments $(VAL_OPTIONS)vg_stringListTest_log.txt

valgrind3: stringListSortTest
	$(VAL) ./stringListSortTest $(VAL_OPTIONS)vg_stringListSortTest_log.txt

