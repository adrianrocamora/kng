CC = icpc
TARGET = run

all: main.cpp
	$(CC) -o $(TARGET) main.cpp -I. -I/usr/local/include/ -L/usr/local/lib -lgmp -lgmpxx

clean:
	$(RM) $(TARGET)
