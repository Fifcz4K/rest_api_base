#include "rest.h"

static char response[RESPONSE_BUFFER_SIZE] = {0};
static char* (*callback)(char *request);

static char* getTemperature(char* request);
static char* getHumidity(char* request);
static char* postConfig(char* request);

struct restApi requestCallbacks[NUMBER_OF_REQUESTS] =
{
    {"GET /temperature", getTemperature},
    {"GET /humidity", getHumidity},
    {"POST /config", postConfig}
};

static enum requestResult checkRestApiMethod(char* request)
{
    for(uint8_t i = 0; i < NUMBER_OF_REQUESTS; i++)
    {
        if(strstr(request, requestCallbacks[i].request) != NULL)
        {
            callback = requestCallbacks[i].callback;
            return requestOK;
        }
    }

    return requestWrong;
}

char* rest_processRequest(char* request)
{
    enum requestResult reqResult = checkRestApiMethod(request);
    if(reqResult != requestOK)
    {
        //handle error
        return "HTTP/1.1 404 Not Found\n\n";
    }

    char* responseContent = (*callback)(request);

    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: %d\r\n\r\n%s", strlen(responseContent), responseContent);

    return response;
}

static char* getTemperature(char* request)
{
    return "Response to GET /temperature";
}

static char* getHumidity(char* request)
{
    return "Response to GET /humidity";
}

static char* postConfig(char* request)
{
    char *body = strstr(request, HEADER_BODY_SEPARATOR);
    body += 4; // skip \r\n\r\n
    return body;
}