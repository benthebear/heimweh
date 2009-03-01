<?

/**
 * General abstract Module for Modules
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 *
 */


class module{

	public function menu ($path){
		print get_class($this)."::".implode("/", $path);
	}
}