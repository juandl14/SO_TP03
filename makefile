GCC= gcc
GCCFLAGS= -std=gnu99  -Wall -pedantic 
GCCLIBS= -lm

SOURCES_SERVER= src/newServer.c
SOURCES_CLIENT= src/client.c
SOURCES_CHALLENGES= src/challenges.c
SOURCES_LIB= src/lib.c

OBJECT_CHALLENGES=$(SOURCES_CHALLENGES:.c=.o)
OBJECTS_LIB=$(SOURCES_LIB:.c=.o)

SERVER_EXEC= newServer
CLIENT_EXEC= client

all: $(OBJECT_CHALLENGES) client
		$(GCC) $(GCCFLAGS) $(SOURCES_SERVER) $(SOURCES_CHALLENGES) $(SOURCES_LIB) -I./include -o $(SERVER_EXEC) $(GCCLIBS)

%.o: %.c
		$(GCC) $(GCCFLAGS) -I./include -c $^ $(GCCLIBS)

# newServer:

# challenges:

client:
		$(GCC) -I./include $(SOURCES_CLIENT) $(SOURCES_LIB) -o $(CLIENT_EXEC) $(GCCFLAGS)

clean:
		rm -rf *.o newServer client ./src/*.o

cleanTest:
		rm -rf output.cppOut report.tasks results.valgrind

test: clean
		./pvs.sh; cppcheck --quiet --enable=all --force --suppress=missingIncludeSystem --inconclusive $(SOURCES_SERVER) $(SOURCES_CHALLENGES) $(SOURCES_CHALLENGES) $(SOURCES_LIB) 2>> output.cppOut; valgrind --leak-check=full -v ./newServer 2>> results.valgrind; valgrind --leak-check=full -v ./client 2>> results.valgrind

.PHONY: all clean cleanTest test client