<?

/**
 * A File contains several global Functions
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 */

function sanitize_text($text){
	$clean = ereg_replace("\n", "", strip_tags($text));
	return $clean;
}

function sanitize_array($array){
	foreach ($array as $key => $value){
		if(is_array($value)){
			$clean[$key] = sanitize_array($value);
		}else{
			$clean[$key] = sanitize_text($value);
		}
	}
	return $clean;
}

function sanitize($mixed){
	if(is_array($mixed)){
		$clean = sanitize_array($mixed);
	}else{
		$clean = sanitize_text($mixed);
	}
	return $clean;
}