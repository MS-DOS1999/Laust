var geneNULL=[];



for(i=0; i<40; i++){
	geneNULL.push("TabCollide["+i+"] = NULL;");
}

for(i=0; i<40; i++){
	geneNULL.push("TabDirection["+i+"] = NULL;");
}

for(i=0; i<80; i++){
	document.getElementById("lel").innerHTML += geneNULL[i];
	document.getElementById("lel").innerHTML += "<br />"
}