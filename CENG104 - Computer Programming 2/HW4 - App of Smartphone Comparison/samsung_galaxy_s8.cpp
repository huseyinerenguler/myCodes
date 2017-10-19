#include "samsung_galaxy_s8.h"

Samsung_Galaxy_S8::Samsung_Galaxy_S8()
{
	Smart_Phone();
	
	name = "Samsung Galaxy S8";
	
	screen.size = 5.8;
    screen.resolution = "QHD+";
	screen.intensity = 570;
	screen.technology = "Super AMOLED";
	screen.ratio = 84.2;
	screen.durability = "Corning Gorilla Glass 5";

	battery.capacity = 3000;
	battery.charging = "USB Type-C";
	battery.changeable = false;

	hardware.chipset = "Samsung Exynos 9 Octa 8895";
	hardware.main_processor = "Quad-Core 2.3 GHz Exynos M2";
	hardware.second_processor = "Quad-Core 1.7 GHz ARM Cortex-A53";
	hardware.core = 8;
	hardware.graphics_processor = "Mali-G71 MP20";
	hardware.GPU_frequency = 550;
	hardware.memory = 4;
	hardware.memory_type = "LPDDR4x";
	hardware.storage = 64;
	hardware.storage_support = true;

	camera.first_rear_camera_resolution = 12;
	camera.first_rear_aperture = 1.7;
	camera.second_rear_camera_resolution = 0;
	camera.second_rear_aperture = 0;
	camera.front_camera_resolution = 8;
	camera.front_aperture = 1.7;

	design.length = 148.9;
	design.width = 68.1;
	design.thickness = 8;
	design.weight = 155;

	features.water_resistance = true;
	features.dust_resistance = true;
	features.fingerprint = true;
}
