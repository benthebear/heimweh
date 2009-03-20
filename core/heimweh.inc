<?


/**
 * Main Class of the Heimweh XML Content Storage and Rendering Thing
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

	
	
	/**
	 * Main Constructor of Heimweh
	 *
	 */
	public function __construct(){
		// At first, create the path
		$this->create_path();
		// Set default Theme
		$this->theme = "nationalgalerie";
		// Load all Modules
		$this->load_modules();
		// Set Modules to Attribute
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
		// Load Core Modules
		include("core/module.module");
		include("core/admin.module");	
		// Load Everything in the Modules Folder
		foreach (directory_to_array("modules") as $file){
			include("modules/".$file);
		}
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

	/**
	 * A general Function to invoke Hooks.
	 * 
	 * A hook is a Method of a Module-Class with a special name.
	 * When a hook is invoked, all loaded Modules are checked, wether
	 * they have a method, with the name of the hook and in case
	 * the hook implementation in that module is called.
	 *
	 * @param unknown_type $hook
	 */
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
		// If theres a module with the same name as the first part of the path,
		// it's menu method is called
		if(in_array($this->path[0], $this->modules)){
			$class = new $this->path[0]();
			$class->menu($this->path, $this->theme);
		}else{
			// Otherwise we send a 404
			theme_call_page($this->theme, "404");
		}
	}
}