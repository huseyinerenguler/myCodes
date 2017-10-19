#include "xiaomi_mi_6.h"

Xiaomi_Mi_6::Xiaomi_Mi_6()
{
	Smart_Phone();
	
	name = "Xiaomi Mi 6";
	
   	screen.size = 5.15;
    screen.resolution = "FHD";
	screen.intensity = 428;
	screen.technology = "IPS LCD";
	screen.ratio = 71.45;
	screen.durability = "Corning Gorilla Glass 4";

	battery.capacity = 3350;
	battery.charging = "USB Type-C";
	battery.changeable = false;

	hardware.chipset = "Qualcomm Snapdragon 835 MSM8998";
	hardware.main_processor = "Quad-Core 2.45 GHz Kryo 280";
	hardware.second_processor = "Quad-Core 1.9 GHz Kryo 280";
	hardware.core = 8;
	hardware.graphics_processor = "Adreno 540";
	hardware.GPU_frequency = 653;
	hardware.memory = 6;
	hardware.memory_type = "LPDDR4x";
	hardware.storage = 64;
	hardware.storage_support = false;

	camera.first_rear_camera_resolution = 12;
	camera.first_rear_aperture = 1.8;
	camera.second_rear_camera_resolution = 12;
	camera.second_rear_aperture = 2.6;
	camera.front_camera_resolution = 8;
	camera.front_aperture = 1.8;

	design.length = 145.17;
	design.width = 70.49;
	design.thickness = 7.45;
	design.weight = 168;

	features.water_resistance = true;
	features.dust_resistance = false;
	features.fingerprint = true;
}
