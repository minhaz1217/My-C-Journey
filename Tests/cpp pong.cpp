#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

double xpos = 300;
double ypos = 200;
//coordinates for the center of the ball

double dx = -4;
double dy = 0;
//distance ball travels per frame

int leftScore = 0;
int rightScore = 0;
//player scores

double paddlePosLeft = 200;
double paddlePosRight = 200;
//y positions of the centers of the paddles

bool play = true;
//whether a game is currently in session

   void resetBall(){
           xpos = 300;
           ypos = 200;
           //resets the ball to the center of the field
           dy = 0;
           //sets the y derivative of the ball's position to zero
           }

    bool checkHit (double paddlePos, int side){
        //takes parameters:
        //y position of center of paddle in question and which paddle (left(1) right(2)) is in question
        double xDiff;
        //the x distance between the center of the ball and the front of the paddle
        double yDiff = 0;
        //the y distance between the center of the ball and the edge of the paddle
        double mag = 0;
        //the distance between the center of the paddle and the center of the ball

        if(side == 1){
        xDiff = xpos -110;
        //if the left paddle is being examined
        //xDiff is the distance from the center of the ball to the left paddle
        } else {
        xDiff = xpos -490;
        //if the right paddle is being examined
        //xDiff is the distance from the center of the ball to the right paddle
        }

        double yDiffCenter = ypos - paddlePos;
        //the y distance between the center of the ball and the middle of the paddle
        if (ypos > paddlePos){
            //if the ball is above the paddle
            yDiff = abs(ypos - (paddlePos + 20));
        } else if (ypos < paddlePos){
            //if the ball is below the paddle
            yDiff = abs(ypos - (paddlePos - 20));
}

if ((pow(xDiff, 2) + pow(yDiff, 2)) <= 625){
        //if the distance from the center of the ball to the paddle is smaller than the ball's radius
    mag = sqrt((pow(xDiff, 2)) + (pow(yDiffCenter, 2)));
    //the magnitude of the distance between the center of the ball and the paddle
    dx = (4/mag) * xDiff;
    dy = (4/mag) * yDiffCenter;
    //the ball is bounced according to where the ball hit in relation to the center of the paddle
    //the ball's velocity maintains it's magnitude of 4
    return true;
    //registering that a hit has occurred for this paddle in this time frame
} else {
return false;
//registering that a hit has not occurred for this paddle in this time frame
}
    }

main()
{
   int gd = DETECT, gm, x, y, color, angle = 0;
   //initializes window graph

   struct arccoordstype a, b;
   initgraph(&gd, &gm, "");
   //graph is initialized

   while(play)
   {
       setcolor(BLUE);
       line(98,0,98,1000);
       //left border is drawn

       setcolor(BLUE);
       line(502,0,502,1000);
       //right border is drawn

       setcolor(RED);
       line(100,75,502,75);
       //top border is drawn

       setcolor(RED);
       line(100,325,502,325);
       //bottom border is drawn

       bool hitLeft = false;
       bool hitRight = false;
       //boolean value corresponding to whether a collision with a paddle has occurred

       setcolor(YELLOW);
       char numbufLeft[6];
       sprintf(numbufLeft, "YELLOW: %d", leftScore);
       outtextxy(100, 50, numbufLeft);
       //displays the score for the left (yellow) player

       setcolor(WHITE);
       char numbufRight[6];
       sprintf(numbufRight, "WHITE: %d", rightScore);
       outtextxy(350, 50, numbufRight);
       //displays the score for the right (white) player

       setcolor(BLACK);
       circle(xpos,ypos,25);
       //clears out old image of ball

       xpos += dx;
       ypos += dy;
       //ball's position iterated one time step based on it's velocity

       hitLeft = checkHit(paddlePosLeft, 1);
       hitRight = checkHit(paddlePosRight, 2);
       //each time step the checkHit method is applied to each paddle to determine whether the ball has made contact
       //if a hit has occurred this method changes the ball's velocity accordingly

       setcolor(YELLOW);
       rectangle(100, (paddlePosLeft - 20), 110, (paddlePosLeft + 20));
       //yellow paddle is drawn on screen

       setcolor(WHITE);
       rectangle(490, (paddlePosRight - 20), 500, (paddlePosRight + 20));
       //white paddle is drawn on screen

       if( GetAsyncKeyState(87)){
            //if the 'w' key is pressed
           if (101 <= paddlePosLeft){
               setcolor(BLACK);
               rectangle(100, (paddlePosLeft - 20), 110, (paddlePosLeft + 20));
               //old paddle image is cleared
               paddlePosLeft -= 5;
               //paddle's y position is iterated down
               setcolor(YELLOW);
               rectangle(100, (paddlePosLeft - 20), 110, (paddlePosLeft + 20));
               //new paddle image is drawn
               }

               } else if( GetAsyncKeyState(83)){
                   //if the 's' key is pressed
                   if (paddlePosLeft <= 299){
                        setcolor(BLACK);
                        rectangle(100, (paddlePosLeft - 20), 110, (paddlePosLeft + 20));
                        //old paddle image is cleared
                        paddlePosLeft += 5;
                        //paddle's y position is iterated up
                        setcolor(YELLOW);
                        rectangle(100, (paddlePosLeft - 20), 110, (paddlePosLeft + 20));
                        //new paddle image is drawn
                        }
                        }

      if( GetAsyncKeyState(VK_UP)){
            //if the 'up' key is pressed
            if (101 <= paddlePosRight){
                setcolor(BLACK);
                rectangle(490, (paddlePosRight - 20), 500, (paddlePosRight + 20));
                //old paddle image is cleared
                paddlePosRight -= 5;
                //paddle's y position is iterated down
                setcolor(WHITE);
                rectangle(490, (paddlePosRight - 20), 500, (paddlePosRight + 20));
                //new paddle image is drawn
                }

} else if( GetAsyncKeyState(VK_DOWN)){
    //if the 'up' key is pressed
    if (paddlePosRight <= 299){
            setcolor(BLACK);
            rectangle(490, (paddlePosRight - 20), 500, (paddlePosRight + 20));
            //old paddle image is cleared
            paddlePosRight += 5;
            //paddle's y position is iterated up
            setcolor(WHITE);
            rectangle(490, (paddlePosRight - 20), 500, (paddlePosRight + 20));
            //new paddle image is drawn
            }
            }

if((ypos <= 100) || (ypos >= 300)){
        //if the ball collides with the top or bottom borders
        dy = -1 * dy;
        //y velocity is reversed
        setcolor(RED);
        line(100,75,502,75);
        line(100,325,502,325);
        //top and bottom borders redrawn
      }

if (!(hitLeft || hitRight)){
        //if a hit with the paddles has not occurred

    if (xpos > 477){
        //if the edge of the ball passes the right border
        dx = 4;
        //ball's x velocity is set to rightward as left player is now serving to right
        resetBall();
        //method that resets the ball to the center of the field
        setcolor(BLUE);
        line(502,0,502,1000);
        //right border redrawn
        leftScore += 1;
        //right player score increased by one point
      }

    if (xpos < 123){
        //if the edge of the ball passes the right border
        dx = -4;
        //ball's x velocity is set to leftward as right player is now serving to left
        resetBall();
        //method that resets the ball to the center of the field
        setcolor(GREEN);
        line(98,0,98,1000);
        //right border redrawn
        rightScore += 1;
        //left player score increased by one point
      }

      setcolor(RED);
      circle(xpos,ypos,25);
      //redraw ball at new position
}
      delay(10);
      //time delay each time frame
   }

   getch();
   closegraph();
}
