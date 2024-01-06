const key = '9f4c1fcdecc54ff62573c3763650ee8c';

function search(){
    const phrase = document.querySelector(selectors: 'input[type="text"]').value;
    fetch(input: '');
}
const debouncedSearch = _.debounce(() => {
    search();
}, 600);

document.querySelector('input[type="text"]').addEventListener('keyup', debouncedSearch);
