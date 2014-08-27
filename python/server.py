import tornado.ioloop
import tornado.web

import redis
#10.16.1.131
#10.16.33.

client = redis.StrictRedis( password='1d32rh48cl:87a03e86c2c1650c4a32b679ba30a4edd7aca89e',host='10.16.1.131', port=8359)

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        message = 'test-python'
        result = client.lpush('1dy1mgefqy', message)
        self.write("complete")

application = tornado.web.Application([
    (r"/", MainHandler),
])

if __name__ == "__main__":
    application.listen(8080)
    tornado.ioloop.IOLoop.instance().start()