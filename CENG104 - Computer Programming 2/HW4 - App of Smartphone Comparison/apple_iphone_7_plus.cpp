#include "apple_iphone_7_plus.h"

Apple_iPhone_7_Plus::Apple_iPhone_7_Plus()
{
	Smart_Phone();
	
	name = "Apple iPhone 7 Plus";
	
   	screen.size = 5.5;
    screen.resolution = "FHD";
	screen.intensity = 401;
	screen.technology = "IPS LCD";
	screen.ratio = 67.67;
	screen.durability = "Corning Gorilla Glass 4";

	battery.capacity = 2900;
	battery.charging = "Lightning";
	battery.changeable = false;

	hardware.chipset = "Apple A10 Fusion";
	hardware.main_processor = "Quad-Core 2.34 GHz ARM v8-A";
	hardware.second_processor = "M10 Motion Processor";
	hardware.core = 4;
	hardware.graphics_processor = "Hexa-Core PowerVR Series7XT Plus";
	hardware.GPU_frequency = 0;
	hardware.memory = 3;
	hardware.memory_type = "LPDDR4";
	hardware.storage = 32;
	hardware.storage_support = false;

	camera.first_rear_camera_resolution = 12;
	camera.first_rear_aperture = 1.8;
	camera.second_rear_camera_resolution = 12;
	camera.second_rear_aperture = 2.8;
	camera.front_camera_resolution = 7;
	camera.front_aperture = 2.2;

	design.length = 158.2;
	design.width = 77.9;
	design.thickness = 7.3;
	design.weight = 188;

	features.water_resistance = true;
	features.dust_resistance = true;
	features.fingerprint = true;
}
