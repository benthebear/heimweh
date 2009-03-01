<?


function theme_call_page($theme, $page, $data = array()){
	include ("themes/".$theme."/".$page.".php");
}