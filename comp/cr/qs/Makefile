UNAME := $(shell uname)
TARGET = run
ifeq ($(UNAME), MINGW32_NT-6.1)
CC = g++ 
TARGETRM = $(TARGET).exe
else
CC = icpc
TARGETRM = $(TARGET)
endif

all:
	$(CC) -o $(TARGET) main.cpp

clean:
	$(RM) $(TARGETRM)
