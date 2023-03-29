# hw2-3

specification: PwmOut (D6); AnalogIn (A0); AnalogOut (D7);

How to setup: connect D6 and GND to the led light to form breathing light. Connect the AO of light sensor to A0 to recieve the light sensor signal, then connect D7 to picoscope to display the signal we recieve from light sensor on the picoscope. Then close your mbed program and open terminal to execute the python code.

How to execute and Result: you should see multiple nonideal sine wave on the picoscope, when you press reset button. When press the reset button after you execute the python code, you should keep the light sensor near the breathing light for at leat 3 second to get full 3000 data sample. Then wait for about 10 second for python code to recieve the 3000 data from your COM.
