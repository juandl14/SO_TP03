#ifndef LIB_H
#define LIB_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

#define ERROR_CODE -1

void errorHandler(const char *errorMsg);

#endif