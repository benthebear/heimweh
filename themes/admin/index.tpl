<?header("Content-Type: text/html; charset=utf-8");?>
<title>Heimweh Admin Area</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="Generator" content="Heimweh 0.1"/>
<link type="text/css" rel="stylesheet" media="all" href="<?=get_base()?>themes/admin/admin.css" />
<script src="<?=get_base()?>javascript/quicktags.js" type="text/javascript"></script>
<h1>Heimweh Admin Area</h1>



<form action="<?=get_base()?><?=implode("/", $data["q"])?>" method="POST" accept-charset="UTF-8">
<script type="text/javascript">edToolbar('canvas');</script>
<textarea id="canvas" name="document" rows="20" cols="100">
<?=$data["document"]?>
</textarea>

<p>
<input type="password" name="password" />
<input name="submit" type="submit" value="Save" />
<input name="submit" type="submit" value="Buffer" />
<input name="submit" type="submit" value="Publish" />
<?
$xml = simplexml_load_string($data["document"]);
print "<a href='/heimweh/document/".$xml["id"]."'>View No. ".$xml["id"]."</a>";
?>
</p>

</form>


<?if(isset($data["message"])){?>
<div class="message">
<h2>Nachrichten</h2>
<ul>
<?foreach ($data["message"] as $message){?>
	<li><?=$message?></li>
<?}?>
</ul>
</div>
<?}?>

<div> 
<pre>
<? //print_r($data); ?>
</pre>
</div>

<?//phpinfo()?>