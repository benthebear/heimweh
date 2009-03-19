<?
// At First load the xml into an Simple-XML Object.
$xml = simplexml_load_string($data["document"]["xml"])?>
<?include("header.tpl");?>
<?include("sidebar.tpl");?>
<div id="arena">
<?if(isset($xml->teaserimage)){ ?><img class="teaserimage" src="<?=$xml->teaserimage["url"]?>" /><?}?>
<h2><?=$xml->title?></h2>

<div class="text">
<?=$xml->text->asXML()?>
</div>

<div id="comments">
<h3>Kommentare</h3>
<? theme_foreach_template("nationalgalerie", "comment", $xml->comments->comment); ?>


<form method="POST" enctype="text/plain" action="<?=env_get_base()?>comment/add/<?=$xml["id"]?>">
<textarea name="text"></textarea><br/>
Bitte kein HTML schreiben! Alle Tags werden weggeworfen.<br/>
Absätze werden automatisch generiert. URLs werden verlinkt.<br/>
<input name="commentator" type="text"  /> Mein Name<br/>
<input name="url" type="text" value="http://" /> Meine Webseite<br/>
<input name="wederhundnochspambot" type="text"  /> Bin weder Hund noch Spambot<br/>
<input class="submit" type="submit" value="Kommentieren"/>
</form>


</div>




<? include("rawdata.tpl");?>

</div>

<? //include("footer.tpl");?>