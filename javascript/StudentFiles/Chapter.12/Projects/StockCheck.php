<?php
header("Content-Type: text/xml");
$QuoteXML = "<?xml version='1.0' encoding='iso-8859-1' standalone='yes' ?>\n";
$TickerSymbol = $_GET["checkQuote"];
$Quote = fopen("http://quote.yahoo.com/d/quotes.csv?s=$TickerSymbol&f=sl1d1t1c1ohgv&e=.csv", "r");
$QuoteString = fread($Quote, 2000);
fclose($Quote);
$QuoteString = str_replace("\"", "", $QuoteString);
$QuoteArray = explode(",", $QuoteString);
$QuoteXML .= "<quote>\n";
$QuoteXML .= "<ticker>{$QuoteArray[0]}</ticker>\n";
$QuoteXML .= "<lastTrade>{$QuoteArray[1]}</lastTrade>\n";
$QuoteXML .= "<lastTradeDate>{$QuoteArray[2]}</lastTradeDate>\n";
$QuoteXML .= "<lastTradeTime>{$QuoteArray[3]}</lastTradeTime>\n";
$QuoteXML .= "<change>{$QuoteArray[4]}</change>\n";
$QuoteXML .= "<open>{$QuoteArray[5]}</open>\n";
$QuoteXML .= "<rangeHigh>{$QuoteArray[6]}</rangeHigh>\n";
$QuoteXML .= "<rangeLow>{$QuoteArray[7]}</rangeLow>\n";
$QuoteXML .= "<volume>{$QuoteArray[8]}</volume>\n";
$QuoteXML .= "<chart>http://ichart.yahoo.com/t?s=$TickerSymbol</chart>\n";
$QuoteXML .= "</quote>";
header("Content-Length: " . strlen($QuoteXML));
header("Cache-Control: no-cache");
echo $QuoteXML;
?>

