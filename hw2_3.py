import matplotlib.pyplot as plt
import numpy as np
import serial
import time

Fs = 3000.0;  # sampling rate
Ts = 3.0/Fs; # sampling interval
t = np.arange(0,3,Ts) # time vector; create Fs samples between 0 and 1.0 sec.
y = np.arange(0,3,Ts) # signal vector; create Fs samples

serdev = 'COM3'
s = serial.Serial(serdev)

for x in range(0, int(Fs), 1):
    line=s.readline() # Read an echo string from B_L4S5I_IOT01A terminated with '\n'
    # print line
    y[x] = float(line)
plt.plot(t, y)
plt.xlabel('time')
plt.ylabel('light sensor')
plt.show()
s.close()