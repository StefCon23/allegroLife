all:
	gcc -o allegroLife allegroLife.c `allegro-config --libs` -lm 2> err
