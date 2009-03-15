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
	// The name of the theme;
	protected $theme;

	
	
	public function __construct(){		
		$this->create_path();
		$this->theme = "nationalgalerie";
		$this->load_modules();
		$this->modules = $this->get_all_modules();
	}
	
	
	/**
	 * Get the Query-Parameter
	 *
	 * @return array containing the explodes $q
	 */
	public function create_path(){
		// If the path is set, use it
		if(isset($_GET["q"])){
			$q = sanitize_text($_GET["q"]);
			$path = explode("/", $q);
			//print_r ($path);
		// If the path isn't set use core-Module
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
	public function load_modules(){
		include("modules/node.module.class.php");
		include("modules/archive.module.class.php");
		include("modules/tests.module.class.php");
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
				$modules [] = $class;
			}
		}
		return $modules;
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
	public function call_menu(){
		if(in_array($this->path[0], $this->modules)){
			$class = new $this->path[0]();
			$class->menu($this->path, $this->theme);
		}else{
			theme_call_page($this->theme, "404");
		}
	}
}