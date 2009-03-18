<?include("header.tpl");?>
<?include("sidebar.tpl");?>

<div id="arena">
<? theme_foreach_template("nationalgalerie", "teaser", $data["documents"]); ?>
</div>

<?//include("rawdata.tpl");?>

<?include("footer.tpl");?>