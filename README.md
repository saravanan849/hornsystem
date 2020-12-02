# hornsystem
There are two modes horn mode and calibration mode
when engine(PD1) is on, it enters into hornmode, when horn(PD7) is pressed, a pwm signal of 30% is generated and When the temperature of sensor(potentiometer) is 
  1. >500 and <1000, dutycycle is reduced to 10% 
  2. >1000, dutycyle is 0%
  3. <=500, dutycule is current value.
  
  when horn is released, pwm signal is off.  
When engine(PD1) is off, it enters into calibration mode, here when GPIO+(PD3) is pressed the dutycycle is increased by 5%, when GPIO-(PD2) is pressed the dutycyle is decreased by 
5%. 
