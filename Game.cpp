/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it u\nder the terms of the GNU General Public License as published by				  *
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
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

	upKey = wnd.kbd.KeyIsPressed(VK_UP);
	leftKey = wnd.kbd.KeyIsPressed(VK_LEFT);
	downKey = wnd.kbd.KeyIsPressed(VK_DOWN);
	rightKey = wnd.kbd.KeyIsPressed(VK_RIGHT);
	Ctrl = wnd.kbd.KeyIsPressed(VK_CONTROL);
	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
	

	// Update cursor position with the velocity.

	if (Ctrl)
	{
		vx = 0;
		vy = 0;

	}


	// Cursor Logic,
	// Inhibition system to prevent Cursor from moving when Key is held.

	if (upKey)
	{
		
		
		
			y = y - 1;

		


	}


	if (downKey)
	{
		
		
			
			y = y + 1;
		
	}



	if (rightKey)
	{

			x = x + 1;
		

	}


	if (leftKey)
	{
		
			x = x - 1;
		
	}
	
	/*
	if ((x > 200 && x < 400) && (y > 100 && y < 350))
	{
		shapeIsChanged = true;
		c = 0;
	}
	*/



	if (isOverlaped(x, y, x_2, y_2))
	{
		g = 0;
		b = 0;
	}


}

void Game::drawBox(int x, int y, int r, int g, int b)
{

	
		gfx.PutPixel(-5 + x, -5 + y, r, g, b);
		gfx.PutPixel(-5 + x, -4 + y, r, g, b);
		gfx.PutPixel(-5 + x, -3 + y, r, g, b);
		gfx.PutPixel(-4 + x, -5 + y, r, g, b);
		gfx.PutPixel(-3 + x, -5 + y, r, g, b);
		gfx.PutPixel(-5 + x, 5 + y, r, g, b);
		gfx.PutPixel(-5 + x, 4 + y, r, g, b);
		gfx.PutPixel(-5 + x, 3 + y, r, g, b);
		gfx.PutPixel(-4 + x, 5 + y, r, g, b);
		gfx.PutPixel(-3 + x, 5 + y, r, g, b);
		gfx.PutPixel(5 + x, -5 + y, r, g, b);
		gfx.PutPixel(5 + x, -4 + y, r, g, b);
		gfx.PutPixel(5 + x, -3 + y, r, g, b);
		gfx.PutPixel(4 + x, -5 + y, r, g, b);
		gfx.PutPixel(3 + x, -5 + y, r, g, b);
		gfx.PutPixel(5 + x, 5 + y, r, g, b);
		gfx.PutPixel(5 + x, 4 + y, r, g, b);
		gfx.PutPixel(5 + x, 3 + y, r, g, b);
		gfx.PutPixel(4 + x, 5 + y, r, g, b);
		gfx.PutPixel(3 + x, 5 + y, r, g, b);
	

}

void Game::KeepAtBoundaries(int* ptrx, int* ptry)
{


	int right = *ptrx + 5;
	int left = *ptrx + -5;
	int up = *ptry + -5;
	int down = *ptry + 5;

	// Setting X-boundaries for the Cursor. 

	if ( right >= gfx.ScreenWidth - 5)
	{
		*ptrx = gfx.ScreenWidth - 10;
		


	}



	else if (left <= 0)
	{
		*ptrx = 10;
		

	}

	// Setting Y-boundaries for the Cursor.

	if (down > gfx.ScreenHeight - 5)
	{
		*ptry = gfx.ScreenHeight - 10;
	
	}

	else if (up < 0)
	{
		*ptry = 6;
		
	}
}

void Game::drawReticle(int x, int y, int r, int g, int b)
{

	gfx.PutPixel(x + -5, y, r, g, b);
	gfx.PutPixel(x + -4, y, r, g, b);
	gfx.PutPixel(x + -3, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);
	gfx.PutPixel(x + 5, y, r, g, b);


	gfx.PutPixel(x, y + -5, r, g, b);
	gfx.PutPixel(x, y + -4, r, g, b);
	gfx.PutPixel(x, y + -3, r, g, b);
	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x, y + 5, r, g, b);

}

bool Game::isOverlaped(int x, int y, int x_1, int y_2)
{


	return (x + 5 >= x_2 - 5 && x -5 <= x_2 + 5 && y + 5 >= y_2 - 5 && y - 5 <= y_2 + 5);
	
 
}


void Game::ComposeFrame()
{

	

		
	
		if (shapeIsChanged) {


			drawBox(x, y, c, 255, b);


		}

		else 
		{


			drawBox(x, y, c, g, b);


		}
	
	KeepAtBoundaries(ptrx, ptry);


		drawBox(x_2, y_2, 255, 255, 255);
}