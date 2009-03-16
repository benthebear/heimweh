<title>Heimweh Admin Area</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="Generator" content="Heimweh 0.1"/>
<script src="js-quicktags/js_quicktags.js" type="text/javascript"></script>
<h1>Heimweh Admin Area</h1>

<form action="admin" method="POST">
<script type="text/javascript">edToolbar('canvas');</script>
<textarea id="canvas" name="document" rows="20" cols="50">
<?=$_POST["document"]?>
</textarea>

<p>
<input name="submit" type="submit" value="Save">
<input name="submit" type="submit" value="Buffer">
<input name="submit" type="submit" value="Publish">
</p>

</form>

<div> 
<pre>
<? print_r($_POST); ?>
</pre>
</div>