#include "../catch2.hpp"

extern "C"
{
    #include "rest.h"
}

TEST_CASE("GET temperature")
{
    char *request = "GET /temperature HTTP/1.1 Host: localhost:30000 Connection: keep-alive Cache-Control: max-age=0 sec-ch";
    const char *expectedRespValue = "Response to GET /temperature";

    char *response = rest_processRequest(request);

    REQUIRE(strstr(response, expectedRespValue) != NULL);
}

TEST_CASE("GET humidity")
{
    char *request = "GET /humidity HTTP/1.1 Host: localhost:30000 Connection: keep-alive Cache-Control: max-age=0 sec-ch";
    const char *expectedRespValue = "Response to GET /humidity";

    char *response = rest_processRequest(request);

    REQUIRE(strstr(response, expectedRespValue) != NULL);
}

TEST_CASE("POST config")
{
    char *request = "POST /config HTTP/1.1 Host: localhost:30000 User-Agent: python-requests/2.28.1 Accept-Encoding: gzip, deflate Accept: */* Connection: keep-alive \\
    Content-Length: 35 Content-Type: application/json\r\n\r\n{\"delay\": \"100\", \"setpoint\": \"255\"}";
    const char *expectedRespValue = "{\"delay\": \"100\", \"setpoint\": \"255\"}";

    char *response = rest_processRequest(request);

    REQUIRE(strstr(response, expectedRespValue) != NULL);
}






