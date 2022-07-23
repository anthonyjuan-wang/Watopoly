CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
EXEC = watopoly
OBJECTS = main.o board.o player.o boarddisplay.o academic.o coop.o dcTimsLine.o gooseNesting.o goToTims.o gyms.o needlesHall.o osap.o residences.o slc.o tuition.o tile.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
