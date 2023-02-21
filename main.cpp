#include <GL/gl.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double windowHeight=800, windowWidth=600;
double eyeX=3, eyeY=2.0, eyeZ=12, refX = 0, refY=0,refZ=0;
bool robotswitch=false, lampswitch=false, lightbulbswitch=false, robotwaved=true;
void setMaterial(float difX, float difY, float difZ, float ambX, float ambY, float ambZ, float shine)
{
    float no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    float mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    float mat_diffuse[] = { difX, difY, difZ, 1.0 };
    float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    float mat_shininess[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}


void drawcarpet(float x, float y, float z)
{
    setMaterial(0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x+1.5, y-0.9 ,z+8);
    glScalef(8, 0.01, 8);
    glutSolidCube(1);
    glPopMatrix();
}
void drawroom()
{
    setMaterial(1, 0.5, 0.0, 0.5, 0.25, 0.0, 0.35);
    // floor
    glPushMatrix();
    glTranslatef(1.5, -1, 7);
    glScalef(9, 0.1, 12);
    glutSolidCube(1);
    glPopMatrix();
    setMaterial(1, 1, 0.0, 0.5, 0.5, 0.0, 0.35);
    // right wall
    glPushMatrix();
    glTranslatef(6.05, 1.95, 4);
    glScalef(0.1, 6, 6);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.05, 1.95, 12.2);
    glScalef(0.1, 6, 1.8);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.05, 4.13, 7);
    glScalef(0.1, 1.95, 12);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.05, -0.085, 7);
    glScalef(0.1, 1.8, 12);
    glutSolidCube(1);
    glPopMatrix();


    //windows
    glPushMatrix();
    setMaterial(0, 0, 0, 0, 0, 0, 0);
    glTranslatef(6.05, 1.95, 9.2);
    glScalef(0.05, 2, 4);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(6.05, 3.05, 9.2);
    glScalef(0.08, 0.2, 4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.05, 0.85, 9.2);
    glScalef(0.08, 0.2, 4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.05, 1.95, 7.1);
    glScalef(0.08, 2.43, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.05, 1.95, 11.2);
    glScalef(0.08, 2.43, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.05, 1.95, 10);
    glScalef(0.1, 2.43, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.05, 1.95, 8.7);
    glScalef(0.1, 2.43, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6, 1.95, 8.7);
    glScalef(0.1, 0.5, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, 0.8, 9.2);
    glScalef(0.15, 0.1, 4);
    glutSolidCube(1);
    glPopMatrix();

    //curtains

    glPushMatrix();
    glTranslatef(6.0, 4.9, 9.1);
    glScalef(0.15, 0.1, 5.6);
    glutSolidCube(1);
    glPopMatrix();


    setMaterial(0, 0, 1, 0, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(6.0, 2.5, 6.5);
    glScalef(0.1, 4.8, 0.4);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.0, 2.5, 11.7);
    glScalef(0.1, 4.8, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1, 1, 0.0, 0.5, 0.5, 0.0, 0.35);



    // left wall
    glPushMatrix();
    glTranslatef(-3, 1.95, 7);
    glScalef(0.1, 6, 12);
    glutSolidCube(1);
    glPopMatrix();


    // back wall
    glPushMatrix();
    glTranslatef(-1.05, 1.95, 1);
    glScalef(4, 6, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4.5, 1.95, 1);
    glScalef(3.1, 6, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2, 4.45, 1);
    glScalef(2.1, 1.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    // door

    glPushMatrix();
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    glTranslatef(1.95, 1.5, 1);
    glScalef(2, 4.75, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    setMaterial(1, 1, 1, 0.5, 0.5, 0.5, 0.35);
    glTranslatef(1.3, 1.2, 1.1);
    glScalef(0.2, 0.2, 0.2);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();
    setMaterial(1, 1, 0.0, 0.5, 0.5, 0.0, 0.35);
    // front wall
    glPushMatrix();
    glTranslatef(1.55, 1.95, 13);
    glScalef(9, 6, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    // ceiling
    glPushMatrix();
    glTranslatef(1.5, 5, 7);
    glScalef(9, 0.1, 12);
    glutSolidCube(1);
    glPopMatrix();

}

void drawbed(float x, float y, float z)
{
    //bed frame
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    glPushMatrix();
    glTranslatef(x-1, y+0.1 , z+6);
    glScalef(2.8, -0.9, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x-1, y+0.1 , z+7.5);
    glScalef(2.8, -0.9, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+0.3, y-0.2 , z+6.7);
    glScalef(0.2, -1.5, 1.65);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.5, y+0.4 , z+6.7);
    glScalef(0.2, -2.6, 1.65);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x-1, y+0.1 , z+6.7);
    glScalef(2.8, 0, 1.65);
    glutSolidCube(1);
    glPopMatrix();


    //mattress
    setMaterial(0.0, 1.0, 0.0, 0.0, 0.5, 0.0, 0.35);
    glPushMatrix();
    glTranslatef(x-1, y+0.2 , z+6.7);
    glScalef(2.6, -0.8, 1.60);
    glutSolidCube(1);
    glPopMatrix();

    //blanket
    setMaterial(0.5, 1.0, 1.0, 0.25, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-0.9, y+0.6 , z+6.6);
    glScalef(2.2, 0.1, 1.5);
    glutSolidCube(1);
    glPopMatrix();


    //pillow
    glPushMatrix();
    glTranslatef(x-2.2, y+0.7 , z+6.6);
    glScalef(0.4, 0.2, 1);
    glutSolidCube(1);
    glPopMatrix();
}

void drawdrawer(float x, float y, float z)
{
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    //frame
    glPushMatrix();
    glTranslatef(x-2.2, y-0.48 , z+8.2);
    glScalef(0.7, 0.86, 1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.35);
    //drawer
    glPushMatrix();
    glTranslatef(x-2.2, y+0.1 , z+8.2);
    glScalef(0.7, 0.3, 1);
    glutSolidCube(1);
    glPopMatrix();

    //handle
    setMaterial(1.0, 1.0, 1.1, 0.5, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-1.8, y+0.1 , z+8.2);
    glScalef(0.05, 0.1, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    //frame top
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    glPushMatrix();
    glTranslatef(x-2.2, y+0.3 , z+8.2);
    glScalef(0.7, 0.1, 1);
    glutSolidCube(1);
    glPopMatrix();
}

void drawbooks(float x, float y, float z)
{
    setMaterial(0, 0, 1, 0, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    setMaterial(1, 0, 0, 0.5, 0, 0, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z+0.2);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 1, 0, 0, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z+0.4);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1, 1, 0, 0.5, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z+0.6);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    setMaterial(1, 0, 1, 0.5, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z+0.8);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(2, 0, 0, 1, 0, 0, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z+1);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 0, 2, 0, 0, 1, 0.35);
    glPushMatrix();
    glTranslatef(x, y , z+1.2);
    glScalef(0.3, 0.6, 0.2);
    glutSolidCube(1);
    glPopMatrix();
}

void drawlamp(float x, float y, float z)
{
    setMaterial(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 0.35);
    glPushMatrix();
    glTranslatef(x-2.2, y+0.35 , z+8.2);
    glScalef(0.3, 0.2, 0.6);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.2, y+0.4 , z+8.2);
    glScalef(0.1, 1, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1, 1, 1, 1, 1, 1, 0);
    glPushMatrix();
    glTranslatef(x-2.2, y+0.9 , z+8.2);
    glRotatef(270, 1, 0, 0);
    glScalef(0.3, 0.3, 0.7);
    if(lampswitch)
    {
    float light_ambient[]  = {0.5, 0.5, 0.5};
    float light_diffuse[]  = { 1.0, 1.0, 1.0};
    float light_position[] = { 0.7, 1.5, 9.0};
    glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT2, GL_POSITION, light_position);
    float spot_direction[] = { 0.3, -1, -0.8 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT2, GL_SPOT_CUTOFF, 35.0);
    }
    glutSolidCone(0.7, 2, 5 ,5);
    glPopMatrix();
}

void drawshelf(float x, float y, float z)
{
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    //frame
    glPushMatrix();
    glTranslatef(x-2.2, y-0.8 , z+10);
    glScalef(0.7, 0.2, 1.5);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.2, y+0.85 , z+9.2);
    glScalef(0.7, 3.5, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.2, y+0.85 , z+10.8);
    glScalef(0.7, 3.5, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.2, y+0 , z+10);
    glScalef(0.7, 0.2, 1.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x-2.2, y+0.8 , z+10);
    glScalef(0.7, 0.2, 1.5);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.2, y+1.6 , z+10);
    glScalef(0.7, 0.2, 1.5);
    glutSolidCube(1);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(x-2.2, y+2.5 , z+10);
    glScalef(0.7, 0.2, 1.5);
    glutSolidCube(1);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(x-2.5, y+0.85 , z+10);
    glScalef(0.1, 3.5, 1.5);
    glutSolidCube(1);
    glPopMatrix();

    //books
    drawbooks(x-2.1, y+2, z+9.4);
    drawbooks(x-2.1, y+1.2, z+9.4);
    drawbooks(x-2.1, y+0.4, z+9.4);
    drawbooks(x-2.1, y-0.4, z+9.4);

}

void drawwardrobe(float x, float y, float z)
{
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    glPushMatrix();
    glTranslatef(x-2.2, y-0.8 , z+11.8);
    glScalef(0.7, 0.2, 1.55);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.2, y+0.9 , z+11.4);
    glScalef(0.7, 3.2, 0.75);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 0, 1, 0, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-2.2, y+0.9 , z+12.2);
    glScalef(0.7, 3.2, 0.75);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 0, 0, 0, 0 ,0 ,0);
    glPushMatrix();
    glTranslatef(x-2.2, y+0.9 , z+11.8);
    glScalef(0.7, 3.2, 0.05);
    glutSolidCube(1);
    glPopMatrix();



    setMaterial(1, 1, 1, 0.5, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-1.8, y+1.3 , z+11.6);
    glScalef(0.1, 0.3, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    setMaterial(1, 1, 1, 0.5, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-1.8, y+1.3 , z+12);
    glScalef(0.1, 0.3, 0.1);
    glutSolidCube(1);
    glPopMatrix();

}

void drawwallshelf(float x, float y, float z)
{
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    //frame
    glPushMatrix();
    glTranslatef(x-2.6, y+3 , z+3);
    glScalef(0.7, 0.5, 3);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.9, y+3.7 , z+3);
    glScalef(0.1, 0.9, 3);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+3);
    glScalef(0.7, 0.9, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+1.6);
    glScalef(0.7, 0.9, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+4.4);
    glScalef(0.7, 0.9, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    //books
    setMaterial(0, 0, 1, 0, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+2.75);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1, 0, 1, 0.5, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+2.45);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1, 0, 0, 0.5, 0, 0, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+2.15);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 1, 0, 0, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+1.85);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 1, 0, 0, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+3.25);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 0, 2, 0, 0, 1, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+3.55);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(1, 0, 0, 0.5, 0, 0, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+3.85);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 1, 0, 0, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x-2.6, y+3.65 , z+4.15);
    glScalef(0.3, 0.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();
}

void drawdesk(float x, float y, float z)
{
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    //frame
    glPushMatrix();
    glTranslatef(x+5.5, y+0.4 , z+3);
    glScalef(1, 3, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+5.5, y+0.4 , z+5);
    glScalef(1, 3, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+5.5, y+1.8 , z+4);
    glScalef(1, 0.2, 3);
    glutSolidCube(1);
    glPopMatrix();


    //paper
    setMaterial(1, 1, 1, 0.5, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x+5.5, y+1.9 , z+4);
    glScalef(0.7, 0.05, 0.5);
    glutSolidCube(1);
    glPopMatrix();



    setMaterial(1, 1, 1, 0.5, 0.5, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x+5.5, y+1.9 , z+3);
    glScalef(0.7, 0.2, 0.5);
    glutSolidCube(1);
    glPopMatrix();


    //pencil
    setMaterial(0, 1, 0, 0, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x+5.5, y+1.9 , z+4.51);
    glScalef(0.2, 0.1, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 0.35);
    glPushMatrix();
    glTranslatef(x+5.4, y+1.9 , z+4.5);
    glScalef(0.05, 0.05, 0.1);
    glutSolidCone(1, 0.2, 5, 5);
    glPopMatrix();

}

void drawchair(float x, float y, float z)
{
    setMaterial(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 0.35);
    glPushMatrix();
    glTranslatef(x+4, y-0.55 , z+3.8);
    glScalef(1, 0.2, 0.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4, y-0.55 , z+3.8);
    glScalef(0.2, 0.2, 1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+3.55, y-0.7 , z+3.8);
    glScalef(0.1, 0.2, 0.1);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4.45, y-0.7 , z+3.8);
    glScalef(0.1, 0.2, 0.1);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4, y-0.7 , z+4.25);
    glScalef(0.1, 0.2, 0.1);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+4, y-0.7 , z+3.35);
    glScalef(0.1, 0.2, 0.1);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4, y+0 , z+3.8);
    glScalef(0.1, 1.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4, y+0.5 , z+3.8);
    glScalef(1, 0.2, 1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+3.6, y+1.2 , z+3.8);
    glScalef(0.2, 1.4, 1);
    glutSolidCube(1);
    glPopMatrix();
}

void drawsmallshelf(float x, float y, float z)
{
    setMaterial(0.5, 0.35, 0.05, 0.25, 0.17, 0.02, 0.35);
    //frame
    glPushMatrix();
    glTranslatef(x+4.7, y-0.8 , z+1.5);
    glScalef(1.5, 0.2, 0.6);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4.7, y+0.3 , z+1.15);
    glScalef(1.5, 2.5, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4.7, y+0.3 , z+1.5);
    glScalef(1.5, 0.2, 0.6);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+4.7, y+1.45 , z+1.5);
    glScalef(1.5, 0.2, 0.6);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+4, y+0.3 , z+1.5);
    glScalef(0.1, 2.5, 0.6);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+5.4, y+0.3 , z+1.5);
    glScalef(0.1, 2.5, 0.6);
    glutSolidCube(1);
    glPopMatrix();

    //objects
    setMaterial(0, 0, 1, 0, 0, 0.5, 0.35);
    glPushMatrix();
    glTranslatef(x+4.8, y+1.7 , z+1.5);
    glScalef(0.2, 0.2, 0.3);
    glutSolidSphere(1, 10, 10);
    glPopMatrix();


    setMaterial(1, 0, 0, 0.5, 0, 0, 0.35);
    glPushMatrix();
    glTranslatef(x+4.6, y+0.6 , z+1.5);
    glScalef(0.3, 0.3, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    setMaterial(0, 1, 0, 0, 0.5, 0, 0.35);
    glPushMatrix();
    glTranslatef(x+5.1, y-0.65 , z+1.5);
    glScalef(0.3, 0.3, 0.3);
    glRotatef(270, 1, 0, 0);
    glutSolidCone(0.7, 2, 5 ,5);
    glPopMatrix();
}

void drawrobot(float x, float y, float z)
{
    setMaterial(1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 0.35);
     // Create body
    glPushMatrix();
    glTranslatef(x, y+1, z);
    glRotatef(90, 1, 0, 0);
    glScalef(0.7, 0.3, 0.7);
    glutSolidCone(0.7, 2, 5, 5);
    glPopMatrix();

    // Create neck
    glPushMatrix();
    glTranslatef(x, y+1.2, z);
    glScalef(0.2, 0.4, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // Create head
    glPushMatrix();
    glTranslatef(x, y+1.5, z);
    glScalef(0.45, 0.45, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+0.15, y+1.8, z);
    glScalef(0.1, 0.2, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x-0.15, y+1.8, z);
    glScalef(0.1, 0.2, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    //Create legs base

    glPushMatrix();
    glTranslatef(x, y-0.2, z);
    glScalef(0.5, 0.35, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    // Create right leg
    glPushMatrix();
    glTranslatef(x-0.15, y-1.2, z);
    glScalef(0.2, 1.7, 0.3);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-0.15, y-1.95, z+0.1);
    glScalef(0.2, 0.2, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    // Create right leg
    glPushMatrix();
    glTranslatef(x+0.15, y-1.2, z);
    glScalef(0.2, 1.7, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+0.15, y-1.95, z+0.1);
    glScalef(0.2, 0.2, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    // Create right arm

    glPushMatrix();
    if(!robotwaved)
    {
    glRotatef(35, 0, 0 ,1);
    glTranslatef(x+0.65, y+0.95, z);
    }
    else
    {
    glTranslatef(x-0.40, y+0.2, z);
    }
    glScalef(0.2, 1.2, 0.25);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x-0.4, y+0.9, z);
    glScalef(0.2, 0.2, 0.1);
    glutSolidSphere(1.0, 16 , 16);
    glPopMatrix();


    glPushMatrix();
    if(!robotwaved)
    {
     glTranslatef(x-1.25, y+2, z);
    }
    else
    {
    glTranslatef(x-0.4, y-0.5, z);
    }
    glScalef(0.15, 0.15, 0.1);
    glutSolidSphere(1.0, 16 , 16);
    glPopMatrix();

    // Create left arm
    glPushMatrix();
    glTranslatef(x+0.40, y+0.2, z);
    glScalef(0.2, 1.2, 0.25);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+0.4, y+0.9, z);
    glScalef(0.2, 0.2, 0.1);
    glutSolidSphere(1.0, 16 , 16);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x+0.4, y-0.5, z);
    glScalef(0.15, 0.15, 0.1);
    glutSolidSphere(1.0, 16 , 16);
    glPopMatrix();

    setMaterial(0, 0, 0, 0, 0, 0, 0.35);
    if(robotswitch)
    {
    glColor3f(0, 0, 1);
    glDisable(GL_LIGHTING);
    }
    // Right eye
    glPushMatrix();
    glTranslatef(x+0.1, y+1.6, z+0.1);
    glScalef(0.05, 0.05, 0.01);
    glutSolidSphere(1.0, 16 , 16);
    glPopMatrix();
    // Left eye
    glPushMatrix();
    glTranslatef(x-0.1, y+1.6, z+0.1);
    glScalef(0.05, 0.05, 0.01);
    glutSolidSphere(1.0, 16 , 16);
    glPopMatrix();

    // Nose
    glPushMatrix();
    glTranslatef(x, y+1.5, z+0.1);
    glScalef(0.05, 0.05, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // Mouth
    glPushMatrix();
    glTranslatef(x, y+1.4, z+0.1);
    glScalef(0.2, 0.05, 0.01);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(x-0.1, y+1.41, z+0.1);
    glScalef(0.05, 0.05, 0.01);
    glRotatef(325 ,x, y, z);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+0.1, y+1.41, z+0.1);
    glScalef(0.05, 0.05, 0.01);
    glRotatef(315,x, y, z);
    glutSolidCube(1);
    glPopMatrix();
    if(robotswitch)
    {
        glEnable(GL_LIGHTING);
    }


}

void drawlightbulb(float x, float y, float z)
{
    float no_mat[] = { 0.0, 0.0, 0.0};
    float mat_diffuse[] = { 1.000, 0.843, 0.000 };
    float high_shininess[] = { 100.0 };
    float mat_emission[] = {1.000, 1,1, 0.0};
    float light_position[] = { 5.0, 5.0, 8.0 };
    float light_ambient[]  = {0.5, 0.5, 0.5};
    float light_diffuse[]  = { 1.0, 1.0, 1.0 };
    glPushMatrix();
    glTranslatef (x+1.5, y+4.8, z+5);
    glScalef(0.2, 0.2, 0.2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    if(lightbulbswitch == true){
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
        glLightfv( GL_LIGHT0, GL_SPECULAR, no_mat);
        glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    }else{
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
        glLightfv( GL_LIGHT0, GL_AMBIENT, no_mat);
        glLightfv( GL_LIGHT0, GL_DIFFUSE, no_mat);
        glLightfv( GL_LIGHT0, GL_SPECULAR, no_mat);

    }
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,1,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,  refX,refY,refZ,  0,1,0);
    glEnable(GL_LIGHTING);
    drawroom();
    drawcarpet(0, 0, 0);
    drawbed(0, 0, 0);
    drawdrawer(0, 0, 0);
    drawlamp(0, 0, 0);
    drawshelf(0, 0, 0);
    drawsmallshelf(0, 0, 0);
    drawwardrobe(0, 0, 0);
    drawlightbulb(0, -0.02, 0);
    drawwallshelf(0, 0, 0);
    drawdesk(0, 0.2, 0);
    drawchair(0, 0, 0.3);
    drawrobot(1, 1.2, 8);
    glDisable(GL_LIGHTING);

    glFlush();
    glutSwapBuffers();
}

void keyboard( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case 'w':
            if(eyeZ-1.0>2)
            eyeZ-=1;
            break;
        case 's':
            if(eyeZ+1.0<14)
            eyeZ+=1;
            break;
        case 'a':
            if(eyeX-1.0>-3)
            eyeX-=1.0;
            break;
        case 'd':
            if(eyeX+1.0<6)
            eyeX+=1.0;
            break;
        case 'k':
            if(eyeY-1.0>-1)
            eyeY-=1.0;
            break;
        case 'i':
            if(eyeY+1.0<5)
            eyeY+=1.0;
            break;
        case 'j':
            refX-=1.0;
            break;
        case 'l':
            refX+=1.0;
            break;
        case '1':
            if(lightbulbswitch == false)
            {
                lightbulbswitch = true;
                glEnable( GL_LIGHT0); break;
            }
            else if(lightbulbswitch == true)
            {
                lightbulbswitch = false;
                glDisable( GL_LIGHT0); break;
            }
        case '2':
            if(lampswitch == false)
            {
                lampswitch = true;
                glEnable( GL_LIGHT2); break;
            }
            else if(lampswitch == true)
            {
                lampswitch = false;
                glDisable( GL_LIGHT2); break;
            }
        case '3':
            if(robotswitch == false)
            {
                robotswitch = true;
                robotwaved = false;
                display();
                Sleep(500);
                robotwaved = true;
                break;
            }
            else if(robotswitch == true)
            {
                robotswitch = false;
                break;
            }
            break;

    }

    glutPostRedisplay();
}
void update_scene(int v) {
   glutTimerFunc(1000 / 60, update_scene, 0);
   glutPostRedisplay();

}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("GUI Project");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glutTimerFunc(1000/60, update_scene, 0);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
