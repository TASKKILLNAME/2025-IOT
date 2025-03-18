import serial
from influxdb_client import InfluxDBClient
import time

serial_port = 'COM15'
baud_rate = 9600
timeout = 2

influxdb_url = "http://localhost:8086"

influxdb_token = "UFhRmvNym_usJpQiptY_MkzR58frnPSD-BMjTlMW0ALgxnaeFKOC7Hn_-xK2Ie6bhm8QvcjId8yk7fXyNDpC9g=="
influxdb_org = "test"
influxdb_bucket = "dust"

client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)
write_api = client.write_api()

try:
    ser = serial.Serial(serial_port,baud_rate,timeout=timeout)
    print(f"Connected to {serial_port} at {baud_rate} baud")
except serial.SerialException:
    print("Failed to connect to serial port.")
    exit()

try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('UTF-8').strip()
            print(f"Received: {line}")

            if "=" in line:
                key, value = line.split("=")
                try:
                    value = float(value)
                    data = f"sensor_data,device=arduino {key}={value}"
                    write_api.write(bucket=influxdb_bucket,record=data)
                    print(f"Data written to InfluxDB: {key}={value}")

                except ValueError:
                    print("Invalid data format")

            time.sleep(1)

except KeyboardInterrupt:
    print("Stopping data collection..")
finally:
    ser.close()

