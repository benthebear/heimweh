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

function ajaxManager() {
	var args = ajaxManager.arguments;
	switch (args[0]) {
		case "start_up":
		/*ajaxManager('load_page','navigation.xml','menu'); */
		/*
		Args 0: load_page (der Fall, der bearbeitet werden soll)
		Args 1: navigation.xml (die zu ladende Datei)
		Args 2: contentLYR (das Ziel-Div)
		*/
		break;
		case "load_page":
		if (document.getElementById) { // Nur Browser die "document.getElementById" koennen duerfen weitermachen
			// Browserweiche: IE braucht ActiveX, alle anderen koennen es direkt (if else Geschichte)
			var x = (window.ActiveXObject) ? new ActiveXObject("Microsoft.XMLHTTP") : new XMLHttpRequest();
		}//if

		// Jetzt muss es die Variable X geben, ob IE oder sonstwas:
		// X ist irgendwie die XMLHTTP-Schnittstelle...
		if (x) {
			x.onreadystatechange = function() {
				// Vigilant fuer Veraenderungen an X.
				if(x.readyState == 4 && x.status == 200) { // 4 heisst "complete" (0 = uninitialized, 1 = loading, 2 = loaded, 3 = interactive)
					el = document.getElementById(args[2]);
					el.innerHTML = x.responseText;          // "Place the data into an element and display it"
				}//if
			}//function
			x.open("GET",args[1],true); // Get the data, which file?, loading asynchronously is true
			x.send(null); // Es werden keine Daten transferiert, darum Null.
		}//if
		break;
		case "hide_menu":
		document.getElementById("eddies").style.visibility = "hidden";
		break;
	}//switch
}//function ajaxManager