/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/4332e2a5-378f-42f1-89af-6913ed341b54

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float lightSensor;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

//Include the required libraries and header files.

#include "thingProperties.h"  //Contains automatically created IoT Cloud attributes.
#include <BH1750FVI.h>  // Include the BH1750FVI library for light sensor

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);  // Create an instance of the BH1750FVI light sensor

// Setup function, runs once when the device starts

void setup() {
  // Initialize serial and wait for port to open:

  Serial.begin(115200); // Initiate serial transmission at 115200 baud rate.
  LightSensor.begin();  // Initialize the LightSensor instance
  delay(1500);  // Wait 1.5 seconds for the sensor to initialise.

  // Defined in thingProperties.h
  initProperties();  // Initialize the properties defined in thingProperties.h

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();  // Display debugging information regarding the Arduino IoT Cloud connection.
}

// Loop function, runs repeatedly after setup

void loop() {
  ArduinoCloud.update();   // Update the Arduino IoT Cloud connection
  // Your code here

  uint16_t lux = LightSensor.GetLightIntensity(); // Retrieve the sensor's light intensity value
  lightSensor = lux;  // Update the IoT Cloud variable "lightSensor" with the light intensity value
  if (lightSensor >= 93) {  // Determine if the light intensity indicates the presence of sunlight.

  // Print message indicating sunlight is present
    Serial.println("Sunlight is present");
    Serial.print("Value:"); // Print the label "Value:" 
    Serial.println(lux);
    delay(250);   //delay for a short period

  } else {

     // Print message indicating no sunlight is present (it's dark)
    Serial.println("No sunlight is present.It is dark");
    Serial.print("Value:"); // Print the label "Value:" 
    Serial.println(lux);
    delay(250); //delay for a short period
  }
}



/*
  Since LightSensor is READ_WRITE variable, onLightSensorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightSensorChange() {
  // Add your code here to act upon LightSensor change
}