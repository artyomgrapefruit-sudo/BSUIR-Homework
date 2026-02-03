let main = document.getElementById("main");
let button = document.getElementById("button");
let m = document.getElementById("m");
let p1 = document.getElementById("p1");
let p2 = document.getElementById("p2");

button.addEventListener("click", f);

function f() {
	button.innerText = "Bye-bye!"
	button.style.setProperty("border-radius", "10px 10px 100px 100px");
	m.style.setProperty("transform", "translate(170px, 48px)");
	setTimeout(y, 500);
}

function y() {
	p1.style.setProperty("transform", "translatex(16px) scaley(1)");
	p2.style.setProperty("transform", "translate(-104px, -145px) scaley(1)");
	setTimeout(z, 1000);
}

function z()
{
	main.style.setProperty("transform", "translatex(calc(1500px - 0px)");
}