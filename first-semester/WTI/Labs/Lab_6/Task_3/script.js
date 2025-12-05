function func() {
  const my_selector = document.getElementById('text');
  // my_selector.innerText = 'Изменился и стал';

  my_selector.outerHTML = '<p>Изменился и стал <em>жирным</em></p>' ;
}