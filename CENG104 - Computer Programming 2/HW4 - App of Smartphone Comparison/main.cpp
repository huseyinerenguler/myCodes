#include <iostream>
#include <conio.h>

#include "samsung_galaxy_s8.h"
#include "apple_iphone_7_plus.h"
#include "xiaomi_mi_6.h"
#include "lg_g6.h"

using namespace std;

/********** Function Prototype **********/
void gotoxy(int x,int y){printf("%c[%d;%df", 0x1B, y, x);}
void show_phone_list(void);
void compare(Smart_Phone *, Smart_Phone *);
void draw_table(void);
void show_phone_details(Smart_Phone *, int);
/****************************************/

int main () 
{
	Samsung_Galaxy_S8 samsung_galaxy_s8;
	Apple_iPhone_7_Plus apple_iphone_7_plus;
	Xiaomi_Mi_6 xiaomi_mi_6;
	LG_G6 lg_g6;
	
	while (1)
	{
		show_phone_list();
		int first,second; cin >> first >> second;
	
		Smart_Phone *phone1, *phone2;
	
		if (first == 1) phone1 = &samsung_galaxy_s8;
		else if (first == 2) phone1 = &xiaomi_mi_6;
		else if (first == 3) phone1 = &apple_iphone_7_plus;
		else if (first == 4) phone1 = &lg_g6;
	
		if (second == 1) phone2 = &samsung_galaxy_s8;
		else if (second == 2) phone2 = &xiaomi_mi_6;
		else if (second == 3) phone2 = &apple_iphone_7_plus;
		else if (second == 4) phone2 = &lg_g6;
	
		compare(phone1,phone2);
		
		cout << "\n\n\nDo you want a make another comparison (Y/N) ? ";
		char choice; cin >> choice;
		if(choice == 'N' || choice == 'n') return 0;
		system("cls");
	}
    return 0;
}

void show_phone_list(void) 
{
	cout << "1) Samsung Galaxy S8" << endl;
	cout << "2) Xiaomi Mi 6" << endl;
	cout << "3) Apple iPhone 7 Plus" << endl;
	cout << "4) LG G6" << endl;
	cout << "\nSelect 2 phones to compare: ";
}

void compare(Smart_Phone *phone1, Smart_Phone *phone2) 
{
	draw_table();
	show_phone_details(phone1,1);
	show_phone_details(phone2,2);
}

void draw_table(void) 
{
	system("cls");
	int x = 4, y = 4;
	
	gotoxy(x-4,y-1); cout << "_____________________________________________________________________________________________________________";
	
	gotoxy(x-4,y+0); cout << "SCREEN";
	gotoxy(x,y+1); cout << "Size";
	gotoxy(x,y+2); cout << "Resolution";
	gotoxy(x,y+3); cout << "Intensity";
	gotoxy(x,y+4); cout << "Technology";
	gotoxy(x,y+5); cout << "Screen/Body Ratio";
	gotoxy(x,y+6); cout << "Durability";
	gotoxy(x-4,y+7); cout << "_____________________________________________________________________________________________________________";
	
	gotoxy(x-4,y+8); cout << "BATTERY";
	gotoxy(x,y+9); cout << "Capacity";
	gotoxy(x,y+10); cout << "Technology";
	gotoxy(x,y+11); cout << "Changeable";
	gotoxy(x-4,y+12); cout << "_____________________________________________________________________________________________________________";
	
	gotoxy(x-4,y+13); cout << "HARDWARE";
	gotoxy(x,y+14); cout << "Chipset";
	gotoxy(x,y+15); cout << "Main Processor";
	gotoxy(x,y+16); cout << "Second Processor";
	gotoxy(x,y+17); cout << "CPU Core";
	gotoxy(x,y+18); cout << "Graphics Processor";
	gotoxy(x,y+19); cout << "GPU Frequency";
	gotoxy(x,y+20); cout << "Memory";
	gotoxy(x,y+21); cout << "Memory Type";
	gotoxy(x,y+22); cout << "Storage Capacity";
	gotoxy(x,y+23); cout << "Storage Support";
	gotoxy(x-4,y+24); cout << "_____________________________________________________________________________________________________________";
	
	gotoxy(x-4,y+25); cout << "CAMERA";
	gotoxy(x,y+26); cout << "1. Rear Camera Resolution";
	gotoxy(x,y+27); cout << "1. Rear Camera Aperture";
	gotoxy(x,y+28); cout << "2. Rear Camera Resolution";
	gotoxy(x,y+29); cout << "2. Rear Camera Aperture";
	gotoxy(x,y+30); cout << "Front Camera Resolution";
	gotoxy(x,y+31); cout << "Front Camera Aperture";
	gotoxy(x-4,y+32); cout << "_____________________________________________________________________________________________________________";
	
	gotoxy(x-4,y+33); cout << "DESIGN";
	gotoxy(x,y+34); cout << "Length";
	gotoxy(x,y+35); cout << "Width";
	gotoxy(x,y+36); cout << "Thickness";
	gotoxy(x,y+37); cout << "Weight";
	gotoxy(x-4,y+38); cout << "_____________________________________________________________________________________________________________";

	gotoxy(x-4,y+39); cout << "FEATURES";
	gotoxy(x,y+40); cout << "Water Resistance";
	gotoxy(x,y+41); cout << "Dust Resistance";
	gotoxy(x,y+42); cout << "Fingerprint Sensor";
	gotoxy(x-4,y+43); cout << "_____________________________________________________________________________________________________________";
	
	for(int k = 0; k < 44; k++) {
		gotoxy(32,k+4); cout << "|";
		gotoxy(71,k+4); cout << "|";
		gotoxy(109,k+4); cout << "|";
	}
}

void show_phone_details(Smart_Phone *phone, int k)
{
	int x = (k == 2) ? 73 : 35;
	int y = 4;
	
	gotoxy(x,y-2); cout << phone->name;
	
	gotoxy(x,y+1); cout << phone->screen.size << " inches";
	gotoxy(x,y+2); cout << phone->screen.resolution;
	gotoxy(x,y+3); cout << phone->screen.intensity << " PPI";
	gotoxy(x,y+4); cout << phone->screen.technology;
	gotoxy(x,y+5); cout << "% " << phone->screen.ratio;
	gotoxy(x,y+6); cout << phone->screen.durability;
	
	gotoxy(x,y+9); cout << phone->battery.capacity << " mAh";
	gotoxy(x,y+10); cout << phone->battery.charging;
	gotoxy(x,y+11); (phone->battery.changeable) ? cout<<"Yes" : cout<<"No";
	
	gotoxy(x,y+14); cout << phone->hardware.chipset;
	gotoxy(x,y+15); cout << phone->hardware.main_processor;
	gotoxy(x,y+16); cout << phone->hardware.second_processor;
	gotoxy(x,y+17); cout << phone->hardware.core;
	gotoxy(x,y+18); cout << phone->hardware.graphics_processor;
	gotoxy(x,y+19); cout << phone->hardware.GPU_frequency << " MHz";
	gotoxy(x,y+20); cout << phone->hardware.memory << " GB";
	gotoxy(x,y+21); cout << phone->hardware.memory_type;
	gotoxy(x,y+22); cout << phone->hardware.storage << " GB";
	gotoxy(x,y+23); (phone->hardware.storage_support) ? cout<<"Yes" : cout<<"No";
	
	gotoxy(x,y+26); cout << phone->camera.first_rear_camera_resolution << " MP";
	gotoxy(x,y+27); cout << "F" << phone->camera.first_rear_aperture;
	
	gotoxy(x,y+28);
	if(phone->camera.second_rear_camera_resolution!=0)
		cout << phone->camera.second_rear_camera_resolution << " MP";
	else cout << "No Second Camera";
	
	gotoxy(x,y+29);
	if(phone->camera.second_rear_aperture!=0)
		cout << "F" << phone->camera.second_rear_aperture;
	else cout << "No Second Camera";
	
	gotoxy(x,y+30); cout << phone->camera.front_camera_resolution << " MP";
	gotoxy(x,y+31); cout << "F" << phone->camera.front_aperture;
	
	gotoxy(x,y+34); cout << phone->design.length << " mm";
	gotoxy(x,y+35); cout << phone->design.width << " mm";
	gotoxy(x,y+36); cout << phone->design.thickness << " mm";
	gotoxy(x,y+37); cout << phone->design.weight << " grams";
	
	gotoxy(x,y+40); (phone->features.water_resistance) ? cout<<"Yes" : cout<<"No";
	gotoxy(x,y+41); (phone->features.dust_resistance) ? cout<<"Yes" : cout<<"No";
	gotoxy(x,y+42); (phone->features.fingerprint) ? cout<<"Yes" : cout<<"No";
}
