#########################################
# 
# Makefile for compiling lab 7
#
# Created by Kohdy Nicholson
#
##########################################

# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -Wall -g -lm

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make sortTest               (build exercise one program)\n"
	@printf "	make stringListSortTest     (build exercise two program)\n"
	@printf "	make sortPoint2D            (build exercise three program)\n"

# build exercise one program
sortTest: sortTest.o 
	$(COMPILER) $(C_FLAGS) -o sortTest sortTest.o

sortTest.o: sortTest.c
	$(COMPILER) $(C_FLAGS) -c sortTest.c

stringListSortTest: stringListSortTest.o modules
	$(COMPILER) $(C_FLAGS) -o stringListSortTest stringListSortTest.o Strings.o

stringListSortTest.o: stringListSortTest.c
	$(COMPILER) $(C_FLAGS) -c stringListSortTest.c

sortPoint2D: sortPoint2D.o modules
	$(COMPILER) $(C_FLAGS) -o sortPoint2D sortPoint2D.o Point2D.o

sortPoint2D.o: sortPoint2D.c
	$(COMPILER) $(C_FLAGS) -c sortPoint2D.c

# compile the module files
modules:
	$(COMPILER) $(C_FLAGS) -c ./Modules/*.c