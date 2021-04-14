
// By Maci Harrell
// Special thanks to: 
// Miuzei tutorial libraries for help with the beeper program
// RobotDyn tutorial libraries for help with the dimmer program
// Konstantin Dimitrov on the Arduino project hub for help with temp probe program
// And my dad for helping me wire everything up :)

/********************************************************************/
// Imports Libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <RBDdimmer.h>//
/********************************************************************/
// This section controls what pins the modules are plugged into. They are currently set to 8 for the temp probe and 11 for the dimmer. Do not change the buzzer's pin.
#define ONE_WIRE_BUS 8 // This is the pin the temp probe is plugged into
#define USE_SERIAL  Serial
#define outputPin  11 // This is the pin the dimmer is plugged into
#define zerocross  5 
int buzzerPin = 5; // This is the pin the buzzer is plugged into. Do not change unless you know what you're doing.
/********************************************************************/
// Initialises temperature probe
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 
// Initialises dimmer
dimmerLamp dimmer(outputPin);
/********************************************************************/ 
// Initialises variables
int brightness = 30; 
// The above light brightness is controlled on a scale of 0-100, with 0 being off and 100 being full power
// This variable controls what brightness the light should start at before it begins to adjust to fit the temperature
// I would recommend figuring out what brightness would start it at about room temperature and setting the variable to that, so it can slowly warm up and not shock your animal
float current_temp = 0;
float previous_temp = 0;
float temp_difference = 0;
bool needs_increase = false;
bool needs_decrease = false;
int count = 0;
int o_brightness = 0;
int current_mils = 0;
int previous_temp_mils = 0;


void setup(void) 
{ 
 // Set up for the temperature probe:
 Serial.begin(9600); 
 sensors.begin();
 // Set up for the dimmer:
  USE_SERIAL.begin(9600);
  dimmer.begin(NORMAL_MODE, ON); 
  pinMode (buzzerPin, OUTPUT);
} 


void loop(void) 
{
  // This counts the number of milliseconds that have passed and calls the tempandlights function and buzzer function
  current_mils = millis(); 
  tempandlights();
  buzzer();
}

void tempandlights(void) {
  if (current_mils - previous_temp_mils >= 60000) { // causes another reading and adjustment to occur in 60 seconds; to change, replace the "60000" with number of MILLIseconds you'd like to delay
     o_brightness = brightness;
     sensors.requestTemperatures(); // Send the command to get temperature readings 
/********************************************************************/
     bool needs_increase = false; // Resets the switch that tells the dimmer if it should increase or decrease
     bool needs_decrease = false;
/********************************************************************/
     Serial.print("\nTemperature is: "); // Finds and prints the current temperature to the serial monitor
     current_temp = sensors.getTempFByIndex(0);
     Serial.print(current_temp);
/********************************************************************/
     Serial.print(" Temperature difference: "); // Finds and prints the difference between the current temperature and the last temperature reading
     temp_difference = current_temp - previous_temp;
     Serial.print(temp_difference);
/********************************************************************/
// This block determines if the temperature is within the range needed for your animal and if it needs to increase or decrease, prints it to the serial monitor
     if ((current_temp < 80) and (temp_difference <= 0.1)) { // Replace the "80" in this line with the lower bound for your animal's temperature range
        needs_increase = true;
        Serial.print(" Needs increase"); // prints if temp needs to increase
     }
 
     if ((current_temp > 82) and (temp_difference >= -0.1)) { // Replace the "82" in this line with the upper bound of your animal's temperature range
        needs_decrease = true;
        Serial.print(" Needs decrease"); // prints if temp needs to decrease
     }
 /********************************************************************/
     previous_temp = current_temp; // sets the previous temperature reading to the most recent temperature reading
     // This block increases or decreases the temperature based on the previous block of code
     if (needs_increase) {
       brightness = brightness + 1;
       Serial.print(" Brightness increasing "); // prints if brightness increases
     }
    if (needs_decrease) {
     brightness = brightness - 1;
     Serial.print(" Brightness decreasing "); // prints if brightness decreases
    }
    // If you would like your light to go up or down by more than 1% brightness at a time, change the 1 in "brightness +/- 1" to whatever you would like
    // I would recommend using a very low number, though, or else it might boomerang between hot and cold without regulating easily
    Serial.print(brightness); // prints the current brightness setting
    Serial.print(count);
    count = count + 1;
    previous_temp_mils = current_mils;
    }
 dimmer.setPower(brightness);
}


void buzzer() {
 // This block causes the buzzer to go off if the temperature goes above or below a certain threshold
  if ((current_temp > 80) or (current_temp < 83)) { // Change the "83" to your upper threshold and the "80" to your lower threshold
    digitalWrite (buzzerPin, HIGH);
    delay (500);
    digitalWrite (buzzerPin, LOW);
    delay (500);
    Serial.print(" Danger!");
  }
}
