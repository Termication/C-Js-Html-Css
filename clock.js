const myclock = document.getElementById("clock");

update();

function update(){
    let date = new Date();
    myclock.innerHTML = formatTime(date);

    function formatTime(){
        let hours = date.getHours();
        let minutes = date.getMinutes();
        let seconds = date.getSeconds();

        return '${hours}:${minutes}:${seconds}'
    }
}