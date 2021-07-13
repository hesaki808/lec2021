from machine import PWM, Pin
import utime

IN1 = PWM(Pin(16))
IN2 = PWM(Pin(19))
IN1.freq(100)
IN2.freq(100)

max_duty = 65025

while True:
    # 正転
    IN2.duty_u16(0)
    for i in range(50, 100):
        IN1.duty_u16(int(max_duty*i*0.01))
        utime.sleep(0.1)
        
    # ブレーキ
    IN1.duty_u16(max_duty)
    IN2.duty_u16(max_duty)
    utime.sleep(2)
    
    # 逆転
    IN1.duty_u16(0)
    for i in range(50, 100):
        IN2.duty_u16(int(max_duty*i*0.01))
        utime.sleep(0.1)
        
    # 停止
    IN1.duty_u16(0)
    IN2.duty_u16(0)
    utime.sleep(2)