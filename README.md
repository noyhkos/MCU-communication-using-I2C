# I2C on MCU
[MCU 간의 I2C 통신] 

## 하드웨어 스펙
보드1: ST Nucleo-F103RB(Master)
보드2: ESP32(Slave)

## 개요
1. ST Board에서 gpio를 통해 버튼 입력
2. I2C 통신을 이용하여 ESP32 보드에 전송
3. 수신한 정보에 따라 LED ON/OFF

## 기타
ST 보드 개발: STM CubeIDE(main.c)
ESP32 보드 개발: Arduino

