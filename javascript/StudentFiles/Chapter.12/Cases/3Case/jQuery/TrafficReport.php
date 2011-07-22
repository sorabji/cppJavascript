<?php
$varCity = $_GET["city"];
$myModelFile = file_get_contents("http://cityrss.traffic.com/feeds/rss_" . $varCity);
header("content-Type: text/xml");
header("Content-Length: " . strlen($myModelFile));
header("Cache-Control: no-cache");
echo $myModelFile;
?>
