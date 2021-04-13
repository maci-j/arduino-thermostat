# Arduino Dimmer Thermostat
An Arduino-controlled light dimmer thermostat intended for animal use.
# Introduction
This project is intended to help you create an affordable dimmer thermostat for usage on animal enclosures (though I imagine it would work fine for other uses as well). This iteration of the design is fairly simple; it controls only one heat source based on temperature parameters set in the code. However, it would be easy to modify this design to accommodate additional heat sources, temperature warning alarms, clocks, or humidity probes. 

PLEASE NOTE THAT THIS PROJECT DOES INVOLVE SOME ELECTRICAL WIRING. DO NOT DO THIS IF YOU DO NOT KNOW WHAT YOU ARE DOING. I am not responsible for any damages if something goes wrong.
# Materials Needed
- An Arduino Uno or Arduino Uno Clone ~$15 (I am using Miuzei brand)
- RobotDyne AC Light Dimmer Module ~$3 [(link here)](https://robotdyn.com/ac-light-dimmer-module-1-channel-3-3v-5v-logic-ac-50-60hz-220v-110v.html)
- Breadboard ~$5
- Breadboard Jumper Wires ~$5
- Plastic Electrical Junction Box ~$7
- Basic Extention Cord ~$5
- DS18B20 Temperature Sensor with 4.7KΩ Resistors ~$10

Approximate Total Cost: $50 (this is based off of prices I looked up and what I paid for things; might vary based on what materials you already have and which brands you buy)

I did not include the cost for basic tools needed (screwdriver, drill, wire cutters) as you should probably already have them. If you don't, then go buy a toolbox! They're super useful in general, not just for this project.

Also, make sure the bulb you're using is actually dimmable. 
# The Extension Cord and Dimmer
The dimmer we are using is an AC PWM dimmer. These dimmers basically work by chopping up the electrical signal in order to regulate the amount of power being delivered to the electronic. They're pretty easy to wire up, but please note that this is still working with 120V wires that can really mess you up. You should ALWAYS make sure everything is 100% unplugged before following any of the below steps. If you do everything correctly, you should never actually end up anywhere near a live wire. But once again, if something does go wrong, I take no responsibility. 
# Setting Up Your Breadboard
For this part of the tutorial, we will focus on connecting your Arduino to your breadboard. 

![](images/Breadboard_Anno.jpeg)

This image shows the basics of how a breadboard works. Small strips of metal run along the inside of the breadboard, connecting the holes in the manner above. Of particular note are the long red and blue rails running along the breadboard. The red rail is the live rail and will have the 5V from the Arduino running in it. The blue rail is the ground rail. If you would like to know more, I'd check out [this](https://magpi.raspberrypi.org/articles/breadboard-tutorial) link (also my image source).

For the purposes of this tutorial, I will refer to the long rails as vertical red or blue rails, and the short rails in the middle as horizonal rails.

![](images/arduino.PNG)

This image shows a basic diagram of an Arduino Uno (image credits [here](http://arduinotogo.com/2016/09/09/chapter-3-arduino-schematic/)). For this project, we will only be concerned with the digital pins and the power and ground pins. 

### Connecting your Arduino to your breadboard:
1. Get four small male-male jumper wires. I would recommend two black ones and two red ones, but whatever works for you. Just try to keep it consistent.
2. Plug one side of one red wire into the 5V pin on the power and ground pin side of the Arduino. 
3. Plug the other side of the red wire into the red (live) rail on the breadboard.
4. Plug one side of the other red wire into the red rail.
5. Plug the other side of the red wire into one of the horizontal rails (NOT the red or blue rails - the rails in the middle).
4. Plug one side of one black wire into one of the GND pins on the power and ground pin side of the Arduino.
5. Plug the other side of the black wire into the blue (ground) rail on the breadboard.
6. Plug one side of the other black wire into the blue rail.
7. Plug the other side of the black wire into one of the horizontal rails near where the red wire was plugged in, but not the same rail.

If that explanation was confusing, here are images of my board (I only had one red wire, so one a dark blue wire was used in place of the other red):

![](images/breadboard_r.jpg) ![](images/breadboard2_r.jpg)

If you would like to and if your breadboard is big enough, you can screw your Arduino into the breadboard using the Arduino screw holes for compactness' sake. HOWEVER, if you do so, make sure your go to the underside of your breadboard and strip any metal that may be touching the screws. I have all the metal in my breadboard above the black sharpie line stripped. This is to make sure that no power will conduct through the metal rails and into the Arduino's screws.

# Setting Up the Temperature Probe
Your temperature probe should have three wires coming out of the non-probe end: a black one, red one, and yellow or white one. The black wire is your ground wire, the red wire is your power wire, and your yellow/white wire is the data wire. In addition to these, you should have a small resistor. Hooking these up to your breadboard is a fairly simple and straightforward task.

### Connecting your temperature probe to your breadboard:
1. Plug the metal end of the red wire into the same horizontal rail you previously plugged the red (or dark blue in my case) wire from the red rail into. Leave at least one square open on the breadboard between the plugged in red wires.
2. Plug the metal end of the black wire into the same horizontal rail you previously plugged the black wire from the blue rail into. 
3. Plug the yellow/white wire into a horizontal rail that is not being used by any other wires.
4. Plug one end of the resistor into the square left open between the wires on the red horizontal rail. Plug the other end of the resistor into a square on the same rail as the yellow wire.
5. Grab a small male-male yellow wire, and plug one end on the other side of the resistor beside the yellow wire. Plug the other end into the 8 pin on the digital pins side of the Arduino.

Your breadboard should look something like this:

![](images/temp1.jpg) ![](images/temp2.jpg)
