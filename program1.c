/*
 * Programmer: Vernon Leon Watson II
 * Chaos Game
 */

/*
 * program1.c
 * modified from hello.c
 * This is a fun little game, called Chaos Game, done 
 * by british mathmatician Michael Barnsley.
 * It results in a Sierpinski Triangle 
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float v1[] = {.65,.8}, 
      v2[] = {.12,.15}, 
      v3[] = {.9,.25};
float p[] = {.25,.25};

void reshape(int w, int h){
   glViewport(0, 0, w, h);

}

void keypress(unsigned char key, int x, int y){
   printf("%i\n", key);
   switch(key){
      case 27:
         glutDestroyWindow(glutGetWindow());
         break;
         
   }
}
/*
*  Sets new midpoint 
*/
void midpoint(float vert[]){
   
   p[0] = (vert[0] + p[0])/2;
   if(p[0] < 0) p[0] = p[0]*-1;

   p[1] = (vert[1] + p[1])/2;
   if(p[1] < 0) p[1] = p[1]*-1;
}

/*
*  Draws a point on the screen 
*  with color white.
*/
void drawPoint(float vert[]){
         glBegin(GL_POINTS);
            glColor3f(1.0,1.0,1.0);
            glVertex2d(vert[0], vert[1]);
         glEnd();
   
}
/*
*  Chaos Game rules implemented here using 
*  global
*/
void chaosAlgorithm(){
      for (int i = 0; i < 60000; i++)
      {
         int r = rand() % 3;
         if(r == 0) midpoint(v1);
         else if(r == 1) midpoint(v2);
         else midpoint(v3);

         drawPoint(p);

      }

}
void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw points using Chaos Algorithm  */
   chaosAlgorithm();
   
   glFlush ();
}


void init (void) 
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 1.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/* 
 * Declare initial window size, position, and display mode

 * (single buffer and RGBA).  Open window with "Chaos Game:Leon"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Register callback function for keypresses.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutReshapeFunc(reshape);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (300, 300);
   glutCreateWindow ("Choas Game: Leon");
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keypress);
   glutMainLoop();
   return 0;   
}
