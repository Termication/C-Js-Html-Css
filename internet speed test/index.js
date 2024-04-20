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

}