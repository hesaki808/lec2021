from machine import Pin
import utime

trig = Pin(10, Pin.OUT)
echo = Pin(11, Pin.IN)

def read_distance():
    trig.low()
    utime.sleep_us(2)
    trig.high()
    utime.sleep(0.00001)
    trig.low()
    while echo.value() == 0:
        signaloff = utime.ticks_us()
    while echo.value() == 1:
        signalon = utime.ticks_us()
    timepassed = signalon - signaloff
    distance = (timepassed * 0.0343) / 2
    return distance

while True:
    dist = read_distance()
    print(round(dist, 2))
    utime.sleep(1)
    
    
