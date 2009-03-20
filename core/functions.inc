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
	ob_start();
	print_r($var);
	$output = ob_get_contents();
	ob_end_clean();
	print htmlspecialchars($output, ENT_COMPAT, "UTF-8");
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

function directory_to_array($path){
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


function string_add_leading_zeros($string, $n){
	$null = "0";
	for($i=1; $i<=$n; $i++){
		$add = $add.$null;
	}
	return substr($add.$string, $n*-1);
}

/**
 * This function converts line breaks into <p> and <br> in an intelligent fashion.
 * 
 * Based on: http://drupal.org
 * Based on: http://photomatt.net/scripts/autop
 * 
 * Standing on the shoulders of giants
 * 
 * @param string $text // The text to be autoparagraphed
 * @return string // Autoparagraphed text
 */
function string_autop($text) {
	// All block level tags
	$block = '(?:table|thead|tfoot|caption|colgroup|tbody|tr|td|th|div|dl|dd|dt|ul|ol|li|pre|select|form|blockquote|address|p|h[1-6]|hr)';

	// Split at <pre>, <script>, <style> and </pre>, </script>, </style> tags.
	// We don't apply any processing to the contents of these tags to avoid messing
	// up code. We look for matched pairs and allow basic nesting. For example:
	// "processed <pre> ignored <script> ignored </script> ignored </pre> processed"
	$chunks = preg_split('@(</?(?:pre|script|style|object)[^>]*>)@i', $text, -1, PREG_SPLIT_DELIM_CAPTURE);
	// Note: PHP ensures the array consists of alternating delimiters and literals
	// and begins and ends with a literal (inserting NULL as required).
	$ignore = FALSE;
	$ignoretag = '';
	$output = '';
	foreach ($chunks as $i => $chunk) {
		if ($i % 2) {
			// Opening or closing tag?
			$open = ($chunk[1] != '/');
			list($tag) = split('[ >]', substr($chunk, 2 - $open), 2);
			if (!$ignore) {
				if ($open) {
					$ignore = TRUE;
					$ignoretag = $tag;
				}
			}
			// Only allow a matching tag to close it.
			else if (!$open && $ignoretag == $tag) {
				$ignore = FALSE;
				$ignoretag = '';
			}
		}
		else if (!$ignore) {
			$chunk = preg_replace('|\n*$|', '', $chunk) ."\n\n"; // just to make things a little easier, pad the end
			$chunk = preg_replace('|<br />\s*<br />|', "\n\n", $chunk);
			$chunk = preg_replace('!(<'. $block .'[^>]*>)!', "\n$1", $chunk); // Space things out a little
			$chunk = preg_replace('!(</'. $block .'>)!', "$1\n\n", $chunk); // Space things out a little
			$chunk = preg_replace("/\n\n+/", "\n\n", $chunk); // take care of duplicates
			$chunk = preg_replace('/\n?(.+?)(?:\n\s*\n|\z)/s', "<p>$1</p>\n", $chunk); // make paragraphs, including one at the end
			$chunk = preg_replace('|<p>\s*</p>\n|', '', $chunk); // under certain strange conditions it could create a P of entirely whitespace
			$chunk = preg_replace("|<p>(<li.+?)</p>|", "$1", $chunk); // problem with nested lists
			$chunk = preg_replace('|<p><blockquote([^>]*)>|i', "<blockquote$1><p>", $chunk);
			$chunk = str_replace('</blockquote></p>', '</p></blockquote>', $chunk);
			$chunk = preg_replace('!<p>\s*(</?'. $block .'[^>]*>)!', "$1", $chunk);
			$chunk = preg_replace('!(</?'. $block .'[^>]*>)\s*</p>!', "$1", $chunk);
			$chunk = preg_replace('|(?<!<br />)\s*\n|', "<br />\n", $chunk); // make line breaks
			$chunk = preg_replace('!(</?'. $block .'[^>]*>)\s*<br />!', "$1", $chunk);
			$chunk = preg_replace('!<br />(\s*</?(?:p|li|div|th|pre|td|ul|ol)>)!', '$1', $chunk);
			$chunk = preg_replace('/&([^#])(?![A-Za-z0-9]{1,8};)/', '&amp;$1', $chunk);
		}
		$output .= $chunk;
	}
	return $output;
}




//############# Object Functions


/**
 * Returns all ancestors of a given class
 *
 * @param object $class   // Any given Object
 * @return array $classes // a numeric array containing all ancestors
 */
function object_get_ancestors ($class) {
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
function object_is_subclass($descendant, $ancestor){
	$ancestors = get_ancestors($descendant);
	if(in_array($ancestor, $ancestors)){
		return true;
	}else{
		return false;
	}
}




// ############# Array Functions

function array_literalArray2numericArray($literalArray){
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

// ############# Server Variables Functions

function env_get_base(){
	return ereg_replace("index.php", "", 	$_SERVER["SCRIPT_NAME"]);
}
