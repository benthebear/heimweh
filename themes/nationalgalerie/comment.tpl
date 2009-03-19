<div class="comment" id="<?=$item["cid"]?>">
<div class="text"><?=$item->text->asXML()?></div>
<p class="commentator">
<?if($item->commentator["url"]!=""){?><a href="<?=$item->commentator["url"]?>"><?}?><?=$item->commentator?><?if($item->commentator["url"]!=""){?></a><?}?>
</p>
</div>