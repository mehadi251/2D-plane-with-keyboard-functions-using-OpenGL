
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;


char title[] = "2D plane" ,c;
GLfloat anglePyramid = 0.0f;
GLfloat angleCube = 0.0f,x=0.0f,y=0.0f,z=0.0f;
int refreshMills = 15,a=0,b=0,d=0,t=0,r=0,f=0,m=0;
float j=0.0,k=0.0,l=0.0,i=0.0;



void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

#define DEG2RAD 3.14159/180.0


void DrawEllipse(float cx, float cy,float radiusX, float radiusY)
{
   int i;

   glBegin(GL_LINES);

   for(i=0;i<360;i++)
   {

      float rad = i*DEG2RAD;
     // if(i%20<10)
      glColor3f(0.6f, 0.35f, 0.05f);
     // glColor3f(1.0f, 1.0f, 1.0f);
      float x= cos(rad)*radiusX;
      float y= sin(rad)*radiusY;
      glVertex2f(x + cx, y + cy);
   }

   glEnd();
}
void DrawCircle(float cx, float cy, float r, int num_segments) {
    glEnable(GL_LINE_SMOOTH);
glLineWidth(8.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)   {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(i%20==0)
          glColor3f(1.0f, 1.0f, 1.0f);
      else
        glColor3f(0.6f, 0.35f, 0.05f);
        glVertex2f(x + cx, y + cy);//output vertex
    }

  //  glutSwapBuffers();
    glEnd();
}
void drawbox() {
 glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f);
       glVertex2f( -4.0f, 2.5f);
       glVertex2f( -4.0f, -3.5f);
       glVertex2f( -4.0f, 2.5f);
       glVertex2f( 4.7f, 2.5f);
       glVertex2f( 4.7f, 2.5f);
       glVertex2f( 4.7f, -3.5f);
       glVertex2f( 4.7f, -3.5f);
       glVertex2f( -4.0f, -3.5f);
glEnd();


}
void plane()
{

 DrawEllipse(-2.0,-0.0,0.5,1.0);
 DrawEllipse(-2.5,-0.0,0.5,0.2);
 DrawEllipse(-3.0,1.0,0.2,1.0);
 DrawEllipse(-3.0,-1.0,0.2,1.0);


 glBegin(GL_LINES);
     glVertex2f(-2.0f,1.0f);
     glVertex2f(3.0f,1.0f);
     glVertex2f(3.0f,-1.0f);
     glVertex2f(-2.0f,-1.0f);
     glVertex2f(3.0f,1.0f);
     glVertex2f(4.0f,-0.55f);
     glVertex2f(4.0f,-0.55f);
     glVertex2f(3.0f,-1.0f);
     glVertex2f(3.0f,1.0f);
     glVertex2f(4.0f,2.0f);
     glVertex2f(4.0f,2.0f);
     glVertex2f(4.0f,-0.55f);

 glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex2f(2.2f,-0.65f);
    glVertex2f(4.0f,-0.65f);
    glVertex2f(4.0f,-1.5f);

  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f,1.0f);
    glVertex2f(1.0f,1.0f);
    glVertex2f(0.75f,1.5f);
    glVertex2f(-0.25f,1.5f);
  glEnd();


  glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f,-0.25f);
    glVertex2f(1.25f,-0.25f);
    glVertex2f(1.55f,-3.0f);
    glVertex2f(1.25f,-3.0f);
  glEnd();

  glBegin(GL_LINES);
    glVertex2f(-0.8f,2.0f);
    glVertex2f(-0.8f,1.0f);
    glVertex2f(-0.8f,2.0f);
    glVertex2f(0.0f,1.5f);
    glVertex2f(-0.8f,-1.0f);
    glVertex2f(-1.3f,-2.0f);
    glVertex2f(-0.8f,-1.0f);
    glVertex2f(-0.3f,-2.0f);
    glVertex2f(2.8f,-1.0f);
    glVertex2f(2.3f,-2.0f);
    glVertex2f(2.8f,-1.0f);
    glVertex2f(3.3f,-2.0f);



  glEnd();

  const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
  const double s = t*180.0;

   glPushMatrix();
   glTranslated(-1.4,-2.5,0);
   glRotated(s,0,0,1);
   glTranslated(1.4,2.5,0);
  DrawCircle(-1.4,-2.5,0.5,100);
  glPopMatrix();

  glPushMatrix();
   glTranslated(-0.2,-2.5,0);
   glRotated(s,0,0,1);
   glTranslated(0.2,2.5,0);
  DrawCircle(-0.2,-2.5,0.5,100);
  glPopMatrix();

  glPushMatrix();
   glTranslated(2.3,-2.5,0);
   glRotated(s,0,0,1);
   glTranslated(-2.3,2.5,0);
   DrawCircle(2.3,-2.5,0.5,100);
   glPopMatrix();


  glPushMatrix();
   glTranslated(3.5,-2.5,0);
   glRotated(s,0,0,1);
   glTranslated(-3.5,2.5,0);
  DrawCircle(3.5,-2.5,0.5,100);
  glPopMatrix();

}
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

        case '1':
            a=1;
            break;
        case '2':
            a=2;
            break;
     case '3':
            a=3;
            break;
        case '4':
            a=4;
            break;
        case'R':
            r++;
            break;
        case 'X':
         {
                b=1;  x+=0.5f;
         }
            break;
        case 'Y':
          {
              b=2;  y++; }
            break;
        case'Z':
           {
               b=3;  z++;
           }
            break;
        case'T':
            t++;
            break;
        case'I':
            i++;
            break;
        case'J':
            j++;
            break;
        case'K':
            k++;
            break;
        case'L':
            l++;
            break;

        case'C':
            d++;
            break;
        case'F':
            f++;
            break;
        case'M':
            m++;
    }

    }


void rotation()
{
    const double f = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
                const double q = f*90.0;

     if(b==1 && r%2==1 )
           { if(d%2==1)    glRotated(q,1,0,0);
            else if(d!=0 && d%2==0)    glRotated(q,-1,0,0);

           }

             else if(b==2 && r%2==1 )
           { if(d%2==1)    glRotated(q,0,1,0);
            else if(d!=0 && d%2==0)    glRotated(q,0,-1,0);

           }
           else if(b==3 && r%2==1 )
           { if(d%2==1)    glRotated(q,0,0,1);
            else if(d!=0 && d%2==0)    glRotated(q,0,0,-1);

           }
           else if(r%2==0){
                   r=0; b=0; d=0;
            glPushMatrix();
            glRotated(0,0,0,0);
            glPopMatrix();


           }
}

void transltion()
{
    if(t%2==1 ){
            if(j>0)  glTranslated(-j,0.0,0.0f);
            if(k>0)  glTranslated(k,0.0,0.0f);
          if(i>0) glTranslated(0.0,i,0.0f);
           if(l>0) glTranslated(0.0,-l,0.0f);
           }
    if(t%2==0){
            t=0; i=0; j=0; k=0; l=0;
           //  glPushMatrix();
            glTranslated(0.0f,0.0f,0.0f);
           // glPopMatrix();
           }
}
void flip()
{
    if(f%2==1) glRotated(180,0,1,0);
    else  glTranslated(0.0f,0.0f,0.0f);
}
void mirrorop()
{   const double f = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
                const double q = f*90.0;
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(m%2==1)    { a=0; glRotated(q,0,0,1); }
}
void display() {


   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);

                glLoadIdentity();

           glTranslatef(6.0f, 4.0f, -7.0f);

           glPushMatrix();  mirrorop();
          if(a==1) {  rotation();  transltion(); flip();  drawbox();}
          plane();
           glPopMatrix();

           glPushMatrix();
              glTranslatef(-6.0f, 4.0f, 0.0f);
              glRotated(180,0,1,0);
              glTranslatef(6.0f, -4.0f, 0.0f);  mirrorop(); if(a==2) {  rotation();  transltion(); flip();  drawbox();}
              plane();
              glPopMatrix();

            glPushMatrix();
              glTranslatef(-6.0f, -4.0f, 0.0f);
              glRotated(180,0,1,0);
              glRotated(180,1,0,0);
              glTranslatef(6.0f, 4.0f, 0.0f);    mirrorop(); if(a==3) {  rotation(); transltion(); flip(); drawbox(); }
              plane();
              glPopMatrix();

            glPushMatrix();
              glTranslatef(6.0f, -4.0f, 0.0f);
              glRotated(180,0,1,0);
              glRotated(180,1,0,0);
              glRotated(180,0,1,0);
              glTranslatef(-6.0f, 4.0f, 0.0f);  mirrorop();  if(a==4)   {  rotation();  transltion(); flip(); drawbox(); }
              plane();
              glPopMatrix();


   glutSwapBuffers();
}

/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window

   glViewport(0, 0,width,height);


   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(90.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {




   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(840, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);
   glutReshapeFunc(reshape);      // Create window with the given title
   glutDisplayFunc(display);
          // Register callback handler for window re-paint event

   glutKeyboardFunc(key);     // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
   glutMainLoop();
               // Enter the infinite event-processing loop
   return 0;
}

