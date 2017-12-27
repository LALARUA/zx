
window.onload=function()
{


var lnks=document.getElementsByTagName("a");

for (var i = 0; i < lnks.length; i++) {
	lnks[i].onclick=function()
	{
		showpic(this);
		return false;
	}
}

}

       

function showpic(whichpic)
		{
			var source=whichpic.getAttribute("href");
			document.getElementById("blankimg").setAttribute("src", source);
			var title1=whichpic.getAttribute("title");
			document.getElementById("pp").firstChild.nodeValue=title1;
			

		}
		function count()
		{
            var bodyelement=document.getElementsByTagName("body")[0];
			alert(bodyelement.childNodes.length);
		}
		function popup(winurl)
		{
			window.open(winurl,"popup","width=320px,height=450px;")

		}