/*
 * File: Rainbown.cpp
 * -------------------------
 *  This program illustrates the use of graphics using the GWindow class.
 *
 * Need to utilize the Stanford Libraries to get the "gwindow" libraries
 * linked.
 */

#include <string>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;
/* Prototypes */

void drawDiamond(GWindow & gw);
void drawRectangleAndOval(GWindow &gw);
void drawRectangle(GWindow & gw,  double x, double y, double width, double height, string color);

void drawArc(GWindow & gw, double x, double y,double width, double height,
             double start, double sweep, string color);
// Main program

int main(){
    GWindow gw;
    double width = gw.getWidth() + 120;
    double height = gw.getHeight();
    double interval = 10;
    double x = - 60;
    double y = 60;



    string colour[7] = {"red","orange","yellow","green","blue", "magenta", "cyan"};

    // setting the "cyan" background color for entire frame.
    drawRectangle(gw, 0, 0, width, height, "cyan");

    for(int i=0; i<7; i++){
         drawArc(gw, x, y, width, height*2, 0, 180, colour[i]);
         x += interval;
         y += interval;
         width -= 2 * interval;
         height -= interval;
    }
    return 0;
}


/* Function: drawArc
 * Usage: drawArc(gw, x, y, width, height, start, sweep, color)
 * ------------------------------------------------------
 * Draws a art with specific color.
 */
void drawArc(GWindow & gw, double x, double y,double width, double height,
             double start, double sweep, string color){
    GArc *arc = new GArc(x, y, width, height,  start, sweep);
    arc->setFillColor(color);
    gw.add(arc);
}


/* Function: drawRectangle
 * Usage: drawReactangle(gw, width, height);
 * ----------------------------------------
 * Draws a rectangle with specific color
 */
void drawRectangle(GWindow & gw, double x, double y, double width, double height, string color){
    gw.setColor(color);
    gw.fillRect(x, y, width, height);
}
