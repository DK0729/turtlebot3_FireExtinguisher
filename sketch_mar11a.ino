#include <Servo.h>
#include <math.h>

Servo servo;

bool isTrue = false;
bool finish = false;
float target_y = 0.0; 

// --- 상하 스윕(진동)을 위한 설정값 ---
const float SWEEP_AMPLITUDE = 15.0; 
const float PERIOD_MS = 1000.0;     

unsigned long high_start_time = 0;  
bool fireDetected = false; 

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  servo.attach(3);

  Serial.begin(115200);
  Serial.setTimeout(10); 

  digitalWrite(2, LOW);
}

void loop() {
  getCommand();
  FireExtinguish();
}

void FireExtinguish() {
  if (isTrue == true && finish == false) {
    
    // 1. 현재 센서 상태 읽기
    bool current_fire_signal = (digitalRead(4) == LOW);

    if (current_fire_signal) {
      // 불꽃이 감지되면 상태 기록 및 타이머 리셋
      fireDetected = true; 
      high_start_time = 0; 
    } 
    else {
      // 불꽃 신호가 끊겼을 때(HIGH)
      if (!fireDetected) {
        // 애초에 불꽃을 본 적이 없다면 (명령 직후 바로 HIGH인 경우) 즉시 종료
        finish = true; 
        return; // 아래의 진압 동작을 실행하지 않고 탈출
      } 
      else {
        // 불을 끄다가 신호가 잠시 끊긴 경우 -> 잔불 확인 타이머 시작
        if (high_start_time == 0) {
          high_start_time = millis();
        }

        // 불꽃이 꺼진 지 '연속 1초'가 지나면 완전히 종료하고 정지
        if (millis() - high_start_time >= 1000) {
          servo.write(90);       // 대기 위치로
          digitalWrite(2, LOW);  // 워터펌프 OFF
          finish = true;
          high_start_time = 0; 
          return; // 진압 종료되었으므로 탈출
        }
      }
    }

    // 2. [진압 동작 유지] 불꽃이 감지 중이거나, 신호가 끊겼어도 1초가 지나지 않았다면 수행
    float center_angle = 87.0;
    float time_sec = millis() / PERIOD_MS;
    int current_angle = center_angle + (SWEEP_AMPLITUDE * sin(2 * PI * time_sec));
    
    servo.write(center_angle);
    digitalWrite(2, HIGH); // 유예 시간 동안 펌프 ON 상태 유지!
  }
}

void getCommand() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); 
    input.trim(); 
    
    if (input.length() > 0) {
      target_y = input.toFloat();
      isTrue = true;
      finish = false;
      fireDetected = false; 
      high_start_time = 0;
    }
  }
  
  if (finish == true) {
    Serial.println("off"); 
    isTrue = false;
    finish = false;
  }
}
