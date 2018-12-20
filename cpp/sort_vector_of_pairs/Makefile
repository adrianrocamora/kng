ifdef SystemRoot
	RM = rm -f
	FixPath = $(subst /,\,$1)
	CC = g++
else
	ifeq ($(shell uname), Darwin)
		RM = rm -f
		FixPath = $1
	endif
	#CC = clang++
	CC = icpc
endif

TARGET = run

all: template.cpp
	$(CC) -o $(TARGET) template.cpp -I./

clean: 
	$(RM) $(call FixPath,$(TARGET)*)
