#include <Windows.h>
#include <iostream>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

//TUGAS GRAFIKA KOMPUTER -IF8
//GAMBAR 3d DIMENSI

//1.Imam Zainudin       < 10108380 > 
//2.Dimas Ricky F       < 10108401 >
//3.Sani Surya S        < 10108416 >
//4.Hamdi Jamin         < 10109701 >
//5.Kurniawan           < 10106268 >


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0,0.8,0);

    glPushMatrix();//donat
                    glTranslated(-2,0,-6);
                    glScaled(0.5,0.5,0.5);
                    glRotated(60,0,1,0);
                    glRotated(a,0,0,1);
                    glutSolidTorus(1,3,20,40);
     glPopMatrix();
    
    glPushMatrix();//donat2
                    glTranslated(2,0,-6);
                    glScaled(0.5,0.5,0.5);
                    glRotated(60,0,1,0);
                    glRotated(a,0,0,1);
                    glutSolidTorus(1,3,20,40);
     glPopMatrix();
     
    glPushMatrix();
                   glColor3d(1,1,0);
                   glTranslated(0,0,-6);//lingkaran
                   glScaled(1,1,1);
                   glRotated(60,0,1,0);
                   glRotated(a,1,1,0);
                   glutWireSphere(7, 9, 10);
                   //glutSolidCube(2.0);
    glPopMatrix();
    
 
 /*   glPushMatrix();
                   glColor3d(0.5,0,1);
                   glTranslated(-1,0,-6);//kubus
                   glScaled(0.5,0.5,0.5);
                   glRotated(60,0,1,0);
                   glRotated(a,0,0,1);
                   glutSolidTetraHedron(2.0);
    
    glPopMatrix();
*/    
    
    glPushMatrix();
                   glColor3d(0,1,1);
                   glTranslated(-2,0,-6);//kubus1
                   glScaled(0.5,0.5,0.5);
                   glRotated(60,0,1,0);
                   glRotated(a,0,1,1);
                   glutSolidCube(2.0);
    glPopMatrix();
    /*
    glPushMatrix();
                   glColor3d(0.5,0,1);
                   glTranslated(1,0,-6);//kubus
                   glScaled(0.5,0.5,0.5);
                   glRotated(60,0,1,0);
                   glRotated(a,0,0,1);
                   glutSolidCube(2.0);
    glPopMatrix();        
    */
    glPushMatrix();
                   glColor3d(0,1,1);
                   glTranslated(2,0,-6);//kubus2
                   glScaled(0.5,0.5,0.5);
                   glRotated(60,0,1,0);
                   glRotated(a,1,0,1);
                   glutSolidCube(2.0);
    glPopMatrix();
            
    glutSwapBuffers();
}

void setCamera()
{

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(2,5,8,0,2,0,0,2,0.0);
}

static void idle(void)
{
    glutPostRedisplay();
    setCamera();
}


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("TUGAS GRAFIKA KOMPUTER OBJEK 3D");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
