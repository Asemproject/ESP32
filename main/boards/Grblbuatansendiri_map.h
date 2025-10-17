/*
  Grblbuatansendiri_map.h - grblHAL board map for WeMos D1 R32 (ESP32-WROOM-32)
  Adapted for direct compatibility with CNC Shield V3 (Arduino UNO pinout)
  Modified 2025 for WeMos D1 R32 + CNC Shield V3 mapping
*/

#if N_ABC_MOTORS > 1
#error "Axis configuration not supported!"
#endif

#if KEYPAD_ENABLE == 1
#error No free pins for I2C keypad!
#endif

#if TRINAMIC_ENABLE
#error WROOM-32 build does not use Trinamic drivers
#endif

#define BOARD_NAME "GrblBuatansendiri (WeMos D1 R32 - CNC Shield V3)"
#define BOARD_URL  "https://github.com/grblHAL/ESP32"

//
// ─── STEPPER DRIVERS ───────────────────────────────────────────
//
#define STEPPERS_ENABLE_PIN   GPIO_NUM_13   // CNC Shield: EN (D8)

#define X_STEP_PIN            GPIO_NUM_16   // UNO D2
#define X_DIRECTION_PIN       GPIO_NUM_2    // UNO D5

#define Y_STEP_PIN            GPIO_NUM_17   // UNO D3
#define Y_DIRECTION_PIN       GPIO_NUM_14   // UNO D6

#define Z_STEP_PIN            GPIO_NUM_4    // UNO D4
#define Z_DIRECTION_PIN       GPIO_NUM_15   // UNO D7

//
// ─── LIMIT SWITCHES ─────────────────────────────────────────────
//
#define X_LIMIT_PIN           GPIO_NUM_12   // UNO D9
#define Y_LIMIT_PIN           GPIO_NUM_5    // UNO D10
#define Z_LIMIT_PIN           GPIO_NUM_26   // UNO A5

//
// ─── PROBE ─────────────────────────────────────────────────────
#if PROBE_ENABLE
  #define PROBE_PIN           GPIO_NUM_25   // UNO A4
#endif

//
// ─── SPINDLE & COOLANT ─────────────────────────────────────────
#define SPINDLE_PWM_PIN       GPIO_NUM_23   // UNO D11
#define SPINDLE_DIRECTION_PIN GPIO_NUM_18   // UNO D13
#define SPINDLE_ENABLE_PIN    GPIO_NUM_19   // UNO D12
#define COOLANT_FLOOD_PIN     GPIO_NUM_35   // UNO A3

//
// ─── CONTROL INPUTS (Abort, Hold, Resume) ──────────────────────
//
// CNC Shield V3 biasanya punya tombol di pin A0, A1, A2
// A0 = Reset/Abort, A1 = Feed Hold, A2 = Cycle Start
//
#define CONTROL_RESET_PIN     GPIO_NUM_36   // A0
#define CONTROL_FEED_HOLD_PIN GPIO_NUM_39   // A1
#define CONTROL_CYCLE_START_PIN GPIO_NUM_34 // A2

// Safety Door feature dihapus total
#undef  SAFETY_DOOR_ENABLE
#undef  SAFETY_DOOR_PIN

// Aktifkan kontrol manual tanpa Safety Door
#define CONTROL_ENABLE 1

//
// ─── SD CARD SPI PINS ──────────────────────────────────────────
//
// SD Card terhubung ke pin SD0..SD3, CMD, CLK pada board
//
#define PIN_NUM_MISO          GPIO_NUM_19
#define PIN_NUM_MOSI          GPIO_NUM_23
#define PIN_NUM_CLK           GPIO_NUM_18
#define PIN_NUM_CS            GPIO_NUM_5   // chip select SD

//
// ─── STATUS LED / AUX OUTPUT (Opsional) ────────────────────────
#define AUXOUTPUT0_PIN        GPIO_NUM_2    // optional LED / indicator

//
// ─── WIFI / WEBUI (Opsional) ───────────────────────────────────
#ifdef WIFI_ENABLE
  #define WEBUI_ENABLE       1
  #define WEBUI_AUTH_ENABLE  0
#endif

//
// ─── CATATAN PENTING ───────────────────────────────────────────
// 1. Aman untuk shield CNC V3 langsung plug ke WeMos D1 R32.
// 2. Tidak ada safety door (fitur dihapus).
// 3. Abort, Hold, Resume aktif dan bekerja seperti Arduino UNO.
// 4. GPIO6–11 tidak digunakan (area flash internal ESP32).
// 5. Gunakan resistor pull-up internal pada input tombol.
// 6. Gunakan SD card 3.3V langsung ke pin SD0..SD3, CMD, CLK.
// ───────────────────────────────────────────────────────────────
