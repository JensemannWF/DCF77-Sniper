#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

// DCF77 Pin via define
#ifndef DCF77_PIN
#define DCF77_PIN 15
#endif

#define HOSTNAME "DCF-Sniper"
#define WLAN_SSID "WIFI-Repeater"
#define WLAN_PASS "Leberwurst2019"

unsigned long letzteSekunde = 0;
unsigned long driftMillis = 1000;  // Startwert, wird später gelernt
bool letzteSekundeValid = false;

void setupWiFi() {
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("\nWLAN verbunden: " + WiFi.localIP().toString());
  WiFi.setSleep(false);
}

void syncWithNTP() {
  configTime(0, 0, "pool.ntp.org");
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    Serial.printf("NTP-Zeit: %02d:%02d:%02d\n", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  } else {
    Serial.println("NTP fehlgeschlagen");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(DCF77_PIN, INPUT);

  setupWiFi();
  syncWithNTP();

  Serial.println("DCF-Sniper bereit");
}

void loop() {
  static unsigned long letzterTick = 0;
  unsigned long jetzt = millis();

  if (jetzt - letzterTick >= driftMillis) {
    letzterTick = jetzt;
    Serial.println("Sekundentick");
    // später: Anzeige, GPIO, Sync, Driftanpassung etc.
  }

  // später: DCF77-Minimalfenster prüfen (z. B. Sekunde 59 detektieren)
  delay(10);
}