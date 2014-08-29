#pragma once

typedef struct {
void (*init)();
void (*deinit)();
} app_t;

#define ENTRYPOINTS(NAME) void NAME ## _init(); void NAME ## _deinit(); 

ENTRYPOINTS(app_font_browser)
ENTRYPOINTS(app_font_viewer)
ENTRYPOINTS(app_mockup_helper)
ENTRYPOINTS(feature_accel_discs)
ENTRYPOINTS(feature_app_logging)
ENTRYPOINTS(feature_clock_mode)
ENTRYPOINTS(feature_custom_font)
ENTRYPOINTS(feature_draw_bitmap)
ENTRYPOINTS(feature_draw_bitmap_composite)
ENTRYPOINTS(feature_focus_handler)
ENTRYPOINTS(feature_gpath)
ENTRYPOINTS(feature_image)
ENTRYPOINTS(feature_image_transparent)
ENTRYPOINTS(feature_inverter_layer)
ENTRYPOINTS(feature_layer_data)
ENTRYPOINTS(feature_menu_layer)
ENTRYPOINTS(feature_persist_counter)
ENTRYPOINTS(feature_property_animation)
ENTRYPOINTS(feature_scroll_layer)
ENTRYPOINTS(feature_simple_menu_layer)
ENTRYPOINTS(feature_stdlib)
ENTRYPOINTS(feature_text_alignment)
ENTRYPOINTS(feature_text_draw)
ENTRYPOINTS(feature_timer)
ENTRYPOINTS(feature_timer_animation)
ENTRYPOINTS(feature_vibe)
ENTRYPOINTS(feature_vibe_custom)
ENTRYPOINTS(pebble_arcade)

ENTRYPOINTS(big_time)
ENTRYPOINTS(classio)
ENTRYPOINTS(classio_battery_connection)
ENTRYPOINTS(drop_zone)
ENTRYPOINTS(fuzzy_time)
ENTRYPOINTS(just_a_bit)
ENTRYPOINTS(ninety_one_dub)
ENTRYPOINTS(onthebutton)
ENTRYPOINTS(rumbletime)
ENTRYPOINTS(segment_six)
ENTRYPOINTS(simple_analog)
ENTRYPOINTS(simplicity)
ENTRYPOINTS(tic_tock_toe)

#define ENTRYPOINTROW(NAME) { .init = NAME ## _init, .deinit = NAME ## _deinit}

static app_t appConfig[] = {
	ENTRYPOINTROW(app_font_browser),
	ENTRYPOINTROW(app_font_viewer),
	ENTRYPOINTROW(app_mockup_helper),
	ENTRYPOINTROW(feature_accel_discs),
	ENTRYPOINTROW(feature_app_logging),
	ENTRYPOINTROW(feature_clock_mode),
	ENTRYPOINTROW(feature_custom_font),
	ENTRYPOINTROW(feature_draw_bitmap),
	ENTRYPOINTROW(feature_draw_bitmap_composite),
	ENTRYPOINTROW(feature_focus_handler),
	ENTRYPOINTROW(feature_gpath),
	ENTRYPOINTROW(feature_image),
	ENTRYPOINTROW(feature_image_transparent),
	ENTRYPOINTROW(feature_inverter_layer),
	ENTRYPOINTROW(feature_layer_data),
	ENTRYPOINTROW(feature_menu_layer),
	ENTRYPOINTROW(feature_persist_counter),
	ENTRYPOINTROW(feature_property_animation),
	ENTRYPOINTROW(feature_scroll_layer),
	ENTRYPOINTROW(feature_simple_menu_layer),
	ENTRYPOINTROW(feature_stdlib),
	ENTRYPOINTROW(feature_text_alignment),
	ENTRYPOINTROW(feature_text_draw),
	ENTRYPOINTROW(feature_timer),
	ENTRYPOINTROW(feature_timer_animation),
	ENTRYPOINTROW(feature_vibe),
	ENTRYPOINTROW(feature_vibe_custom),
	ENTRYPOINTROW(pebble_arcade),

	ENTRYPOINTROW(big_time),
	ENTRYPOINTROW(classio),
	ENTRYPOINTROW(classio_battery_connection),
	ENTRYPOINTROW(drop_zone),
	ENTRYPOINTROW(fuzzy_time),
	ENTRYPOINTROW(just_a_bit),
	ENTRYPOINTROW(ninety_one_dub),
	ENTRYPOINTROW(onthebutton),
	ENTRYPOINTROW(rumbletime),
	ENTRYPOINTROW(segment_six),
	ENTRYPOINTROW(simple_analog),
	ENTRYPOINTROW(simplicity),
	ENTRYPOINTROW(tic_tock_toe),
};

	


static char* appNames[] = {
	"Font Browser",
	"Font Viewer",
	"Mockup Helper",
	"Accel Discs",
	"App Logging",
	"Clock Mode",
	"Custom Font",
	"Draw Bitmap",
	"Draw Bitmap Composite",
	"Focus Handler",
	"Gpath",
	"Image",
	"Image Transparent",
	"Inverter Layer",
	"Layer Data",
	"Menu Layer",
	"Persist Counter",
	"Property Animation",
	"Scroll Layer",
	"Simple Menu Layer",
	"Stdlib",
	"Text Alignment",
	"Text Draw",
	"Timer",
	"Timer Animation",
	"Vibe",
	"Vibe Custom",
	"Pebble Arcade",

	"big_time",
	"classio",
	"classio-battery-connection",
	"drop_zone",
	"fuzzy_time",
	"just_a_bit",
	"ninety_one_dub",
	"onthebutton",
	"rumbletime",
	"segment_six",
	"simple_analog",
	"simplicity",
	"tic_tock_toe",

};