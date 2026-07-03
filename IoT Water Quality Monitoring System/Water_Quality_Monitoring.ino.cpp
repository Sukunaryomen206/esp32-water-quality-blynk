/**
 * @file Water_Quality_Monitoring.ino
 * @brief IoT Water Quality Monitoring System using ESP32, TDS, and EC Sensors.
 * @details Measures Total Dissolved Solids (TDS) and Electrical Conductivity (EC)
 * via analog inputs and streams live telemetry to the Blynk IoT Dashboard.
 */

#define BLYNK_TEMPLATE_ID "TMPL3EUAAS5GE"
#define BLYNK_TEMPLATE_NAME "WATER QUALITY MONITERING"
#define BLYNK_AUTH_TOKEN "_J6a5muvPh9dQoWBA4m1TMXoAc8S0w60"

#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// --- Network Configuration ---
// Default network profile for Wokwi simulation:
char ssid[] = "Wokwi-GUEST";         
char pass[] = "";                    

// For physical hardware deployment, switch comments with your credentials:
// char ssid[] = "Aesha's OnePlus";
// char pass[] = "20061106";

// --- Pin Allocations ---
#define TDS_PIN 34                   // GPIO 34 (ADC1_CH6) -> TDS Sensor Analog Out
#define EC_PIN 35                    // GPIO 35 (ADC1_CH7) -> EC Sensor Analog Out

// --- Constants ---
const float ADC_REF = 3.3;           // ESP32 reference voltage
const float ADC_MAX = 4095.0;        // 12-bit ADC maximum resolution steps

BlynkTimer timer;

void sendSensorData()
{
  // Read raw 12-bit values from the ADC converter lanes
  int tdsRaw = analogRead(TDS_PIN);
  int ecRaw = analogRead(EC_PIN);

  // Convert raw readings into true DC voltage levels (0.0V - 3.3V)
  float tdsVoltage = (tdsRaw * ADC_REF) / ADC_MAX;
  float ecVoltage = (ecRaw * ADC_REF) / ADC_MAX;

  // Linear Conversion scaling factors (Adjust variables post physical calibration)
  float tds = tdsVoltage * 500.0; 
  float ec = ecVoltage * 500.0; 

  // Debugging Telemetry printout for local Serial Monitor tracking
  Serial.print("TDS Raw: ");      Serial.print(tdsRaw);
  Serial.print(" | Voltage: ");   Serial.print(tdsVoltage, 2);
  Serial.print("V | TDS: ");      Serial.print(tds, 1); Serial.print(" ppm");

  Serial.print("  ||  EC Raw: "); Serial.print(ecRaw);
  Serial.print(" | Voltage: ");   Serial.print(ecVoltage, 2);
  Serial.print("V | EC: ");       Serial.print(ec, 1); Serial.println(" uS/cm");

  // Stream metrics data packets to designated Blynk Virtual Pins
  Blynk.virtualWrite(V0, tds); 
  Blynk.virtualWrite(V1, ec);  
}

void setup()
{
  Serial.begin(115200);

  // Enforce ESP32 analog pins to execute at 12-Bit resolution
  analogReadResolution(12);
  
  // Connect to the local Wi-Fi gateway and authenticate with Blynk IoT Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Schedule the sensor polling loop interrupt to execute every 2000ms
  timer.setInterval(2000L, sendSensorData);
}

void loop()
{
  Blynk.run();
  timer.run();
}