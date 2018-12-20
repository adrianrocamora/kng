CC = icpc
TARGET = run

all: template.cpp
	$(CC) -o $(TARGET) template.cpp -I./

big: template.cpp
	$(CC) -o $(TARGET) template.cpp -I./ -I/usr/local/include/ -L/usr/local/lib -lgmp -lgmpxx

clean: 
	$(RM) $(TARGET)
