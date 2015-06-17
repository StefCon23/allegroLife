//#include<stdio.h>
//#include<allegro.h>
//#include<stdlib.h>
//#include<math.h>
//
////General Allegro game
////
////Pseudo Code:
////	
////	Includes
////	Functions
////
////	Main (void)
////		Initialise: screen, keyboard, mouse
////		int image
////		Main (loop)
////			Break Away (fail safe exit)
////			Clear Screen
////			Update Logic
////			Draw image
////			Refresh screen
//
//BITMAP * backBuffer;
//
//
//struct point
//{
//	float x;
//	float y;
//	float z;
//	//life cells stuff
//	bool state;
//};
//
////////~~~~~~~~~~~~~~~~~~~~FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//void sixShoot(int & r, int & g, int & b)
//{
//	// Colour 6 Shooter
//	//   solid rand colours
//	//   reproduces [respectively]:
//	//      red				0
//	//      green			1
//	//      blue			2
//	//      yellow/orange	3
//	//      purple			4
//	//      turkoise?		5
//	int col;
//	col = rand()%6;
//	if(col == 0)
//	{
//		r = rand() % 256;
//		g = 0;
//		b = 0;
//	}
//	else if(col == 1)
//	{
//		r = 0;
//		g = rand() % 256;
//		b = 0;
//	}
//	else if(col == 2)
//	{
//		r = 0;
//		g = 0;
//		b = rand() % 256;
//	}
//	else if(col == 3)
//	{
//		r = rand() % 256;
//		g = rand() % 256;
//		b = 0;
//	}
//	else if(col == 4)
//	{
//		r = rand() % 256;
//		g = 0;
//		b = rand() % 256;
//	}
//	else if(col == 5)
//	{
//		r = 0;
//		g = rand() % 256;
//		b = rand() % 256;
//	}
//}
//
//float archer(int xOrY, float centerP, float radius, float angle)
//{
//
//	int x;
//
//	float radian=(angle*3.14159265)/180;
//	
//	float differ;
//	differ = xOrY == 0 ? (radius * cos(radian)) : (radius * sin(radian));
//
//	x = centerP + differ;
//
//	return x;
//
//}
//
//void rotate(point realWorld, float angle, char axis, point & rotation)
//{
//	/*
//		rotation function
//	rotates realworld co-ordinates
//	about defined axis (char)
//	by angle
//
//	stores transformation in point projection
//	*/
//
//	while(angle>=360)
//	{
//		angle -= 360;
//	}
//
//	float radian = (angle * 3.14159265) / 180;
//
//	if(axis=='x')
//	{
//		rotation.x = realWorld.x;
//		rotation.y = (realWorld.y * cos(radian)) + (realWorld.z * sin(radian));
//		rotation.z = (realWorld.z * cos(radian)) - (realWorld.y * sin(radian));
//	}
//	else if(axis=='y')
//	{
//		rotation.x = (realWorld.x * cos(radian)) - (realWorld.z * sin(radian));
//		rotation.y = realWorld.y;
//		rotation.z = (realWorld.z * cos(radian)) + (realWorld.x * sin(radian));
//	}
//	else if(axis=='z')
//	{
//		rotation.x = (realWorld.x * cos(radian)) + (realWorld.y * sin(radian));
//		rotation.y = (realWorld.y * cos(radian)) - (realWorld.x * sin(radian));
//		rotation.z = realWorld.z;
//	}
//}
//
//int offset(int x, int y, int z, int xLen, int yLen)
//{
//	int ret;
//
//	ret = (z * yLen * xLen) + (y * xLen) + x;
//
//	return(ret);
//}
//
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//void main()
//{
//	if(allegro_init() != 0)
//	{
//		return;
//	}
//
//	
////////~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	
//	//	width and height
//	int w = 900;
//	int h = 900;
//	
//	//	button
//	float buttonX, buttonY, buttonRadius;
//	int buttonRed, buttonGreen, buttonBlue;
//	bool buttonPress = false;
//
//	//	tickers etc.
//	int i = 0;
//	int j = 0;
//	int k = 0;
//
//	float x = 0;
//	float y = 0;
//	float z = 0;
//
//	//	cursor colour
//	int cursorRed = 0;
//	int cursorGreen = 255;
//	int cursorBlue = 0;
//
//
//
//	/*int xlen = 90;
//	int ylen = 90;
//	int zlen = 90;
//	float cellR = 5;*/
//
//	int length = 21;
//	int xlen = length;
//	int ylen = length;
//	int zlen = length;
//	//float cellR = (w / xlen) / 2;
//	float cellR = 10;
//
//	float centerer = (w - ((cellR * 2) * xlen)) / 2;
//	
//
//
//	//	3d array test
//	point * cells3d = (point*)malloc(xlen*ylen*zlen*sizeof(point));
//	point * cells3doriginal = (point*)malloc(xlen*ylen*zlen*sizeof(point));
//	bool * cells3dnext = (bool*)malloc(xlen*ylen*zlen*sizeof(bool));
//
//	point * jelly = (point*)malloc(xlen*ylen*zlen*sizeof(point));
//
//	int pos = 0;
//
//	//z = cellR;
//	z = cellR - (w/2) + centerer;
//	i = 0;
//	while(i<zlen)
//	{
//		//y = cellR;
//		y = cellR - (h/2) + centerer;
//		j = 0;
//		while(j<ylen)
//		{
//			//x = cellR;
//			x = cellR - (w/2) + centerer;
//			k = 0;
//			while(k<xlen)
//			{
//
//				pos = offset(k, j, i, xlen, ylen);
//				
//				cells3d[pos].x = x;
//				cells3d[pos].y = y;
//				cells3d[pos].z = z;
//				cells3d[pos].state = false;
//
//				cells3doriginal[pos].x = x;
//				cells3doriginal[pos].y = y;
//				cells3doriginal[pos].z = z;
//				cells3doriginal[pos].state = false;
//
//				cells3dnext[pos] = false;
//
//				x += 2 * cellR;
//				k ++;
//			}
//			y += 2 * cellR;
//			j ++;
//		}
//		z += 2 * cellR;
//		i ++;
//	}
//
//
//	bool menu = false;
//	bool grid = true;
//	bool dots = true;
//	bool colours = false;
//
//	bool edit = false;
//	bool play = false;
//
//	point angle = {0, 0, 0};
//	float speed = 1;
//
//	bool click = false;
//	float mx, my, mx2, my2;
//
//	int neighbours = 0;
//	bool mid = true;
//
//	int live1 = 2;
//	int live2 = 3;
//	int born1 = 3;
//	int born2 = 3;
//
//	point dotCol = {0, 255, 0};
//
//	point cellCol = {255, 255, 255};
//
//	int delboy = 0;
//	//int rodney = 100;
//	int rodney = 10;
//
//	bool presets = false;
//
//	point axis[3];
//	axis[0].x = xlen * 2;
//	axis[0].y = 0;
//	axis[0].z = 0;
//	axis[1].x = 0;
//	axis[1].y = ylen * 2;
//	axis[1].z = 0;
//	axis[2].x = 0;
//	axis[2].y = 0;
//	axis[2].z = zlen * 2;
//	point axisoriginal[3];
//	i = 0;
//	while(i < 3)
//	{
//		axisoriginal[i] = axis[i];
//		i ++;
//	}
//
//	bool madcols = false;
//	bool options = false;
//
//	float a, b, c, d, e, f, m, n, o;
//
//	bool tool = true;
//
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//	//	system
//	set_color_depth(desktop_color_depth());
//	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, w, h, 0, 0) != 0)
//	{
//		return;
//	}
//	//	image
//	backBuffer = create_bitmap(w, h);
//	//	keyboard & mouse
//	install_mouse();
//	install_keyboard();
//	//	main loop
//	bool done = false;
//	while (! done)
//	{
//		//	game exit(on esc)
//		if (key[KEY_ESC])
//		{
//			done = true;
//			break;
//		}
//		//	clear screen
//		clear_to_color(backBuffer, makecol(0, 0, 0));
//
//
////////~~~~~~~~~~~~~~~~~~~~CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//		/*
//		//	Button Template
//		buttonX = w / 2;
//		buttonY = h / 2;
//		buttonRadius = 30;
//		buttonRed = 0;
//		buttonGreen = 0;
//		buttonBlue = 255;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//		//circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//		// y co-ordinates vary in textprint lines
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY - 5, makecol(buttonRed, buttonGreen, buttonBlue), -1, "Button");
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY + 5, makecol(buttonRed, buttonGreen, buttonBlue), -1, "Words");
//		//textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 5), makecol(150, 150, 150), "2 Line");
//		//textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 5), makecol(150, 150, 150), "Title");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				//while mouse is still within button
//				while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//
//				}
//			}
//		}
//		*/
//		
//
//
//		//	grid
//		if(grid)
//		{
//
//			if(dots)
//			{
//
//				i = 0;
//				while(i < zlen)
//				{
//					j = 0;
//					while(j < ylen)
//					{
//						k = 0;
//						while(k < xlen)
//						{
//							pos = offset(k, j, i, xlen, ylen);
//
//							putpixel(backBuffer, w/2 + cells3d[pos].x, h/2 + cells3d[pos].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//
//							k ++;
//						}
//						j ++;
//					}
//					i ++;
//				}
//
//			}
//			else
//			{
//
//				int pos2;
//
//				i = 0;
//				while(i < xlen)
//				{
//					j = 0;
//					while(j < ylen)
//					{
//
//						//	x direction
//						pos = offset(0, j, i, xlen, ylen);
//						pos2 = offset(xlen - 1, j, i, xlen, ylen);
//						line(backBuffer, (w/2) + cells3d[pos].x - cellR, (h/2) + cells3d[pos].y - cellR, (w/2) + cells3d[pos2].x + cellR, (h/2) + cells3d[pos2].y - cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//						if(j == ylen - 1)
//						{
//							line(backBuffer, (w/2) + cells3d[pos].x - cellR, (h/2) + cells3d[pos].y + cellR, (w/2) + cells3d[pos2].x + cellR, (h/2) + cells3d[pos2].y + cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//						}
//
//						//	y direction
//						pos = offset(j, 0, i, xlen, ylen);
//						pos2 = offset(j, xlen - 1, i, xlen, ylen);
//						line(backBuffer, (w/2) + cells3d[pos].x - cellR, (h/2) + cells3d[pos].y - cellR, (w/2) + cells3d[pos2].x - cellR, (h/2) + cells3d[pos2].y + cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//						if(j == ylen - 1)
//						{
//							line(backBuffer, (w/2) + cells3d[pos].x + cellR, (h/2) + cells3d[pos].y - cellR, (w/2) + cells3d[pos2].x + cellR, (h/2) + cells3d[pos2].y + cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//						}
//						
//						//	z direction
//						pos = offset(j, i, 0, xlen, ylen);
//						pos2 = offset(j, i, xlen - 1, xlen, ylen);
//						line(backBuffer, (w/2) + cells3d[pos].x - cellR, (h/2) + cells3d[pos].y - cellR, (w/2) + cells3d[pos2].x - cellR, (h/2) + cells3d[pos2].y - cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//						if(j == ylen - 1)
//						{
//							line(backBuffer, (w/2) + cells3d[pos].x + cellR, (h/2) + cells3d[pos].y - cellR, (w/2) + cells3d[pos2].x + cellR, (h/2) + cells3d[pos2].y - cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//						}
//						if(i == ylen - 1)
//						{
//							line(backBuffer, (w/2) + cells3d[pos].x - cellR, (h/2) + cells3d[pos].y + cellR, (w/2) + cells3d[pos2].x - cellR, (h/2) + cells3d[pos2].y + cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//							if(j == ylen - 1)
//							{
//								line(backBuffer, (w/2) + cells3d[pos].x + cellR, (h/2) + cells3d[pos].y + cellR, (w/2) + cells3d[pos2].x + cellR, (h/2) + cells3d[pos2].y + cellR, makecol(dotCol.x, dotCol.y, dotCol.z));
//							}
//						}
//
//						j ++;
//					}
//
//					i ++;
//				}
//
//
//			}
//
//
//		}
//
//
//
//
//		//		rotation
//
//		//  mose rotation (by click)
//		if(mouse_b&1)
//		{
//			if(!click)
//			{
//				click = true;
//
//				mx2 = mouse_x;
//				my2 = mouse_y;
//			}
//
//			/////// cell selecting TO BE DONE
//
//			if(click)
//			{
//				mx = mouse_x;
//				my = mouse_y;
//				if(mx2 < mx)
//				{
//					angle.y += (mx - mx2) / (1 / speed);
//					/// same as
//					///   (mx - mx2) * speed
//				}
//				else if(mx < mx2)
//				{
//					angle.y -= (mx2 - mx) / (1 / speed);
//				}
//				if(my2 < my)
//				{
//					angle.x -= (my - my2) / (1 / speed);
//				}
//				else if(my < my2)
//				{
//					angle.x += (my2 - my) / (1 / speed);
//				}
//				mx2 = mx;
//				my2 = my;
//			}
//		}
//
//		if(!mouse_b&1)
//		{
//			click = false;
//		}
//
//		if(key[KEY_Q])
//		{
//			angle.x += speed;
//		}
//		if(key[KEY_A])
//		{
//			angle.x -= speed;
//		}
//		if(key[KEY_W])
//		{
//			angle.y += speed;
//		}
//		if(key[KEY_S])
//		{
//			angle.y -= speed;
//		}
//		if(key[KEY_E])
//		{
//			angle.z += speed;
//		}
//		if(key[KEY_D])
//		{
//			angle.z -= speed;
//		}
//		if(key[KEY_SPACE])
//		{
//			if(tool)
//			{
//  				if(play == true)
//				{
//					play = false;
//				}
//				else if(play == false)
//				{
//					play = true;
//				}
//				tool = false;
//			}
//		}
//		if(!key[KEY_SPACE])
//		{
//			tool = true;
//		}
//		if(key[KEY_R])
//		{
//			i = 0;
//			while(i < zlen)
//			{
//				j = 0;
//				while(j < ylen)
//				{
//					k = 0;
//					while(k < xlen)
//					{
//						pos = offset(k, j, i, xlen, ylen);
//						int q;
//						q = rand() % 2;
//						if(q==0)
//						{
//							cells3dnext[pos] = false;
//						}
//						else if(q==1)
//						{
//							cells3dnext[pos] = true;
//						}
//
//						k ++;
//					}
//					j ++;
//				}
//				i ++;
//			}
//		}
//
//
//		//  point rotation
//		i = 0;
//		while(i < zlen)
//		{
//			j = 0;
//			while(j < ylen)
//			{
//				k = 0;
//				while(k < xlen)
//				{
//
//					pos = offset(k, j, i, xlen, ylen);
//					
//					cells3d[pos].x = cells3doriginal[pos].x;
//					cells3d[pos].y = cells3doriginal[pos].y;
//					cells3d[pos].z = cells3doriginal[pos].z;
//					
//					rotate(cells3d[pos], angle.x, 'x', cells3d[pos]);
//					rotate(cells3d[pos], angle.y, 'y', cells3d[pos]);
//					rotate(cells3d[pos], angle.z, 'z', cells3d[pos]);
//
//
//
//					k ++;
//				}
//				j ++;
//			}
//			i ++;
//		}
//
//
//		//tester
//		i = 0;
//		while(i < 3)
//		{
//			
//			axis[i].x = axisoriginal[i].x;
//			axis[i].y = axisoriginal[i].y;
//			axis[i].z = axisoriginal[i].z;
//			
//			rotate(axis[i], angle.x, 'x', axis[i]);
//			rotate(axis[i], angle.y, 'y', axis[i]);
//			rotate(axis[i], angle.z, 'z', axis[i]);
//
//			i ++;
//		}
//
//
//
//
//		//		update logic
//		if(play)
//		{
//			if(delboy % rodney == 0)
//			{
//				i = 0;
//				while(i < zlen)
//				{
//					j = 0;
//					while(j < ylen)
//					{
//						k = 0;
//						while(k < xlen)
//						{
//							neighbours = 0;
//
//							d = -1;
//							e = -1;
//							f = -1;
//
//							m = 2;
//							n = 2;
//							o = 2;
//
//							if(k == 0)
//							{
//								d = 0;
//								m = 2;
//							}
//							else if(k == (zlen - 1))
//							{
//								d = -1;
//								m = 1;
//							}
//
//							if(j == 0)
//							{
//								e = 0;
//								n = 2;
//							}
//							else if(j == (ylen - 1))
//							{
//								e = -1;
//								n = 1;
//							}
//
//							if(i == 0)
//							{
//								f = 0;
//								o = 2;
//							}
//							else if(i == (ylen - 1))
//							{
//								f = -1;
//								o = 1;
//							}
//
//
//							a = d;
//							while(a < m)
//							{
//								b = e;
//								while(b < n)
//								{
//									c = f;
//									while(c < o)
//									{
//
//										if((a==0)&&(b==0)&&(c==0))
//										{
//											//do nothing
//										}
//										else
//										{
//											pos = offset(k + a, j + b, i + c, xlen, ylen);
//											if(cells3d[pos].state == true)
//											{
//												neighbours ++;
//											}
//										}
//
//										c ++;
//									}
//									b ++;
//								}
//								a ++;
//
//
//							}
//
//							//life rules
//  							pos = offset(k, j, i, xlen, ylen);
//							if(cells3d[pos].state == true)
//							{
//								if((neighbours < live1)||(neighbours > live2))
//								{
//									cells3dnext[pos] = false;
//								}
//								else if((neighbours >= live1)&&(neighbours <= live2))
//								{
//									cells3dnext[pos] = true;
//								}
//							}
//							else if(cells3d[pos].state == false)
//							{
//								if((neighbours >= born1)&&(neighbours <= born2))
//								{
//									cells3dnext[pos] = true;
//								}
//								else if((neighbours < born1)||(neighbours > born2))
//								{
//									cells3dnext[pos] = false;
//								}
//							}
//
//							k ++;
//						}
//
//						j ++;
//					}
//
//					i ++;
//				}
//			}
//		}
//
//
//		i = 0;
//		//i = zlen - 1;
//		//while(i >= 0)
//		while(i < zlen)
//		{
//			j = 0;
//			while(j < ylen)
//			{
//				k = 0;
//				while(k < xlen)
//				{
//					pos = offset(k, j, i, xlen, ylen);
//
//					cells3d[pos].state = cells3dnext[pos];
//
//					k ++;
//				}
//				j ++;
//			}
//			//i --;
//			i ++;
//		}
//
//		while(angle.x > 360)
//		{
//			angle.x -= 360;
//		}
//		while(angle.x < 0)
//		{
//			angle.x += 360;
//		}
//		while(angle.y > 360)
//		{
//			angle.y -= 360;
//		}
//		while(angle.y < 0)
//		{
//			angle.y += 360;
//		}
//		while(angle.z > 360)
//		{
//			angle.z -= 360;
//		}
//		while(angle.z < 0)
//		{
//			angle.z += 360;
//		}
//
//
//
//		
//		//draw logic
//
//		//angle work
//		/*
//
//		z:
//		i = d
//		i += m
//
//		y:
//		j = e
//		j += n
//
//		x:
//		k = f
//		k += o
//
//		*/
//
//		if((angle.x >= 0) && (angle.x < 180))
//		{
//			//e = ylen - 1;
//			//n = -1;
//			e = 0;
//			n = 1;
//		}
//		else if((angle.x >= 180) && (angle.x < 360))
//		{
//			//e = 0;
//			//n = 1;
//			e = ylen - 1;
//			n = -1;
//		}
//		if((angle.x >= 90) && (angle.x < 270))
//		{
//			d = 0;
//			m = 1;
//		}
//		else if((angle.x >= 270) || (angle.x < 90))
//		{
//			d = zlen - 1;
//			m = -1;
//		}
//
//		if((angle.y >= 0) && (angle.y < 180))
//		{
//			//f = xlen - 1;
//			//o = -1;
//			f = 0;
//			o = 1;
//		}
//		else if((angle.y >= 180) && (angle.y < 360))
//		{
//			//f = 0;
//			//o = 1;
//			f = xlen - 1;
//			o = -1;
//		}
//		if((angle.y >= 90) && (angle.y < 270))
//		{
//			d = 0;
//			m = 1;
//		}
//		else if((angle.y >= 270) || (angle.y < 90))
//		{
//			d = zlen - 1;
//			m = -1;
//		}
//
//		if((angle.z >= 0) && (angle.z < 180))
//		{
//			e = ylen - 1;
//			n = -1;
//		}
//		else if((angle.z >= 180) && (angle.z < 360))
//		{
//			e = 0;
//			n = 1;
//		}
//		if((angle.z > 90) && (angle.z <= 270))
//		{
//			f = xlen - 1;
//			o = -1;
//		}
//		else if((angle.z > 270) || (angle.z <= 90))
//		{
//			f = 0;
//			o = 1;
//		}
//
//		/*
//		if(((angle.x > 90)&&(angle.x < 270))&&((angle.y > 90)&&(angle.y < 270)))
//		{
//			d = 0;
//			m = 1;
//		}
//		else if(((angle.x > 270)||(angle.x < 90))&&((angle.y > 270)||(angle.y < 90)))
//		{
//			d = ylen - 1;
//			m = -1;
//		}
//		else
//		{
//			d = 0;
//			m = 1;
//		}
//
//		if(angle.z != 0)
//		{
//			if(((angle.x > 0)&&(angle.x < 180))&&((angle.z > 90)&&(angle.z < 270)))
//			{
//				e = ylen - 1;
//				n = -1;
//			}
//			else if(((angle.x > 180)&&(angle.x < 360))&&((angle.z > 270)||(angle.z < 90)))
//			{
//				e = 0;
//				n = 1;
//			}
//			else
//			{
//				e = 0;
//				n = 1;
//			}
//
//			if(((angle.y > 0)&&(angle.y < 180))&&((angle.z > 180)&&(angle.z < 360)))
//			{
//				//f = 0;
//				//o = 1;
//				f = ylen - 1;
//				o = -1;
//			}
//			else if(((angle.y > 180)&&(angle.y < 360))&&((angle.z > 0)&&(angle.z < 180)))
//			{
//				//f = ylen - 1;
//				//o = -1;
//				f = 0;
//				o = 1;
//			}
//			else
//			{
//				f = 0;
//				o = 1;
//			}
//		}
//		else
//		{
//
//			if((angle.x > 0)&&(angle.x < 180))
//			{
//				e = 0;
//				n = 1;
//				//e = ylen - 1;
//				//n = -1;
//			}
//			else if((angle.x > 180)&&(angle.x < 360))
//			{
//				e = ylen - 1;
//				n = -1;
//				//e = 0;
//				//n = 1;
//			}
//			else
//			{
//				e = 0;
//				n = 1;
//			}
//
//			if((angle.y > 0)&&(angle.y < 180))
//			{
//				//f = 0;
//				//o = 1;
//				f = ylen - 1;
//				o = -1;
//			}
//			else if((angle.y > 180)&&(angle.y < 360))
//			{
//				//f = ylen - 1;
//				//o = -1;
//				f = 0;
//				o = 1;
//			}
//			else
//			{
//				f = 0;
//				o = 1;
//			}
//
//		}*/
//		
//
//
//		a = 0;
//		i = d;
//		while(a < zlen)
//		{
//			b = 0;
//			j = e;
//			while(b < ylen)
//			{
//				c = 0;
//				k = f;
//				while(c < xlen)
//				{
//					pos = offset(k, j, i, xlen, ylen);
//					if(cells3d[pos].state == true)
//					{
//						if(madcols)
//						{
//							cellCol.x = rand() % 255;
//							cellCol.y = rand() % 255;
//							cellCol.z = rand() % 255;
//						}
//						else if(!madcols)
//						{
//							cellCol.x = 255;
//							cellCol.y = 255;
//							cellCol.z = 255;
//						}
//						circlefill(backBuffer, (w/2) + cells3d[pos].x, (h/2) + cells3d[pos].y, cellR, makecol(cellCol.x, cellCol.y, cellCol.z));
//						circle(backBuffer, (w/2) + cells3d[pos].x, (h/2) + cells3d[pos].y, cellR, makecol(0, 0, 0));
//					}
//					c ++;
//					k += o;
//				}
//				b ++;
//				j += n;
//			}
//			a ++;
//			i += m;
//		}
//
//		
//
//
//		///////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//		//		menu
//
//		buttonX = w - (2 * cellR);
//		buttonY = 2 * cellR;
//		buttonRadius = 10;
//		buttonRed = 0;
//		buttonGreen = 0;
//		buttonBlue = 255;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "M");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//					menu = true;
//				}
//			}
//		}
//		if((mouse_x>(w - 100)) && (mouse_y<100))
//		{
//			//menu = true;
//		}
//		else
//		{
//			if(!presets)
//			{
//				menu = false;
//			}
//			if(options)
//			{
//				menu = true;
//			}
//		}
//
//
//		if(menu)
//		{
//			rectfill(backBuffer, w - 100, 0, w, 100, makecol(0, 0, 0));
//			rect(backBuffer, w - 100, 0, w, 100, makecol(255, 255, 255));
//
//			line(backBuffer, mouse_x, mouse_y, mouse_x, mouse_y + 17, makecol(cursorRed, cursorGreen, cursorBlue));
//			line(backBuffer, mouse_x, mouse_y, mouse_x + 11, mouse_y + 11, makecol(cursorRed, cursorGreen, cursorBlue));
//			line(backBuffer, mouse_x, mouse_y + 17, mouse_x + 11, mouse_y + 11, makecol(cursorRed, cursorGreen, cursorBlue));
//
//
//			buttonX = w - 80;
//			buttonY = 25;
//			buttonRadius = 5;
//			buttonRed = 255;
//			buttonGreen = 0;
//			buttonBlue = 0;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "C");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						i = 0;
//						while(i < zlen)
//						{
//							j = 0;
//							while(j < ylen)
//							{
//								k = 0;
//								while(k < xlen)
//								{
//									pos = offset(k, j, i, xlen, ylen);
//
//									cells3dnext[pos] = false;
//
//									k ++;
//								}
//								j ++;
//							}
//							i ++;
//						}
//
//					}
//				
//			}
//				}
//
//			buttonX = w - 50;
//			buttonY = 25;
//			buttonRadius = 5;
//			buttonRed = 0;
//			buttonGreen = 255;
//			buttonBlue = 0;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "R");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						i = 0;
//						while(i < zlen)
//						{
//							j = 0;
//							while(j < ylen)
//							{
//								k = 0;
//								while(k < xlen)
//								{
//									pos = offset(k, j, i, xlen, ylen);
//									int q;
//									q = rand() % 2;
//									if(q==0)
//									{
//										cells3dnext[pos] = false;
//									}
//									else if(q==1)
//									{
//										cells3dnext[pos] = true;
//									}
//
//									k ++;
//								}
//								j ++;
//							}
//							i ++;
//						}
//
//
//					}
//				}
//			}
//
//			buttonX = w - 20;
//			buttonY = 25;
//			buttonRadius = 5;
//			buttonRed = 0;
//			buttonGreen = 0;
//			buttonBlue = 255;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "E");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						if(edit)
//						{
//							edit = false;
//						}
//						else if(!edit)
//						{
//							edit = true;
//						}
//				
//					}
//				}
//			}
//
//			buttonX = w - 50;
//			buttonY = 50;
//			buttonRadius = 5;
//			buttonRed = 0;
//			buttonGreen = 255;
//			buttonBlue = 0;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "c");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						if(madcols)
//						{
//							madcols = false;
//						}
//						else if(!madcols)
//						{
//							madcols = true;
//						}
//
//
//					}
//				}
//			}
//
//			buttonX = w - 80;
//			buttonY = 50;
//			buttonRadius = 5;
//			buttonRed = 255;
//			buttonGreen = 0;
//			buttonBlue = 0;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "Ca");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						angle.x = 0;
//						angle.y = 0;
//						angle.z = 0;
//
//					}
//				
//				}
//			}
//
//			buttonX = w - 20;
//			buttonY = 50;
//			buttonRadius = 5;
//			buttonRed = 0;
//			buttonGreen = 0;
//			buttonBlue = 255;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "#");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//						if(dots)
//						{
//							dots = false;
//						}
//						else if(!dots)
//						{
//							dots = true;
//						}
//					}
//				}
//			}
//
//			buttonX = w - 80;
//			buttonY = 75;
//			buttonRadius = 5;
//			buttonRed = 255;
//			buttonGreen = 0;
//			buttonBlue = 0;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			if(play)
//			{
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, ">");
//			}
//			else if(!play)
//			{
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "=");
//			}
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						if(play)
//						{
//							play = false;
//						}
//						else if(!play)
//						{
//							play = true;
//						}
//
//					}
//				
//				}
//			}
//
//			buttonX = w - 50;
//			buttonY = 75;
//			buttonRadius = 5;
//			buttonRed = 0;
//			buttonGreen = 255;
//			buttonBlue = 0;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "O");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						if(options)
//						{
//							options = false;
//						}
//						else if(!options)
//						{
//							options = true;
//						}
//
//
//					}
//				}
//			}
//			//	options
//			if((mouse_x>(w - 80)) && (mouse_y<500))
//			{
//				//options = true;
//			}
//			else
//			{
//				options = false;
//			}
//			if(options)
//			{
//
//				rectfill(backBuffer, w - 80, 100, w, 500, makecol(0, 0, 0));
//				rect(backBuffer, w - 80, 100, w, 500, makecol(255, 255, 255));
//
//
//				buttonX = w - 20;
//				buttonY = 125;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "+");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							if(rodney < 5)
//							{
//								rodney ++;
//							}
//							else
//							{
//								rodney += 5;
//							}
//
//						}
//					}
//				}
//
//				textprintf_centre_ex(backBuffer, font, buttonX - 16, buttonY, makecol(0, 255, 255), -1, "delay");
//
//				buttonX = w - 50;
//				buttonY = 125;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 255;
//				buttonBlue = 0;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "-");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							if(rodney <= 5)
//							{
//								if(rodney>1)
//								{
//									rodney --;
//								}
//							}
//							else
//							{
//								rodney -= 5;
//							}
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 150;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "+");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							if((speed >= -0.11) && (speed <= 0.1))
//							{
//								speed += 0.01;
//							}
//							else
//							{
//								speed += 0.1;
//							}
//
//						}
//					}
//				}
//
//				textprintf_centre_ex(backBuffer, font, buttonX - 16, buttonY, makecol(0, 255, 255), -1, "speed");
//
//				buttonX = w - 50;
//				buttonY = 150;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 255;
//				buttonBlue = 0;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "-");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							if((speed <= 0.1) && (speed >= -0.1))
//							{
//								speed -= 0.01;
//							}
//							else
//							{
//								speed -= 0.1;
//							}
//
//						}
//					}
//				}
//
//
//
//
//
//
//
//				buttonX = w - 20;
//				buttonY = 375;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				textprintf(backBuffer, font, buttonX - 55, buttonY, makecol(0, 255, 255), "tester3");
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "L");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							live1 = 6;
//							live2 = 6;
//							born1 = 6;
//							born2 = 6;
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 400;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				textprintf(backBuffer, font, buttonX - 55, buttonY, makecol(0, 255, 255), "tester2");
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "L");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							live1 = 3;
//							live2 = 3;
//							born1 = 3;
//							born2 = 3;
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 425;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				textprintf(backBuffer, font, buttonX - 55, buttonY, makecol(0, 255, 255), "tester");
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "L");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							live1 = 3;
//							live2 = 4;
//							born1 = 4;
//							born2 = 4;
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 450;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				textprintf(backBuffer, font, buttonX - 55, buttonY, makecol(0, 255, 255), "ibiblio");
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "L");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							live1 = 3;
//							live2 = 2;
//							born1 = 3;
//							born2 = 4;
//
//						}
//					}
//				}
//				
//				buttonX = w - 20;
//				buttonY = 475;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				textprintf_centre_ex(backBuffer, font, buttonX - 16, buttonY, makecol(0, 255, 255), -1, "life rules");
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "L");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							live1 = 2;
//							live2 = 3;
//							born1 = 3;
//							born2 = 3;
//
//						}
//					}
//				}
//
//
//
//
//			}
//
//
//
//
//
//
//			buttonX = w - 20;
//			buttonY = 75;
//			buttonRadius = 5;
//			buttonRed = 0;
//			buttonGreen = 0;
//			buttonBlue = 255;
//			rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//				buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "P");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//					if(buttonPress == false)
//					{
//						buttonPress = true;
//			
//						if(presets)
//						{
//							presets = false;
//						}
//						else if(!presets)
//						{
//							presets = true;
//						}
//
//					}
//				}
//			}
//			//	presets
//			if((mouse_x>(w - 50)) && (mouse_y<500))
//			{
//				//presets = true;
//			}
//			else
//			{
//				presets = false;
//			}
//			if(presets)
//			{
//
//				rectfill(backBuffer, w - 50, 100, w, 500, makecol(0, 0, 0));
//				rect(backBuffer, w - 50, 100, w, 500, makecol(255, 255, 255));
//
//
//				buttonX = w - 20;
//				buttonY = 125;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, ".");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							int junebug = 21 / 2;
//							pos = offset((xlen / 2), (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 150;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "-");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							pos = offset((xlen / 2), (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) - 1, (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) + 1, (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 175;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "::");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							pos = offset((xlen / 2) - 1, (ylen / 2) - 1, (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) - 1, (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) - 1, (ylen / 2), (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2), (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//
//							pos = offset((xlen / 2) - 1, (ylen / 2) - 1, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) - 1, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) - 1, (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 200;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "[]");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							x = -1;
//							while(x < 2)
//							{
//								y = -1;
//								while(y < 2)
//								{
//									z = -1;
//									while(z < 2)
//									{
//										pos = offset((xlen / 2) + z, (ylen / 2) + y, (zlen / 2) + x, xlen, ylen);
//										cells3dnext[pos] = true;
//										z ++;
//									}
//									y ++;
//								}
//								x ++;
//							}
//
//
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 225;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "<>");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							x = -1;
//							while(x < 2)
//							{
//								y = -1;
//								while(y < 2)
//								{
//									z = -1;
//									while(z < 2)
//									{
//										pos = offset((xlen / 2) + z, (ylen / 2) + y, (zlen / 2) + x, xlen, ylen);
//										cells3dnext[pos] = true;
//										z ++;
//									}
//									y ++;
//								}
//								x ++;
//							}
//
//							pos = offset((xlen / 2) - 2, (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) + 2, (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//
//							pos = offset((xlen / 2), (ylen / 2) - 2, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) + 2, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//
//							pos = offset((xlen / 2), (ylen / 2), (zlen / 2) - 2, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2), (zlen / 2) + 2, xlen, ylen);
//							cells3dnext[pos] = true;
//
//
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 250;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "[]");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							x = -2;
//							while(x < 3)
//							{
//								y = -2;
//								while(y < 3)
//								{
//									z = -2;
//									while(z < 3)
//									{
//										pos = offset((xlen / 2) + z, (ylen / 2) + y, (zlen / 2) + x, xlen, ylen);
//										cells3dnext[pos] = true;
//										z ++;
//									}
//									y ++;
//								}
//								x ++;
//							}
//
//
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 275;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "[]");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							x = -4;
//							while(x < 5)
//							{
//								y = -4;
//								while(y < 5)
//								{
//									z = -4;
//									while(z < 5)
//									{
//										pos = offset((xlen / 2) + z, (ylen / 2) + y, (zlen / 2) + x, xlen, ylen);
//
//										cells3dnext[pos] = true;
//										z ++;
//									}
//									y ++;
//								}
//								x ++;
//							}
//
//
//						}
//					}
//				}
//
//				buttonX = w - 20;
//				buttonY = 300;
//				buttonRadius = 5;
//				buttonRed = 0;
//				buttonGreen = 0;
//				buttonBlue = 255;
//				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//					buttonX + buttonRadius, buttonY + buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "G");
//				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//					if(mouse_b&1){
//						if(buttonPress == false)
//						{
//							buttonPress = true;
//
//							
//							pos = offset((xlen / 2) - 1, (ylen / 2), (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) - 1, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) - 1, (ylen / 2) + 1, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) + 1, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) + 1, (ylen / 2) + 1, (zlen / 2), xlen, ylen);
//							cells3dnext[pos] = true;
//
//							pos = offset((xlen / 2) - 1, (ylen / 2), (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) - 1, (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) - 1, (ylen / 2) + 1, (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2), (ylen / 2) + 1, (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//							pos = offset((xlen / 2) + 1, (ylen / 2) + 1, (zlen / 2) - 1, xlen, ylen);
//							cells3dnext[pos] = true;
//
//
//
//						}
//					}
//				}
//
//
//
//
//
//
//
//
//
//
//			}
//
//
//		}
//
//
//		///////	debug
//
//		// cell numbers
//		i = 0;
//		while(i < xlen)
//		{
//			pos = offset(i, 0, 0, xlen, ylen);
//			textprintf(backBuffer, font, (w/2) + cells3d[pos].x, (h/2) + cells3d[pos].y - 10, makecol(dotCol.x, dotCol.y, dotCol.z), "%d", i + 1);
//			pos = offset(0, i, 0, xlen, ylen);
//			textprintf(backBuffer, font, (w/2) + cells3d[pos].x - 10, (h/2) + cells3d[pos].y - 10, makecol(dotCol.x, dotCol.y, dotCol.z), "%d", i + 1);
//			pos = offset(0, 0, xlen - i, xlen, ylen);
//			textprintf(backBuffer, font, (w/2) + cells3d[pos].x - 10, (h/2) + cells3d[pos].y - 10, makecol(dotCol.x, dotCol.y, dotCol.z), "%d", (xlen + 1) - i);
//			i ++;
//		}
//
//		/*
//		// axis
//		//x
//		line(backBuffer, w/2, h/2, w/2 + axis[0].x, h/2 + axis[0].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf(backBuffer, font, w/2 + axis[0].x, h/2 + axis[0].y, makecol(dotCol.x, dotCol.y, dotCol.z), "x");
//		//rotate(axis[0], 90, x, axis[0]);
//		//line(backBuffer, w/2, h/2, w/2 + axis[0].x, h/2 + axis[0].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//		//textprintf(backBuffer, font, w/2 + axis[0].x, h/2 + axis[0].y, makecol(dotCol.x, dotCol.y, dotCol.z), "x 90");
//		//y
//		line(backBuffer, w/2, h/2, w/2 + axis[1].x, h/2 + axis[1].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf(backBuffer, font, w/2 + axis[1].x, h/2 + axis[1].y, makecol(dotCol.x, dotCol.y, dotCol.z), "y");
//		//rotate(axis[1], 90, y, axis[1]);
//		//line(backBuffer, w/2, h/2, w/2 + axis[1].x, h/2 + axis[1].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//		//textprintf(backBuffer, font, w/2 + axis[1].x, h/2 + axis[1].y, makecol(dotCol.x, dotCol.y, dotCol.z), "y 90");
//		//z
//		line(backBuffer, w/2, h/2, w/2 + axis[2].x, h/2 + axis[2].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf(backBuffer, font, w/2 + axis[2].x, h/2 + axis[2].y, makecol(dotCol.x, dotCol.y, dotCol.z), "z");
//		//rotate(axis[2], 90, z, axis[2]);
//		//line(backBuffer, w/2, h/2, w/2 + axis[2].x, h/2 + axis[2].y, makecol(dotCol.x, dotCol.y, dotCol.z));
//		//textprintf(backBuffer, font, w/2 + axis[2].x, h/2 + axis[2].y, makecol(dotCol.x, dotCol.y, dotCol.z), "z 90");
//		*/
//
//		// angle
//		textprintf(backBuffer, font, 20, h - 20, makecol(dotCol.x, dotCol.y, dotCol.z), "angle:");
//		textprintf(backBuffer, font, 80, h - 20, makecol(dotCol.x, dotCol.y, dotCol.z), "%0.1f", angle.x);
//		textprintf(backBuffer, font, 140, h - 20, makecol(dotCol.x, dotCol.y, dotCol.z), "%0.1f", angle.y);
//		textprintf(backBuffer, font, 200, h - 20, makecol(dotCol.x, dotCol.y, dotCol.z), "%0.1f", angle.z);
//		//speed
//		textprintf(backBuffer, font, 20, h - 40, makecol(dotCol.x, dotCol.y, dotCol.z), "rotation speed: %0.2f", speed);
//		//delay
//		//speed
//		textprintf(backBuffer, font, 20, h - 60, makecol(dotCol.x, dotCol.y, dotCol.z), "delay: %d", rodney);
//
//		//rules
//		textprintf(backBuffer, font, w - 550, h - 120, makecol(dotCol.x, dotCol.y, dotCol.z), "live cells with %d or %d neighbours live", live1, live2);
//		textprintf(backBuffer, font, w - 450, h - 100, makecol(dotCol.x, dotCol.y, dotCol.z), "live cells with less than %d neighbours die", live1);
//		textprintf(backBuffer, font, w - 450, h - 80, makecol(dotCol.x, dotCol.y, dotCol.z), "live cells with more than %d neighbours die", live2);
//		if(born1==born2)
//		{
//			textprintf(backBuffer, font, w - 550, h - 60, makecol(dotCol.x, dotCol.y, dotCol.z), "dead cells with exactly %d neighbours live", born1);
//		}
//		else
//		{
//			textprintf(backBuffer, font, w - 550, h - 60, makecol(dotCol.x, dotCol.y, dotCol.z), "dead cells with more than %d and less than %d neighbours live", born1, born2);
//		}
//		textprintf(backBuffer, font, w - 450, h - 40, makecol(dotCol.x, dotCol.y, dotCol.z), "dead cells with more than or %d neighbours live", born1);
//		textprintf(backBuffer, font, w - 450, h - 20, makecol(dotCol.x, dotCol.y, dotCol.z), "dead cells with less than or %d neighbours live", born2);
//		
//		buttonX = w - 40;
//		buttonY = h - 120;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					live1 --;
//					live2 --;
//
//				}
//			}
//		}
//		buttonX = w - 20;
//		buttonY = h - 120;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					live1 ++;
//					live2 ++;
//
//				}
//			}
//		}
//
//		buttonX = w - 40;
//		buttonY = h - 100;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					live1 --;
//
//				}
//			}
//		}
//		buttonX = w - 20;
//		buttonY = h - 100;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					live1 ++;
//
//				}
//			}
//		}
//
//		buttonX = w - 40;
//		buttonY = h - 80;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					live2 --;
//
//				}
//			}
//		}
//		buttonX = w - 20;
//		buttonY = h - 80;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					live2 ++;
//
//				}
//			}
//		}
//
//		buttonX = w - 40;
//		buttonY = h - 60;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					born1 --;
//					born2 --;
//
//				}
//			}
//		}
//		buttonX = w - 20;
//		buttonY = h - 60;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					born1 ++;
//					born2 ++;
//
//				}
//			}
//		}
//
//		buttonX = w - 40;
//		buttonY = h - 40;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					born1 --;
//
//				}
//			}
//		}
//		buttonX = w - 20;
//		buttonY = h - 40;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					born1 ++;
//
//				}
//			}
//		}
//
//		buttonX = w - 40;
//		buttonY = h - 20;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					born2 --;
//
//				}
//			}
//		}
//		buttonX = w - 20;
//		buttonY = h - 20;
//		buttonRadius = 5;
//		rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
//			buttonX + buttonRadius, buttonY + buttonRadius, makecol(dotCol.x, dotCol.y, dotCol.z));
//		textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(dotCol.x, dotCol.y, dotCol.z), -1, "+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					born2 ++;
//
//				}
//			}
//		}
//
//		//Play pause
//		buttonX = 30;
//		buttonY = h / 2;
//		buttonRadius = 25;
//		buttonRed = 0;
//		buttonGreen = 0;
//		buttonBlue = 0;
//		if(play)
//		{
//			buttonRed = 255;
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, "||");
//		}
//		else
//		{
//			buttonGreen = 255;
//			textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(buttonRed, buttonGreen, buttonBlue), -1, ">");
//		}
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(buttonRed, buttonGreen, buttonBlue));
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				if(buttonPress == false)
//				{
//					buttonPress = true;
//
//					if(play)
//					{
//						play = false;
//					}
//					else if(!play)
//					{
//						play = true;
//					}
//
//				}
//			}
//		}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//		delboy ++;
//
//		if(!mouse_b&1)
//		{
//			buttonPress = false;
//		}
//
//		line(backBuffer, mouse_x, mouse_y, mouse_x, mouse_y + 17, makecol(cursorRed, cursorGreen, cursorBlue));
//		line(backBuffer, mouse_x, mouse_y, mouse_x + 11, mouse_y + 11, makecol(cursorRed, cursorGreen, cursorBlue));
//		line(backBuffer, mouse_x, mouse_y + 17, mouse_x + 11, mouse_y + 11, makecol(cursorRed, cursorGreen, cursorBlue));
//
//
////////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//		//	refresh screen
//		blit(backBuffer, screen, 0, 0, 0, 0, w, h);
//	}
//	
//	free(cells3d);
//	free(cells3doriginal);
//	free(cells3dnext);
//
//}
//END_OF_MAIN()