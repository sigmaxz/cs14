DIR     = .
TARGET  = a.out

C       = g++
WFLAGS  = -W -Wall -Wextra -Wsign-promo -Werror
LFLAGS  = 
CFLAGS  = -c -O2 -ansi -pedantic-errors $(WFLAGS)
LIBS	= 

HDRS = $(shell find $(DIR) -name '*.h')
SRCS = SortedList.cpp SortedArrayList.cpp SortedLinkedList.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: build

$(TARGET): $(OBJS)
	$(C) $^ $(LIBS) -o $@

%.o: %.cpp
	$(C) $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(TARGET) *.gz .??* *.tgz *.zip

tar:
	tar -czf $(LOGNAME).tar.gz

build: $(TARGET)

rebuild: clean build
