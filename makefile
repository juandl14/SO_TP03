CC= gcc
GCCFLAGS= -std=gnu99  -Wall -pedantic 
GCCLIBS= -lm

SOURCES_SERVER= newServer.c
SOURCES_CLIENT= client.c
SOURCES_LIB= lib.c

OBJECTS_LIB=$(SOURCES_LIB:.c=.o)

