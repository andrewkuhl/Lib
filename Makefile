CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = testing.o
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJFILES)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
		rm -f $(OBJFILES) $(TARGET) *~
