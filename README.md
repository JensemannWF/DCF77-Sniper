# 🛰️ DCF77-Sniper

Ein modernes, intelligentes DCF77-Auswertesystem auf Basis eines ESP32 (Classic oder S3). Ziel ist es, eine hocheffiziente, stromsparende und selbstoptimierende Funkuhr zu bauen, die sich durch hybride Methoden (DCF77 + NTP + Driftkorrektur) selbst eicht, anpasst und über längere Zeiträume präzise autark weiterläuft.

---

## ⚙️ Hardwarevoraussetzungen

- ESP32 DevKit V1 oder ESP32-S3
- DCF77-Empfangsmodul (z. B. Pollin, Conrad, ELV)
- OLED-Display (SSD1306, 128x64)
- Temperatur-NTC (10k) + Spannungsteiler
- Poti als Simulationseingabe
- LDR für Helligkeitsmessung
- Relaismodul zur Lüftersteuerung (optional)
- Taster zur Interaktion (z. B. Watchdog-Test)
- WLAN-Zugang für OTA/NTP

---

## 📡 Funktionen

- Dekodierung und Analyse des DCF77-Zeitsignals
- Erkennung und Validierung der "Nullsekunde"
- Millis-basierter Drift-Abgleich durch DCF oder NTP
- Autokalibrierung des Takts durch Temperaturmessung
- OTA-Update via ArduinoOTA
- Webserver mit `/debug`-Ausgabe für Logdaten
- Tacho-/PWM-/Sensorsteuerung für Hybrid-Anwendungen
- Modulare Struktur mit elegantem `loop()` und wartungsfreundlichem Setup

---

## �� Betriebsmodi

- **DCF-only**: rein empfangsbasiert
- **Hybridbetrieb**: Initiale Zeitabfrage über NTP, spätere Synchronisierung über DCF77-Nullbits
- **Offshore-Modus**: Millis-basiertes Uhrwerk, das sich nur gelegentlich durch Funk nachstellt

---

## 🚀 Installation & Kompilierung

```bash
# Voraussetzung: PlatformIO installiert
git clone https://github.com/JensemannWF/DCF77-Sniper.git
cd DCF77-Sniper
platformio run -t upload
