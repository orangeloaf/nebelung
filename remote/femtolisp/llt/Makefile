#FREEBSD-GE-10 = $(shell test `uname` = FreeBSD -a `uname -r | cut -d. -f1` -ge 10 && echo YES)
#CC = $(if $(FREEBSD-GE-10),clang,gcc)

TCC = $(shell command -v tcc 2> /dev/null)
CC = $(if $(TCC),tcc,gcc)

SRCS = bitvector.c hashing.c socket.c timefuncs.c ptrhash.c utf8.c ios.c \
	dirpath.c htable.c bitvector-ops.c int2str.c dump.c random.c wcwidth.c \
	lltinit.c
OBJS = $(SRCS:%.c=%.o)
DOBJS = $(SRCS:%.c=%.do)
TARGET = libllt.a

FLAGS = -Wall -Wno-strict-aliasing $(CFLAGS)
LIBS =

DEBUGFLAGS = -g -DDEBUG $(FLAGS)
SHIPFLAGS = -O3 -DNDEBUG $(FLAGS)

default: release

%.o: %.c
	$(CC) $(SHIPFLAGS) -c $< -o $@
%.do: %.c
	$(CC) $(DEBUGFLAGS) -c $< -o $@

debug: $(DOBJS)
	rm -rf $(TARGET)
	ar rs $(TARGET) $(DOBJS)

release: $(OBJS)
	rm -rf $(TARGET)
	ar rs $(TARGET) $(OBJS)

clean:
	rm -f *.o
	rm -f *.do
	rm -f *~
	rm -f core*
	rm -f $(TARGET)
