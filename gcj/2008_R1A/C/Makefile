#CC = clang++
CC = icpc
#TARGET = A
#TARGET = B
TARGET = C

#all: template.cpp
	#$(CC) -o $(TARGET) template.cpp -I./
all: template.cpp
	$(CC) -o $(TARGET) template.cpp -I. -I/usr/local/include/ -L/usr/local/lib -lgmp -lgmpxx

clean: 
	$(RM) $(TARGET)
