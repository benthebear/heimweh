<?


/**
 * Main Class of the Heimweh CMS
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 *
 */

class heimweh{

	public function get_path(){
		if(isset($_GET["q"])){
			$path = explode("/", $_GET["q"]);
			print_r ($path);
		}else{
			$path = array("module");
		}
		return $path;
	}



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

	public function call_menu($modules, $path){
		if(in_array($path[0], $modules)){
			$class = new $path[0]();
			$class->menu($path);
		}else{
			print "404 - nichts ist hier";
		}
	}

}