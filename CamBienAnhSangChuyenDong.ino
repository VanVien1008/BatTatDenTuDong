int ledNTrai = 11;
int ledNGiua = 9;
int ledNPhai = 7;
int ledLTrai  = 12;
int ledLGiua = 10;
int ledLPhai = 8;
int pirSensorTrai = 4;
int pirSensorPhai = 5;


int trangThaiLed = 0;

long long int startTime[6];

int trangThaiSensorTrai;
int trangThaiSensorPhai;
int nguongAnhSang = 30;
int quangTro;  // biến lưu trữ thời điểm bắt đầu bật đèn
unsigned long timeDelay = 15000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  pinMode(ledNTrai, OUTPUT);
  pinMode(ledNGiua, OUTPUT);
  pinMode(ledNPhai, OUTPUT);
  pinMode(ledLGiua, OUTPUT);
  pinMode(ledLPhai, OUTPUT);
  pinMode(ledLTrai, OUTPUT);
  pinMode(pirSensorTrai, INPUT);
  pinMode(pirSensorPhai, INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  quangTro = analogRead(A0);
  trangThaiSensorPhai = digitalRead(pirSensorPhai);
  trangThaiSensorTrai = digitalRead(pirSensorTrai);
  //Serial.println(trangThai2);
  //Serial.println(trangThai1);
  //trangThai = digitalRead(PIRsensor);
  //Serial.println(trangThai);
  Serial.println(quangTro);


  if (150 < quangTro < 400) {
    trangThaiLed = 2;
  }
  if (quangTro < 150) {
    trangThaiLed = 1;
  }
  if (quangTro > 400) {
    trangThaiLed = 0;
  }

  if (trangThaiLed == 2) {
    if (trangThaiSensorPhai == 1) {
      digitalWrite(ledNPhai, HIGH);
      startTime[0] = millis();
    }

    if (trangThaiSensorTrai == 1) {
      digitalWrite(ledNTrai, HIGH);
      startTime[1] = millis();
    }

    if (trangThaiSensorPhai == 1 && trangThaiSensorTrai == 1) {
      digitalWrite(ledNGiua, HIGH);
      startTime[2] = millis();
    }
  }

  if (trangThaiLed == 1) {
    if (trangThaiSensorPhai == 1) {
      digitalWrite(ledLPhai, HIGH);
      startTime[3] = millis();
    }

    if (trangThaiSensorTrai == 1) {
      digitalWrite(ledLTrai, HIGH);
      startTime[4] = millis();
    }

    if (trangThaiSensorPhai == 1 && trangThaiSensorTrai == 1) {
      digitalWrite(ledLGiua, HIGH);
      startTime[5] = millis();
    }
  }


  for (int i = 0; i < 6; i++) {
    if (millis() - startTime[i] > timeDelay) {
      if (i == 0) {
        digitalWrite(ledNPhai, LOW);
      }
      if (i == 1) {
        digitalWrite(ledNTrai, LOW);
      }
      if (i == 2) {
        digitalWrite(ledNGiua, LOW);
      }

      if (i == 3) {
        digitalWrite(ledLPhai, LOW);
      }

      if (i == 4) {
        digitalWrite(ledLTrai, LOW);
      }

      if (i == 5) {
        digitalWrite(ledLGiua, LOW);
      }
    }
  }
}
