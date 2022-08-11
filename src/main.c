#include "stdio.h"
#include "server.h"

int main(void)
{
#ifdef __WIN32__
    serverStartup();
#endif
    serverSocketCreate();
    serverSocketBind();
    serverListen();

	serverProcess();

#ifdef __WIN32__
    serverClean();
#endif
    return 0;
}
