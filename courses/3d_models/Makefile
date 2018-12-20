UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	OTHER_FLAGS = -lGL -lglut
else
	OTHER_FLAGS = -framework OpenGL -framework GLUT
endif
INCLUDE_DIR = -I/usr/include/GL/ -I. 
CCX = clang++

all:
	$(CXX) md2.cpp $(INCLUDE_DIR) $(OTHER_FLAGS) -o demo
