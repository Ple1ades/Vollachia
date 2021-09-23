all:
	g++ -o Vollachia.o -c Vollachia/* -I src/include -L src/lib/x64 -lm -lmingw32 -lSDL2main -lSDL2
#all:
#	g++  -o Vollachia/* Vollachia.o 