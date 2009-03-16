<?

/**
 * A File contains several global Functions
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 */

//############# Debugging Functions
function debug_var($var){
	print ("<pre>");
	print_r($var);
	print ("</pre>\n");
}

function debug_str($var){
	print "<pre>$var</pre>\n";
}

function debug($mixed){
	if(is_array($mixed)){
		debug_var($mixed);
	}else{
		debug_str($mixed);
	}
}




// ######### Sanitization Tools

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

// ######### Files and Directories

function directory2array($path){
	$array = array();
	$handle = opendir ($path);
	$counter = 0;
	while (false !== ($file = readdir ($handle))) {
		if(!($file=="." or $file=="..")){
			$array[$counter] = $file;
			$counter++;
		}
	}
	if(count($array)){
		sort($array);
	}
	return $array;
}

// ######### String Functions

function clean_alpha_num_string($string){
	return preg_replace("/\W/",  "", $string);
}

function clean_xml_content_string($string){
	if(is_string($string)){
		$string = stripslashes($string);
		$string = strip_tags($string);
		$string = ereg_replace("<", "", $string);
		$string = ereg_replace(">", "", $string);
		$string = ereg_replace("&", "&amp;", $string);
	}
	return $string;
}

function clean_quotation_string($string){
	$string = preg_replace("/\"/", "&#34;", $string);
	$string = preg_replace("/\'/", "&#39;", $string);
	return $string;
}

function clean_strip_quotations($string){
	$string = preg_replace("/\"/", "", $string);
	$string = preg_replace("/\'/", "", $string);
	return $string;
}

function clean_replace_umlaute($string){
	if(is_string($string)){
		$string = preg_replace("/Ö/", "Oe", $string);
		$string = preg_replace("/Ä/", "Ae", $string);
		$string = preg_replace("/Ü/", "Ue", $string);
		$string = preg_replace("/ö/", "oe", $string);
		$string = preg_replace("/ä/", "ae", $string);
		$string = preg_replace("/ü/", "ue", $string);
		$string = preg_replace("/ß/", "ss", $string);
		$string = preg_replace("/É/", "E", $string);
		$string = preg_replace("/È/", "E", $string);
		$string = preg_replace("/é/", "e", $string);
		$string = preg_replace("/è/", "e", $string);
		$string = preg_replace("/Á/", "A", $string);
		$string = preg_replace("/À/", "A", $string);
		$string = preg_replace("/á/", "a", $string);
		$string = preg_replace("/à/", "a", $string);
	}
	return $string;
}

function clean_replace_xmlentities($string){
	if(is_string($string)){
		$string = preg_replace("/&/", "", $string);
		$string = preg_replace("/</", "", $string);
		$string = preg_replace("/>/", "", $string);
	}
	return $string;
}

function clean_ascii_string($string){
	if(is_string($string)){
		$string = clean_replace_xmlentities($string);
		$string = clean_replace_umlaute($string);
		$string = preg_replace("/\s/",  "_", $string);
		$string = preg_replace("/\W/",  "", $string);
		$string = preg_replace("/_/",  " ", $string);
	}
	return $string;
}

function clean_file_name($string){
	if(is_string($string)){
		$string = clean_replace_xmlentities($string);
		$string = clean_replace_umlaute($string);
		$string = preg_replace("/\s/",  "_", $string);
	}
	return $string;

}


function add_leading_zeros($string, $n){
	$null = "0";
	for($i=1; $i<=$n; $i++){
		$add = $add.$null;
	}
	return substr($add.$string, $n*-1);
}


//############# Object Functions


/**
 * Returns all ancestors of a given class
 *
 * @param object $class   // Any given Object
 * @return array $classes // a numeric array containing all ancestors
 */
function get_ancestors ($class) {
	for ($classes[] = $class; $class = get_parent_class ($class); $classes[] = $class);
	return $classes;
}

/**
 * Test if one class is an subclass of a given class
 *
 *
 * @param string $descendant  	//name of the possivle subclass
 * @param string $ancestor		//name of the possible superclass
 * @return bool
 */
function is_subclass($descendant, $ancestor){
	$ancestors = get_ancestors($descendant);
	if(in_array($ancestor, $ancestors)){
		return true;
	}else{
		return false;
	}
}



// ############# Array Functions

function literalArray2numericArray($literalArray){
	$numericArray = array();
	foreach ($literalArray as $entry){
		$numericArray[] = $entry;
	}
	return $numericArray;
}

// ############# XML Functions
function xml_is_wellformed($string){
	$xml = @simplexml_load_string($string);				
	if(get_class($xml)!="SimpleXMLElement"){
		return false;
	}else{
		return true;
	}
}