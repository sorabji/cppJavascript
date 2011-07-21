<?php
header("content-Type: text/xml");
$varMovie = $_GET["movies"];
//$myModelFile = fopen($varMovie,"r");
$myModelFile = file_get_contents($varMovie);

//$xmlContent = fread($myModelFile);
fclose($myModelFile);

$fp = fopen("xmlShit.xml","w");
fwrite($fp,$xmlContent);
fclose($fp);


//header("Content-Length: " . strlen(trim($xmlContent)));
header("Content-Length: " . strlen($xmlContent));
header("Cache-Control: no-cache");
//echo $xmlContent;
echo $myModelFile;
?>
