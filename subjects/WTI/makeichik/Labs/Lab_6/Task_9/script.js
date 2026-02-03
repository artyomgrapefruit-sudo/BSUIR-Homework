let button = document.getElementById("button");

button.onclick = function go() {
    window.timerId = window.setInterval(f, 1000);
    button.disabled = true;
}

function f() {
    let asteroid = document.getElementById("asteroid");
    let spaceship = document.getElementById("spaceship");
    let ufo = document.getElementById("ufo");
    let zero = asteroid.src;
    asteroid.src = spaceship.src;
    spaceship.src = ufo.src;
    ufo.src = zero;
}