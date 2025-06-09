import tos
import sys
from influxdb import InfluxDBClient as influxdb
import serial

# 시리얼 연결
seri = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = None)

# 데이터 파싱 및 변환
while True:
    if seri.in_waiting !=0:
        content = seri.readline()
        a = float(content.decode())
        
        # InfluxDB 데이터 형식
        data = [{
            'measurement': 'dust',
            'tags': {'InhaUni': '2222'},
            'fields': {'dust': a}
        }]
        
        # InfluxDB 연결 및 저장
        client = influxdb('localhost', 8086, 'root', 'root', 'dust')
        client.write_points(data)
