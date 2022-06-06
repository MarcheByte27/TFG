//Librerias
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h> //Librería para comunicación SPI
#include <Adafruit_PN532.h>
#include <WiFi.h>
#include <WebServer.h>
#include "FS.h"
#include "SPIFFS.h"
#include "SPIFF_fun.h"


//definiciones de PN532
#define PN532_SCK (18)
#define PN532_MOSI (23)
#define PN532_SS (5)
#define PN532_MISO (19)
#define FORMAT_SPIFFS_IF_FAILED true

//Variables PN532
uint8_t DatoRecibido[4]; // Para almacenar los datos
Adafruit_PN532 nfc(PN532_SS); // Línea enfocada para la comunicación por SPI

//variables para la red
static const char *SSID = "ConfigNFC";
static const char *PASSWORD = "hola1234";
WebServer server(80);
String answer = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Hola desde ESP32-Modo Punto de Acceso(AP)</h1>\
</body>\
</html>";


//Declaracion de funciones/tareas
void TaskLeerIdNFC(void *pvParameters);
void TaskRedWifi(void *pvParameters);
void handleConnectionRoot();