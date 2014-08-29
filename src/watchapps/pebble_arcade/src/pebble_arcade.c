#include <pebble.h>
#include "game.h"
#include "score.h"
#include "entry.h"

void pebble_arcade_init(void) {
  game_init();
  high_score_init();
  entry_init();
}

void pebble_arcade_deinit(void) {
  game_deinit();
  high_score_deinit();
  entry_deinit();
}

// int main(void) {
//   init();
//   app_event_loop();
//   deinit();

//   return 0;
// }
