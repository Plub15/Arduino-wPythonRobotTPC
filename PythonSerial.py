import pygame
import time
import serial

# Initialize Pygame
pygame.init()

# Set up the joystick
pygame.joystick.init()
if pygame.joystick.get_count() > 0:
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
else:
    print("No joystick found.")
    exit()

try:
    arduino = serial.Serial('COM3', 115200, timeout=1)  # Replace 'COM3' with the correct port for your Arduino
    time.sleep(2)  # Wait for the serial connection to initialize
except serial.SerialException as e:
    print(f"Error opening serial port: {e}")
    exit()

def read_joystick():
    pygame.event.pump()
    axis_data = [round(joystick.get_axis(i),3) for i in range(joystick.get_numaxes())]
    button_data = [joystick.get_button(i) for i in range(joystick.get_numbuttons())]
    return axis_data,button_data

try:
    while True:
        # Read joystick data
        axes,button = read_joystick()
        axes = list(map(lambda x:str(round(x*255,2)),axes[:4]))
        button = list(map(str,button[:4]))
        data_string = ','.join(axes+button)
        print(data_string)
        arduino.write(data_string.encode())
        time.sleep(0.05)  # Adjust the sleep time as needed
        arduino.readline() #ลบออกแล้วโค้ดใช้ไม่ได้wtf
except KeyboardInterrupt:
    print("Program interrupted by user.")
finally:
    pygame.quit()
