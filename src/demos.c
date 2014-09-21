#include "pebble.h"
#include "common.h"
#include "overlord.h"

#define DEMO_NUM_MENU_SECTIONS 2
#define DEMO_NUM_APPS_ITEMS 29
#define DEMO_NUM_FACES_ITEMS 13

#define NUM_APP_PKEY 1
#define NUM_APP_DEFAULT 0

static Window *window;

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_sections[DEMO_NUM_MENU_SECTIONS];
static SimpleMenuItem apps_menu_items[DEMO_NUM_APPS_ITEMS];
static SimpleMenuItem faces_menu_items[DEMO_NUM_FACES_ITEMS];

// last loaded app
static int num_app = -1;

static void menu_app_select_callback(int index, void *ctx) {

  if(num_app != -1){
    appConfig[num_app].deinit();
  }

  int res = overlay_load(index);
  if(res > 0){
    num_app = index;
    appConfig[num_app].init();
  }
}

static void menu_face_select_callback(int index, void *ctx) {

  if(num_app != -1){
    appConfig[num_app].deinit();
  }

  int res = overlay_load(index+DEMO_NUM_APPS_ITEMS);
  if(res > 0){
    num_app = index+DEMO_NUM_APPS_ITEMS;
    appConfig[num_app].init();
  }
}

// This initializes the menu upon window load
static void window_load(Window *window) {
  for(int i=0; i<DEMO_NUM_APPS_ITEMS; i++){
    apps_menu_items[i] = (SimpleMenuItem){
      .title = "",
      .subtitle = appNames[i],
      .callback = menu_app_select_callback,
    };
  }
  for(int i=0; i<DEMO_NUM_FACES_ITEMS; i++){
    faces_menu_items[i] = (SimpleMenuItem){
      .title = "",
      .subtitle = appNames[DEMO_NUM_APPS_ITEMS+i],
      .callback = menu_face_select_callback,
    };
  }

  menu_sections[0] = (SimpleMenuSection){
    .num_items = DEMO_NUM_APPS_ITEMS,
    .items = apps_menu_items,
    .title = "WatchApps"
  };
  menu_sections[1] = (SimpleMenuSection){
    .num_items = DEMO_NUM_FACES_ITEMS,
    .items = faces_menu_items,
    .title = "WatchFaces"
  };

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, DEMO_NUM_MENU_SECTIONS, NULL);
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));

  int last_index = persist_exists(NUM_APP_PKEY) ? persist_read_int(NUM_APP_PKEY) : NUM_APP_DEFAULT;
  simple_menu_layer_set_selected_index(simple_menu_layer, last_index, false);
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

int main(void) {
  window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_set_fullscreen(window, true);
  window_stack_push(window, true);

  app_event_loop();

  window_destroy(window);

  if(num_app != -1){
    appConfig[num_app].deinit();
  }

  persist_write_int(NUM_APP_PKEY, num_app);
}
