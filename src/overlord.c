// Overlord.c is the Overlay loader for pebble watch
// By Ron Ravid and Gregoire Sage

#include "pebble.h"
#include "overlord.h"
#include "pebble_process_info.h"

extern const PebbleProcessInfo __pbl_app_info;
extern unsigned long _ovly_table[][2];

uint8_t * OVL_P = NULL;  //pointer to start of overlay area

int overlay_load(OverlayId overlay)
{
 	if (OVL_P == NULL){
 		OVL_P = (void *) & __pbl_app_info;
		OVL_P+=0x84;
 	}
	
	int size = resource_load_byte_range(resource_get_handle(RESOURCE_ID_OVL_FULL), _ovly_table[overlay][0], OVL_P, _ovly_table[overlay][1]);
	return size;
}
