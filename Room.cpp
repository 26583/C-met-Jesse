#include "Room.h"

Room::Room(int aX, int aY, int aWidth, int aHeight)
{
	x = aX;
	y = aY;
	width = aWidth;
	height = aHeight;
}

Room::~Room()
{
}

int Room::getX() {
	return x;
 }

int Room::getY()
{
	return y;
}

int Room::getW()
{
	return width;
}

int Room::getH()
{
	return height;
}
