//================================================================================================= 
//================================================================================================= 
//
//                                    C O N F I G U R A T I O N 
// 
//================================================================================================= 
//================================================================================================= 

/*
Complete change log and debugging options are at the bottom of this tab
                                    
v2.60.1 2020-05-24 Schedule fr 0x5007 params individually, fixes periodic flight-mode announcement.
                   Schedule fr 0xf101 rssi when mavlink #109, #65 or #35 arrives. Avg < 200 mS. Fixes
                   periodic "telemetry lost".                                       
*/
//===========================================================================================
//
//                   PLEASE SELECT YOUR DEFAULT OPTIONS BELOW BEFORE COMPILING
//
//===========================================================================================

#define webSupport                      // ESP only. Enable wifi web support, including OTA firmware updating. Browse to IP.
#define webPassword      "changeme!"    // Web password 
//#define Reset_Web_Defaults            // Reset settings in eeprom. Do this if eeprom settings are corrupt or wrong.

//#define SD_Support                    // Enable if you have an SD card reader attached
#define OLED_Support                  // Enable if you have an OLED display attached

//#define AutoBaud                      // Auto detect Mavlink serial-in baud rate
                                        // NOTE: Set mvBaudFC = 57600 for Dragonlink and RFD900X
#define mvBaudFC               57600    // Mavlink to/from the flight controller - max 921600 - must match FC or long range radio
#define frBaud                 57600    // S.Port baud setting - default 57600 


// Do not enable for FlightDeck
#define PlusVersion  // Added support for 0x5009 Mission WPs, 0x50F1 Servo_Channels, 0x50F2 VFR_Hud

//=================================================================================================
//           D E F A U L T   T R A N S L A T I O N   M O D E   S E T T I N G S   
//=================================================================================================       
// Choose only one of these three translation modes
#define Ground_Mode          // Translator between Taranis et al and LRS transceiver (like Dragonlink, ULRS, RFD900...)
//#define Air_Mode             // Translator between FrSky receiver (like XRS) and Flight Controller (like Pixhawk)
//#define Relay_Mode           // Translator between LRS tranceiver (like Dragonlink) and FrSky receiver (like XRS) in relay box on the ground


//=================================================================================================
//           D E F A U L T   F L I G H T   C O M P U T E R    I / O   S E T T I N G S   
//=================================================================================================
// Choose only one of these default Flight-Controller-side I/O channels 
// How does Mavlink telemetry enter this translator?
#define FC_Mavlink_IO  0    // Serial Port (default)         
//#define FC_Mavlink_IO  1    // BlueTooth Classic - ESP32 only
//#define FC_Mavlink_IO  2    // WiFi - ESP32 or ESP8266 only
//#define FC_Mavlink_IO  3    // SD Card / TF - ESP32 only


//=================================================================================================
//           D E F A U L T   G R O U N D S T A T I O N    I / O   S E T T I N G S   
//=================================================================================================
// Choose only one of these default GCS-side I/O channels
// How does Mavlink telemetry leave this translator?
// These are optional, and in addition to the S.Port telemetry output
//#define GCS_Mavlink_IO  0    // Serial Port  - Only Teensy 3.x and Maple Mini have Serial3     
//#define GCS_Mavlink_IO  1    // BlueTooth Classic - ESP32 only
//#define GCS_Mavlink_IO  2    // WiFi - ESP32 or ESP8266 only - auto selects on ESP8266
#define GCS_Mavlink_IO  3    // WiFi AND Bluetooth simultaneously - ESP32 only

#ifndef GCS_Mavlink_IO
  #define GCS_Mavlink_IO  9    // NONE (default)
#endif

// NOTE: The Bluetooth class library uses a lot of application memory. During Compile/Flash
//       you may need to select Tools/Partition Scheme: "Minimal SPIFFS (1.9MB APP ...) or similar

//#define GCS_Mavlink_SD       // SD Card - ESP32 only - mutually inclusive with other GCS I/O

//=================================================================================================                             
//                          S E L E C T   E S P   B O A R D   V A R I A N T   
//=================================================================================================

//#define ESP32_Variant     1    //  ESP32 Dev Module - Use Partition Scheme: "Minimal SPIFFS(1.9MB APP...)"
//#define ESP32_Variant     2    //  Wemos® LOLIN ESP32-WROOM-32_OLED_Dual_26p
//#define ESP32_Variant     3    //  Dragonlink V3 slim with internal ESP32 - contributed by Noircogi
#define ESP32_Variant     4    //  Heltec Wifi Kit 32 - Use Partition Scheme: "Minimal SPIFFS(Large APPS ith OTA)" - contributed by Noircogi

//#define ESP8266_Variant   1   // NodeMCU ESP 12F - choose "NodeMCU 1.0(ESP-12E)" board in the IDE
#define ESP8266_Variant   2   // ESP-12E, ESP-F barebones boards. RFD900X TX-MOD, QLRS et al - use Generic ESP8266 on IDE


//=================================================================================================
//                      D E F A U L T   B L U E T O O T H   S E T T I N G S   
//=================================================================================================

//#define BT_Mode  1           // Master Mode - active, initiate connection with slave (name)
#define BT_Mode  2           // Slave Mode - passive, advertise our hostname & wait for master to connect to us
#define BT_ConnectToSlave     "Crossfire 0277"  // Example


//=================================================================================================
//                            D E F A U L T   W  I  F  I   S E T T I N G S   
//=================================================================================================

#define Start_WiFi                              // Start WiFi at startup, override startWiFi Pin

#define HostName             "MavToPass"        // This translator's host name
#define APssid               "MavToPassthru"    // The AP SSID that we advertise         ====>
#define APpw                 "password"         // Change me!
#define APchannel            9                  // The wifi channel to use for our AP
#define STAssid              "OmegaOffice"      // Target AP to connect to (in STA mode) <====
#define STApw                "changeme"         // Target AP password (in STA mode)       

// Choose one default mode for ESP only - AP means advertise as an access point (hotspot). STA means connect to a known host
//#define WiFi_Mode   1  //AP            
#define WiFi_Mode   2  // STA
//#define WiFi_Mode   3  // STA failover to AP

// Choose one default protocol - for ESP32 only
#define WiFi_Protocol 1    // TCP/IP
//#define WiFi_Protocol 2    // UDP 


//=================================================================================================
//                            O T H E R   U S E R   O P T I O N S  
//=================================================================================================

//#define Battery_mAh_Source  1  // Get battery mAh from the FC - note both rx and tx lines must be connected      
//#define Battery_mAh_Source  2  // Define bat1_capacity and bat2_capacity below and use those 
const uint16_t bat1_capacity = 5200;       
const uint16_t bat2_capacity = 0;
#define Battery_mAh_Source  3         // Define battery mAh in the LUA script on the Taranis/Horus - Recommended

#define SPort_Serial        1         // Teensy port1=pin1, port3=pin8. The default is Serial 1, but 3 is possible 

// RSSI_Source is now automatic. Order of precedence: 
//      First:  #109 SiK style RADIO_STATUS
//      Second: #65 RC_CHANNELS
//      Third:  #35 RC_CHANNELS_RAW

//#define RSSI_Override          // Dummy RSSI - fixed at 70% - REDUNDANT due to PR by Hasi123 (if no rssi, force fixed 69%)                                                                                                                

//#define Rssi_In_Percent        // Un-comment if RSSI is already in %, not relative to (254->100%)

//#define QLRS // QLRS Longe Range System (QRLS uses remote rssi field - PR from giocomo892 april 2020)

// Status_Text messages place a huge burden on the meagre 4 byte FrSky telemetry payload bandwith
// The practice has been to send them 3 times to ensure that they arrive unscathed at the receiver
//  but that makes the bandwidth limitation worse and may crowd out other message types. Try without
//  sending 3 times, but if status_text gets distorted, un-comment the next line
//#define Send_status_Text_3_Times

//#define Send_Sensor_Health_Messages

//#define Request_Missions_From_FC    // Un-comment if you need mission waypoint from FC - NOT NECESSARY RIGHT NOW

//#define Data_Streams_Enabled        // Requests data streams from FC. Requires both rx and tx lines to FC. Rather set SRn in Mission Planner

//================================== Set your time zone here ======================================
// Only for SD / TF Card adapter option
// Date and time determines the TLog file name only
//const float Time_Zone = 10.5;    // Adelaide, Australia
const float Time_Zone = 2.0;    // Jo'burg
bool daylightSaving = false;

//=================================================================================================
//                        E X P E R I M E N T A L    O P T I O N S  
//    Don't change anything here unless you are confident you know the outcome

//#define ESP32_SoftwareSerial    // otherwise HardwareSerial is used 
//#define ESP_Onewire             // enable half_duplex on single (tx) pin and wire - Air/Relay
//#define ESP_Air_Relay_Blind_Inject_OK  // Blind inject instead of interleaving

//=================================================================================================   
//                              Auto Determine Target Platform
//================================================================================================= 
//
//                Don't change anything here
//
#if defined (__MK20DX128__) || defined(__MK20DX256__)
  #define TEENSY3X   
      
#elif defined ESP32
  #define Target_Board   3      // Espressif ESP32 Dev Module

#elif defined ESP8266
  #define Target_Board   4      // Espressif ESP8266
  
#else
  #error "Unsupported board type!"
#endif

//=================================================================================================   
//                              CHECK #MACRO OPTIONS LOGIC
//================================================================================================= 

#if defined PlusVersion
  #define Request_Mission_Count_From_FC // Needed for yaapu's mission/waypoint script
#endif

#if (not defined ESP32) && (not defined ESP8266)
  #if defined webSupport
    #undef webSupport
    //    #error webSupport only available on ESP32 or ESP8266
  #endif
#endif
  
#if defined ESP32
  #include <iostream> 
  #include <sstream> 
  #include <driver/uart.h>  // In Arduino ESP32 install repo 
  //C:\Users\<YourName>\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.4\tools\sdk\include\driver

#endif
  
  #if (defined ESP32) || (defined ESP8266)  // ESP32 or ESP8266 (UART0, UART1, and UART2)
    #if (SPort_Serial  == 3)    
      #error Board does not have Serial3. This configuration is not possible.
    #endif
  #endif

  #if (defined TEENSY3X) 
    #if (FC_Mavlink_IO == 3) || (defined GCS_Mavlink_SD)  
      #error SD card not currently implemented for Teensy
    #endif
  #endif

  #ifndef Battery_mAh_Source
    #error Please choose at least one Battery_mAh_Source
  #endif

  #if (not defined ESP32) && (not defined ESP8266) 
     #if (FC_Mavlink_IO == 2) || (GCS_Mavlink_IO == 2) || (GCS_Mavlink_IO == 3) || (defined webSupport)
    //   #error WiFi and webSupport only work on an ESP32 or ESP8266 board
       #if defined FC_Mavlink
         #undef FC_Mavlink
       #endif  
       #define FC_Mavlink_IO  0
       #if defined GCS_Mavlink_IO
         #undef GCS_Mavlink_IO
       #endif   
       #define GCS_Mavlink_IO 9
       #if defined webSupport
         #undef  webSupport
       #endif  
     #endif  
  #endif

  #if (defined ESP8266)  && ((GCS_Mavlink_IO == 1) || (GCS_Mavlink_IO == 3))  // Can't do BT on 8266
      #undef GCS_Mavlink_IO
      #define GCS_Mavlink_IO  2    // WiFi Only
  #endif

  #if (FC_Mavlink_IO == 1) || (GCS_Mavlink_IO == 1) || (GCS_Mavlink_IO == 3)       
    #if (not defined ESP32) 
      #error Bluetooth works only on an ESP32 board      
    #else
      #if (not defined BT_Mode)
        #error Please define BT_Mode  
      #endif
    #endif
  #endif  
  
  #ifndef FC_Mavlink_IO
    #error Please choose at least one Mavlink FC IO channel
  #endif

  #if (defined ESP32)
    #ifndef WiFi_Mode 
      #error Please define WiFi_Mode
    #endif
  #endif  

  #if (defined ESP32)
    #ifndef WiFi_Protocol
      #error Please define WiFi_Protocol
    #endif
  #endif

  #if (defined ESP32)         
    #ifndef ESP32_Variant 
      #error Please define an ESP32 board variant
    #endif
  #endif

  #if (defined ESP8266)
    #ifndef ESP8266_Variant
         #error Please define an ESP8266 board variant
    #endif
 
  #endif         

  #if (defined ESP32 || defined ESP8266) && (FC_Mavlink_IO == 2 || FC_Mavlink_IO == 3 || GCS_Mavlink_IO == 2 || GCS_Mavlink_IO == 3 || defined webSupport)
    #define wifiBuiltin   //  for these features we need wifi support compiled in
  #endif    

  #if (defined ESP32) && (FC_Mavlink_IO == 1 || FC_Mavlink_IO == 3 || GCS_Mavlink_IO == 1 || GCS_Mavlink_IO == 3)
    #define btBuiltin   //  for these features we need bluetooth support compiled in
  #endif      
//=================================================================================================   
//                          P L A T F O R M   D E P E N D E N T   S E T U P S
//================================================================================================= 

  
#if defined TEENSY3X               // Teensy3x
  #define MavStatusLed  13
  #define InvertMavLed false   
  #define BufStatusLed  14        
  #define FC_Mav_rxPin  9  
  #define FC_Mav_txPin  10
  #if (SPort_Serial == 1)
    #define Fr_txPin       1      // SPort tx - Use me in single wire mode 
    #define GC_Mav_rxPin   7    
    #define GC_Mav_txPin   8   
  #elif (SPort_Serial == 3)
    #define Fr_txPin       8      // Optional SPort tx 
  #endif  
    
  #if (defined SD_Support) || (defined OLED_Support)
  #endif
 
#elif defined ESP32                 // ESP32 Platform

  #if (ESP32_Variant == 1)          // ESP32 Dev Module
    #define MavStatusLed  02        // Onboard LED
    #define InvertMavLed false      
    #define BufStatusLed  27        // untested pin      
    #define FC_Mav_rxPin  16        // Mavlink to FC
    #define FC_Mav_txPin  17        // Mavlink from FC
    #define Fr_rxPin      13        // SPort - Not used in 1-wire mode
    #define Fr_txPin       4        // SPort tx - Use me in single wire mode
    #define startWiFiPin   5        // Trigger WiFi startup       
    #if (defined SD_Support) || (defined OLED_Support)   
      #define SDA           21        // I2C OLED board
      #define SCL           22        // I2C OLED board
      #define i2cAddr      0x3C       // I2C OLED board
    #endif   
    /*  
      SPI/CS                       Pin 05   For optional TF/SD Card Adapter
      SPI/MOSI                     Pin 23   For optional TF/SD Card Adapter
      SPI/MISO                     Pin 19   For optional TF/SD Card Adapter
      SPI/SCK                      Pin 18   For optional TF/SD Card Adapter  
    */

  #endif

  #if (ESP32_Variant == 2)          // Wemos® LOLIN ESP32-WROOM-32_OLED_Dual_26p
    #define MavStatusLed  15        // No Onboard LED
    #define InvertMavLed false     
    #define BufStatusLed  99        // None    
    #define FC_Mav_rxPin  25        // Mavlink to FC
    #define FC_Mav_txPin  26        // Mavlink from FC
    #define Fr_rxPin      12        // SPort - Not used in single wire mode
    #define Fr_txPin      14        // SPort tx - Use me in single wire mode
    #define startWiFiPin  13        // Trigger WiFi startup      
    #if (defined SD_Support) || (defined OLED_Support)
      #define SDA           05        // I2C OLED board
      #define SCL           04        // I2C OLED board
      #define i2cAddr      0x3C       // I2C OLED board
    #endif  
  #endif

  #if (ESP32_Variant == 3)          // Dragonlink V3 slim with internal ESP32
    #if defined mvBaudFC
      #undef mvBaudFC
      #define mvBaudFC 115200       // Force baud rate to DragonLink rate
    #endif
    #define MavStatusLed  18        // Blue LED
    #define InvertMavLed false    
    #define BufStatusLed  19        // Green LED        
    #define FC_Mav_rxPin  16        // Mavlink to FC
    #define FC_Mav_txPin  17        // Mavlink from FC
    #define Fr_rxPin      12        // SPort - Not used in single wire mode
    #define Fr_txPin      01        // SPort tx - Use me in single wire mode
    #define startWiFiPin  13        // Trigger WiFi startup   
    #if (defined SD_Support) || (defined OLED_Support)
      #define SDA           05        // I2C OLED board
      #define SCL           04        // I2C OLED board 
      #define i2cAddr      0x3C       // I2C OLED board
    #endif  
  #endif
  
  #if (ESP32_Variant == 4)          // Heltec Wifi Kit 32 (NOTE! 8MB) 
    #define MavStatusLed  25        // Onboard LED
    #define InvertMavLed false     
    #define BufStatusLed  99   
    #define FC_Mav_rxPin  27        // Mavlink to FC
    #define FC_Mav_txPin  17        // Mavlink from FC
    #define Fr_rxPin      12        // SPort rx 
    #define Fr_txPin      14        // SPort tx - Use me in single wire mode
    #define startWiFiPin  13        // Trigger WiFi startup   
    #if !defined OLED_Support    // I2C OLED board is built into Heltec WiFi Kit 32
      #define OLED_Support
    #endif

    #if (defined SD_Support) || (defined OLED_Support)   
      #define SDA           04        // I2C OLED board 
      #define SCL           15        // I2C OLED board
      #define i2cAddr      0x3C       // I2C OLED board
      #define OLED_RESET    16        // RESET here so no rest lower down    
    #endif   

  #endif
  
#elif defined ESP8266                    // ESP8266 Platform

  #if (ESP8266_Variant == 1)        // NodeMCU 12F board - Dev board with usb etc
  
    #define MavStatusLed  D4        // D4 Board LED - Mav Status LED inverted logic - use 99 while debug
    #define InvertMavLed true      
    #define BufStatusLed  99        // None     
   //                     D4        // TXD1 - Serial1 debug log out SHARED WITH BOARD LED                         
    #define FC_Mav_rxPin  D9        // RXD0 default  
    #define FC_Mav_txPin  D10       // TXD0 default    
    #define Fr_rxPin      D5        // SPort - Not used in single wire mode
    #define Fr_txPin      D6        // SPort tx - Use me in single wire mode
    #define startWiFiPin  D3        // Trigger WiFi startup       
    #if (defined SD_Support) || (defined OLED_Support)  
      #define SCL           D1        // I2C OLED board   
      #define SDA           D2        // I2C OLED board
      #define i2cAddr      0x3C       // I2C OLED board
    #endif     
  #endif
  
  #if (ESP8266_Variant == 2)   // ESP-12E, ESP-F barebones boards. RFD900X TX-MOD, QLRS et al - use Generic ESP8266 on IDE
    //                         GPIO as per node mcu
    static const uint8_t D0   = 16;   // SCL - optional
    static const uint8_t D1   = 5;    // SDA - optional
    static const uint8_t D2   = 4;    // SPort tx - Use me in single wire mode
    static const uint8_t D3   = 0;    // Flash
    static const uint8_t D4   = 2;    // BoardLED & TXD1 optional debug out
    static const uint8_t D5   = 14;   // SPort rx (unused in half-duplex)
    static const uint8_t D6   = 12;   // P2-3 exposed dual row of pins
    static const uint8_t D7   = 13;   // CTS
    static const uint8_t D8   = 15;   // RTS
    static const uint8_t D9   = 3;    // RXD0
    static const uint8_t D10  = 1;    // TXD0 
    
    #define MavStatusLed  D4        // D4 Board LED - Mav Status LED inverted logic - use 99 while debug
    #define InvertMavLed true    
    #define BufStatusLed  99        // None
    //                    D4        // TXD1 - Serial1 default debug log out SHARED WITH BOARD LED                           
    #define FC_Mav_rxPin  D9        // RXD0 default  
    #define FC_Mav_txPin  D10       // TXD0 default    
    #define Fr_rxPin      D5        // SPort - Not used in single wire mode
    #define Fr_txPin      D2        // SPort (half-duplex) inverted - Use me in single wire mode
    #define startWiFiPin  D8        // Trigger WiFi startup       
    #if (defined SD_Support) || (defined OLED_Support)
      #define SCL           D0        // I2C OLED board   
      #define SDA           D1        // I2C OLED board
      #define i2cAddr      0x3C       // I2C OLED board
    #endif       
  #endif  
  
#endif

  //=================================================================================================   
  //                            E E P R O M    S U P P O R T   -   ESP Only - for now
  //================================================================================================= 

  #if (defined ESP32) || (defined ESP8266)
    #include <EEPROM.h>       // To store AP_Failover_Flag and webSupport Settings
    #define EEPROM_SIZE 160   // 1 + 159 bytes, addr range 0 thru 160
  #endif
    
  //=================================================================================================   
  //                             S D   C A R D   S U P P O R T   -   ESP Only - for now
  //================================================================================================= 
  #if ((defined ESP32)  || (defined ESP8266)) && (defined SD_Support) 

    #include <FS.h>
    #include <SD.h>
    #include <SPI.h>
    #define SD_Libs_Loaded 

    /*
    // Optional SPI interface pins for SD card adapter or SSD1306 OLED display
    #define CS            5        
    #define MOSI          23 
    #define MISO          19 
    #define SCK           18 
    */  

    // Pins generally   CS=5    MOSI=23   MISO=19   SCK=18    3.3V   GND   Dev Board, LilyGO/TTGO
 
 
     
    // Rememeber to change SPI frequency from 4E6 to 25E6, i.e 4MHz to 25MHz in SD.h otherwise MavRingBuff fills up 
    // C:\Users\YourUserName\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.2\libraries\SD\src  
    // bool begin(uint8_t ssPin=SS, SPIClass &spi=SPI, uint32_t frequency=25000000, const char * mountpoint="/sd", uint8_t max_files=5);  

    char     cPath[40];
    std::string   fnPath[30];
    uint8_t  fnCnt;
    uint16_t sdReadDelay = 10;  // mS   Otherwise the reads run through unnaturally quickly

    File     file;  // Create global object from File class for general use

    static  const uint8_t mthdays[]={31,28,31,30,31,30,31,31,30,31,30,31}; 

    typedef struct  { 
      uint16_t yr;   // relative to 1970;  
      uint8_t mth;
      uint8_t day;
      uint8_t dow;   // sunday is day 1 
      uint8_t hh; 
      uint8_t mm; 
      uint8_t ss; 
    }   DateTime_t;

    static DateTime_t dt_tm; 

  #endif  
  //=================================================================================================   
  //                                 O L E D   S U P P O R T    E S P  O N L Y - for now
  //================================================================================================= 
  #if (defined ESP32 || defined ESP8266)  
  
    #if not defined SD_Libs_Loaded   //  by SD block
      #include <SPI.h>                // for SD card and/or OLED
      #include <Wire.h>
    #endif  

    #include <Adafruit_SSD1306.h> 
    
    #define max_col  22
    #define max_row   8
    // 8 rows of 21 characters

    struct OLED_line {
      char OLx[max_col];
      };
  
     OLED_line OL[max_row]; 

    uint8_t row = 0;
    uint8_t col = 0;
  
    #define SCREEN_WIDTH 128 // OLED display width, in pixels
    #define SCREEN_HEIGHT 64 // OLED display height, in pixels
    // 8 rows of 21 characters

    // Declaration for an SSD1306 I2C display
    #ifndef OLED_RESET
      #define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
    #endif  
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  #endif

  //=================================================================================================   
  //                     B L U E T O O T H   S U P P O R T -  E S P 3 2  O n l y
  //================================================================================================= 

  #if (defined ESP32) 

    #include "BluetoothSerial.h"
    #include "esp_bt.h"
    #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
      #error Bluetooth is not enabled! Please run `make menuconfig in ESP32 IDF` 
    #endif

    BluetoothSerial SerialBT;

  #endif  

  //=================================================================================================   
  //                       W I F I   S U P P O R T - ESP32 and ES8266 Only
  //================================================================================================= 

    uint16_t TCP_localPort = 5760;
    uint16_t UDP_localPort = 14555;     
    uint16_t UDP_remotePort = 14550;      
    bool FtRemIP = true;

    int16_t           wifi_rssi;         
    volatile uint32_t debnceTimr;
    volatile int16_t  wifiButnPres;
    volatile uint32_t delaytm = 100;
    
  #if (defined ESP32 || defined ESP8266) 

    // Define link variables
    struct linkStatus {
      uint32_t    packets_received;
      uint32_t    packets_lost;
      uint32_t    packets_sent;
    };
    bool          hb_heard_from = false;
    uint8_t       hb_system_id = 0;
    uint8_t       hb_comp_id = 0;
    uint8_t       hb_seq_expected = 0;
    uint32_t      hb_last_heartbeat = 0;
    linkStatus    link_status;
  
    #if defined ESP32 
      #include <WiFi.h>  
      #include <WiFiClient.h>
      #if defined webSupport
        #include <WebServer.h> 
        #include <Update.h> 
        WebServer server(80);          
      #endif      
      #include <WiFiAP.h>  
    #endif

    #if defined ESP8266
      #include <ESP8266WiFi.h>   // Includes AP class
      #include <WiFiClient.h>
      #if defined webSupport
        #include <ESP8266WebServer.h>    
        ESP8266WebServer server(80);
      #endif      
    #endif
    
    #include <WiFiUdp.h>   

   //====================  Instantiate WiFi Objects 

    WiFiClient WiFiSTA;   
       
    WiFiServer TCPserver(TCP_localPort);         // Dummy TCP local port(changes on TCPserver.begin() ).

    IPAddress udp_remoteIP(192, 168, 1, 255);    // Declare UDP broadcast on dummy IP (changes on connect).
    WiFiUDP UDP;       // Create UDP object    
         
    IPAddress localIP;   // tcp and udp
  
  #endif  // end of ESP32 and ESP8266
  
//=================================================================================================   
//                                 S E R I A L
//=================================================================================================

#if (defined ESP32)  
  #define Debug               Serial         // USB
  #define mvSerialFC          Serial2        //  RXD0 and TXD0
   
  #if defined ESP32_SoftwareSerial
    #include <SoftwareSerial.h>
    SoftwareSerial frSerial; 
  #else     // default HW Serial
    #define frSerial          Serial1     
  #endif   
    
#elif (defined ESP8266)
  #define Debug               Serial1        //  D4   TXD1 debug out  - no RXD1 !
  #define mvSerialFC          Serial         //  RXD0 and TXD0
  #include <SoftwareSerial.h>
  SoftwareSerial frSerial;  
#endif 

#if (defined TEENSY3X)      //  Teensy 3.1
  #define Debug               Serial         // USB  
  #define mvSerialFC          Serial2   
  #if (SPort_Serial == 1) 
    #define frSerial              Serial1        // S.Port 
  #elif (SPort_Serial == 3)
    #define frSerial              Serial3        // S.Port 
 #else
    #error SPort_Serial can only be 1 or 3. Please correct.
  #endif 
#endif 

#if (defined TEENSY3X) || (defined MAPLE_MINI)  //  only these have 4 uarts at present
  //#define Enable_GCS_Serial  //  OPTION SET HERE   OPTION SET HERE   OPTION SET HERE 
#endif

#if defined Enable_GCS_Serial  // only Teensy and maple mini have 4 uarts at present
  #if (SPort_Serial == 3) 
   #error Mavlink_GCS and SPort both configured for Serial3. Please correct.
  #endif 
  
  #if (defined TEENSY3X)          
    #define mvSerialGCS             Serial3 
    #define mvBaudGCS               57600        // Use 57600
  #else
    #error Mavlink_GCS Serial not available for ESP32 or ESP8266  - no Serial3. Please correct.
  #endif
#endif

//=================================================================================================   
//                                 D E B U G G I N G   O P T I O N S
//=================================================================================================

//#define inhibit_SPort     // Use me to send debug messages only, out of GPIO1/TX0 on ESP32_Variant 3, DL V3 internal ESP32
//#define Mav_Debug_All
//#define Frs_Debug_All
//#define Frs_Debug_Payload
//#define Mav_Debug_RingBuff
//#define Frs_Debug_Period
//#define Debug_Air_Mode
//#define Debug_Relay_Mode
//#define Mav_List_Params      // Use this to test uplink to Flight Controller 
//#define Mav_Debug_Params
//#define Debug_BT    
//#define Debug_FC_Down        // traffic down from FC to Ring Buffer
//#define Debug_FC_Up          // traffic up to FC from GCS
//#define Debug_GCS_Down       // traffic from RB to GCS
//#define Debug_GCS_Up         // traffic up from GCS to FC
//#define Mav_Debug_Servo
//#define Frs_Debug_Servo
//#define Debug_Rssi
//#define Mav_Debug_RC
//#define Frs_Debug_RC
//#define Mav_Debug_FC_Heartbeat
//#define Mav_Debug_GCS_Heartbeat
//#define Frs_Debug_Params       //0x5007
//#define Mav_Debug_MavToPass_Heartbeat
//#define Frs_Debug_APStatus    // 0x5001
//#define Mav_Debug_SysStatus   // #1 && battery
//#define Debug_Batteries       // 0x5003
//#define Frs_Debug_Home        // 0x5004
//#define Mav_Debug_GPS_Raw     // #24
//#define Mav_Debug_GPS_Int     // #33
//#define Frs_Debug_LatLon      // 0x800
//#define Frs_Debug_VelYaw      // 0x5005
//#define Frs_Debug_GPS_status  // 0x5002
//#define Mav_Debug_Scaled_IMU
//#define Mav_Debug_Raw_IMU
//#define Mav_Debug_Hud         // #74
//#define Frs_Debug_Hud         // 0x50F2
//#define Mav_Debug_Scaled_Pressure
//#define Mav_Debug_Attitude    // #30
//#define Frs_Debug_AttiRange   // 0x5006
//#define Mav_Debug_StatusText  // #253  
//#define Frs_Debug_StatusText  // 0x5000
//#define Mav_Debug_Mission
//#define Frs_Debug_Mission   
//#define Debug_SD    
//#define Mav_Debug_System_Time   
//#define Frs_Debug_Scheduler // - this debugger affects the performance of the scheduler when activated
//#define Decode_Non_Essential_Mav 
//#define Debug_Baud 
//#define Debug_Radio_Status  
//#define Debug_GCS_Unknown
//#define Debug_Param_Request_Read
//#define Mav_Show_Unknown_Msgs
//#define Mav_Print_All_Msgid
//#define Debug_Eeprom
//#define Debug_Web_Settings
//#define Debug_SPort
//#define Mav_Debug_RPM
//#define Debug_SRAM

//=================================================================================================   
//                                   C H A N G E   L O G
//=================================================================================================
/*

Change log:
                                    
v2.00 2019-06-07 Plus version firmware ported to ESP32 Dev Module V1 successfully - no improvements  
v2.01 2019-06-09 Added OLED display support
v2.02 2019-05-18 Belatedly include Alex's Rangefinder PR that I missed.
v2.03 2019-05-21 Reduce voltage and current display moving average smoothing
                 Empirical correction of mAh consumed as per Markus Greinwald's measurements 
                 Change mav heartbeat timeout from 3 to 6 seconds
v2.04 2019-05-24 Merge Alex's BT classic PR. Thank you! 
                 Remove Aux port as no longer required
                 Tidy #define options  
v2.05 2019-06-09 Support 3 possible I/O channels on FC side, and 3 on GCS side. UART serial, BT and WiFi.
                 WiFi AP ssid = 'Mav2Passthru', pw = 'password' for now.  
v2.06 2019-06-10 Support added for STA mode and AP mode. Tidied up some lose ends. 
v2.07 2019-06-16 Initiate WiFi session with push button from GPIO15 momentary to ground. 
v2.08 2019-06-16 Add SD/TF card support - wip!!  Added UTP protocol option 
v2.09 2019-06-30 WiFi activation push button momentary but one-time. 
      2019-07-03 Implemented optional TLog input and output via SD card.  
v2.10 2019-07-09 For PX4 flight stack only, send HB to FC every 2 seconds  
      2019-07-10 Radical redesign of S.Port scheduling algorithm. Support SD and WiFi/BT I/O simultaneously 
v2.11 2109-07-11 Auto determine target board. Publish "Universal" version 2.11. One source, four platforms / boards 
v2.12 2019-07-12 Add #define PlusVersion, comment out for FlightDeck   
v2.13 2019-08-13 UDP now working in Access Point mode 
v2.14 2019-07-17 PX4 flight stack only - fixed longitude typo    if (ap_lat24<0) should be if (ap_lon24<0)
v2.15 2019-07-17 Switch to Adafruit_SSD1306 OLED library. 8 lines x 21 chars
v2.16 2019-07-18 Increase time burden for each successive Status Text chunk by 5mS
v2.17 2019-07-19 Auto detect serial telemetry and baud rate    
v2.18 2019-07-21 Tune FrSky packet schduler. Add option. Default is 1x.  //Send_status_Text_3_Times
v2.19 2019-07-22 Implement 2 tier scheduling. Tier1 gets priority, tier2 (0x5000) only when tier1 empty 
v2.20 2019-07-26 Release candidate. Send HB back to FC for APM also, not just PX4. Streamline library #includes.
                 #undef troublesome F function.  
v2.21 2019-07-26 Trap attempt to do GCS I/O on ESP32 or Blue Pill - no Serial3 UART.
      2019-07-29 Implement system health status-text messages as per Alex's request.  
v2.22 2019-08-10 Make sensor health messages optional for now. Fix end-of-sensor message text detection.
v2.23 2019-08-21 Add support for RFD900x long-range telemetry modems, specifically RSSI  
v2.24 2019-08-23 Workaround for Esp32 library "wifi: Set status to INIT" bug
                 Improve responsiveness to baud detect with no telemetry present.    
v2.25 2019-08-28 Version for RFD900x. Bug fixes on rssi. Include #define StartWiFi option to 
                 override startWiFi Pin.  
v2.26 2019-08-31 Improved GCS to FC debugging. Make baud rate sensing optional. 
v2.27 2019-09-13 Small additions to test LILYGO®_TTGO_MINI32_ESP32-WROVER_B
v2.28 2019-09-17 Localise pin definitions in one place to define ESP32 variants more easily
v2.29 2019-09-24 Use #if (TargetBoard == 3) to define soft pins for mvSerialFC
v2.30 2019-09-26 Don't push #5007 into sensor table from #147. Push from #1 only.
v2.31 2019-09-30 Configurable declarations moved to config.h file
v2.32 2019-10-08 Source line corrupted in v2.17 affecting Relay Mode, fixed. Thank you burtgree! 
v2.33 2019-10-09 Don't invert ESP32 SPort in Relay Mode. Use commercial inverter/converter. 
                 Tidy up config.h file.
                 Send #5007 3 times at startup and then every 50th heartbeat.
v2.34 2019-10-15 Move typedef struct DateTime_t to global scope in line with VS Code/Platform IO.  
v2.35 2019-10-18 Add pre-defined ESP32 board variants. TargetBoard >> Target_Board typo Paul Atherton. 
v2.36 2019-10-30 Optimise WiFi amd BT read/send as per excellent mavesp8266 bridge by Tridge.
                 Add support for ESP8266. 
v2.41 2019-11-08 Fix STA mode no-connect loop 
      2019-11-08 Make AutoAP optional    
v2.42 2019-11-09 Add support for GCS-side simultaneous WiFi and BT telemetry option 
v2.43 2019-11-10 Tidy up WiFi Setup for auto AP failover. 
                 Support for 2 new ESP32 board variants, complements of Noircogi.     
      2019-11-11 Implement Auto RSSI selection(Order of precedence #109, then #65 then #35) 
      2019-11-11  Support AutoBaud up to 921600. 
v2.44 2019-11-12  Include Target0815 recommended reset after STA fail to connect.     
v2.45 2019-11-12  Augment mission debugging for athertop.  
      2019-11-13  Move #endif outside } in SetupWiFi         
v2.46 2019-11-16  A few cosmetic improvements     
v2.47 2019-12-23  For ESP32 Dev Module, use pin 27 for S.Port tx, 
                   because boot fails if pin 12 pulled high   

v2.48 2019-12-17 Option for SiK #109, if RSSI is already in %, i.e. not relative to 2.54 
                 Added #define Rssi_In_Percent 
      2019-12-31 Changes for PlatformIO compatibility 
      2020-01-02 ESP32 Dev Board change again for stability - S.Port pins rx=13, tx=14 
v2.49 2020-01-07 Move baud, ssid and BT settings to top of config.h for convenience 
v2.50 2020-01-12 AutoAP: Activate udp broadcast on AP dhcp allocated IP subnet.
                 Eliminate annoying periodic "Stabilized Flight Mode" announcements.
                 Further localise options in to logical groups.     
      2020-01-13 Revert max rssi to 254. 255 is invalid/unknown in ardupilot  
v2.51 2020-01-18 Make default rssi 69% for SiK radios, like RFD900x. PR by Hasi123   
v2.52 2020-01-21 Support web OTA. Rehash STA to AP failover using reboot - now stable. 
v2.53 2020-01-25 ESP8266 (Node MFU 12F) debugged, tested. ESP8266 OTA included. 
v2.54 2020-01-27 ESP8266 inverted single-wire enabled, like Teensy. 
      No hardware invert/convert required.                     
v2.54a 2020-01-28 Setup OTA password in config.h   
v2.54b 2020-01-30 Correct irritating warnings  
v2.55  2020-02-04 Add RFD900X TXMOD ESP8266 variant    
v2.56.1  2020-02-26 Add web interface to allow settings/parameter changes 
v2.56.2  2020-02-27 STM32F103C / Blue Pill / Maple Mini deprecated. Tidy up Teensy3.x warnings. 
v2.56.3 2020-03-03 Minor ESP8266 variants logic check 
v2.56.4 2020-03-04 Remove spurious debugging code affecting S.Port Thanks pascale dragos.     
v2.56.5 2020-03-09 Reduce rssi timing cycle to 350mS from 700mS. 
v2.57   2020-03-15 Fix RFD900/TXMOD status LED. SoftwareSerial for ESP32.  
v2.58   2020-03-17 Option to work around apparent bug in Mavlink V2 Library. Tolerate crc errors.
                   This fixes failure to parse certain mavlink messages, including #226 RPM 
                   Needs more investigation. Use with caution!
v2.58.1 2020-03-18 Improve user options on hw/sw serial 
v2.58.2 2020-03-20 Stable. Lots of nice, small tweaks. Exp. code for inherent 1-wire on ESP
v2.58.3 2020-03-22 Deactivate experimental CRC error tolerance for general use. My bad. 
v2.58.4 2020-03-25 RPM fixed (library path). 
v2.58.5 2020-03-28 Add //#define SD_Support to optionally remove all SD support at compile time.
                   This is especially useful for PlatformIO on ESP8266.   
v2.59.1 2020-04-02 Support for QLRS (rssi) by giacomo892. Style and function improvements to web
                   interface.  
v2.59.2 2020-04-21 Some structural tidying up.   
v2.59.3            Main loop minor fix.  
                   wifiBuiltin and btBuiltim macros added.  
        2020-04-28 GetBaud(FC_Mav_rxPin) fix. Thanks has1123. 
v2.59.4 2020-05-08 Broadcast on the subnet we attached to. Can't assume 192.168.1/24 :) 
        Patch by Stefan Arbes.   
v2.59.5 2020-05-11 Fixed TCP_LocalPort initialisation 
v2.59.6 2020-05-20 Improve WiFi start button debounce . Add Debug_SRAM.     
v2.60.0 2020-05-23 Deactivate BT to reclaim critical SRAM during web support. Patch by Scott P.
                   Reboot on Cancel web settings page
   
                                                                                        
*/
