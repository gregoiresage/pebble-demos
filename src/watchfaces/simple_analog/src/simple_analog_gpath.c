#include "simple_analog.h"

void simple_analog_create_gpathes(GPath **minute_segment_path, GPath **hour_segment_path, GPath *tick_paths[]){
	*minute_segment_path = gpath_create(&MINUTE_HAND_POINTS);
  	*hour_segment_path = gpath_create(&HOUR_HAND_POINTS);

  	for (int i = 0; i < NUM_CLOCK_TICKS; ++i) {
    	tick_paths[i] = gpath_create(&ANALOG_BG_POINTS[i]);
  	}
}