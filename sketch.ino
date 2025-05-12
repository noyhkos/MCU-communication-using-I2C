#include <Wire.h>
#define LED_PIN 2
#define SLAVE_ADDR 0x08  // I2C 슬레이브 주소 (0x08로 설정)

// 마스터가 요청할 때 호출되는 함수 (여기서는 필요 없지만 정의는 해야 함)
void requestEvent() {
  // 마스터가 데이터를 요청할 때 응답하는 코드 작성 가능

}
// 마스터가 슬레이브에게 데이터를 보낼 때 호출되는 함수
void receiveEvent(int bytes) {
  while ( Wire.available() ) {
    char received = Wire.read();  // 마스터로부터 받은 데이터 읽기
    if (received == '1') {
      digitalWrite(LED_PIN, HIGH);  // LED 켜기
    } else if (received == '0') {
      digitalWrite(LED_PIN, LOW);   // LED 끄기
    }
  }
}

void setup() {
  // I2C 슬레이브 초기화
  Wire.begin(SLAVE_ADDR);

  // 슬레이브 데이터 수신 시 처리할 함수 등록
  //Wire.onRequest(requestEvent);  // 마스터가 요청할 때 호출
  Wire.onReceive(receiveEvent);  // 마스터가 데이터를 보낼 때 호출

  pinMode(LED_PIN, OUTPUT);

  for(int i=0; i<5; i++){
    digitalWrite(LED_PIN, HIGH);  // LED 켜기
    delay(500);
    digitalWrite(LED_PIN, LOW);   // LED 끄기
    delay(500);
  }
}

void loop() {

  delay(100);
}