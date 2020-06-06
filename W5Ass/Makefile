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

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make all                    (builds every target)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make loadRoutesTest         (builds the driver to test the loading of bus routes)\n"
	@printf "	make loadStudentsTest       (builds the driver to test the loading of students)\n"
	@printf "	make modules                (builds the modules that used)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make routeplan              (builds the main program)\n"
	@printf "	make valgrind_loadRoutes    (run memory leak tests)\n"
	
# link our .o files to make an executable
loadRoutesTest: loadRoutesTest.o modules.o
	$(COMPILER) $(C_FLAGS) -o loadRoutesTest *.o

loadRoutesTest.o: loadRoutesTest.c
	$(COMPILER) $(C_FLAGS) -c loadRoutesTest.c

modules.o:
	$(COMPILER) $(C_FLAGS) -c ./Modules/*.c

valgrind_loadRoutes: loadRoutesTest
	$(VAL) ./loadRoutesTest A5Data/busroutes.txt $(VAL_OPTIONS)
