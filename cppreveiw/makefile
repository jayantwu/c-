OBJS=human.o location.o main.o
CC=g++
CFLAGS+=-c -std=c++11
a.out:$(OBJS)
	$(CC) $^ -o $@

%.o:%.cpp
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o a.out -r
