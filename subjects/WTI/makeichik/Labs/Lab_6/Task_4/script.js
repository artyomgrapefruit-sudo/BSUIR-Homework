function func() {
  const a = document.getElementById('a');
  const b = document.getElementById('b');

  let a_val = Number(a.value);
  let b_val = Number(b.value);

  const answer = document.getElementById('answer');
  answer.innerHTML = a_val + b_val;
}