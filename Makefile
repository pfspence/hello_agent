CXX = i686-w64-mingw32-g++
CXXFLAGS = -std=c++11
CXXFLAGS += -s
CXXFLAGS += -lws2_32 
CXXFLAGS += -Wno-write-strings

CXXFLAGS += -fno-exceptions
CXXFLAGS += -fmerge-all-constants
CXXFLAGS += -static-libstdc++
CXXFLAGS += -static-libgcc


SRCS = hello_agent.cpp
OBJS = hello_agent.o
HEADERS = 
OUTPUT = hello_agent.exe

TITLE = HelloAgent

main: ${OUTPUT}

${OUTPUT}: ${OBJS}
	${CXX} -o ${OUTPUT} ${OBJS} ${CXXFLAGS}

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp) ${CXXFLAGS}

valgrind:
	valgrind --leak-check=full ./${OUTPUT}

clean:
	rm -rf *.o *.dSYM ${OUTPUT}
