from machine import Pin
import utime

IN1 = Pin(16, Pin.OUT)
IN2 = Pin(19, Pin.OUT)

while True:
    # 正転
    IN1.value(1)
    IN2.value(0)
    utime.sleep(2)
    
    # ブレーキ
    IN1.value(1)
    IN2.value(1)
    utime.sleep(2)
    
    # 逆転
    IN1.value(0)
    IN2.value(1)
    utime.sleep(2)
    
    # 停止
    IN1.value(0)
    IN2.value(0)
    utime.sleep(2)