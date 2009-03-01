<?

/**
 * General abstract Module for Modules
 * 
 * All other Modules have to be a direct subclass of this one
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 *
 */


class module{

	public function menu ($path, $theme){
		$data[] = $path;
		$data[] = "Ich war hier";
		theme_call_page($theme, "index", $data);
	}
}