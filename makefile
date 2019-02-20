CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-return-type -pedantic-errors -g

SRCS = main.cpp Menu.cpp Queue.cpp
OBJS = ${SRCS: .cpp = .o}
HEADERS = Menu.hpp Queue.hpp

MAIN = queue

all: ${MAIN}
	@echo sucessfully compiled!

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
