# hornsystem

when engine(PD1) is on, it enters into hornmode, when horn(PD7) is pressed, a pwm signal of 30% is generated and When the temperature of sensor(potentiometer) is 
  1. >500 and <1000, dutycycle is reduced to 10% 
  2. >1000, dutycyle is 0%
  3. <=500, dutycule is current value.
  
  when horn is released, pwm signal is off.  
When engine(PD1) is off, LED glows(PD4).
