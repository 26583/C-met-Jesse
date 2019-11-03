#pragma once
class Room
{
public:
	Room(int aX,int aY,int aWidth,int aHeight);
	~Room();
	int getX();
	int getY();
	int getW();
	int getH();

private:
	int x;
	int y;
	int width;
	int height;
};

