function func() {
  const elems = document.querySelectorAll('.pr');
  for(let i=0; i<elems.length; i++){
    elems[i].innerHTML = i+1;
  }
}