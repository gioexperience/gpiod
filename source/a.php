<?php

function fast_request($url)
{
    $parts=parse_url($url);
	print_r($parts);

	$path=$parts['path'];
	if( isset($parts["query"]) ) $path.="?".$parts["query"];
	
    $fp = fsockopen($parts['host'],isset($parts['port'])?$parts['port']:80,$errno, $errstr, 30);
    $out = "GET $path HTTP/1.1\r\n";
    $out.= "Host: ".$parts['host']."\r\n";
    $out.= "Content-Length: 0"."\r\n";
    $out.= "Connection: Close\r\n\r\n";

    fwrite($fp, $out);
    fclose($fp);
}



fast_request("http://192.168.0.1/api/b.php?uno=1&due=2",array("uno"=>1,"due"=>2));


?>