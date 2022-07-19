import requests
import serial
 
ADD_URL = "http://localhost:9000/steps/add"

Arduino = serial.Serial("COM16", 9600)


while True:
    if (Arduino.inWaiting() > 0):
        data = Arduino.read()
        data = data.decode()
        print(data)
        if data == "1":
            requests.get(url=ADD_URL)
    

