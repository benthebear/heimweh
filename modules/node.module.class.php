<?

/**
 * Node Module of Heimweh CMS
 * 
 * Organizes Loading, Editing and Saving of Content Objects.
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 *
 */

class node extends module  {
	
	public function menu ($path){
		print "my::".implode("/", $path);
	}
	
}