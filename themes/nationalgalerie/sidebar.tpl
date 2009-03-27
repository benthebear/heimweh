<div id="sidebar">
<!-- <img src="<?=env_get_base()?>themes/nationalgalerie/anmutunddemut-logo.jpg"> -->



<ul>

<li><a href="/node/12" title="Vorwort">Vorwort</a></li>
<li><a href="/codex" title="Codex">Codex</a></li>
<li><a href="/register/all" title="">Register</a></li>
<li><a href="/archive/" title="Chronologisches Archiv aller Blogbeiträge">Archiv</a></li>
<li><a href="/impressum" title="Impressume">Impressum</a></li>
<li><a href="/feeds" title="Feeds">Feeds</a></li>
</ul>

<?if(isset($xml->created)){
	print("<p class='date'>".date("d. m. Y", strtotime("".$xml->created))."</p>");
	
}?>

<?if(isset($xml->topics)){
print "<ul>";
foreach ($xml->topics->topic as $topic) {
		print "<li>".$topic."</li>";
	}	
print "</ul>";	
}?>

</div>