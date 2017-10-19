#include "lg_g6.h"

LG_G6::LG_G6()
{
	Smart_Phone();
	
	name = "LG G6";
	
    screen.size = 5.7;
    screen.resolution = "QHD+";
	screen.intensity = 564;
	screen.technology = "IPS LCD";
	screen.ratio = 78.32;
	screen.durability = "Corning Gorilla Glass 3";

	battery.capacity = 3300;
	battery.charging = "USB Type-C";
	battery.changeable = false;

	hardware.chipset = "Qualcomm Snapdragon 821 MSM8996 Pro";
	hardware.main_processor = "Dual-Core 2.35 GHz Kryo";
	hardware.second_processor = "Dual-Core 1.6 GHz Kryo";
	hardware.core = 4;
	hardware.graphics_processor = "Adreno 530";
	hardware.GPU_frequency = 653;
	hardware.memory = 4;
	hardware.memory_type = "LPDDR4";
	hardware.storage = 32;
	hardware.storage_support = true;

	camera.first_rear_camera_resolution = 13;
	camera.first_rear_aperture = 1.8;
	camera.second_rear_camera_resolution = 13;
	camera.second_rear_aperture = 2.4;
	camera.front_camera_resolution = 5;
	camera.front_aperture = 2.2;

	design.length = 148.9;
	design.width = 71.9;
	design.thickness = 7.9;
	design.weight = 163;

	features.water_resistance = true;
	features.dust_resistance = true;
	features.fingerprint = true;
}
