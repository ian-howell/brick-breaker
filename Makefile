CXXHEADERS = $(wildcard *.h)
CXXSOURCES = $(wildcard *.cpp)
CXXOBJECTS = $(CXXSOURCES:%.cpp=%.o)

LINKER = -lncurses

CPP = g++
C_FLAGS = -Wall --pedantic-errors -O2

EXE = brick-breaker

EXE: ${CXXHEADERS} ${CXXOBJECTS} ${MAINOBJECT}
	${CPP} ${C_FLAGS} ${CXXOBJECTS} ${MAINOBJECT} ${LINKER} -o ${EXE}

%.o: %.cpp ${CXXHEADERS}
	${CPP} -c $<

clean:
	-@rm -f *.o
	-@rm -f ${EXE}
