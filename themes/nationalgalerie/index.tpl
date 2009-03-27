<?include("header.tpl");?>
<?include("sidebar.tpl");?>

<div id="arena">
<? theme_foreach_template("nationalgalerie", "teaser", $data["documents"]); ?>
<?//include("rawdata.tpl");?>
</div>

<?include("footer.tpl");?>
