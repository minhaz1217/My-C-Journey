#include<iostream>
#include<stdlib.h>

#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

using namespace std;


#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


// 	#b5d6e0 	(181,214,224)
//	#c7e1e5 	(199,225,229)
//	#ffef7a 	(255,239,122)
//	#f7c16a 	(247,193,106)
//	#f46a55 	(244,106,85)





string skyColors[] = { "b5d6e0", "c7e1e5", "ffef7a", "f7c16a" , "f46a55", "333333"}; // dusk, morning, noon, afternoon, evening, night
int totalAnimationTime = 7; // 10 second
int refreshRate = 10;
int colorStart[]  ={ 0,2,3,5,6,8};
int colorEnd[]  = { 1,3,5,6,8,10}; // color seperations


float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
float colR=3.0;
float colG=1.5;
float colB=1.0;
float bgColR=0.0;
float bgColG=0.0;
float bgColB=0.0;

static int isSunGoingUp=1;
int screenWidth = 800;
int screenHeight= 450;


void drawBall(void) {

        glColor3f(colR,colG,colB); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.05, 30, 30); //create ball.

}

void drawAv(void) {

    glBegin(GL_POLYGON);

        glColor3f(1.0,1.0,1.0);

        glVertex3f(-0.9,-0.7,-1.0);

        glVertex3f(-0.5,-0.1,-1.0);

        glVertex3f(-0.2,-1.0,-1.0);

        glVertex3f(0.5,0.0,-1.0);

        glVertex3f(0.6,-0.2,-1.0);

        glVertex3f(0.9,-0.7,-1.0);

    glEnd();

}

void drawClouds(){}

void keyPress(int key, int x, int y)
{
    if(key==GLUT_KEY_RIGHT)
        ballX -= 0.05f;
    if(key==GLUT_KEY_LEFT)
        ballX  += 0.05f;

    glutPostRedisplay();
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
   cout << w << " "<< h << endl;
}

// hexToRGBA converts any rgb color to glFloat rgba.
GLfloat* hexToRGBA(string rgb, unsigned int opacity =1){
    if(opacity >1 || opacity < 0){
        opacity = 1;
    }
    if(rgb[0] == '#' || rgb.size() > 6){
        rgb = rgb.substr(1, 6);
    }
    string red, green, blue;
    if(rgb.size() ==3){
        red = rgb[0] + rgb[0];
        green = rgb[1] + rgb[1];
        blue= rgb[2] + rgb[2];
    }else{
        red = rgb.substr(0,2);
        green = rgb.substr(2,2);
        blue = rgb.substr(4,2);
    }
    int r,g,b;
    r = strtol(red.c_str(), NULL, 16);
    g = strtol(green.c_str(), NULL, 16);
    b = strtol(blue.c_str(), NULL, 16);

    GLfloat colors[] = {r/255.0f,g/255.0f,b/255.0f,opacity};
    return colors;
}
float hexToFloat(string hex){
    return strtol(hex.c_str(), NULL, 16)/255.0f;
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(bgColR, bgColG, bgColB,0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 0}; //Color (0.2, 0.2, 0.2)

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    //drawing the SUN
    glPushMatrix();
        drawBall();
    glPopMatrix();
    //drawing the Mount Avarest
    glPushMatrix();
        drawAv();
    glPopMatrix();

    //drawing the Clouds
    glPushMatrix();
        drawClouds();
    glPopMatrix();

    glutSwapBuffers();
}
// get background color
void changeBackGroundColor(){
    // pick the segment.
}
int currentWindowHeight(){
    return glutGet(GLUT_WINDOW_HEIGHT) ;
}

int currentWindowWidth(){
    return glutGet(GLUT_WINDOW_WIDTH) ;
}


double ballMinX = -.8;
double ballMaxX = .9;
double ballMinY = -.3;
double ballMaxY = .6;

void resetBallToOriginalPosition(){
    cc("RESETED");
    ballX = ballMinX;
    ballY = ballMinY;
    colR=2.0;
    colG=1.50;
    colB=1.0;

    bgColB=0.0;
    isSunGoingUp = 1;
}

double getXDiff(){
    return (ballMaxX - ballMinX)/((double)totalAnimationTime*1000.0/refreshRate);
}
double getYDiff(){
    return (ballMaxY - ballMinY) / ((double)totalAnimationTime*1000.0/refreshRate);
}

unsigned int getRefreshTime(){
    // 30 frames per second;
    // 1000 sec 30 FrameRect
    return (refreshRate);
}
//float _angle = 30.0f;
void update(int value) {

    cc(glutGet(GLUT_ELAPSED_TIME));
    //msg2(mx, ballY, ballZ)
    /// ballX will go from -.8 to .9
    /// ballY will go from -.3f to -.0165
    // ball has passed the right side of the screen
    if(ballX>ballMaxX)
    {
        isSunGoingUp = 1;
        resetBallToOriginalPosition();
    }

    if(isSunGoingUp)
    {
        ballY += getYDiff();

        colR-=0.001;
        //colG+=0.002;
        colB+=0.005;
        bgColB+=0.001;

        // ball is at x axis mid point, so it needs to go down now.
        if(ballX> (ballMaxX + ballMinY)/2 ){
           isSunGoingUp=0;
        }
    }

    if (!isSunGoingUp)
    {
        ballY -= getYDiff();
        colR+=0.001;
        colB-=0.01;

        bgColB-=0.001;
    }
    ballX += getXDiff(); // ball will always go right,


    glutPostRedisplay(); //Tell GLUT that the display has changed

//std::cout << "glut screen width: " << glutGet(GLUT_WINDOW_WIDTH) << std::endl;
//std::cout << "glut screen height: " << glutGet(GLUT_WINDOW_HEIGHT) << std::endl;

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(getRefreshTime(), update, 0);
}
int main(int argc,char** argv)
{
    hexToRGBA("#106EBE");
    //return 0;
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Sun");

    initRendering();

    glutDisplayFunc(drawScene);

    //glutFullScreen();
    glutSpecialFunc(keyPress);
    glutReshapeFunc(handleResize);

    glutTimerFunc(getRefreshTime(), update, 0);

    glutMainLoop();

    return(0);
}

