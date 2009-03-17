function shownhide(id) {
	if(document.getElementById){
		if (document.getElementById(id).style.visibility == "visible"){
			document.getElementById(id).style.visibility = "hidden";
			document.getElementById(id).style.display = "none";
		}else{
			if (document.getElementById(id).style.visibility == "hidden"){
				document.getElementById(id).style.visibility = "visible";
				document.getElementById(id).style.display = "block";
			}
		}
	}
}