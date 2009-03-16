<title>Heimweh Admin Area</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="Generator" content="Heimweh 0.1"/>
<script src="<?=get_base()?>js-quicktags/heimweh_quicktags.js" type="text/javascript"></script>
<h1>Heimweh Admin Area</h1>

<form action="admin" method="POST">
<script type="text/javascript">edToolbar('canvas');</script>
<textarea id="canvas" name="document" rows="20" cols="100">
<?=$data["document"]?>
</textarea>

<p>
<input name="submit" type="submit" value="Save">
<input name="submit" type="submit" value="Buffer">
<input name="submit" type="submit" value="Publish">
</p>

</form>


<div> 
<pre>
<? print_r($data); ?>
</pre>
</div>

<?//phpinfo()?>