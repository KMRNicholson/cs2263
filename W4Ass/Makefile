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
C_FLAGS = -Wall

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help                   (this command)\n"
	@printf "	make htags                  (to build your C program)\n"
	@printf "	make remove_comments_test   (to build the test C program)\n"
	@printf "	make test                   (to run every test case)\n"
	@printf "	make compound_test          (to run htags compound tests)\n"
	@printf "	make remove_comment_test    (to run test cases against the function to remove_comments)\n"
	
# link our .o files to make an executable
htags: htags.o parser.o
	$(COMPILER) $(C_FLAGS) -o htags htags.o parser.o

remove_comments_test: remove_comments_test.o parser.o
	$(COMPILER) $(C_FLAGS) -o remove_comments_test remove_comments_test.o parser.o

# compile the .o files
htags.o: htags.c
	$(COMPILER) $(C_FLAGS) -c htags.c

parser.o: parser.c
	$(COMPILER) $(C_FLAGS) -c parser.c

remove_comments_test.o: remove_comments_test.c
	$(COMPILER) $(C_FLAGS) -c remove_comments_test.c


##################################################################
# Test Cases
test: compound_test remove_comment_test

##############################
# compound test cases
compound_test: Sample_test HelloWorld_test hello_test

Sample_test: htags
	./htags < Data/Sample.html > Sample_test.result
	./TestPassed.sh Sample_test.result Data/Sample_test.expected

HelloWorld_test: htags
	./htags < Data/HelloWorld.html > HelloWorld_test.result
	./TestPassed.sh HelloWorld_test.result Data/HelloWorld_test.expected

hello_test: htags
	./htags < Data/hello.html > hello_test.result
	./TestPassed.sh hello_test.result Data/hello_test.expected


##############################
# remove_comment test cases
remove_comment_test: remove_comment_test1 remove_comment_test2

remove_comment_test1: remove_comments_test
	./remove_comments_test < Data/Sample.html > remove_comment_test1.result
	./TestPassed.sh remove_comment_test1.result Data/remove_comment_test1.expected

remove_comment_test2: remove_comments_test
	./remove_comments_test < Data/HelloWorld.html > remove_comment_test2.result
	./TestPassed.sh remove_comment_test2.result Data/remove_comment_test2.expected