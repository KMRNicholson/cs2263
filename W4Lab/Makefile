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
C_FLAGS = -Wall

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make all                    (build drivers and tests them)\n"
	@printf "	make fputString             (to build driver test program for fputString)\n"
	@printf "	make fgetString             (to build driver test program for fgetString)\n"
	@printf "	make fputString_test        (test fputString)\n"
	@printf "	make fgetString_test        (test fgetString)\n"


# build executables and run tests on them
all: fputString fgetString test

# link our .o files to make executables
fputString: fputString.o Strings.o
	$(COMPILER) $(C_FLAGS) -o fputString fputString.o Strings.o

fgetString: fgetString.o Strings.o
	$(COMPILER) $(C_FLAGS) -o fgetString fgetString.o Strings.o

# compile the .o files
fputString.o: fputString.c
	$(COMPILER) $(C_FLAGS) -c fputString.c

fgetString.o: fgetString.c
	$(COMPILER) $(C_FLAGS) -c fgetString.c

Strings.o: Strings.c
	$(COMPILER) $(C_FLAGS) -c Strings.c

#########################################
# TESTS
#########################################

test: fputString_test fgetString_test

fputString_test: fputString
	./fputString fputString.result < Data/fputString.input
	./TestPassed.sh fputString.result Data/fputString.expected

fgetString_test: fgetString
	./fgetString fputString.result > fgetString.result
	./TestPassed.sh fgetString.result Data/fgetString.expected

