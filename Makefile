objects = Point.o Food.o Snake.o View.o main.o
CC = g++
all : main clean

main : $(objects)
	$(CC) -o main $(objects) -lpthread -lGL -lGLU -lglut

main.o : Snake.h
Snake.o : Snake.h
View.o : View.h
Food.o : Food.h
Point.o : Point.h

.PHONY : clean
clean :
	rm $(objects)
