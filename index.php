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
 * Julia Sörgel						yol.lk
 * Konstantin Weiss				konnexus.net
 * Maurice Sand						fymmie.de
 * Arne Seemann						arnalyse.blogspot.com
 * Basti Sbr							zweipunknull.de
 * Christian Steiner			zweipunknull.de
 * Stefan Auditor					audiens.de
 * Frank Westphal					frankwestphal.de
 * 
 * Bring me the spriti, the son and the father, tell them their pillar of faith has ascended!
 * 
 * @author Benjamin Birkenhake <benjamin@birkenhake.org>
 * @package Heimweh
 * 
 */

// Set Constants for Database
define("DATABASE_SERVER", "localhost");
define("DATABASE_USER", "root");
define("DATABASE_PASSWORD", "root");
define("DATABASE_DATABASE", "heimweh");
define("DATABASE_PREFIX", "heimweh_");
define("ADMIN_PASSWORD", "12ced2b7254f998a728f5ba70c40921e");
define("DATETIME", "Y-m-d H:i:s");

// Connect to Database Server
$db = mysql_connect(DATABASE_SERVER, DATABASE_USER, DATABASE_PASSWORD);
// Instantly forcing a UFT8 Client Connection to avoid Schei�encoding 
mysql_query('SET NAMES "utf8"', $db);
// Connect to Heimweh Database
mysql_select_db(DATABASE_DATABASE);

// Loading Core Functions
include("core/functions.inc");
include("core/themengine.inc");

// Loading Core Classes
include("core/heimweh.inc");

$heimweh = new heimweh();
$heimweh->call_menu();

