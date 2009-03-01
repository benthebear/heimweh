<?

/**
 * "Heimweh" is a Minimalistic XML Web Content Management System
 * 
 * I have to say thank you to all the great Developers who inspired this project by their passion.
 * Especially those who are Part of Drupal.org Wordpress.org Zeit.de and Digitalkombinat.net
 * 
 * Personally I have to thank
 * 
 * Marcus Abel						digitalkombinat.net
 * Thomas Baumann					digitalkombinat.net
 * Sebastian Ermshaus 		digitalkombinat.net
 * Sascha Hagemann				digitalkombiant.net 
 * Ron Drongowski					drongowski.net
 * Nico Brünjes						codecandies.de
 * Marc Tönsing						marctv.de
 * Sven Heising						endeneu.de
 * Sebastian Munz					yo.lk
 * Konstantin Weiss				konnexus.net
 * Maurice Sand						fymmie.de
 * Arne Seemann						arnalyse.blogspot.com
 * Basti Sbr							zweipunknull.de
 * Christian Steiner			zweipunknull.de
 * Stefan Auditor					audiens.de
 * Frank Westphal					frankwestphal.de
 * 
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * 
 */




// Loading Core Functions
include("core/functions.php");
include("core/theme.php");

// Loading Core Classes
include("core/heimweh.class.php");
include("core/module.module.class.php");

$heimweh = new heimweh();
$heimweh->call_menu();

