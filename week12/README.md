# 설치 명령어 모음

## InfluxDB 설치
sudo apt-get update && sudo apt-get install influxdb -y
sudo service influxdb start

## Grafana 설치
sudo apt-get install -y apt-transport-https software-properties-common wget
sudo apt-get update && sudo apt-get install grafana -y
sudo systemctl start grafana-server

## Python 라이브러리
pip install influxdb

## InfluxDB 데이터베이스 생성
$ influx
> create database dust
> show databases
> exit
