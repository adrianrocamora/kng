# Simple app using SFML


## Prerequisites

''' 
sudo apt-get install libsfml-dev
'''
or
''' 
brew install sfml
'''

## Compiling and linking

'''
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
'''
or
'''
clang++ -c main.cpp -I/usr/local/include
clang++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/lib
'''

