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
	downKey = wnd.kbd.KeyIsPressed(VK_DOWN);
	rightKey = wnd.kbd.KeyIsPressed(VK_RIGHT);
	leftKey = wnd.kbd.KeyIsPressed(VK_LEFT);
	Ctrl = wnd.kbd.KeyIsPressed(VK_CONTROL);
	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
	c = 255;

	x = vx + x;
	y = vy + y;
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
		if (inhibitUp)
		{
			// Do nothing
		}

		else
		{
			inhibitUp = true;
			vy--;

		}


	}

	else
	{
		inhibitUp = false;
	}

	if (downKey)
	{
		if (inhibitDown)
		{
			// Do nothing.
		}
		else
		{
			inhibitDown = true;
			vy++;
		}
	}

	else
	{
		inhibitDown = false;
	}

	if (rightKey)
	{



		if (inhibitRight)
		{
			// Do nothing
		}
		else
		{
			inhibitRight = true;
			vx++;
		}

	}

	else
	{
		inhibitRight = false;

	}



	if (leftKey)
	{
		if (inhibitLeft)
		{
			// Do nothing
		}

		else
		{
			inhibitLeft = true;
			vx--;
		}

	}
	else
	{
		inhibitLeft = false;
	}

	// Setting X-boundaries for the Cursor. 

	if (x + 5 > gfx.ScreenWidth - 10)
	{
		x = gfx.ScreenWidth - 15;
		vx = 0;
		

	}


	
	if (x - 5 <= 0)
	{
		x = 6;
		vx = 0;
		
	}

	// Setting Y-boundaries for the Cursor.

	if (y + 12 > gfx.ScreenHeight -10)
	{
		vy = 0;
		y = gfx.ScreenHeight - 22;
	}

	if (y - 5 < 10)
	{
		vy = 0;
		y = 11;
	}

	/*

	if ((x >= 200 && x <= 400))
	{
		if (y >= 200 && y <= 250)
		{
			shapeIsChanged = true;
		}
	}
	*/
	

	if ((x > 200 && x < 400) && (y > 100 && y < 350))
	{
		shapeIsChanged = true;
		c = 0;
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

void Game::ComposeFrame()
{

	


	
	
		if (shapeIsChanged) {



			gfx.PutPixel(x + 5, y + 5, c, 255, b);
			gfx.PutPixel(x + 6, y + 6, c, 255, b);
			gfx.PutPixel(x + 7, y + 7, c, 255, b);
			gfx.PutPixel(x + 8, y + 8, c, 255, b);
			gfx.PutPixel(x + 9, y + 9, c, 255, b);
			gfx.PutPixel(x + 10, y + 10, c, 255, b);
			gfx.PutPixel(x + 11, y + 11, c, 255, b);
			gfx.PutPixel(x + 12, y + 12, c, 255, b);
			gfx.PutPixel(x + 12, y + 5, c, 255, b);
			gfx.PutPixel(x + 11, y + 6, c, 255, b);
			gfx.PutPixel(x + 10, y + 7, c, 255, b);
			gfx.PutPixel(x + 9, y + 8, c, 255, b);
			gfx.PutPixel(x + 8, y + 9, c, 255, b);
			gfx.PutPixel(x + 7, y + 10, c, 255, b);
			gfx.PutPixel(x + 6, y + 11, c, 255, b);
			gfx.PutPixel(x + 5, y + 12, c, 255, b);
			gfx.PutPixel(x + 8, y + 5, c, 255, b);
			gfx.PutPixel(x + 8, y + 6, c, 255, b);
			gfx.PutPixel(x + 8, y + 7, c, 255, b);
			gfx.PutPixel(x + 8, y + 8, c, 255, b);
			gfx.PutPixel(x + 8, y + 9, c, 255, b);
			gfx.PutPixel(x + 8, y + 10, c, 255, b);
			gfx.PutPixel(x + 8, y + 11, c, 255, b);
			gfx.PutPixel(x + 8, y + 12, c, 255, b);
			gfx.PutPixel(x + 5, y + 8, c, 255, b);
			gfx.PutPixel(x + 6, y + 8, c, 255, b);
			gfx.PutPixel(x + 7, y + 8, c, 255, b);
			gfx.PutPixel(x + 8, y + 8, c, 255, b);
			gfx.PutPixel(x + 9, y + 8, c, 255, b);
			gfx.PutPixel(x + 10, y + 8, c, 255, b);
			gfx.PutPixel(x + 11, y + 8, c, 255, b);
			gfx.PutPixel(x + 12, y + 8, c, 255, b);










		}

		else 
		{


			drawReticle(x, y, c, 255, b);


		}
	



}