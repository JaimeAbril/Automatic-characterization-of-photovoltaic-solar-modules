# Automatic-characterization-of-photovoltaic-solar-modules
Automatic characterization of photovoltaic solar modules with an Arduino Uno, digital pot MCP4251, current sensor CSLW6B40M and a solar cell.

PLEASE READ BEFORE DOING THE PROJECT

In this page you can found the code for the project. But you will also need an Arduino Uno, digital pot MCP4251, current sensor (you can
use CSLW6B40M or any other), a solar cell, one NTC, one LDR and finally you will need the program PLX-DAQ: https://forum.arduino.cc/index.php?topic=437398.msg3251256#msg3251256

Once you have all the items, you can start. 

First of all, you will need to do the connections between Arduino and solar cell, current sensor, LDR and NTC. There is an example of 
the connections in this page (fritzing diagram.fzz or image.png)

The second step it's trying to run the codes for NTC and LDR.
LDR---> code_brightness     In this code you won't need PLX-DAQ. You can see the results through serial monitor.
NTC---> code_NTC            In this code you will need PLX-DAQ. You can also use this code to get familiar with PLX-DAQ (remember to change 
the port of Arduino in PLX-DAQ if necessary).


NOTE THAT THE PIN FOR THE LECTURE OF THE DATA IT'S THE SAME IN THE TWO EXAMPLES CODES THAN IN THE MAIN ONE. IT'S NOT NECESSARY TO DO ANY CHANGE


With the tests of the two codes done, now you can try to run the main code. Check your wiring before starting. 
You will need PLX-DAQ on your computer and also the code. There are two steps when launching the code:
1.- Launch the code on the Arduino IDE.
2.- When the code is launched, connect the PLX-DAQ to Arduino. Wait a few seconds and you'll see the data in the PLX-DAQ.


