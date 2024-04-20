let startTime, endTime;
let imageSize = "";
let image = new Image();
let bitSpeed = document.getElementById("bits");
    kbSpeed = document.getElementById("kbs");
    mbSpeed = document.getElementById("mbs")
    info = document.getElementById("info");

let totalBitSpeed = 0;
let totalKbSpeed = 0;
let totalMbSpeed = 0;
let numTests = 0;
let testCompleted = 0;

let imageApi = "https://source.unsplash.com/random?topic=nature";

//when image loads
image.onload = async function(){
    endTime = new Date().getTime();

    //get image size
    await fetch(imageApi).then((response) => {
        imageSize = response.headers.get("content-length");
        calculateSpeed();
    });

};

//calculate function

function calculateSpeed(){
    //time taken in sec
    let timeDuration = (endTime - startTime) / 1000;
    
    let loadedBits = imageSize * 8;
    let speedInBts = loadedBits / timeDuration;
    let speedInKbs = speedInBts / 1024;
    let speedInMbs = speedInKbs / 1024;


    totalBitSpeed += speedInBts;
    totalKbSpeed += speedInKbs;
    totalMbSpeed += speedInMbs;

    testCompleted++;


    if(testCompleted === numTests){
        let averageSpeedInBps = (totalBitSpeed / numTests).toFixed(2);
        let averageSpeedInKbps = (totalKbSpeed / numTests).toFixed(2);
        let averageSpeedInMbs = (totalMbSpeed / numTests).toFixed(2);

        //display average speeds
        bitSpeed.innerHTML += `${averageSpeedInBps}`;
        kbSpeed.innerHTML += `${averageSpeedInKbps}`;
        mbSpeed.innerHTML += `${averageSpeedInMbs}`;
        info.innerHTML = "Test Completed!";
    }else{
        //run the next test
        startTime = new Date().getTime();
        image.src = imageApi;
    }

}