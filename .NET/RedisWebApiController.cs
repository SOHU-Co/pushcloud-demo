using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

using ServiceStack.Redis;

namespace WebApplication.Controllers
{
    

    public class RedisWebApiController : ApiController
    {
        static RedisClient redisClient = new RedisClient("10.16.33.62", 8359);

        public long Get()
        {
            redisClient.Password = "1duvrlo7ws:2ee3e6e33465f1da9e50ce6ea35f921b3e690563";
            string message = "helloworld";
            byte[] byteArray = System.Text.Encoding.Default.GetBytes(message);
            long result = redisClient.LPush("test", byteArray);
            return result;
        }

        // GET: api/RedisWebApi/5
        public void Get(int id)
        {
        }

        // POST: api/RedisWebApi
        public void Post([FromBody]string value)
        {
        }

        // PUT: api/RedisWebApi/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/RedisWebApi/5
        public void Delete(int id)
        {
        }
    }
}
