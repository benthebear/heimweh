<?


/**
 * Main Class of the Heimweh CMS
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 *
 */

class heimweh{
	// Contains an Array with the path from the $q Variable
	protected $path;
	// Contains an Array with the loaded modules
	protected $modules;
	// Contains an Array with the data from the menu-call
	protected $data;

	/**
	 * Get the Query-Parameter
	 *
	 * @return array containing the explodes $q
	 */
	public function create_path(){
		if(isset($_GET["q"])){
			$path = explode("/", $_GET["q"]);
			print_r ($path);
		}else{
			$path = array("module");
		}
		$this->path = $path;
	}


	/**
	 * Load all Modules
	 * 
	 * 
	 */
	function load_modules(){
		
	}

	/**
	 * Returns a List of all included Modules
	 *
	 * @return array containing the names of all loaded modules
	 */
	public function get_all_modules(){
		$modules = array("module");
		foreach (get_declared_classes() as $class){
			if(get_parent_class($class)=="module"){
				$this->modules [] = $class;
			}
		}
		
	}

	public function invoke_hook($hook){

	}

	/**
	 * Given a path and all Modules, this class invokes the Data-Switcher
	 * 
	 * It works pretty simple. It takes a look at the path.
	 * The it takes the first part of the path and looks wether there is a module with that name.
	 * If there ist a module with that name, it's method "menu" is called
	 *
	 *
	 * @param array $modules
	 * @param array $path
	 */
	public function call_menu($path){
		if(in_array($path[0], $this->modules)){
			$class = new $path[0]();
			$data = $class->menu($path);
		}else{
			print "404 - nichts ist hier";
		}
	}

}