#ifndef CONFIG_H
#define CONFIG_H

// ===== WiFi Configuration =====
#define WIFI_SSID "YOUR_SSID"
#define WIFI_PASSWORD "YOUR_PASSWORD"

// ===== Weather API Configuration =====
#define WEATHER_API_KEY "YOUR_OPENWEATHERMAP_API_KEY"
#define WEATHER_CITY "Warsaw"
#define WEATHER_COUNTRY_CODE "PL"
#define WEATHER_API_URL "https://api.openweathermap.org/data/2.5/weather"
#define WEATHER_UPDATE_INTERVAL 600000 // 10 minutes in ms

// ===== Radio Stations =====
#define MAX_STATIONS 10

struct RadioStation {
  const char* name;
  const char* url;
};

const RadioStation RADIO_STATIONS[MAX_STATIONS] = {
  {"RMF FM", "http://217.74.76.208:8000/rmf_fm"},
  {"Radio Zet", "http://217.74.76.208:8000/radiozet"},
  {"TOK FM", "http://217.74.76.208:8000/tokfm"},
  {"Eska", "http://217.74.76.208:8000/eska"},
  {"Polskie Radio 1", "http://stream.polskieradio.pl/pr1"},
  {"Polskie Radio 2", "http://stream.polskieradio.pl/pr2"},
  {"Polskie Radio 3", "http://stream.polskieradio.pl/pr3"},
  {"BBC Radio", "http://bbcmedia.ic.llnwd.net/stream/bbcmedia_radio1_mux_p.aac"},
  {"", ""},
  {"", ""}
};

// ===== Display Configuration =====
#define TFT_WIDTH 480
#define TFT_HEIGHT 800
#define TFT_ROTATION 1

// ===== GPIO Configuration =====
#define I2S_DOUT 42  // ESP32-S3 speaker GPIO
#define I2S_BCLK 41  // I2S bit clock
#define I2S_LRC 40   // I2S left/right clock

// ===== Audio Configuration =====
#define I2S_SAMPLE_RATE 44100
#define I2S_BITS_PER_SAMPLE 16
#define I2S_DMA_BUF_COUNT 8

// ===== NTP Configuration =====
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600    // UTC+1 for Poland
#define DAYLIGHT_OFFSET_SEC 3600 // +1 hour during DST

// ===== UI Configuration =====
#define UI_UPDATE_INTERVAL 1000 // 1 second
#define SCREEN_TIMEOUT 300000   // 5 minutes

// ===== Debug =====
#define DEBUG_MODE 1
#define DEBUG_BAUD 115200

#endif // CONFIG_H
