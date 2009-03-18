<?


function theme_call_page($theme, $page, $data = array()){
	include ("themes/".$theme."/".$page.".tpl");
}

function theme_foreach_template($theme, $template, $array){
	foreach ($array as $item){
		include("themes/".$theme."/".$template.".tpl");
	}
}

function theme_get_teaser_text($text){
	return substr(strip_tags($text), 0, 600);
}