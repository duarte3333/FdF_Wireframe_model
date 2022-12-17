#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int make_color(float percent, int flag, int r, int g)
{
    if (flag == 1)
        return (create_trgb(0, percent*255, 0, 0));
    else if (flag == 2)
        return (create_trgb(0, 0, percent*255, 0));
    else if (flag == 3)
        return (create_trgb(0, 0, 0, percent*255));   
    else if (flag == 4)
        return (create_trgb(0, g, r, 0));
    else if (flag == 5)
        return (create_trgb(0, 0, r, g));
    else if (flag == 6)
        return (create_trgb(0, g, 0, r));
    return(0);
}

//0    -> (0,     0,     0)
//0.25 -> (255,   127.5, 0)
//0.49 -> (255,   255,   0)
//0.5  -> (255,   255,   0)
//0.75 -> (127,5, 255,   0)
//1    -> (0,     255,   0)
//Mais perto de 0.5, mais perto de (255, 255, 0)
//Mais perto de 1, mais perto de (0,255, 0)
int percent_to_color(float percent, int flag)
{
    int r;
    int g;
    
    r=255;
    g=255;
    if (flag == 4 || flag == 5 || flag == 6) 
    {
        if (percent<0 || percent>1)
            return (0);
        if (percent<0.5)
            g = (255*percent/0.5);
        else
            r = 255 - (255*(percent-0.5)/0.5);
        return(make_color(percent, flag, r, g));
    }
    else
        return(make_color(percent, flag, 0, 0));
}