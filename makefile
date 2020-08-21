CC = g++
CPPFLAGS =  -std=c++11 -g -Wall
OBJS =  project5.o menutools.o songlist.o song.o utility.o

project5: $(OBJS) 

project5.o: menutools.h songlist.h song.h utility.h

menutools.o: songlist.h song.h utility.h

songlist.o: song.h utility.h

song.o: utility.h

utility.o: utility.h

clean:
	rm *.o project5

