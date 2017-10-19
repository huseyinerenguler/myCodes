#ifndef SMART_PHONE_H
#define SMART_PHONE_H

#include <string>
using namespace std;

class Smart_Phone {
public:
	string name;
	
	class Screen {
    public:
        double size; // screen size (inches)
        string resolution; // display resolution (HD, FHD, QHD..)
        int intensity; // pixel intensity (PPI)
        string technology; // display technology (IPS, SuperAmoled..)
        double ratio; // screen-body ratio (%70, %80..)
        string durability; // display durability (Corning Gorilla Glass 4..)
    };
    class Battery {
    public:
        int capacity; // battery capacity (mAh)
        string charging; // charging technology (Micro USB, USB Type-C..)
        bool changeable; // changed battery (true, false)
    };
    class Hardware {
    public:
        string chipset; // chipset
        string main_processor; // CPU
		string second_processor; // second CPU
        int core; // CPU core
        string graphics_processor; // GPU
        double GPU_frequency; // GPU frequency (MHz)
        double memory; // random access memory (GB)
        string memory_type; // RAM type (DDR3, DDR4..)
        int storage; // internal storage (GB)
        bool storage_support; // memory card support (true, false)
    };
    class Camera {
    public:
        double first_rear_camera_resolution; // first rear camera resolution (MP)
        double first_rear_aperture; // first rear camera aperture clearance (F1.7, F1.8..)
        double second_rear_camera_resolution; // second rear camera resolution (MP)
        double second_rear_aperture; // second rear camera aperture clearance (F1.7, F1.8..)
        double front_camera_resolution; // front camera resolution (MP)
        double front_aperture; // front camera aperture clearance (F1.7, F1.8..)
    };
    class Design {
    public:
        double length; // length of phone (mm)
        double width; // width of phone (mm)
        double thickness; // thickness of phone (mm)
        double weight; // weight of phone (grams)
    };
    class Features {
    public:
        bool water_resistance; // water resistance (true, false)
        bool dust_resistance; // dust resistance (true, false)
        bool fingerprint; // fingerprint reader (true, false)
    };
    
	Screen screen;
    Battery battery;
    Hardware hardware;
    Camera camera;
    Design design;
    Features features;
};
#endif
