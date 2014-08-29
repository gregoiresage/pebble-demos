#include "pebble.h"

static const GPathInfo MINUTE_SEGMENT_PATH_POINTS = {
  3,
  (GPoint []) {
    {0, 0},
    {-8, -80}, // 80 = radius + fudge; 8 = 80*tan(6 degrees); 6 degrees per minute;
    {8,  -80},
  }
};

static const GPathInfo HOUR_SEGMENT_PATH_POINTS = {
  3,
  (GPoint []) {
    {0, 0},
    {-13, -50}, // 50 = radius + fudge; _ = 50*tan(15 degrees); 30 degrees per hour;
    {13,  -50},
  }
};

void create_gpathes(GPath **minute_segment_path, GPath **hour_segment_path){
  *minute_segment_path = gpath_create(&MINUTE_SEGMENT_PATH_POINTS);
  *hour_segment_path = gpath_create(&HOUR_SEGMENT_PATH_POINTS);
}