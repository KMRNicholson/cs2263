areDistinct : areDistinct.o main.o \
	cc -o areDistinct areDistinct.o main.o

main.o: main.c \
	cc -c main.c

areDistinct.o : areDistinct.c \
	cc -c areDistinct.c

clean: 
	rm areDistinct main.o areDistinct.o