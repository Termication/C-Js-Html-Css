const key = '9f4c1fcdecc54ff62573c3763650ee8c';

async function search(){
    const phrase = document.querySelector('input[type="text"]').value;
    //console.log(phrase);
    const response = await fetch(`http://api.openweathermap.org/geo/1.0/direct?q=${phrase}&limit=5&appid=${key}`);
    const data = await response.json();
    const ul = document.querySelector('form ul');
    // acess data from api and let it pop when searching
    ul.innerHTML = '';
    for(let i = 0; i < data.length; i++){
        const {name, lat, lon, country} = data[i];
            ul.innerHTML += `<li data-lat="${lat}" data-lon="${lon}" data-name="${name}">${name} <span>${country}</span></li>`;
    }
}
const debouncedSearch = _.debounce(() => {
    search();
}, 600);

document.querySelector('input[type="text"]').addEventListener('keyup', debouncedSearch);
