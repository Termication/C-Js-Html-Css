const key = '9f4c1fcdecc54ff62573c3763650ee8c';

async function search(){
    const phrase = document.querySelector('input[type="text"]').value;
    
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

async function showWeather(lat, lon, name){
    const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${key}&units=metric`);
    const data = await response.json();
    const temp = Math.round(data.main.temp);
    const feelslike = Math.round(data.main.feels_like);
    const humidity = data.main.humidity;
    const wind = Math.round(data.wind.speed);
    const icon = data.weather[0].icon;

    console.log(data);

    document.getElementById('city').innerHTML = name;
    document.getElementById('degrees').innerHTML = temp + `&deg;C`;
    document.getElementById('feelslikeValue').innerHTML = feelslike + '<span>&deg;C<span></span>';
    document.getElementById('windValue').innerHTML = wind + '<span>km/h<span></span>';
    document.getElementById('humidityValue').innerHTML = humidity + `<span>%<span></span>`;
    //document.getElementById('icon').src = `https://openweathermap.org/img/wn/10@2x.png`;
  
    // Update background image based on weather condition
    /*const body = document.body;
    switch (weatherCondition) {
        case 'clear':
            body.style.backgroundImage = 'url("sunny.jpg")';
            break;
        case 'snow':
        case 'clouds':
            body.style.backgroundImage = 'url("freezing.jpg")';
            break;
        case 'wind':
            body.style.backgroundImage = 'url("windy.jpg")';
            break;
        default:
            body.style.backgroundImage = ''; // Clear background image for other conditions
            break;
    }*/
    document.querySelector('form').style.display = 'none';
    document.getElementById('weather').style.display = 'block';

}
document.querySelector('input[type="text"]').addEventListener('keyup', debouncedSearch);


document.body.addEventListener('click', ev => {
        const li = ev.target;
        const {lat,lon,name} = li.dataset;
        //system to remember last city entered
        localStorage.setItem('lat', lat);
        localStorage.setItem('lon', lon);
        localStorage.setItem('name', name);

        if(!lat){
            return;
        }
        showWeather(lat, lon, name);
});
document.getElementById('change').addEventListener('click', () => {
    document.getElementById('weather').style.display = "none";
    document.querySelector('form').style.display = 'block';
});
