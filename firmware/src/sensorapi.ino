#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP3XX.h>

#define SEA_LEVEL_HPA 1013.25
#define SD_CS_PIN 5

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);
Adafruit_BMP3XX bmp;

File logFile;
String logFileName;

String getNextLogFileName() {
  for (int i = 1; i <= 999; i++) {
    String name = "/LOG_";
    if (i < 10) name += "00";
    else if (i < 100) name += "0";
    name += String(i) + ".csv";
    if (!SD.exists(name)) return name;
  }
  return "/LOG_999.csv";
}

void setup() {
  Serial.begin(115200);

  if (!bno.begin()) {
    Serial.println("BNO055 not detected");
    while (1);
  }

  if (!bmp.begin_I2C(0x76)) {
    Serial.println("BMP388 not detected");
    while (1);
  }

  bno.setExtCrystalUse(true);

  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card init failed");
    while (1);
  }

  logFileName = getNextLogFileName();
  logFile = SD.open(logFileName, FILE_WRITE);
  if (!logFile) {
    Serial.println("Failed to open log file");
    while (1);
  }

  logFile.println("time_ms,yaw_deg,pitch_deg,roll_deg,cal_sys,cal_gyro,cal_accel,cal_mag,temp_c,pressure_hpa,altitude_m");
  logFile.flush();

  Serial.println();
  Serial.println("========================================");
  Serial.println("Rocket Flight Computer - Avionics v1");
  Serial.println("Sensors initialized successfully.");
  Serial.print("Logging to: ");
  Serial.println(logFileName);
  Serial.println("========================================");
}

void loop() {
  sensors_event_t event;
  bno.getEvent(&event);

  uint8_t system, gyro, accel, mag;
  bno.getCalibration(&system, &gyro, &accel, &mag);

  if (!bmp.performReading()) {
    Serial.println("BMP388 reading failed");
    delay(500);
    return;
  }

  unsigned long t = millis();
  float yaw      = event.orientation.x;
  float pitch    = event.orientation.y;
  float roll     = event.orientation.z;
  float temp     = bmp.temperature;
  float pressure = bmp.pressure / 100.0;
  float altitude = bmp.readAltitude(SEA_LEVEL_HPA);

  // Serial output
  Serial.println("----------------------------------------");
  Serial.print("Time: ");   Serial.print(t);        Serial.println(" ms");
  Serial.println();
  Serial.println("Orientation");
  Serial.print("Yaw:   ");  Serial.print(yaw, 2);   Serial.println(" deg");
  Serial.print("Pitch: ");  Serial.print(pitch, 2); Serial.println(" deg");
  Serial.print("Roll:  ");  Serial.print(roll, 2);  Serial.println(" deg");
  Serial.println();
  Serial.println("Calibration");
  Serial.print("SYS="); Serial.print(system);
  Serial.print("  G="); Serial.print(gyro);
  Serial.print("  A="); Serial.print(accel);
  Serial.print("  M="); Serial.println(mag);
  Serial.println();
  Serial.println("Environmental");
  Serial.print("Temperature: "); Serial.print(temp, 2);     Serial.println(" C");
  Serial.print("Pressure:    "); Serial.print(pressure, 2); Serial.println(" hPa");
  Serial.print("Altitude:    "); Serial.print(altitude, 2); Serial.println(" m");
  Serial.println();

  // SD logging
  if (logFile) {
    logFile.print(t);           logFile.print(",");
    logFile.print(yaw, 2);      logFile.print(",");
    logFile.print(pitch, 2);    logFile.print(",");
    logFile.print(roll, 2);     logFile.print(",");
    logFile.print(system);      logFile.print(",");
    logFile.print(gyro);        logFile.print(",");
    logFile.print(accel);       logFile.print(",");
    logFile.print(mag);         logFile.print(",");
    logFile.print(temp, 2);     logFile.print(",");
    logFile.print(pressure, 2); logFile.print(",");
    logFile.println(altitude, 2);
    logFile.flush();
  }

  delay(100);
}