#pragma once
#ifndef GLOBALS
#define GLOBALS

enum class  GameMode
{
	Gameplay
};
const static int TILE_WIDTH = 10;

const static int SCREEN_WIDTH = TILE_WIDTH * 30;
const static int SCREEN_HEIGHT = TILE_WIDTH * 30;
const static int MS_PER_UPDATE = 10;

//int Rows;
const static float PI = 3.14159265359;
float const DEG_TO_RAD = PI / 180.0f;
float const RAD_TO_DEG = 180.0f / PI;

#endif