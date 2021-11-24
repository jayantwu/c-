OBJS=test_gmock.cpp
LDFLAGS += /usr/local/lib/libgtest.a -lgmock -lgmock_main -lpthread
FLAGS += -std=c++11
TARGET=a.out

$(TARGET) : $(OBJS)
	g++ $(FLAGS) -o $@ $^  $(LDFLAGS) 
clean:
	rm a.out
