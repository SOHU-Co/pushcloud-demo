var options = {
    topics: "sohu",
    token: "35e686f50ffa6c9b645b058c6cd1e693",
    timestamp: "1406545809093",
    appid: "1duvtlet0j"
};
var channel = new Channel(options);
channel.onopen = function () {};
channel.onmessage = function (msg) {
    console.log(msg.data);
};
channel.onerror = function (err) {};
channel.onclose = function (reason) {};