# Makefile 
# Genetic Algorithm for music composition
# By: Ari Brown
# Date: Nov. 28, 2016

CXX      = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra
LDFLAGS  = -g3



breed: GenAlgo.o GenerationPopulation.o GenerationQueue.o \
	MelodyNode.o main.o melody.o melody2midi.o \
	note.o otherfuncs.o score.o termfuncs.o
	${CXX} ${LDFLAGS} -o breed src/GenAlgo.cpp src/GenerationPopulation.cpp \
		src/GenerationQueue.cpp src/MelodyNode.cpp src/main.cpp src/melody.cpp src/melody2midi.cpp \
		src/note.cpp src/otherfuncs.cpp src/score.cpp src/termfuncs.cpp


GenAlgo.o: src/GenAlgo.cpp include/GenAlgo.h include/parameters/options.h include/melody.h include/parameters/constants.h \
	include/GenerationPopulation.h include/GenerationQueue.h
GenerationPopulation.o: src/GenerationPopulation.cpp include/GenerationPopulation.h \
	include/parameters/options.h include/melody.h include/parameters/constants.h include/MelodyNode.h
GenerationQueue.o: src/GenerationQueue.cpp include/GenerationQueue.h \
	include/parameters/options.h include/melody.h include/MelodyNode.h
MelodyNode.o: src/MelodyNode.cpp include/MelodyNode.h include/melody.h include/parameters/constants.h include/parameters/options.h \
	include/score.h
main.o: src/main.cpp include/GenAlgo.h
melody.o: src/melody.cpp include/melody.h include/parameters/options.h include/termfuncs.h include/parameters/constants.h include/otherfuncs.h \
	include/GenAlgo.h
melody2midi.o: src/melody2midi.cpp include/melody2midi.h include/melody.h include/note.h include/parameters/constants.h
note.o: src/note.cpp include/note.h include/parameters/options.h include/otherfuncs.h include/parameters/constants.h include/termfuncs.h
otherfuncs.o: src/otherfuncs.cpp include/otherfuncs.h include/parameters/options.h include/parameters/constants.h include/termfuncs.h
score.o: src/score.cpp include/score.h include/parameters/options.h include/melody.h include/note.h include/otherfuncs.h include/parameters/constants.h
termfuncs.o: src/termfuncs.cpp include/termfuncs.h

clean:
	rm -rf breed *.dSYM *.o
