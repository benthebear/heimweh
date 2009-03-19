<div class="teaser">
<?$xml = simplexml_load_string($item["xml"]);?>
<h2><a href="<?=env_get_base()?>document/<?=$xml["id"]?>"><?=$xml->title?></a></h2>
<p class="teaserimage">
<?if(isset($xml->teaserimage)){ ?><img src="<?=$xml->teaserimage["url"]?>" /><br/><?}?>
</p>
<p class="text">
<?=theme_get_teaser_text($xml->text->asXML())?> 
:: <a class="readon" href="<?=env_get_base()?>document/<?=$xml["id"]?>">Artikel lesen</a>
</p>
<p class="meta">
<?=date("d. m. Y", strtotime($xml->created))?> 
:: <a href="<?=env_get_base()?>document/<?=$xml["id"]?>#comments"><?=count($xml->comments->comment)?> Kommentare</a> 
:: <?=$xml->counter?> Klicks
</p>
</div>