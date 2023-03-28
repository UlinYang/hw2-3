#include "mbed.h"
#include <PwmOut.h>
using namespace std::chrono;

PwmOut PWM1(D6);
AnalogIn ain(A0); 
AnalogOut aout(D7);
Thread thread;
float ADCdata[3000];
void generate_thread()
{
  int i = 0;
  while(1)
  {
    float width;
    PWM1.period_ms(5);
    width = 2.5 * (cos(2*3.1416/20 * i + 3.1416)) + 2.5;
    PWM1.pulsewidth_ms(width);
    //printf("%f\n\r", PWM1.read());
    ThisThread::sleep_for(40ms);
    i++;
  }
}

int main()
{
    thread.start(generate_thread);
    
    for(int i = 0; i < 3000; i++){
        ADCdata[i] = (ain * 3.3f);
        aout = ain;
        ThisThread::sleep_for(1ms);
    }
    for (int y = 0; y < 3000; y++)
    {
        printf("%f\r\n", ADCdata[y]);
        ThisThread::sleep_for(1ms);
    }
  
}