#ifndef _HTTPHANDLER_H
#define _HTTPHANDLER_H

#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoOTA.h>
#include "SettingsFile.h"
#include "ConfigFile.h"
#include "IOHandler.h"

class HTTPHandler{
  public:
    HTTPHandler(IOHandler *ioHandler, SettingsFile *settingsFile, ConfigFile *configFile);
    void setupServer();
    void setupOTA();
    void update();

    // static HTTPHandler* get();
    // static HTTPHandler* init();

  private:
    // static HTTPHandler* m_instance;
    AsyncWebServer httpServer;
    SettingsFile *settingsFile;
    ConfigFile *configFile;
    IOHandler *ioHandler;

    bool handleFileRead(AsyncWebServerRequest *request);
    String doDoorAction(const String &action);
    String doLockAction(const String &action);
    String doInHomeArea(const String &action);

    String formatUnknownAction(const String &what, const String &action);
};



#endif
