<?include("header.tpl");?>
<?include("sidebar.tpl");?>
<?$xml = simplexml_load_string($data["document"]["xml"])?>
<div id="arena">
<?if(isset($xml->teaserimage)){ ?><img class="teaserimage" src="<?=$xml->teaserimage["url"]?>" /><?}?>
<h2><?=$xml->title?></h2>

<div class="text">
<?=$xml->text->asXML()?>
</div>

<? //include("rawdata.tpl");?>

</div>

<? //include("footer.tpl");?>