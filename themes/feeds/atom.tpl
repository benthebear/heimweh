<?
header("Content-Type: text/xml; charset=utf-8");
print('<?xml version="1.0" encoding="utf-8"?>');
?>
<feed xmlns="http://www.w3.org/2005/Atom">
 
 <title>Your Blog</title>
 <subtitle>A subtitle.</subtitle>
 <link href="http://example.org/feed/" rel="self"/>
 <link href="http://example.org/"/>
 <updated>2003-12-13T18:30:02Z</updated>
 <author>
   <name>Your Name</name>
   <email>yourname@example.com</email>
 </author>
 
<?theme_foreach_template("feeds", "atom-entry", $data["documents"]);?>
 
</feed>
