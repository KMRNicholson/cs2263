#########################################
# 
# Makefile for compiling and testing the playStack and playQueue program
#
# Created by Kohdy Nicholson
#
##########################################

# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -g -Wall -lm

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make playStack              (builds the playStack program)\n"
	@printf "	make playQueue              (builds the playQueue program)\n"
	@printf "	make modules                (builds the modules that used)\n"
	@printf "	make clean                  (cleans object files in the current folder)\n"
	@printf "	make test_playStack         (run memory leak test for main program)\n"
	@printf "	make test_playQueue         (run memory leak tests for loading routes)\n"
	
# link our .o files to make executables for our main drivers
playStack: clean playStack.o modules
	$(COMPILER) $(C_FLAGS) -o playStack *.o

playQueue: clean playQueue.o modules
	$(COMPILER) $(C_FLAGS) -o playQueue *.o

# targets for compiling our .c files in modules and the main drivers.
modules:
	$(COMPILER) $(C_FLAGS) -c ./Modules/*.c

playStack.o: playStack.c
	$(COMPILER) $(C_FLAGS) -c playStack.c

playQueue.o: playQueue.c
	$(COMPILER) $(C_FLAGS) -c playQueue.c

# cleans all of the object files in the current directory
clean:
	rm -f *.o

####################################################################
# Tests

test_playStack: playStack
	./playStack < ./io/test_input.txt

test_playQueue: playQueue
	./playQueue < ./io/test_input.txt