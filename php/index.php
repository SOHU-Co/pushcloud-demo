
<?php
require_once 'Predis/Autoloader.php';

Predis\Autoloader::register();

$client = new Predis\Client([
    'password' => '1duvtlet0j:cf090196754d78b7090854a916426092728a1e30',
    'host'     => '10.16.33.62',
    'port'     => 8359,
    ]);
$client->lpush('sohu', 'sohu-php');

?>

