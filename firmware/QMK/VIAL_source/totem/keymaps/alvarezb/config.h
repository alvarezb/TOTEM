#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// Determine how handedness is detected
// #define MASTER_LEFT // USB cable on left
// #define MASTER_RIGHT // USB cable on right

#define TAPPING_TERM 200
#define FLOW_TAP_TERM 150

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
