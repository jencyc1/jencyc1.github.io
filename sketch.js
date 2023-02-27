var serial; // variable to hold an instance of the serialport library
var portName = '/dev/tty.usbmodem14101'; //rename to the name of your port
var inData = []; //creates array with data
let isOn = false; // defines inital value for the button
let btnX, btnY; // defines x and y locations for the button

function setup() {
    serial = new p5.SerialPort();       // make a new instance of the serialport library
    serial.on('list', printList);       // set a callback function for the serialport list event
    serial.on('connected', serverConnected); // callback for connecting to the server
    serial.on('open', portOpen);        // callback for the port opening
    serial.on('data', serialEvent);     // callback for when new data arrives
    serial.on('error', serialError);    // callback for errors
    serial.on('close', portClose);      // callback for the port closing
    serial.list();                      // list the serial ports
    serial.open(portName);              // open a serial port
    createCanvas(1200, 800);            // creates background size


    // credit to turtlefingers00@gmail.com sample p5 code. creates button shape
    btnX = width/2;
    btnY = height/2;
    radius = 50;
}

// get the list of ports:
function printList(portList) {
    // portList is an array of serial port names
    for (var i = 0; i < portList.length; i++) {
	// Display the list the console:
	print(i + " " + portList[i]);
    }
}

function serverConnected() {
    print('connected to server.');
}

function portOpen() {
    print('the serial port opened.')
}

function serialError(err) {
    print('Something went wrong with the serial port. ' + err);
}

function portClose() {
    print('The serial port closed.');
}

function serialEvent() {
  if (serial.available()) {
    var datastring = serial.readLine(); // readin some serial
    var newarray;
    try {
      newarray = JSON.parse(datastring); // can we parse the serial
      if (typeof newarray == 'object') {
        inData = newarray;
      }
      console.log("got back " + datastring);
      } catch(err) {
      // got something that's not a json
    }
  }
}


function draw() {
    background(127); // sets background color
    fill(255); // sets text color
    text("photoresistor: " + inData[0], 200, 30); // gets first set of data from array from arduino
    text("thermistor: " + inData[1], 200, 150); // gets second set of data from array from arduino


    // credit to turtlefingers00@gmail.com sample p5 code

    textAlign(CENTER,CENTER); // aligns and centers text
    textSize(40); // sets text size

    if(isOn){
      fill("white"); // if button is on, sets fill to white
      serial.write(255); // turns LED on
    }
    else{
      fill("black"); // if button is off, sets fill to black
      serial.write(0); // turns LED off
    }

    noStroke();
    ellipse(width/2,height/2,radius*2,radius*2);

    if(isOn){
      fill("black");
      text("ON",btnX,btnY); // if button is on, makes text say on
    }
    else{
      fill("white");
      text("OFF",btnX,btnY); // if button is OFF, makes text say on
    }
  }


function mouseClicked(){
  let mouseWithinButton = (dist(btnX,btnY,mouseX,mouseY)<radius)// defines variable as when mouse is clicked within radious of btnX and btnY
  if(mouseWithinButton){
    isOn = !isOn; // if clicked again, turn it off
  }
}
