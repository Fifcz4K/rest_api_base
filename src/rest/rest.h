#ifndef REST_H
#define REST_H

#include "stdio.h"
#include "stdint.h"
#include "string.h"

#define RESPONSE_BUFFER_SIZE 1000
#define NUMBER_OF_REQUESTS 3
#define HEADER_BODY_SEPARATOR "\r\n\r\n"

struct restApi
{
    char* request;
    char* (*callback)(void);
};

enum requestResult
{
    requestOK,
    requestWrong
};

char* rest_processRequest(char* request);

#endif //REST_H