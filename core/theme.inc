<?
/**
 * This file contains the theming function of Heimweh
 * 
 * Themeing in Heimweh is extremely simple. 
 * At any point in the Code (usually somewhere in a module)
 * the function theme_call_page() can be called to enter the
 * rendering process inside a Theme.
 * 
 * Inside a Theme most of the magic is done by include()
 * and Function which may deliver Data into the theme.
 * 
 * Additionally the function theme_foreach_teamplate() can
 * be used to iteratively include one template for the elements
 * of an array or the attributes of an object.
 * 
 *
 * @author Benjamin Birkenhake <benjamin@birkehake.org>
 * @package Heimweh
 */



/**
 * This function calls a Template within a given theme.
 * 
 * The additional array "data" should contain all Variables, 
 * you want to hand in from your module to the template.
 *
 * @param string $theme // The name of the theme. Esp. the name of the folder of the theme.
 * @param string $page // The name of the template. Esp. the name of the template file WITHOUT the .tpl Extension
 * @param array $data // An array containing data, which you want to hand in from the module.
 */
function theme_call_page($theme, $page, $data = array()){
	if(file_exists("themes/".$theme."/".$page.".tpl")){
		include ("themes/".$theme."/".$page.".tpl");
	}else{
		print "<!-- The Template '$page' does not exist inside the Theme '$theme'  -->";
	}
}

/**
 * This function calls a templage within a given theme foreach item in an array.
 * 
 * Usually this function can be used to recusrively include template for
 * lists of documents or comments and such.
 *
 * @param string $theme // The name of the theme. Esp. the name of the folder of the theme.
 * @param string $template // The name of the template. Esp. the name of the template file WITHOUT the .tpl Extension
 * @param array $array // An array with items, like documents, comments and such.
 */
function theme_foreach_template($theme, $template, $mixed){
	// First check wether the $mixed is foreachable
	if(count($mixed)>0){		
		foreach ($mixed as $item){
			if(file_exists("themes/".$theme."/".$page.".tpl")){
				include("themes/".$theme."/".$template.".tpl");
			}else{
				print "<!-- The Template '$page' does not exist inside the Theme '$theme'  -->";
			}
		}
	}else{
		print "<!-- This hasn't been an array -->";
	}
}

/**
 * This function creates a teaser text from any given text
 *
 * Heimweh uses a <hr class="break"/> to separate the teaser from the rest of the text.
 * If this can't be found within the text, it cuts the text just by some ammount of numbers.
 * 
 * @param string $text // The Text containing HTML
 * @return string
 */
function theme_get_teaser_text($text){
	if(count($array = explode('<hr class="break"/>', $text))>1){
		// First try to cut the teaser by the <hr>
		return strip_tags($array[0], "<a> <i> <b> <em> <strong>");
	}elseif(count($array = explode('</p>', $text))>1){
		// Then try to cut it by the end of the first paragraph
		return strip_tags($array[0], "<a> <i> <b> <em> <strong>");
	}else{
		// Otherwise return the first 400 Characters
		return substr(strip_tags($text), 0, 400);
	}
}