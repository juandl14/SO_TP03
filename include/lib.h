#ifndef LIB_H
#define LIB_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define ERROR_CODE -1
#define VALID 0
#define MY_ADDR "127.0.0.1"
#define MY_PORT 8080
#define STDERR 2

void errorHandler(const char *errorMsg);

#endif