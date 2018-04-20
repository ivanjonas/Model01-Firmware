// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
  * These #include directives pull in the Kaleidoscope firmware core,
  * as well as the Kaleidoscope plugins we use in the Model 01's firmware
  */
#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-DualUse.h"
#include "src/Kaleidoscope-LangPack-German.h"


/** Call with `M(MACRO_NAME)` in keymap.
  * Add to 'switch' statement in the `macroAction` function.
  */
enum { MACRO_VERSION_INFO
//   , MACRO_NAME
     };


/** The Model 01's key layouts are defined as 'keymaps'. `Key_` definition references:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Special symbols:
  *   `___` to let a keypress fall through to the previously active layer
  *   `XXX` to disable a keyswitch on this layer
  *   `ShiftToLayer()` and `LockLayer()` keys to change the active keymap.
  *
  * Layers are "0-indexed". This 'enum' lets us use names like 
  * COLEMAK, FUNCTION, and NUMPAD in place of the numbers 0, 1 and 2.
  */
enum { COLEMAK, LAZYNUMBERS, PROGRAMMING, FUNCTION }; // layers

#define LANG(n) (Key){.raw = kaleidoscope::language::n}

#define ANGLE_L LSHIFT(Key_Comma)
#define ANGLE_R LSHIFT(Key_Period)
#define BRACKET_L Key_LeftBracket
#define BRACKET_R Key_RightBracket
#define PAREN_L Key_LeftParen
#define PAREN_R Key_RightParen
#define CURLY_L Key_LeftCurlyBracket
#define CURLY_R Key_RightCurlyBracket
#define PIPE LSHIFT(Key_Backslash)
#define UNDERSCORE LSHIFT(Key_Minus)

#define VOLUME_DOWN Consumer_VolumeDecrement
#define VOLUME_UP   Consumer_VolumeIncrement
#define TRACK_PREV  Consumer_ScanPreviousTrack
#define TRACK_NEXT  Consumer_ScanNextTrack
#define PLAY_PAUSE  Consumer_PlaySlashPause

// *INDENT-OFF*
const Key keymaps[][ROWS][COLS] PROGMEM = {

  [COLEMAK] = KEYMAP_STACKED
  (XXX,           Key_1, Key_2,  Key_3, Key_4, Key_5,   Key_LEDEffectNext,
   Key_Backtick,  Key_Q, Key_W,  Key_F, Key_P, Key_G,   Key_Tab,
   Key_PageUp,    Key_A, Key_R,  Key_S, Key_T, Key_D,
   Key_PageDown,  Key_Z, Key_X,  Key_C, Key_V, Key_B,   XXX,
   Key_Backspace, Key_LeftShift, Key_LeftAlt,  Key_LeftGui,
   Key_LeftControl,
                       Key_PrintScreen,   Key_6, Key_7, Key_8,     Key_9,      Key_0,         Consumer_Mute,
                       Key_Enter,         Key_J, Key_L, Key_U,     Key_Y,      Key_Semicolon, Key_Equals,
                                          Key_H, Key_N, Key_E,     Key_I,      Key_O,         Key_Quote,
                       Key_PcApplication, Key_K, Key_M, Key_Comma, Key_Period, Key_Slash,     XXX,
                       MT(RightAlt, Escape), ShiftToLayer(LAZYNUMBERS), Key_Spacebar, ShiftToLayer(PROGRAMMING),
                       ShiftToLayer(FUNCTION)),


  [LAZYNUMBERS] = KEYMAP_STACKED
  (XXX, XXX,           XXX,           XXX,           XXX,           XXX,             XXX,
   XXX, LSHIFT(Key_1), LSHIFT(Key_2), LSHIFT(Key_3), LSHIFT(Key_4), LSHIFT(Key_5),   ___,
   ___, Key_1,         Key_2,         Key_3,         Key_4,         Key_5,
   ___, XXX,           XXX,           XXX,           XXX,           XXX,             XXX,
   ___, ___, ___, ___,
   ___,
                       XXX, XXX,           XXX,           XXX,           XXX,                XXX,        XXX,
                       ___, LSHIFT(Key_6), LSHIFT(Key_7), LSHIFT(Key_8), LSHIFT(Key_Equals), Key_Equals, XXX,
                            Key_6,         Key_7,         Key_8,         Key_9,              Key_0,      XXX,
                       XXX, XXX,           XXX,           XXX,           XXX,                XXX,        XXX,
                       ___, ___, ___, ___,
                       ___),


  [PROGRAMMING] =  KEYMAP_STACKED
  (XXX, Key_F1,  Key_F2,    Key_F3,  Key_F4,  Key_F5,   XXX,
   XXX, XXX,     XXX,       XXX,     XXX,     XXX,      XXX,
   XXX, ANGLE_L, BRACKET_L, CURLY_L, PAREN_L, Key_Slash,
   XXX, XXX,     XXX,       XXX,     XXX,     XXX,      XXX,
   XXX, ___, ___, ___,
   ___,
                       XXX,            Key_F6,        Key_F7,  Key_F8,     Key_F9,    Key_F10, Key_F11,
                       Key_ScrollLock, XXX,           XXX,     UNDERSCORE, Key_Minus, PIPE,    ___,
                                       Key_Backslash, PAREN_R, CURLY_R,    BRACKET_R, ANGLE_R, ___,
                       Key_Pause,      XXX,           XXX,     XXX,        XXX,       XXX,     XXX,
                       ___, ___, ___, ___,
                       ___),


  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,       Key_F2,       Key_F3,         Key_F4,       Key_F5,       Key_Insert,
   Key_Tab,  VOLUME_DOWN,  VOLUME_UP,    TRACK_PREV,     TRACK_NEXT,   PLAY_PAUSE,   ___,
   Key_Home, LANG(DEU_AU), LANG(DEU_OU), LANG(DEU_SSCH), LANG(DEU_UU), XXX,
   Key_End,  XXX,          XXX,          XXX,            XXX,          XXX,          XXX,
   Key_Delete, ___, ___, ___,
   ___,
                       LALT(Key_PrintScreen), Key_F6,       Key_F7,        Key_F8,        Key_F9,         Key_F10, Key_F11,
                       Key_ScrollLock,        Key_PageUp,   Key_Home,      Key_UpArrow,   Key_End,        XXX,     Key_F12,
                                              Key_PageDown, Key_LeftArrow, Key_DownArrow, Key_RightArrow, XXX,     XXX,
                       Key_Pause,             XXX,          XXX,           XXX,           XXX,            XXX,     Key_Mute,
                       ___, ___, Key_Enter, ___,
                       ___)
};
// *INDENT-ON*


/** versionInfoMacro handles the 'firmware version info' macro
  *  When a key bound to the macro is pressed, this macro
  *  prints out the firmware build information as virtual keystrokes
  */
static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;
  }
  return MACRO_NONE;
}


void setup() {
  Kaleidoscope.setup();

  Kaleidoscope.use(
    &BootGreetingEffect,
    &LEDControl,
    &LEDOff,
    &StalkerEffect,
    &LEDRainbowEffect,
    &LEDRainbowWaveEffect,

    &DualUse,

    &German,

    &Macros
  );

  LEDRainbowEffect.brightness(150); // scale of 0-255
  LEDRainbowWaveEffect.brightness(150);

  StalkerEffect.variant = STALKER(BlazingTrail);

  LEDOff.activate(); // avoids over-taxing underpowered devices
}


void loop() {
  Kaleidoscope.loop();
}
