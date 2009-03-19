<?$xml = simplexml_load_string($item["xml"]);?> 
<entry>
   <title><?=$xml->title?></title>
   <link href="http://example.org/2003/12/13/atom03"/>
   <id><?=$xml["id"]?></id>
   <updated><?=date("c", strtotime($xml->created))?></updated>
   <content type="xhtml" xml:base="http://example.org/">
   	<div xmlns="http://www.w3.org/1999/xhtml">
   	<?=strip_tags($xml->text->asXML(), "<p> <img> <a> <i> <b> <em> <strong>")?>
   	</div>
   </content>  
</entry>