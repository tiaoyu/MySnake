objects = Point.o Food.o Snake.o View.o Score.o Connect.o main.o 
CC = g++
all : main clean

main : $(objects)
	$(CC) -o main -I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG $(objects) -lGL -lGLU -lglut -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl

main.o : Snake.h
Snake.o : Snake.h
View.o : View.h
Food.o : Food.h
Point.o : Point.h
Score.o : Score.h
Connect.o : Connect.h

.PHONY : clean
clean :
	rm $(objects)
