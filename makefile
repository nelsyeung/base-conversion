CC = clang++
CFLAGS = -Wall -g
DEPS = base_converter.h
OBJS = main.o base_converter.o

%.o: %.c++ $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

base_converter: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o *.dSYM 
