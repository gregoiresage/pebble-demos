#include "pebble.h"

static const GPathInfo SQUARE_POINTS = {
  4,
  (GPoint []) {
    {-25, -25},
    {-25,  25},
    { 25,  25},
    { 25, -25}
  }
};


void feature_timer_animation_gpath_create(GPath **gpath){
  *gpath = gpath_create(&SQUARE_POINTS);
}