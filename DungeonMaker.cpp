#include <iostream>
#include "Room.h"
#include "string"
#include <vector>
#include <sstream>
int main()
{
	bool crRoom = true;
	std::string truf;
	int sWidth;
	int sHeight;
	int index = 0;
	int placeInFor = 0;
	bool roomSpace = false;
	std::vector <int> roomHoles;
	std::string roomCoords;
	std::vector <Room> rooms;
	std::vector <std::string> cont;
    //std::cout << "Hello World!\n";
	std::cout << "Welcome to dungeonMaker\n";
	std::cout << "What will the size off your canvas be?\n";
    std::cout << "\nEnter canvas width\n";
	std::cin >> sWidth;
    std::cout << "Enter canvas Height\n";
	std::cin >> sHeight;
	std::cout << std::to_string(sWidth) + ", " + std::to_string(sHeight);
	while (crRoom) {
		std::cout << "\n/-------------------------------------/";
		std::cout << "\n\n1. Create a Room\n";
		std::cout << "2. View Rooms\n";
		std::cout << "3. Draw Dungeon\n";
		std::cin >> truf;
		if (truf == "no") {
			crRoom = false;
		}
		if (truf == "1") {
			std::cout << "Type: x,y,width,height\n";
			std::cin >> roomCoords;
			std::string delimiter = ",";
			std::stringstream ss(roomCoords);
			std::string token;
			cont.clear();
			while (std::getline(ss, token, ',')) {
				cont.push_back(token);
			}
			rooms.push_back(Room(stoi(cont[0]), stoi(cont[1]), stoi(cont[2]), stoi(cont[3])));
		}
		if (truf == "2") {
			index = 0;
			for (Room r : rooms) {
				index++;
				std::cout << "Room " + std::to_string(index) + " is: ";
				std::cout << std::to_string(r.getX()) + ", " + std::to_string(r.getY()) +
			    ", " + std::to_string(r.getW()) + ", " + std::to_string(r.getH()) + "\n";
			}
		}
		if (truf == "3") {
			for (int y = 0; y <= sHeight; y++) {
				for (int x = 0; x <= sWidth; x++) {
					placeInFor++;
					for (int xl = 0; xl < rooms.size(); xl++) {
						if (rooms[xl].getX() <= x && rooms[xl].getW() + rooms[xl].getX() > x 
							&& rooms[xl].getY() <= y && rooms[xl].getH() + rooms[xl].getY() > y) {
							//std::cout << std::to_string(placeInFor) + "\n";
							roomHoles.push_back(placeInFor);
						}
					}
				}
			}
			placeInFor = 0;
			for (int y = 0; y <= sHeight; y++) {
				for (int x = 0; x <= sWidth; x++) {
					placeInFor++;
					roomSpace = false;
					for (int i = 0; i < roomHoles.size(); i++) {
						if (placeInFor == roomHoles[i]) {
							std::cout << "  ";
							i = roomHoles.size();
							roomSpace = true;
						}
					}
					if (!roomSpace) {
						std::cout << "X ";
					}
					if (x == sWidth) {
						std::cout << "\n";
					}
				}
			}
			placeInFor = 0;
			roomHoles.clear();
		}
	}
}