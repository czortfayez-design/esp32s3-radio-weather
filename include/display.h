#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "config.h"

class Display {
private:
    TFT_eSPI tft;
    lv_disp_t *disp;
    lv_indev_t *indev;
    uint32_t lastUpdate;
    
    // UI Objects
    lv_obj_t *mainScreen;
    lv_obj_t *stationLabel;
    lv_obj_t *timeLabel;
    lv_obj_t *tempLabel;
    lv_obj_t *descriptionLabel;
    lv_obj_t *humidityLabel;
    lv_obj_t *pressureLabel;
    lv_obj_t *volumeLabel;
    lv_obj_t *statusLabel;
    lv_obj_t *playButton;
    lv_obj_t *prevButton;
    lv_obj_t *nextButton;
    lv_obj_t *volumeSlider;
    lv_obj_t *stationList;

public:
    Display();
    
    void init();
    void begin();
    void update();
    void updateWeather(float temp, float humidity, int pressure, const char* description);
    void updateStation(const char* name);
    void updateTime(const char* timeStr);
    void updateVolume(int volume);
    void updateStatus(const char* status);
    void updatePlayButton(bool isPlaying);
    void setPlayCallback(lv_event_cb_t cb);
    void setPrevCallback(lv_event_cb_t cb);
    void setNextCallback(lv_event_cb_t cb);
    void setVolumeCallback(lv_event_cb_t cb);
    void setStationListCallback(lv_event_cb_t cb);
    void showNotification(const char* message, uint32_t duration = 2000);
    void setBrightness(uint8_t brightness);
    void sleep();
    void wake();
    lv_obj_t* getStationList() { return stationList; }

private:
    void createMainScreen();
    void createTopPanel();
    void createCenterPanel();
    void createBottomPanel();
    void createStationListPopup();
    static void lvglFlush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
    static void touchpadRead(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
};

#endif // DISPLAY_H
