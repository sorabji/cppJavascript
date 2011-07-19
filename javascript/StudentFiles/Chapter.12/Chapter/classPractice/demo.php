<?php
header("content-Type: text/xml");
$myModelFile = fopen("demo.xml","r");
$xmlContent = fread(myModelFile,2500);
fclose(myModelFile);

header("Content-Length: " . strlen(trim($xmlContent)));
header("Cache-Contorol: no-cache");
echo trim($xmlContent);
?>
