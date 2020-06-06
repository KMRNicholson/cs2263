#########################################
# 
# Makefile for compiling and testing htags.c and parser.c functions
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
	@printf "	make all                    (builds every target)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make loadRoutesTest         (builds the driver to test the loading of bus routes)\n"
	@printf "	make loadStudentsTest       (builds the driver to test the loading of students)\n"
	@printf "	make modules                (builds the modules that used)\n"
	@printf "	make clean                  (cleans object files in the current folder)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make valgrind_loadRoutes    (run memory leak tests for loading routes)\n"
	@printf "	make valgrind_loadStudents  (run memory leak tests for loading students)\n"
	
# link our .o files to make an executable
loadRoutesTest: clean loadRoutesTest.o modules.o
	$(COMPILER) $(C_FLAGS) -o loadRoutesTest *.o

loadStudentsTest: clean loadStudentsTest.o modules.o
	$(COMPILER) $(C_FLAGS) -o loadStudentsTest *.o

loadRoutesTest.o: loadRoutesTest.c
	$(COMPILER) $(C_FLAGS) -c loadRoutesTest.c

loadStudentsTest.o: loadStudentsTest.c
	$(COMPILER) $(C_FLAGS) -c loadStudentsTest.c

modules.o:
	$(COMPILER) $(C_FLAGS) -c ./Modules/*.c

clean:
	rm -f *.o

######################################
# VALGRINDING

valgrind_loadRoutes: loadRoutesTest
	$(VAL) ./loadRoutesTest A5Data/busroutes.txt $(VAL_OPTIONS)

valgrind_loadStudents: loadStudentsTest
	$(VAL) cat A5Data/students.txt | ./loadStudentsTest $(VAL_OPTIONS)
