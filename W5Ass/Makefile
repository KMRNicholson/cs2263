#########################################
# 
# Makefile for compiling and testing the RoutePlanner program
#
# Created by Kohdy Nicholson
#
##########################################

# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -g -Wall -lm

# valgring tool
VAL = valgrind 
VAL_OPTIONS = --tool=memcheck --leak-check=full --verbose --log-file=

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make RoutePlanner           (builds the main program)\n"
	@printf "	make loadRoutesTest         (builds the driver to test the loading of bus routes)\n"
	@printf "	make loadStudentsTest       (builds the driver to test the loading of students)\n"
	@printf "	make modules                (builds the modules that used)\n"
	@printf "	make clean                  (cleans object files in the current folder)\n"
	@printf "	make valgrind_RoutePlanner  (run memory leak test for main program)\n"
	@printf "	make valgrind_loadRoutes    (run memory leak tests for loading routes)\n"
	@printf "	make valgrind_loadStudents  (run memory leak tests for loading students)\n"
	
# link our .o files to make executables for our main drivers
RoutePlanner: clean RoutePlanner.o modules
	$(COMPILER) $(C_FLAGS) -o RoutePlanner *.o

loadRoutesTest: clean loadRoutesTest.o modules
	$(COMPILER) $(C_FLAGS) -o loadRoutesTest *.o

loadStudentsTest: clean loadStudentsTest.o modules
	$(COMPILER) $(C_FLAGS) -o loadStudentsTest *.o

# targets for compiling our .c files in modules and the main drivers.
modules:
	$(COMPILER) $(C_FLAGS) -c ./Modules/*.c

RoutePlanner.o: RoutePlanner.c
	$(COMPILER) $(C_FLAGS) -c RoutePlanner.c

loadRoutesTest.o: loadRoutesTest.c
	$(COMPILER) $(C_FLAGS) -c loadRoutesTest.c

loadStudentsTest.o: loadStudentsTest.c
	$(COMPILER) $(C_FLAGS) -c loadStudentsTest.c

# cleans all of the object files in the current directory
clean:
	rm -f *.o

####################################################################
# VALGRINDING - tests program output and also discovers memory leaks

valgrind_RoutePlanner: RoutePlanner
	$(VAL) ./RoutePlanner A5Data/busroutes.txt < A5Data/students.txt

valgrind_loadRoutes: loadRoutesTest
	$(VAL) ./loadRoutesTest A5Data/busroutes.txt

valgrind_loadStudents: loadStudentsTest
	$(VAL) ./loadStudentsTest < A5Data/students.txt