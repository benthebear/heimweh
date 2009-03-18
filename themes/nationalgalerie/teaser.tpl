<div class="teaser">
<?$xml = simplexml_load_string($item["xml"]);?>
<h2><a href="<?=env_get_base()?>document/<?=$xml["id"]?>"><?=$xml->title?></a></h2>
<?if(isset($xml->teaserimage)){ ?><img class="teaserimage" src="<?=$xml->teaserimage["url"]?>" /><?}?>
<p class="text"><?=theme_get_teaser_text($xml->text->asXML())?></p>
</div>