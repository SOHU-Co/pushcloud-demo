use redis-py

https://github.com/andymccurdy/redis-py

there exsits problem in file _compat.py

when connect to remote server established by pushcloud , 'long' has no method encode

this code line 
    x if isinstance(x, str) else x.encode('utf-8', 'replace') 
need to be revise, one alternate is:
    x if isinstance(x, str) or isinstance(x, long)  else x.encode('utf-8', 'replace')
