DIR     = .
TARGET  = $(DIR)/$(LOGNAME)

C       = g++
WFLAGS  = -W -Wall -Wextra -Wold-style-cast -Wsign-promo -Werror
LFLAGS  = 
CFLAGS  = -c -O2 -ansi -pedantic-errors $(WFLAGS)
LIBS	= 

HDRS = $(shell find $(DIR) -name '*.h')
SRCS = $(shell find $(DIR) -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)

all: clean tar build

$(TARGET): $(OBJS)
	$(C) $^ $(LIBS) -o $@

%.o: %.cpp
	$(C) $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(TARGET) *.gz

tar:
	tar -czf $(TARGET).tar.gz $(DIR)

build: $(TARGET)

rebuild: clean build
