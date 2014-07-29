import tornado.ioloop
import tornado.web

import redis


cache = redis.StrictRedis( password='1duvtlet0j:cf090196754d78b7090854a916426092728a1e30',host='10.16.33.62', port=6379)
#cache.auth('1duvtlet0j:cf090196754d78b7090854a916426092728a1e30');
#can't auth
print cache

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        #cache.lpush('sohu', 'test-sohu');
        #print cache.keys()
        self.write("Hello, sohu")

application = tornado.web.Application([
    (r"/", MainHandler),
])

if __name__ == "__main__":
    application.listen(8888)
    tornado.ioloop.IOLoop.instance().start()