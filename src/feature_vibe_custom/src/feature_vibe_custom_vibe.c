#include "pebble.h"

static const uint32_t durations[6] = {100, 300, 300, 300, 100, 300};
static const VibePattern custom_pattern = {
  .durations = durations,
  .num_segments = 6
};

void doVibe(){
	vibes_enqueue_custom_pattern(custom_pattern);
}