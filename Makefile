CC = g++
CFLAGS = -std=c++11
LDFLAGS =
OBJFILES = testing.o
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJFILES)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
		rm -f $(OBJFILES) $(TARGET) *~
