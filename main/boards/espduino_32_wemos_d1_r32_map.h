/*
  esp32_asem_mod_map.h - Map file for ESP32 Mod by Asem
  Converted from FluidNC configuration

  Part of grblHAL logic
*/

#if N_ABC_MOTORS > 0
#error "Axis configuration is not supported!"
#endif

#define BOARD_NAME "ESP32 Mod by Asem"

// -------------------------------------------------------------------------
// STEPPER MOTOR PINS
// -------------------------------------------------------------------------

// Define step pulse output pins.
// FluidNC: X Step: gpio.2, Y Step: gpio.16, Z Step: gpio.25
#define X_STEP_PIN          GPIO_NUM_12
#define Y_STEP_PIN          GPIO_NUM_33
#define Z_STEP_PIN          GPIO_NUM_26

// Define step direction output pins.
// FluidNC: X Dir: gpio.15, Y Dir: gpio.17, Z Dir: gpio.26
#define X_DIRECTION_PIN     GPIO_NUM_14
#define Y_DIRECTION_PIN     GPIO_NUM_27
#define Z_DIRECTION_PIN     GPIO_NUM_15

// Define stepper driver enable/disable output pin(s).
// FluidNC: shared_stepper_disable_pin: gpio.13
#define STEPPERS_ENABLE_PIN GPIO_NUM_13

// -------------------------------------------------------------------------
// LIMIT SWITCH PINS
// -------------------------------------------------------------------------

// Define homing/hard limit switch input pins.
// FluidNC: X Limit: gpio.27, Y Limit: gpio.14, Z Limit: gpio.4
#define X_LIMIT_PIN         GPIO_NUM_17
#define Y_LIMIT_PIN         GPIO_NUM_4
#define Z_LIMIT_PIN         GPIO_NUM_16

// -------------------------------------------------------------------------
// SPINDLE / COOLANT / PROBE (AUX I/O)
// -------------------------------------------------------------------------

/* NOTE: In your FluidNC config, Spindle, Coolant, and Probe are either
   not defined or set to NO_PIN. 
   
   The original file used GPIO 19/18 for Spindle, but your config uses 
   GPIO 19/18 for SPI (SD Card). Therefore, Spindle pins are disabled here 
   to prevent conflict.
*/

// #define SPINDLE_PWM_PIN     GPIO_NUM_NC
#define SPINDLE_ENABLE_PIN  GPIO_NUM_22
// #define COOLANT_FLOOD_PIN   GPIO_NUM_NC
// #define COOLANT_MIST_PIN    GPIO_NUM_NC
#define PROBE_PIN           GPIO_NUM_32

// -------------------------------------------------------------------------
// SD CARD / SPI PINS
// -------------------------------------------------------------------------

#if SDCARD_ENABLE
// Pin mapping when using SPI mode.
// FluidNC SPI: miso: 19, mosi: 23, sck: 18
// FluidNC SD: cs: 5, card_detect: 35
#define SPI_MISO_PIN        GPIO_NUM_19
#define SPI_MOSI_PIN        GPIO_NUM_23
#define SPI_SCK_PIN         GPIO_NUM_18
#define SD_CS_PIN           GPIO_NUM_5
//#define SD_CD_PIN           GPIO_NUM_nc 
#endif

// -------------------------------------------------------------------------
// CONTROL PINS
// -------------------------------------------------------------------------

// FluidNC: reset, feed_hold, cycle_start are all NO_PIN
// Leaving these undefined or verifying config.h disables them.

#if KEYPAD_ENABLE
#error No free pins for keypad!
#endif
