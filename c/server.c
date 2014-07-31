#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis.h>

int main(int argc, char **argv) {
    unsigned int j;
    redisContext *c;
    redisReply *reply;
    const char *hostname = (argc > 1) ? argv[1] : "10.16.33.62";
    int port = (argc > 2) ? atoi(argv[2]) : 8359;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    /* AUTH */
    reply = redisCommand(c,"AUTH %s", "1duvtlet0j:cf090196754d78b7090854a916426092728a1e30");
    printf("AUTH: %s\n", reply->str);
    freeReplyObject(reply);

    /* PING server */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /*LPUSH*/
    for( j = 0; j < 10; j++) 
    {
        reply = redisCommand(c,"LPUSH %s %s", "sohu", "sohu-c");
        freeReplyObject(reply);      
    }

    /* Disconnects and frees the context */
    redisFree(c);

    return 0;
}