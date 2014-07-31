use hiredis 

https://github.com/redis/hiredis

make

mv *.lib *.o /usr/lib
mv *.h /usr/include

gcc -o server -std=c99 -lm -pthread -g -L. -lhiredis -Wl,-rpath,. server.c