/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */

	void drawBox(int x, int y, int r, int g, int b);
	void KeepAtBoundaries(int* ptrx, int* ptry);
	void drawReticle(int x, int y, int r, int g, int b);
	bool isOverlaped(int x, int y, int x_1, int y_2);

	/********************************/

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	bool upKey = false;
	bool rightKey = false;
	bool downKey = false;
	bool leftKey = false;
	bool Ctrl = false;
	bool shapeIsChanged = false;

	int vx = 0;
	int vy = 0;

	int x = 400;
	int y = 300;

	const int x_2 = 500;
	const int y_2 = 400;

	int* ptrx = &x;
	int* ptry = &y;

	bool inhibitRight = false;
	bool inhibitLeft= false;
	bool inhibitUp = false;
	bool inhibitDown = false;




	int  c = 255;
	int b = 255;
	int g = 255;



	/********************************/
};