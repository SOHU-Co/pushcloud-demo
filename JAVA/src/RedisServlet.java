import redis.clients.jedis.Jedis;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class RedisServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        Jedis jedis = new Jedis("10.16.33.62", 8359);
        jedis.auth("1duvtlet0j:cf090196754d78b7090854a916426092728a1e30");
        System.out.println(jedis.lpush("sohu", "sohu-java"));

        PrintWriter writer = response.getWriter();
        writer.println("Hello, sohu!");
        writer.close();

    }
}
