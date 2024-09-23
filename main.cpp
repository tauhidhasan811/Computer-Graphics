#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>


float _move = 0.0f;
float _move1 = 0.0f;
bool isRaining = false;
bool isCity= false;

void circle(float radius, float cX, float cY, int r, int g, int b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
    {
        glColor3ub(r, g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);

    }
    glEnd();
}

void cloud_circle(float radius, float cX, float cY)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
    {
        glColor3ub(255, 255, 255); // Pure white for clouds
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);

    }
    glEnd();
}

void Cloud()
{
    cloud_circle( 0.13, -1.74, 1.368);
    cloud_circle( 0.155, -1.5945, 1.4423);
    cloud_circle( 0.13, -1.4434, 1.368);
    cloud_circle( 0.155, -1.5945, 1.2843);
}

void Cloud1()
{
    cloud_circle( 0.13, 0.5258, 1.6051);
    cloud_circle( 0.155, 0.6391, 1.7184);
    cloud_circle( 0.13, 0.76883, 1.6114);
    cloud_circle( 0.155, 0.6391, 1.5632);
}

void road_down()
{
    glMatrixMode(GL_POLYGON);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2f(-2.0f,-1.0f);
	glVertex2f(-2.0f,-0.55f);
	glVertex2f(2.0f,-0.55f);
	glVertex2f(2.0f,-1.00f);
	glEnd();


	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19); // Soil brown
	glVertex2f(-2.0f,-1.0f);
	glVertex2f(-2.0f,-1.05f);
	glVertex2f(2.0f, -1.05f);
	glVertex2f(2.0f, -1.00f);
	glEnd();
}
void road_up()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(1, 1, 1);
	glVertex2f(-2.0f,-0.45f);
	glVertex2f(-2.0f,-0.00f);
	glVertex2f(2.0f, 0.00f);
	glVertex2f(2.0f,-0.45f);
	glEnd();
	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19); // Soil brown
	glVertex2f(-2.0f, 0.00f);
	glVertex2f(-2.0f, 0.05f);
	glVertex2f(2.0f,  0.05f);
	glVertex2f(2.0f,  0.00f);
	glEnd();
}
void devider()
{
    glMatrixMode(GL_POLYGON);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-2.0f,-0.55f);
	glVertex2f(-2.0f,-0.45f);
	glVertex2f(-1.5f,-0.45f);
	glVertex2f(-1.5f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-0.70f,-0.55f);
	glVertex2f(-0.70f,-0.45f);
	glVertex2f(-1.3f,-0.45f);
	glVertex2f(-1.3f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(0.9f,-0.55f);
	glVertex2f(0.9f,-0.45f);
	glVertex2f(1.4f,-0.45f);
	glVertex2f(1.4f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-0.50f,-0.55f);
	glVertex2f(-0.50f,-0.45f);
	glVertex2f(-0.00f,-0.45f);
	glVertex2f(-0.00f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(0.2f,-0.55f);
	glVertex2f(0.2f,-0.45f);
	glVertex2f(0.7f,-0.45f);
	glVertex2f(0.7f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1.6f,-0.55f);
	glVertex2f(1.6f,-0.45f);
	glVertex2f(2.00f,-0.45f);
	glVertex2f(2.00f, -0.550f);
	glEnd();
	glPopMatrix();


	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-1.3f,-0.55f);
	glVertex2f(-1.3f,-0.45f);
	glVertex2f(-1.5f,-0.45f);
	glVertex2f(-1.5f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-0.7f,-0.55f);
	glVertex2f(-0.7f,-0.45f);
	glVertex2f(-0.5f,-0.45f);
	glVertex2f(-0.5f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2f(-0.0f,-0.55f);
	glVertex2f(-0.0f,-0.45f);
	glVertex2f(0.2f,-0.45f);
	glVertex2f(0.2f, -0.550f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(0.7f,-0.55f);
	glVertex2f(0.7f,-0.45f);
	glVertex2f(0.9f,-0.45f);
	glVertex2f(0.9f, -0.550f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(1.4f,-0.55f);
	glVertex2f(1.4f,-0.45f);
	glVertex2f(1.6f,-0.45f);
	glVertex2f(1.6f, -0.550f);
	glEnd();


}

void building1()
{
    glMatrixMode(GL_MODELVIEW);  // Use GL_MODELVIEW for transformations
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);  // Apply movement to the building

    // Building Section 1 (Left-most)
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);  // Blue color for the building
    glVertex2f(-1.5f, 0.05f);
    glVertex2f(-1.3f, 0.05f);
    glVertex2f(-1.3f, 0.6f);  // Increased height for proportion
    glVertex2f(-1.5f, 0.6f);
    glEnd();

    // Building Section 2
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-1.3f, 0.05f);
    glVertex2f(-1.1f, 0.05f);
    glVertex2f(-1.1f, 1.0f);  // Proportionally increased height
    glVertex2f(-1.3f, 1.0f);
    glEnd();

    // Windows for Building Section 2
    for (int i = 0; i < 5; i++) {  // Reduced the number of windows for better fit
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);  // White color for the windows
        float windowHeight = 0.075f;
        float windowWidth = 0.05f;
        float spacing = 0.03f;
        float yStart = 0.9f - i * (windowHeight + spacing);  // Adjusted for section 2 height

        // Window coordinates
        glVertex2f(-1.25f, yStart);
        glVertex2f(-1.25f, yStart - windowHeight);
        glVertex2f(-1.2f, yStart - windowHeight);
        glVertex2f(-1.2f, yStart);
        glEnd();
    }

    // Building Section 3
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-1.1f, 0.05f);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.95f, 1.2f);  // Increased height for section 3
    glVertex2f(-1.1f, 1.2f);
    glEnd();

    // Building Section 4
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.75f, 0.05f);
    glVertex2f(-0.75f, 1.4f);  // Tallest section of the building
    glVertex2f(-0.95f, 1.4f);
    glEnd();

    // Building Section 5
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.75f, 0.05f);
    glVertex2f(-0.6f, 0.05f);
    glVertex2f(-0.6f, 1.3f);  // Proportional height for section 5
    glVertex2f(-0.75f, 1.3f);
    glEnd();

    // Building Section 6
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.6f, 0.05f);
    glVertex2f(-0.4f, 0.05f);
    glVertex2f(-0.4f, 1.1f);  // Reduced height for next section
    glVertex2f(-0.6f, 1.1f);
    glEnd();

    // Building Section 7 (Right-most)
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.4f, 0.05f);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.2f, 0.7f);  // Smaller section
    glVertex2f(-0.4f, 0.7f);
    glEnd();

    glPopMatrix();
}
void burjKhalifa()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);  // Apply movement to the building

    // Base section (largest, bottom-most)
    glBegin(GL_POLYGON);
    glColor3ub(255, 155, 55); // Sky blue
    glVertex2f(-1.5f, 0.05f);  // Bottom left
    glVertex2f(-0.5f, 0.05f);  // Bottom right
    glVertex2f(-0.5f, 0.8f);   // Top right of the base section
    glVertex2f(-1.5f, 0.8f);   // Top left of the base section
    glEnd();

    // Divider line for base section
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);  // Black color for divider line
    glVertex2f(-1.5f, 0.8f);  // Left end of the line
    glVertex2f(-0.5f, 0.8f);  // Right end of the line
    glEnd();

    // Windows for the base section
    for (int i = 0; i < 4; i++) {  // 4 rows of windows
        for (int j = 0; j < 5; j++) {  // 5 windows per row
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255);  // White color for the windows
            float windowHeight = 0.05f;
            float windowWidth = 0.1f;
            float yStart = 0.75f - i * 0.15f;  // Spacing for rows
            float xStart = -1.45f + j * 0.2f;  // Spacing for windows in a row

            glVertex2f(xStart, yStart);  // Bottom left
            glVertex2f(xStart, yStart - windowHeight);  // Top left
            glVertex2f(xStart + windowWidth, yStart - windowHeight);  // Top right
            glVertex2f(xStart + windowWidth, yStart);  // Bottom right
            glEnd();
        }
    }

    // Middle section 1
    glBegin(GL_POLYGON);
    glColor3ub(255, 155, 55);
    glVertex2f(-1.3f, 0.8f);  // Bottom left
    glVertex2f(-0.7f, 0.8f);  // Bottom right
    glVertex2f(-0.7f, 1.3f);  // Top right
    glVertex2f(-1.3f, 1.3f);  // Top left
    glEnd();

    // Divider line for middle section 1
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);  // Black color for divider line
    glVertex2f(-1.3f, 1.3f);  // Left end of the line
    glVertex2f(-0.7f, 1.3f);  // Right end of the line
    glEnd();

    // Windows for middle section 1
    for (int i = 0; i < 3; i++) {  // 3 rows of windows
        for (int j = 0; j < 3; j++) {  // 4 windows per row
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255); // Sky blue
  // White color for the windows
            float windowHeight = 0.05f;
            float windowWidth = 0.08f;
            float yStart = 1.25f - i * 0.15f;  // Adjusted row spacing
            float xStart = -1.25f + j * 0.2f;  // Adjusted window spacing

            glVertex2f(xStart, yStart);
            glVertex2f(xStart, yStart - windowHeight);
            glVertex2f(xStart + windowWidth, yStart - windowHeight);
            glVertex2f(xStart + windowWidth, yStart);
            glEnd();
        }
    }

    // Middle section 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 155, 55);
    glVertex2f(-1.1f, 1.3f);  // Bottom left
    glVertex2f(-0.9f, 1.3f);  // Bottom right
    glVertex2f(-0.9f, 1.7f);  // Top right
    glVertex2f(-1.1f, 1.7f);  // Top left
    glEnd();

    // Divider line for middle section 2
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);  // Black color for divider line
    glVertex2f(-1.1f, 1.7f);  // Left end of the line
    glVertex2f(-0.9f, 1.7f);  // Right end of the line
    glEnd();

    // Windows for middle section 2
    for (int i = 0; i < 2; i++) {  // 2 rows of windows
        for (int j = 0; j < 1; j++) {  // 3 windows per row
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255); // Sky blue

            float windowHeight = 0.05f;
            float windowWidth = 0.07f;
            float yStart = 1.65f - i * 0.15f;  // Adjusted row spacing
            float xStart = -1.05f + j * 0.15f;  // Adjusted window spacing

            glVertex2f(xStart, yStart);
            glVertex2f(xStart, yStart - windowHeight);
            glVertex2f(xStart + windowWidth, yStart - windowHeight);
            glVertex2f(xStart + windowWidth, yStart);
            glEnd();
        }
    }



    // Divider line for upper section 1
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);  // Black color for divider line
    glVertex2f(-1.0f, 2.0f);  // Left end of the line
    glVertex2f(-0.8f, 2.0f);  // Right end of the line
    glEnd();

    // Windows for upper section 1


    // Upper section 2 (without windows)
    glBegin(GL_POLYGON);
    glColor3ub(255, 155, 55);
    glVertex2f(-0.95f, 2.0f);  // Bottom left
    glVertex2f(-0.85f, 2.0f);  // Bottom right
    glVertex2f(-0.85f, 2.2f);  // Top right
    glVertex2f(-0.95f, 2.2f);  // Top left
    glEnd();

    // Divider line for upper section 2
    glBegin(GL_LINES);

}

void Buildings()
{
    // Number of floors for each building
    int floors1 = 3, floors2 = 4, floors3 = 2, floors4 = 5, floors5 = 6;
    float floorHeight1 = 0.6f / floors1;  // Height for 1st building's floor
    float floorHeight2 = 0.7f / floors2;  // Height for 2nd building's floor
    float floorHeight3 = 0.5f / floors3;  // Height for 3rd building's floor
    float floorHeight4 = 0.9f / floors4;  // Height for 4th building's floor
    float floorHeight5 = 0.8f / floors5;  // Height for 5th building's floor

    // Define window size
    float windowWidth = 0.05f;
    float windowHeight = 0.05f;

    /// 5th Building (Shifted to the left)
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);  // Red color for 5th building
    glVertex2f(-0.25f, 0.05f);
    glVertex2f(-0.25f, 0.8f);
    glVertex2f(0.05f, 0.8f);
    glVertex2f(0.05f, 0.05f);
    glEnd();

    // Floors and windows for 5th Building
    for (int i = 0; i < floors5-1; i++) {
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);  // Floor lines in white
        glVertex2f(-0.25f, 0.05f + (i + 1) * floorHeight5);
        glVertex2f(0.05f, 0.05f + (i + 1) * floorHeight5);
        glEnd();

        // Windows for each floor
        for (int j = 0; j < 3; j++) {
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255);  // Window color (white)
            glVertex2f(-0.22f + j * 0.1f, 0.05f + (i * floorHeight5) + 0.02f);
            glVertex2f(-0.22f + j * 0.1f, 0.05f + (i * floorHeight5) + 0.02f + windowHeight);
            glVertex2f(-0.17f + j * 0.1f, 0.05f + (i * floorHeight5) + 0.02f + windowHeight);
            glVertex2f(-0.17f + j * 0.1f, 0.05f + (i * floorHeight5) + 0.02f);
            glEnd();
        }
    }

    /// 1st Building (Shifted to the left)
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 128);  // Green color for 1st building
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.1f, 0.65f);
    glVertex2f(0.5f, 0.65f);
    glVertex2f(0.5f, 0.05f);
    glEnd();

    // Floors and windows for 1st Building
    for (int i = 0; i < floors1; i++) {
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.1f, 0.05f + (i + 1) * floorHeight1);
        glVertex2f(0.5f, 0.05f + (i + 1) * floorHeight1);
        glEnd();

        // Windows for each floor
        for (int j = 0; j < 4; j++) {
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255);
            glVertex2f(0.15f + j * 0.08f, 0.09f + (i * floorHeight1) + 0.022f);
            glVertex2f(0.15f + j * 0.08f, 0.09f + (i * floorHeight1) + 0.022f + windowHeight);
            glVertex2f(0.2f + j * 0.08f, 0.09f + (i * floorHeight1) + 0.022f + windowHeight);
            glVertex2f(0.2f + j * 0.08f, 0.09f + (i * floorHeight1) + 0.022f);
            glEnd();
        }
    }

    /// 2nd Building (Shifted to the left)
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);  // Blue color for 2nd building
    glVertex2f(0.55f, 0.05f);
    glVertex2f(0.55f, 0.75f);
    glVertex2f(0.95f, 0.75f);
    glVertex2f(0.95f, 0.05f);
    glEnd();

    // Floors and windows for 2nd Building
    for (int i = 0; i < floors2; i++) {
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.55f, 0.05f + (i + 1) * floorHeight2);
        glVertex2f(0.95f, 0.05f + (i + 1) * floorHeight2);
        glEnd();

        // Windows for each floor
        for (int j = 0; j < 4; j++) {
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255);
            glVertex2f(0.6f + j * 0.08f, 0.09f + (i * floorHeight2) + 0.02f);
            glVertex2f(0.6f + j * 0.08f, 0.09f + (i * floorHeight2) + 0.02f + windowHeight);
            glVertex2f(0.65f + j * 0.08f, 0.09f + (i * floorHeight2) + 0.02f + windowHeight);
            glVertex2f(0.65f + j * 0.08f, 0.09f + (i * floorHeight2) + 0.02f);
            glEnd();
        }
    }

    /// 3rd Building (Shifted to the left)
    glBegin(GL_POLYGON);
    glColor3ub(255, 155, 55);  // Yellow color for 3rd building
    glVertex2f(1.05f, 0.05f);
    glVertex2f(1.05f, 0.5f);
    glVertex2f(1.5f, 0.5f);
    glVertex2f(1.5f, 0.05f);
    glEnd();

    // Floors and windows for 3rd Building
    for (int i = 0; i < floors3; i++) {
        if(i<floors3-1){
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(1.05f, 0.05f + (i + 1) * floorHeight3);
        glVertex2f(1.5f, 0.05f + (i + 1) * floorHeight3);
        glEnd();}

        // Windows for each floor
        for (int j = 0; j < 4; j++) {
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255);
            glVertex2f(1.1f + j * 0.08f, 0.1f + (i * floorHeight3) + 0.02f);
            glVertex2f(1.1f + j * 0.08f, 0.1f + (i * floorHeight3) + 0.02f + windowHeight);
            glVertex2f(1.15f + j * 0.08f, 0.1f + (i * floorHeight3) + 0.02f + windowHeight);
            glVertex2f(1.15f + j * 0.08f, 0.1f + (i * floorHeight3) + 0.02f);
            glEnd();
        }
    }

    /// 4th Building (Shifted to the left)
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);  // Purple color for 4th building
    glVertex2f(1.55f, 0.05f);
    glVertex2f(1.55f, 0.9f);
    glVertex2f(1.75f, 0.9f);
    glVertex2f(1.75f, 0.05f);
    glEnd();

    // Floors and windows for 4th Building
    for (int i = 0; i < floors4; i++) {

        if (i<floors4-1)
        {
            glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(1.55f, 0.05f + (i + 1) * floorHeight4);
            glVertex2f(1.75f, 0.05f + (i + 1) * floorHeight4);
            glEnd();
        }

        // Windows for each floor
        for (int j = 0; j < 2; j++) {
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255);
            glVertex2f(1.57f + j * 0.08f, 0.05f + (i * floorHeight4) + 0.02f);
            glVertex2f(1.57f + j * 0.08f, 0.05f + (i * floorHeight4) + 0.02f + windowHeight);
            glVertex2f(1.62f + j * 0.08f, 0.05f + (i * floorHeight4) + 0.02f + windowHeight);
            glVertex2f(1.62f + j * 0.08f, 0.05f + (i * floorHeight4) + 0.02f);
            glEnd();
        }
    }
}

void drawRiver()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);  // Blue color for the river
    glVertex2f(-2.0f, -1.05f);  // L(-2, -1.05)
    glVertex2f(2.0f, -1.05f);   // M(2, -1.05)
    glVertex2f(2.0f, -2.0f);    // O(2, -2)
    glVertex2f(-2.0f, -2.0f);   // N(-2, -2)
    glEnd();
}

void drawBoat2()
{
    // Ship Body
    glBegin(GL_POLYGON);
    glColor3ub(128, 128, 128);  // Gray color for the ship body
    glVertex2f(-1.2f, -1.2f);   // Bottom left
    glVertex2f(-0.8f, -1.2f);   // Bottom right
    glVertex2f(-0.7f, -1.1f);   // Top right
    glVertex2f(-1.3f, -1.1f);   // Top left
    glEnd();

    // Ship Cabin
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);  // Black color for the cabin
    glVertex2f(-1.1f, -1.1f);   // Bottom left of cabin
    glVertex2f(-0.9f, -1.1f);   // Bottom right of cabin
    glVertex2f(-0.9f, -1.0f);   // Top right of cabin
    glVertex2f(-1.1f, -1.0f);   // Top left of cabin
    glEnd();
}

void drawBoat1()
{
    // Boat Body
    glBegin(GL_POLYGON);
    glColor3ub(165, 42, 42);  // Brown color for the boat
    glVertex2f(0.4f, -1.7f);  // Bottom left
    glVertex2f(0.8f, -1.7f);  // Bottom right
    glVertex2f(0.7f, -1.6f);  // Top right
    glVertex2f(0.5f, -1.6f);  // Top left
    glEnd();

    // Boat Sail (Triangle)
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);  // White color for the sail
    glVertex2f(0.6f, -1.6f);  // Left bottom corner
    glVertex2f(0.7f, -1.6f);  // Right bottom corner
    glVertex2f(0.65f, -1.4f); // Top of the sail
    glEnd();
}


void drawLampPost()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(0,-1.95,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(1,-1.95,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(2,-1.95,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}
void drawLampPost3()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(-1,-1.95,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost4()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(-2,-1.95,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost5()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(-2,0.69,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost6()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(-.5,0.69,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost7()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(0.5,0.69,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}

void drawLampPost8()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.7,0.4,0);
    glTranslatef(2,0.69,0);

    // Pole of the lamppost
    glColor3ub(105, 105, 105); // Dark gray color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Lamp head (rectangular base)
    glColor3ub(169, 169, 169); // Light gray for the base of the lamp head
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.08, 0.4);
    glVertex2f(-0.08, 0.4);
    glEnd();

    // Lamp (light bulb)
    glColor3ub(255, 255, 0); // Yellow color for the light bulb
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.4);
    glVertex2f(0.05, 0.4);
    glVertex2f(0.05, 0.48);
    glVertex2f(-0.05, 0.48);
    glEnd();

    // Top of the lamp head
    glColor3ub(169, 169, 169); // Light gray top cover
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.48);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.07, 0.52);
    glVertex2f(-0.07, 0.52);
    glEnd();

    // Lamp Post base
    glColor3ub(70, 70, 70); // Dark gray base for the lamppost
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, -0.6);
    glVertex2f(0.06, -0.6);
    glVertex2f(0.08, -0.65);
    glVertex2f(-0.08, -0.65);
    glEnd();

    glPopMatrix();
}
void tree(int x)
{
    // Trunk of the tree
    glBegin(GL_POLYGON);
    glColor3ub(65, 55, 48);  // Brown color for the trunk
    glVertex2f(-1.88f + x, 0.05f );  // Bottom left
    glVertex2f(-1.88f + x, 0.3f );   // Top left
    glVertex2f(-1.84f + x, 0.3f );   // Top right
    glVertex2f(-1.84f + x, 0.05f );  // Bottom right
    glEnd();

    // Lower part of the tree (1st triangle)
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 0);  // Green color for the leaves
    glVertex2f(-1.95f + x, 0.3f );   // Left corner
    glVertex2f(-1.77f + x, 0.3f );   // Right corner
    glVertex2f(-1.86f + x, 0.5f );   // Top of the triangle
    glEnd();

    // Middle part of the tree (2nd triangle)
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 0);  // Green color for the leaves
    glVertex2f(-1.92f + x, 0.4f );   // Left corner
    glVertex2f(-1.8f + x, 0.4f  );    // Right corner
    glVertex2f(-1.86f + x, 0.6f );   // Top of the triangle
    glEnd();

    // Upper part of the tree (3rd triangle)
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 0);  // Green color for the leaves
    glVertex2f(-1.89f + x, 0.5f );   // Left corner
    glVertex2f(-1.83f + x, 0.5f );   // Right corner
    glVertex2f(-1.86f + x, 0.7f );   // Top of the triangle
    glEnd();
}


void Sky()
{

    if (isRaining) {
        glBegin(GL_POLYGON);
        glColor3ub(105, 105, 105); // Dark gray for rainy sky
        glVertex2f(-2, 2);
        glVertex2f(2, 2);
        glColor3ub(169, 169, 169); // Light gray for rainy sky gradient
        glVertex2f(2, 0.05);
        glVertex2f(-2, 0.05);
        glEnd();
    }
    else
    {
        glBegin(GL_POLYGON);
        glColor3ub(135, 206, 235); // Light blue for normal sky
        glVertex2f(-2, 2);
        glVertex2f(2, 2);
        glColor3ub(173, 216, 230); // Lighter blue for sky gradient
        glVertex2f(2, 0.05);
        glVertex2f(-2, 0.05);
        glEnd();
    }
}


void boat()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19); // Brown for the boat body
	glVertex2f(-1.7, -1.6);
	glVertex2f(-1.6, -1.7);
	glVertex2f(-1.4, -1.8);
	glVertex2f(-1, -1.8);
	glVertex2f(-0.8, -1.7);
	glVertex2f(-0.7, -1.6);
	glEnd();

	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255); // White for the boat sail
	glVertex2f(-1.4, -1.5);
	glVertex2f(-1.5, -1.6);
	glVertex2f(-0.9, -1.6);
	glVertex2f(-1, -1.5);
	glEnd();
}

void boat1()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(139, 0, 0); // Dark blue for the boat body
	glVertex2f(1, -1.2);
	glVertex2f(1.2, -1.4);
	glVertex2f(1.7, -1.4);
	glVertex2f(1.9, -1.2);
	glEnd();
}

void Car1()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(255, 1, 55);
	glVertex2f(-1.9, -0.75);
	glVertex2f(-1.9, -0.85);
	glVertex2f(-1.15, -0.85);
	glVertex2f(-1.15, -0.75);
	glEnd();
	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(255, 1, 55);
	glVertex2f(-1.3, -0.75);
	glVertex2f(-1.8, -0.75);
	glVertex2f(-1.7, -0.65);
	glVertex2f(-1.4, -0.65);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(173, 216, 230);
	glVertex2f(-1.68, -0.67);
	glVertex2f(-1.68, -0.73);
	glVertex2f(-1.58, -0.73);
	glVertex2f(-1.58, -0.67);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(173, 216, 230);
	glVertex2f(-1.52, -0.67);
	glVertex2f(-1.52, -0.73);
	glVertex2f(-1.42, -0.73);
	glVertex2f(-1.42, -0.67);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(1, 1, 1);
	glVertex2f(-1.55, -0.65);
	glVertex2f(-1.55, -0.75);
	glEnd();

	circle(0.06, -1.72, -0.85, 64, 64, 64);
	circle(0.06, -1.32, -0.85, 64, 64, 64);
}

void Car2()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(0, 1, 255);
	glVertex2f(1.3, -0.25);
	glVertex2f(1.3, -0.35);
	glVertex2f(1.9, -0.35);
	glVertex2f(1.9, -0.25);
	glEnd();
	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(0, 1, 255);
	glVertex2f(1.85, -0.25);
	glVertex2f(1.4, -0.25);
	glVertex2f(1.5, -0.15);
	glVertex2f(1.75, -0.15);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(173, 216, 230);
	glVertex2f(1.51, -0.17);
	glVertex2f(1.51, -0.24);
	glVertex2f(1.59, -0.24);
	glVertex2f(1.59, -0.17);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(173, 216, 230);
	glVertex2f(1.65, -0.17);
	glVertex2f(1.65, -0.24);
	glVertex2f(1.74, -0.24);
	glVertex2f(1.74, -0.17);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(1, 1, 1);
	glVertex2f(1.62, -0.15);
	glVertex2f(1.62, -0.35);
	glEnd();

	///trair
	circle(0.06, 1.4, -0.35, 64, 64, 64);
	circle(0.06, 1.82, -0.35, 64, 64, 64);
}

void bus()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.9, -0.3);
	glVertex2f(-0.45, -0.3);
	glVertex2f(-0.45, -0.1);
	glEnd();
	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(255, 255, 0);
	glVertex2f(-0.9,-0.2);
	glVertex2f(-0.9, -0.3);
	glVertex2f(-1, -0.3);
	glVertex2f(-1, -0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(173, 216, 230);
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.9, -0.2);
	glVertex2f(-1, -0.2);
	glVertex2f(-0.98, -0.18);
	glVertex2f(-0.9662810977655, -0.1589276009894);
	glVertex2f(-0.96, -0.14);
	glVertex2f(-0.94, -0.12);
	glEnd();

	///Door
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(-0.88, -0.18);
	glVertex2f(-0.88, -0.3);
	glVertex2f(-0.82, -0.3);
	glVertex2f(-0.82, -0.18);
	glEnd();

	///Windows
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(-0.8, -0.14);
	glVertex2f(-0.8, -0.22);
	glVertex2f(-0.72, -0.22);
	glVertex2f(-0.72, -0.14);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(-0.71, -0.14);
	glVertex2f(-0.71, -0.22);
	glVertex2f(-0.63, -0.22);
	glVertex2f(-0.63,-0.14);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(-0.62, -0.14);
	glVertex2f(-0.62, -0.22);
	glVertex2f(-0.54, -0.22);
	glVertex2f(-0.54, -0.14);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(-0.53, -0.14);
	glVertex2f(-0.53, -0.22);
	glVertex2f(-0.47, -0.22);
	glVertex2f(-0.47, -0.14);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(1, 1, 1);
	glVertex2f(-1.55, -0.65);
	glVertex2f(-1.55, -0.75);
	glEnd();

	///trair
	circle(0.048, -0.93, -0.3, 64, 64, 64);
	circle(0.048, -0.52,-0.3 , 64, 64, 64);
}

void Plane()
{
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	glVertex2f(1.2, 1.7);
	glVertex2f(1.2, 1.5);
	glVertex2f(1.8, 1.5);
	glVertex2f(1.8, 1.7);
	glEnd();
	glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1.9, 1.9);
	glVertex2f(1.8, 1.7);
	glVertex2f(1.8, 1.5);
	glVertex2f(1.9, 1.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1.2, 1.7);
	glVertex2f(1.2, 1.5);
	glVertex2f(1.05, 1.5);
	glVertex2f(1.05, 1.55);
	glVertex2f(1.1, 1.6);
	glVertex2f(1.1311911141586, 1.6495988383699);
	glVertex2f(1.2, 1.7);
	glEnd();

	///Door


	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(1.14999, 1.66336);
	glVertex2f(1.1311911141586, 1.6495988383699);
	glVertex2f(1.1, 1.6);
	glVertex2f(1.15, 1.6);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(1.3, 1.64);
	glVertex2f(1.3, 1.56);
	glVertex2f(1.38, 1.56);
	glVertex2f(1.38, 1.64);
	glEnd();

	///Windows
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(1.42, 1.64);
	glVertex2f(1.42, 1.56);
	glVertex2f(1.5, 1.56);
	glVertex2f(1.5, 1.64);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(1.54, 1.64);
	glVertex2f(1.54, 1.56);
	glVertex2f(1.62, 1.56);
	glVertex2f(1.62, 1.64);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0, 216, 230);
	glVertex2f(1.66, 1.64);
	glVertex2f(1.66, 1.56);
	glVertex2f(1.74, 1.56);
	glVertex2f(1.74, 1.64);
	glEnd();

	///Wings
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1.4, 1.5);
	glVertex2f(1.6, 1.3);
	glVertex2f(1.7, 1.4);
	glVertex2f(1.6, 1.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1.4, 1.7);
	glVertex2f(1.6, 1.9);
	glVertex2f(1.7, 1.8);
	glVertex2f(1.6, 1.7);
	glEnd();

	}

float car1X = 0.0f;
float car2X = 0.0f;
float busY1 = 0.0f;
float boat2Y = 0.0f;
float boat1X =0.0f;
float cloudX= 0.0f;
float cloudY= 0.00f;
float plane =0.0f;
float speed= 0.0f;
void updateCloud1(int value)
{
    cloudY -= 0.002f+speed;


    if (cloudY < -2.5f)
    {
        cloudY = 1.8f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateCloud1, 0);
}
void updateCloud(int value)
{
    cloudX -= 0.002f+speed;


    if (cloudX < -0.5f)
    {
        cloudX = 3.8f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateCloud, 0);
}
void updateBoat1(int value)
{
    boat1X += 0.005f+speed;


    if (boat1X > 4.0f)
    {
        boat1X = -1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateBoat1, 0);
}
void updateBoat2(int value)
{
    boat2Y -= 0.005f+speed;


    if (boat2Y < -4.0f)
    {
        boat2Y = 1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateBoat2, 0);
}
void updateCar1(int value)
{
    car1X += 0.01f+speed;


    if (car1X > 4.0f)
    {
        car1X = -1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateCar1, 0);
}
void updateCar2(int value)
{
    car2X -= 0.01f+speed;


    if (car2X < -4.0f)
    {
        car2X = 1.30f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateCar2, 0);
}
void updateBusCity(int value)
{
    busY1 -= 0.01f+speed;


    if (busY1 < -2.0f)
    {
        busY1 = 3.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateBusCity, 0);
}
void updatePlane(int value)
{
    plane -= 0.005f+speed;


    if (plane < -3.5f)
    {
        plane = 3.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updatePlane, 0);
}
void moveCar1(float xOffset)
{
    glPushMatrix();
    glTranslatef(xOffset, 0.0f, 0.0f);
    Car1();
    glPopMatrix();
}
void moveCar2(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    Car2();
    glPopMatrix();
}
void moveBus(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    bus();
    glPopMatrix();
}
void moveBoat1(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    boat();
    glPopMatrix();
}
void moveBoat2(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    boat1();
    glPopMatrix();
}
void moveCloud(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    Cloud();
    glPopMatrix();
}
void moveCloud1(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    Cloud1();
    glPopMatrix();
}
void movePlane(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    Plane();
    glPopMatrix();
}




///Village


bool isDay = true; // Start with night scene
void grass1()
{
    // Darker green at the bottom for depth
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0); // Dark green
    glVertex2f(-2, -0.45);
    glVertex2f(2, -0.45);

    // Lighter green near the top for a more realistic grass effect
    glColor3ub(0, 255, 0); // Bright green
    glVertex2f(2, 0.65);
    glVertex2f(-2, 0.65);
    glEnd();
}

void circle(float radius, float cX, float cY)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
    {
        glColor3ub(25, 111, 61 );
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);

    }
    glEnd();
}

void cloud_circle_village(float radius, float cX, float cY)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
    {
        glColor3ub(255, 255, 255);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);

    }
    glEnd();
}

void Sun(float radius, float cX, float cY)
{
    const int numSegments = 200; // Number of segments to approximate the circle
    const float pi = 3.14159265358979323846f; // Pi for calculations
    const float rayLength = radius * 1.5f; // Length of the sun's rays
    const int numRays = 20; // Number of rays

    // Draw the Sun as a circle with a gradient color
    glBegin(GL_TRIANGLE_FAN); // Use TRIANGLE_FAN to draw a filled circle
    glColor3ub(255, 255, 0);  // Set the color to yellow for the center of the sun
    glVertex2f(cX, cY);       // Center of the circle

    for (int i = 0; i <= numSegments; ++i) {
        float angle = (i * 2.0f * pi) / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Optional: Gradually change color from yellow to orange towards the edge
        float gradientFactor = static_cast<float>(i) / numSegments;
        glColor3ub(255, static_cast<GLubyte>(255 - gradientFactor * 50), 0);

        glVertex2f(x + cX, y + cY);
    }
    glEnd();

    // Draw the Sun's rays
    glBegin(GL_LINES);
    for (int i = 0; i < numRays; ++i) {
        float angle = (i * 2.0f * pi) / numRays;

        // Calculate the starting point of the ray (on the surface of the sun)
        float xStart = radius * cos(angle) + cX;
        float yStart = radius * sin(angle) + cY;

        // Calculate the ending point of the ray (extending outwards)
        float xEnd = rayLength * cos(angle) + cX;
        float yEnd = rayLength * sin(angle) + cY;

        // Set ray color (a bit more orange)
        glColor3ub(255, 165, 0); // Orange color for the rays

        // Draw the line (ray)
        glVertex2f(xStart, yStart);
        glVertex2f(xEnd, yEnd);
    }
    glEnd();
}

void Moon(float radius, float cX, float cY)
{
    const int numSegments = 200; // Number of segments to approximate the circle
    const float pi = 3.14159265358979323846f; // Pi for calculations

    // Draw the Moon as a circle
    glBegin(GL_TRIANGLE_FAN); // Use TRIANGLE_FAN to draw a filled circle
    glColor3ub(192, 192, 192);  // Set the color to light gray for the moon
    glVertex2f(cX, cY);         // Center of the circle

    for (int i = 0; i <= numSegments; ++i) {
        float angle = (i * 2.0f * pi) / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        glVertex2f(x + cX, y + cY);
    }
    glEnd();
}

void circleVillage(float radius, float cX, float cY, int r, int g, int b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
    {
        glColor3ub(r, g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);

    }
    glEnd();
}

void ship()
{
    ///Down Part
    glColor3ub(155, 155, 155);
    glBegin(GL_POLYGON);
    glVertex2f(-1.55, -1.8);
    glVertex2f(-1.6707, -1.6551);
    glVertex2f(-1.0712765362405, -1.6551139763049);
    glVertex2f(-1.2, -1.8);
    glEnd();

    glColor3ub(133, 65, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.7, -1.62);
    glVertex2f(-1.6707, -1.6551);
    glVertex2f(-1.0712765362405, -1.6551139763049);
    glVertex2f(-1.04, -1.62);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.699, -1.50165);
    glVertex2f(-1.7, -1.62);
    glVertex2f(-1.04, -1.62);
    glVertex2f(-1.115, -1.51);
    glEnd();

    glColor3ub(133, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.65, -1.51);
    glVertex2f(-1.115, -1.51);
    glVertex2f(-1.15, -1.4);
    glVertex2f(-1.65, -1.4);
    glEnd();

    glColor3ub(133, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.65, -1.42);
    glVertex2f(-1.7, -1.42);
    glVertex2f(-1.7, -1.4);
    glVertex2f(-1.65, -1.4);
    glEnd();

    glColor3ub(133, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.6, -1.4);
    glVertex2f(-1.55, -1.4);
    glVertex2f(-1.55, -1.35);
    glVertex2f(-1.6, -1.35);
    glEnd();
    glColor3ub(133, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, -1.4);
    glVertex2f(-1.45, -1.4);
    glVertex2f(-1.45, -1.35);
    glVertex2f(-1.4, -1.35);
    glEnd();
    glColor3ub(133, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.25, -1.4);
    glVertex2f(-1.3, -1.4);
    glVertex2f(-1.3, -1.35);
    glVertex2f(-1.25, -1.35);
    glEnd();

    ///windows

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.62, -1.54);
    glVertex2f(-1.62, -1.58);
    glVertex2f(-1.58, -1.58);
    glVertex2f(-1.58, -1.54);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5, -1.54);
    glVertex2f(-1.5, -1.58);
    glVertex2f(-1.46, -1.58);
    glVertex2f(-1.46, -1.54);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.38, -1.54);
    glVertex2f(-1.38, -1.58);
    glVertex2f(-1.34, -1.58);
    glVertex2f(-1.34, -1.54);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.24, -1.54);
    glVertex2f(-1.24, -1.58);
    glVertex2f(-1.2, -1.58);
    glVertex2f(-1.2, -1.54);
    glEnd();


    circle(0.02, -1.29, -1.45, 255, 255, 255);
    circle(0.02, -1.38, -1.45, 255, 255, 255);
    circle(0.02, -1.47, -1.45, 255, 255, 255);
    circle(0.02, -1.56, -1.45, 255, 255, 255);

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.09374, -1.68046);
    glVertex2f(-1.14666, -1.73999);
    glVertex2f(-1.31, -1.74);
    glVertex2f(-1.31, -1.68);
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.55, -1.8);
    glVertex2f(-1.5752, -1.7698);
    glVertex2f(-1.1782, -1.7698);
    glVertex2f(-1.2, -1.8);
    glEnd();
}

void Bilding()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, 0, 0);
    glScalef(1.1,1,0);

    /// Building side walls
    glColor3ub(255, 160, 122); // Light salmon for a warm, earthy tone
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, 0.35);
    glVertex2f(-1.8, 0.8);
    glVertex2f(-1.4, 0.8);
    glVertex2f(-1.4, 0.35);
    glEnd();

    /// Door
    glColor3ub(139, 69, 19); // Saddle brown for the door (classic wooden look)
    glBegin(GL_POLYGON);
    glVertex2f(-1.65, 0.35);
    glVertex2f(-1.65, 0.55);
    glVertex2f(-1.55, 0.55);
    glVertex2f(-1.55, 0.35);
    glEnd();

    /// Windows
    glColor3ub(72, 61, 139); // Dark slate blue for windows (elegant contrast)
    glBegin(GL_POLYGON);
    glVertex2f(-1.74, 0.72);
    glVertex2f(-1.66, 0.72);
    glVertex2f(-1.66, 0.64);
    glVertex2f(-1.74, 0.64);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.54, 0.72);
    glVertex2f(-1.46, 0.72);
    glVertex2f(-1.46, 0.64);
    glVertex2f(-1.54, 0.64);
    glEnd();

    /// Foot (foundation)
    glColor3ub(47, 79, 79); // Dark slate gray for the foundation
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, 0.35);
    glVertex2f(-1.8, 0.3);
    glVertex2f(-1.4, 0.3);
    glVertex2f(-1.4, 0.35);
    glEnd();

    glPopMatrix();
}

void Bilding2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.6, 0, 0);
    glScalef(1.1, 1, 0);

    /// Building side walls
    glColor3ub(255, 60, 66); // Light salmon for a warm, earthy tone
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, 0.35);
    glVertex2f(-1.8, 0.8);
    glVertex2f(-1.4, 0.8);
    glVertex2f(-1.4, 0.35);
    glEnd();

    /// Door
    glColor3ub(139, 69, 19); // Saddle brown for the door (classic wooden look)
    glBegin(GL_POLYGON);
    glVertex2f(-1.65, 0.35);
    glVertex2f(-1.65, 0.55);
    glVertex2f(-1.55, 0.55);
    glVertex2f(-1.55, 0.35);
    glEnd();

    /// Windows
    glColor3ub(72, 61, 139); // Dark slate blue for windows (elegant contrast)
    glBegin(GL_POLYGON);
    glVertex2f(-1.74, 0.72);
    glVertex2f(-1.66, 0.72);
    glVertex2f(-1.66, 0.64);
    glVertex2f(-1.74, 0.64);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.54, 0.72);
    glVertex2f(-1.46, 0.72);
    glVertex2f(-1.46, 0.64);
    glVertex2f(-1.54, 0.64);
    glEnd();

    /// Foot (foundation)
    glColor3ub(47, 79, 79); // Dark slate gray for the foundation
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, 0.35);
    glVertex2f(-1.8, 0.3);
    glVertex2f(-1.4, 0.3);
    glVertex2f(-1.4, 0.35);
    glEnd();

    glPopMatrix();
}

void House()
{
    /// Left side
    glColor3ub(205, 133, 63); // Warm brown for side walls (mud or wood)
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, 0.0364);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.52, -0.39);
    glEnd();

    glColor3ub(205, 133, 63); // Same warm brown for upper part
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, 0.0364);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.375, 0.2);
    glEnd();

    /// Foot
    glColor3ub(102, 51, 0); // Dark brown for foundation
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, -0.42);
    glVertex2f(-1.52, -0.39);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.2, -0.45);
    glEnd();

    glColor3ub(102, 51, 0); // Same dark brown for the foot extension
    glBegin(GL_POLYGON);
    glVertex2f(-1.56, -0.01); // M2
    glVertex2f(-1.571, -0.001); // Q
    glVertex2f(-1.4, 0.2); // S1
    glVertex2f(-1.375, 0.2);
    glEnd();

    glColor3ub(102, 51, 0); // Continue dark brown for base
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.2, -0.45);
    glVertex2f(-0.7, -0.45);
    glVertex2f(-0.7, -0.42);
    glEnd();

    glColor3ub(102, 51, 0); // Dark brown for lower foundation part
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, 0.2);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.68, -0.02);
    glVertex2f(-1.18, -0.02);
    glEnd();

    /// Front Side
    glColor3ub(244, 164, 96); // Sandy color for front walls (appealing warm tone)
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-0.7, -0.42);
    glVertex2f(-0.7, 0);
    glEnd();

    /// Door
    glColor3ub(139, 69, 19); // Wooden door (brown)
    glBegin(GL_POLYGON);
    glVertex2f(-1.05, -0.2);
    glVertex2f(-0.88, -0.2);
    glVertex2f(-0.88, -0.42);
    glVertex2f(-1.05, -0.42);
    glEnd();

    glColor3ub(210, 105, 30); // Darker wooden details for the door
    glBegin(GL_POLYGON);
    glVertex2f(-1.05, -0.2);
    glVertex2f(-0.96, -0.3);
    glVertex2f(-0.96, -0.42);
    glVertex2f(-1.05, -0.42);
    glEnd();

    /// Roof
    glColor3ub(165, 42, 42); // Brick red for the roof (common for village houses)
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, 0.2);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.68, -0.02);
    glVertex2f(-1.18, -0.02);
    glEnd();

    /// Windows
    glColor3ub(169, 0, 255); // Bright blue windows for contrast (beautiful touch)
    glBegin(GL_POLYGON);
    glVertex2f(-1.42, -0.3);
    glVertex2f(-1.28, -0.3);
    glVertex2f(-1.28, -0.14);
    glVertex2f(-1.42, -0.14);
    glEnd();

    glColor3ub(0, 0, 0); // Black window frames
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.35, -0.3);
    glVertex2f(-1.35, -0.14);
    glEnd();

    glColor3ub(0, 0, 0); // Horizontal line in the window
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.28, -0.225);
    glVertex2f(-1.42, -0.225);
    glEnd();
}

void House1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.5, 0, 0);

    /// Left side
    glColor3ub(173, 216, 230); // Light blue for the side walls (fresh and clean look)
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, 0.0364);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.52, -0.39);
    glEnd();

    glColor3ub(173, 216, 230); // Same light blue for the upper part
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, 0.0364);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.375, 0.2);
    glEnd();

    /// Foot
    glColor3ub(102, 51, 0); // Dark brown for foundation (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, -0.42);
    glVertex2f(-1.52, -0.39);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.2, -0.45);
    glEnd();

    glColor3ub(102, 51, 0); // Same dark brown for the foot extension
    glBegin(GL_POLYGON);
    glVertex2f(-1.56, -0.01); // M2
    glVertex2f(-1.571, -0.001); // Q
    glVertex2f(-1.4, 0.2); // S1
    glVertex2f(-1.375, 0.2);
    glEnd();

    glColor3ub(102, 51, 0); // Continue dark brown for base (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.2, -0.45);
    glVertex2f(-0.7, -0.45);
    glVertex2f(-0.7, -0.42);
    glEnd();

    glColor3ub(102, 51, 0); // Dark brown for lower foundation part
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, 0.2);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.68, -0.02);
    glVertex2f(-1.18, -0.02);
    glEnd();

    /// Front Side
    glColor3ub(144, 238, 144); // Light green for front walls (fresh and vibrant)
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-0.7, -0.42);
    glVertex2f(-0.7, 0);
    glEnd();

    /// Door
    glColor3ub(139, 69, 19); // Wooden brown for the door (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.05, -0.2);
    glVertex2f(-0.88, -0.2);
    glVertex2f(-0.88, -0.42);
    glVertex2f(-1.05, -0.42);
    glEnd();

    glColor3ub(210, 105, 30); // Darker wooden details for the door
    glBegin(GL_POLYGON);
    glVertex2f(-1.05, -0.2);
    glVertex2f(-0.96, -0.3);
    glVertex2f(-0.96, -0.42);
    glVertex2f(-1.05, -0.42);
    glEnd();

    /// Roof
    glColor3ub(165, 42, 42); // Brick red for the roof (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, 0.2);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.68, -0.02);
    glVertex2f(-1.18, -0.02);
    glEnd();

    /// Windows
    glColor3ub(255, 255, 0); // Bright yellow windows for a cheerful contrast
    glBegin(GL_POLYGON);
    glVertex2f(-1.42, -0.3);
    glVertex2f(-1.28, -0.3);
    glVertex2f(-1.28, -0.14);
    glVertex2f(-1.42, -0.14);
    glEnd();

    glColor3ub(0, 0, 0); // Black window frames
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.35, -0.3);
    glVertex2f(-1.35, -0.14);
    glEnd();

    glColor3ub(0, 0, 0); // Horizontal line in the window
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.28, -0.225);
    glVertex2f(-1.42, -0.225);
    glEnd();

    glPopMatrix();
}

void House2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.45, 0.05, 0);

    /// Left side
    glColor3ub(240, 128, 128); // Light coral for the side walls (soft and welcoming)
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, 0.0364);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.52, -0.39);
    glEnd();

    glColor3ub(240, 128, 128); // Same light coral for the upper part
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, 0.0364);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.375, 0.2);
    glEnd();

    /// Foot
    glColor3ub(102, 51, 0); // Dark brown for foundation (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.52, -0.42);
    glVertex2f(-1.52, -0.39);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.2, -0.45);
    glEnd();

    glColor3ub(102, 51, 0); // Same dark brown for the foot extension
    glBegin(GL_POLYGON);
    glVertex2f(-1.56, -0.01); // M2
    glVertex2f(-1.571, -0.001); // Q
    glVertex2f(-1.4, 0.2); // S1
    glVertex2f(-1.375, 0.2);
    glEnd();

    glColor3ub(102, 51, 0); // Continue dark brown for base (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-1.2, -0.45);
    glVertex2f(-0.7, -0.45);
    glVertex2f(-0.7, -0.42);
    glEnd();

    glColor3ub(102, 51, 0); // Dark brown for lower foundation part
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, 0.2);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.68, -0.02);
    glVertex2f(-1.18, -0.02);
    glEnd();

    /// Front Side
    glColor3ub(255, 228, 181); // Light goldenrod for front walls (warm and inviting)
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, 0);
    glVertex2f(-1.2, -0.42);
    glVertex2f(-0.7, -0.42);
    glVertex2f(-0.7, 0);
    glEnd();

    /// Door
    glColor3ub(139, 69, 19); // Wooden brown for the door (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.05, -0.2);
    glVertex2f(-0.88, -0.2);
    glVertex2f(-0.88, -0.42);
    glVertex2f(-1.05, -0.42);
    glEnd();

    glColor3ub(160, 82, 45); // Saddle brown for darker wooden door details
    glBegin(GL_POLYGON);
    glVertex2f(-1.05, -0.2);
    glVertex2f(-0.96, -0.3);
    glVertex2f(-0.96, -0.42);
    glVertex2f(-1.05, -0.42);
    glEnd();

    /// Roof
    glColor3ub(165, 42, 42); // Brick red for the roof (same as before)
    glBegin(GL_POLYGON);
    glVertex2f(-1.4, 0.2);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.68, -0.02);
    glVertex2f(-1.18, -0.02);
    glEnd();

    /// Windows
    glColor3ub(0, 128, 128); // Teal windows for a modern, refreshing touch
    glBegin(GL_POLYGON);
    glVertex2f(-1.42, -0.3);
    glVertex2f(-1.28, -0.3);
    glVertex2f(-1.28, -0.14);
    glVertex2f(-1.42, -0.14);
    glEnd();

    glColor3ub(0, 0, 0); // Black window frames
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.35, -0.3);
    glVertex2f(-1.35, -0.14);
    glEnd();

    glColor3ub(0, 0, 0); // Horizontal line in the window
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.28, -0.225);
    glVertex2f(-1.42, -0.225);
    glEnd();

    glPopMatrix();
}

void Tree()
{
    glPushMatrix();
    glTranslatef(0,0,0);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3, -0.45);
    glVertex2f(0.2, -0.45);
    glEnd();
    circle(0.2, 0.1, 0.2);
    circle(0.25, 0.25, 0.3);
    circle(0.2, 0.38, 0.2);
    glPopMatrix();
}

void Tree1()
{
    glPushMatrix();
    glTranslatef(0.65,0,0);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3, -0.45);
    glVertex2f(0.2, -0.45);
    glEnd();
    circle(0.2, 0.1, 0.2);
    circle(0.25, 0.25, 0.3);
    circle(0.2, 0.38, 0.2);
    glPopMatrix();
}

void Tree2()
{
    glPushMatrix();
    glTranslatef(1.3,0,0);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3, -0.45);
    glVertex2f(0.2, -0.45);
    glEnd();
    circle(0.2, 0.1, 0.2);
    circle(0.25, 0.25, 0.3);
    circle(0.2, 0.38, 0.2);
    glPopMatrix();
}

void Tree2_1()
{
    glPushMatrix();
    glTranslatef(0.325,0.55,0);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3, -0.55);
    glVertex2f(0.2, -0.55);
    glEnd();
    circle(0.2, 0.1, 0.2);
    circle(0.25, 0.25, 0.3);
    circle(0.2, 0.38, 0.2);
    glPopMatrix();

}

void Tree2_2()
{
    glPushMatrix();
    glTranslatef(0.985,0.55,0);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3, -0.55);
    glVertex2f(0.2, -0.55);
    glEnd();
    circle(0.2, 0.1, 0.2);
    circle(0.25, 0.25, 0.3);
    circle(0.2, 0.38, 0.2);
    glPopMatrix();

}
void Tree2_3()
{
    glPushMatrix();
    glTranslatef(0.985+0.65,0.55,0);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3, -0.55);
    glVertex2f(0.2, -0.55);
    glEnd();
    circle(0.2, 0.1, 0.2);
    circle(0.25, 0.25, 0.3);
    circle(0.2, 0.38, 0.2);
    glPopMatrix();

}
void road_side_grass()
{
    /// Upper Grass
    glColor3ub(34, 139, 34); // Rich green for upper grass (forest green)
    glBegin(GL_POLYGON);
    glVertex2f(-2, -0.5);
    glVertex2f(-2, -0.45);
    glVertex2f(2, -0.45);
    glVertex2f(2, -0.5);
    glEnd();

    /// Lower Grass
    glPushMatrix();
    glTranslatef(0, -0.55, 0);
    glColor3ub(0, 128, 0); // Slightly darker green for lower grass (dark green)
    glBegin(GL_POLYGON);
    glVertex2f(-2, -0.5);
    glVertex2f(-2, -0.45);
    glVertex2f(2, -0.45);
    glVertex2f(2, -0.5);
    glEnd();
    glPopMatrix();
}

void road()
{
    // Road surface
    glColor3ub(105, 105, 105); // Dark gray for the road
    glBegin(GL_POLYGON);
    glVertex2f(-2, -0.5);
    glVertex2f(-2, -1);
    glVertex2f(2, -1);
    glVertex2f(2, -0.5);
    glEnd();

    // Yellow divider line in the middle of the road
    glColor3ub(255, 255, 0); // Bright yellow for the divider
    glLineWidth(3); // Set the width of the divider line
    glBegin(GL_LINES);
    glVertex2f(-2, -0.75);
    glVertex2f(2, -0.75);
    glEnd();
}

void river()
{


    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-2,-1.05);
    glVertex2f(-2,-2);
    glVertex2f(2, -2);
    glVertex2f(2, -1.05);
    glEnd();
}

void Cloud_village()
{
    cloud_circle_village( 0.23, -1.74, 1.368);
    cloud_circle_village( 0.255, -1.5945, 1.4423);
    cloud_circle_village( 0.23, -1.4434, 1.368);
    cloud_circle_village( 0.255, -1.5945, 1.2843);
}

void Cloud1_village()
{
    cloud_circle_village( 0.23, 0.5258, 1.6051);
    cloud_circle_village( 0.255, 0.6391, 1.7184);
    cloud_circle_village( 0.23, 0.76883, 1.6114);
    cloud_circle_village( 0.255, 0.6391, 1.5632);
}
void whiteline()
{
     glBegin(GL_POLYGON);

    // Darker blue at the top for the upper sky
    glColor3ub(255, 255, 255); // Dark blue
    glVertex2f(2, 2);
    glVertex2f(2.1, 2);
    glVertex2f(2.1, -2);
    glVertex2f(2, -2);

    glEnd();
}

void Sky_village()
{
    glBegin(GL_POLYGON);

    // Darker blue at the top for the upper sky
    glColor3ub(0, 0, 139); // Dark blue
    glVertex2f(-2, 2);
    glVertex2f(2, 2);

    // Lighter blue near the horizon for a smooth transition
    glColor3ub(135, 206, 250); // Light sky blue
    glVertex2f(2, 0.65);
    glVertex2f(-2, 0.65);

    glEnd();
}
void star2(float x, float y)
{

    glPushMatrix();
    glScalef(0.5,0.5,0);
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);


    glVertex2f(1.53+x, 1.6+y);///S3
    glVertex2f(1.55+x, 1.65+y);///T3
    glVertex2f(1.57+x, 1.6+y);///U3
    glVertex2f(1.62+x, 1.6+y);///V3
    glVertex2f(1.57+x, 1.57+y);///Z3
    glVertex2f(1.6+x, 1.52+y);///N8
    glVertex2f(1.55+x, 1.55+y);///O8
    glVertex2f(1.5+x, 1.52+y);///A4
    glVertex2f(1.53+x, 1.57+y);///W3
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);

    glVertex2f(1.48+x, 1.6+y);///R3
    glVertex2f(1.53+x, 1.6+y);///S3

    glVertex2f(1.53+x, 1.57+y);///W3
    glEnd();
    glPopMatrix();
}
void drawBus()
{
    // Bus Body
    glColor3ub(255, 165, 0); // Orange color for the bus
    glBegin(GL_POLYGON);
    glVertex2f(-1.7, -0.7);
    glVertex2f(-1.7, -0.9);
    glVertex2f(-1.3, -0.9);
    glVertex2f(-1.3, -0.7);
    glEnd();

    ///fornt part

    glColor3ub(255, 165, 0); // Orange color for the bus
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, -0.8);
    glVertex2f(-1.3, -0.8);
    glVertex2f(-1.3, -0.9);
    glVertex2f(-1.2, -0.9);
    glEnd();
    glColor3ub(173, 216, 230); // Orange color for the bus
    glBegin(GL_POLYGON);
    glVertex2f(-1.2, -0.8);
    glVertex2f(-1.3, -0.8);
    glVertex2f(-1.3, -0.7);
    glEnd();


    // Bus Windows
    glColor3ub(173, 216, 230); // Lighter yellow for the roof
    glBegin(GL_POLYGON);
    glVertex2f(-1.68, -0.74);
    glVertex2f(-1.68, -0.8);
    glVertex2f(-1.6, -0.8);
    glVertex2f(-1.6, -0.74);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.58, -0.74);
    glVertex2f(-1.58, -0.8);
    glVertex2f(-1.5, -0.8);
    glVertex2f(-1.5, -0.74);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.48, -0.74);
    glVertex2f(-1.48, -0.8);
    glVertex2f(-1.42, -0.8);
    glVertex2f(-1.42, -0.74);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.4, -0.74);
    glVertex2f(-1.4, -0.8);
    glVertex2f(-1.32, -0.8);
    glVertex2f(-1.32, -0.74);
    glEnd();

    circle(0.05, -1.6, -0.9, 0,0,0);
    circle(0.05, -1.34, -0.9, 0,0,0);
    if(!isDay)
    {
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(-1.2, -0.82);
        glVertex2f(-1.2, -0.8);
        glVertex2f(-0.94, -0.72);
        glVertex2f(-0.94, -0.88);
        glEnd();
    }

}

void drawBus2()
{
    // Bus Body
    glColor3ub(0, 128, 255); // New color: Blue for the bus body
    glBegin(GL_POLYGON);
    glVertex2f(1.3, -0.5);
    glVertex2f(1.3, -0.7);
    glVertex2f(1.7, -0.7);
    glVertex2f(1.7, -0.5);
    glEnd();

    // Front part of the bus
    glColor3ub(0, 128, 255); // New color: Blue for the front part
    glBegin(GL_POLYGON);
    glVertex2f(1.2, -0.59);
    glVertex2f(1.2, -0.69);
    glVertex2f(1.3, -0.69);
    glVertex2f(1.3, -0.59);
    glEnd();

    // Windshield (front window)
    glColor3ub(173, 216, 230); // Light blue for the windshield
    glBegin(GL_POLYGON);
    glVertex2f(1.2, -0.59);
    glVertex2f(1.3, -0.59);
    glVertex2f(1.3, -0.49);
    glEnd();

    /// Bus Door
    glColor3ub(155, 56, 56); // Red for the bus door
    glBegin(GL_POLYGON);
    glVertex2f(1.32, -0.55);
    glVertex2f(1.38, -0.55);
    glVertex2f(1.38, -0.69);
    glVertex2f(1.32, -0.69);
    glEnd();

    ///Bus Windows
    glColor3ub(173, 216, 230); // Light blue for the windows
    glBegin(GL_POLYGON);
    glVertex2f(1.44, -0.52);
    glVertex2f(1.44, -0.6);
    glVertex2f(1.5, -0.6);
    glVertex2f(1.5, -0.52);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1.52, -0.6);
    glVertex2f(1.52, -0.52);
    glVertex2f(1.58, -0.52);
    glVertex2f(1.58, -0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1.6, -0.6);
    glVertex2f(1.6, -0.52);
    glVertex2f(1.66, -0.52);
    glVertex2f(1.66, -0.6);
    glEnd();

    // Wheels
    circle(0.045, 1.25, -0.69, 0, 0, 0); // Black color for the wheels
    circle(0.05, 1.58, -0.69, 0, 0, 0); // Black color for the wheels
    if(!isDay)
    {
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(1.2, -0.66);
        glVertex2f(1.2, -0.64);
        glVertex2f(0.94, -0.56);
        glVertex2f(0.94, -0.72);
        glEnd();
    }
}

void boat1_village()
{
    glPushMatrix();
    glMatrixMode(GL_POLYGON);
    glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0); // Dark blue for the boat body
	glVertex2f(0.9, -1.3);
	glVertex2f(1, -1.45);
	glVertex2f(1.4, -1.45);
	glVertex2f(1.5, -1.3);
	glEnd();
    glColor3ub(255, 255, 255); // Dark blue for the boat body
	glBegin(GL_POLYGON);
	glVertex2f(1, -1.3);
	glVertex2f(1.1, -1.2);
	glVertex2f(1.3, -1.2);
	glVertex2f(1.4, -1.3);
	glEnd();
	glPopMatrix();
}
float busXV = 0.0f;
float busYV = 0.0f;
float boatX = 0.0f;
float shipX =0.0f;
float cloudXV= 0.0f;
float cloudYV= 0.00f;
float sun =0.0f;
float starX=0.0f;
float starX2=0.0f;
float starX3=0.0f;
float starX4=0.0f;
float starX5=0.0f;

void updateStar(int value)
{
    starX += 0.002f+speed;


    if (starX > 0.9f)
    {
        starX = -3.5f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateStar, 0);
}
void updateStar2(int value)
{
    starX2 += 0.002f+speed;


    if (starX2 > 0.9f)
    {
        starX2 = -4.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateStar2, 0);
}
void updateStar3(int value)
{
    starX3 += 0.002f+speed;


    if (starX3 > 1.8f)
    {
        starX3 = -2.5f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateStar3, 0);
}
void updateStar4(int value)
{
    starX4 += 0.002f+speed;


    if (starX4 > 2.4f)
    {
        starX4 = -2.3f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateStar4, 0);
}
void updateStar5(int value)
{
    starX5 += 0.002f+speed;


    if (starX5 > 3.0f)
    {
        starX5 = -2.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateStar5, 0);
}
void updateSun(int value)
{
    sun += 0.001f+speed;


    if (sun > 3.0f)
    {
        sun = -2.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateSun, 0);
}
void updateCloud1_village(int value)
{
    cloudYV -= 0.002f+speed;


    if (cloudYV < -3.5f)
    {
        cloudYV = 1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateCloud1_village, 0);
}
void updateCloudVillage(int value)
{
    cloudXV -= 0.002f+speed;


    if (cloudXV < -1.0f)
    {
        cloudXV = 3.5f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateCloudVillage, 0);
}
void updateShip(int value)
{
    shipX += 0.005f+speed;


    if (shipX > 4.0f)
    {
        shipX = -1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateShip, 0);
}
void updateBoat(int value)
{
    boatX -= 0.005f+speed;


    if (boatX < -4.0f)
    {
        boatX = 1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateBoat, 0);
}
void updateBus(int value)
{
    busXV += 0.01f+speed;


    if (busXV > 4.0f)
    {
        busXV = -1.0f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateBus, 0);
}
void updateBus2(int value)
{
    busYV -= 0.01f+speed;


    if (busYV < -4.0f)
    {
        busYV = 1.30f; // Reset boat position to the left side
    }
    // Redisplay the scene
    glutPostRedisplay();
    glutTimerFunc(16, updateBus2, 0);
}
void moveBusVillage(float xOffset)
{
    glPushMatrix();
    glTranslatef(xOffset, 0.0f, 0.0f);
    drawBus();
    glPopMatrix();
}
void moveBus2(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    drawBus2();
    glPopMatrix();
}
void moveBoat(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    boat1_village();
    glPopMatrix();
}
void moveShip(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    ship();
    glPopMatrix();
}
void moveCloudVillage(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    Cloud_village();
    glPopMatrix();
}
void moveCloud1Village(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    Cloud1_village();
    glPopMatrix();
}
void moveSun(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    if(isDay)
    {
        Sun(0.15, -0.45, 1.8);
    }
    else
    {
        Moon(0.15, -0.45, 1.8);
    }

    glPopMatrix();
}
void moveStar(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    star2(1.0, 1.0);
    glPopMatrix();
}
void moveStar2(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    star2(2.0, 1.0);
    glPopMatrix();
}
void moveStar3(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    star2(-1.0, 1.5);
    glPopMatrix();
}
void moveStar4(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    star2(-2, 0.8);
    glPopMatrix();
}
void moveStar5(float yOffset)
{
    glPushMatrix();
    glTranslatef(yOffset, 0.0f, 0.0f);
    star2(-2.9, 1.5);
    glPopMatrix();
}
void object()
{
     glPushMatrix();
    glTranslatef(0,0,0);
    glBegin(GL_POLYGON);
	glColor3ub(255, 215, 0); // Golden color

	glVertex2f(-0.52, 0.4);
	glVertex2f(-0.52, 0.6);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.45, 0.7);

	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.25, 0.7);
	glVertex2f(-0.2, 0.65);
	glVertex2f(-0.18, 0.6);
	glVertex2f(-0.18, 0.4);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0); // Golden color

	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.35, 0.8);
	glEnd();
	glPopMatrix();
}
void object1()
{
     glPushMatrix();
    glTranslatef(-0.35,0,0);
    glBegin(GL_POLYGON);
	glColor3ub(255, 215, 0); // Golden color

	glVertex2f(-0.52, 0.4);
	glVertex2f(-0.52, 0.6);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.45, 0.7);

	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.25, 0.7);
	glVertex2f(-0.2, 0.65);
	glVertex2f(-0.18, 0.6);
	glVertex2f(-0.18, 0.4);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0); // Golden color

	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.35, 0.8);
	glEnd();
	glPopMatrix();
}
void object2()
{
    glPushMatrix();
    glTranslatef(0.35,0,0);
    glBegin(GL_POLYGON);
	glColor3ub(255, 215, 0); // Golden color

	glVertex2f(-0.52, 0.4);
	glVertex2f(-0.52, 0.6);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.45, 0.7);

	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.25, 0.7);
	glVertex2f(-0.2, 0.65);
	glVertex2f(-0.18, 0.6);
	glVertex2f(-0.18, 0.4);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0); // Golden color

	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.35, 0.8);
	glEnd();
	glPopMatrix();
}

void renderNightScene()
{
    glBegin(GL_POLYGON);

    // Darker blue at the top for the upper sky
    glColor3ub(10, 10, 50); // Very dark blue (almost black) for the top of the sky
    glVertex2f(-2, 2);
    glVertex2f(2, 2);

    // Slightly lighter blue near the horizon
    glColor3ub(30, 30, 80); // Darker blue for the horizon
    glVertex2f(2, 0.65);
    glVertex2f(-2, 0.65);

    glEnd();

}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
	    speed += 0.005f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 0.005f;
    }
glutPostRedisplay();
}

void drawRain()
{
    if (isRaining) {
        glColor3ub(173, 216, 230);  // Light blue for raindrops
        for (int i = 0; i < 100; ++i) {
            float x = -2.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4.0f)));
            float y = -2.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4.0f)));
            glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x, y - 0.1f);  // Raindrop length
            glEnd();
        }
    }
}

void displayCity()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	Sky();
	moveCloud(cloudX);
	moveCloud1(cloudY);
	road_down();
	devider();
	road_up();
    movePlane(plane);
    Buildings();
	burjKhalifa();
	tree(0);
	tree(1);
	tree(2);
	tree(3);
    drawRiver();
    moveBus(busY1);
    moveCar1(car1X);
    moveCar2(car2X);

    drawLampPost1();
    drawLampPost2();
    drawLampPost3();
    drawLampPost4();
    drawLampPost5();
    drawLampPost6();
    drawLampPost7();
    drawLampPost8();
    drawLampPost();

    moveBoat1(boat1X);
    moveBoat2(boat2Y);

    drawRain();
	glFlush();


}


void displayVillage()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);

	if(isDay)
    {
        Sky_village();
    }
    else
    {
        renderNightScene();
    }

	grass1();
	House2();
	House();
    House1();
    object();
    object1();
    object2();
    Bilding();
    Bilding2();
	road();

	moveBus2(busYV);
	moveBusVillage(busXV);
	moveSun(sun);
	road_side_grass();
	river();
	moveBoat(boatX);
	moveShip(shipX);
	if(isDay)
    {
        moveCloudVillage(cloudXV);
        moveCloud1Village(cloudYV);
    }
    else
    {
       moveStar(starX);
       moveStar2(starX2);
       moveStar3(starX3);
       moveStar4(starX4);
       moveStar5(starX5);
    }

	Tree2_1();
    Tree2_2();
    Tree2_3();
	Tree();
	Tree1();
	Tree2();
	whiteline();
	glFlush();

}
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 'a':
        speed = 0.0f;
        break;
        case 'w':
        speed = 0.01f;
        break;
        case 'c':
        isCity=true;
        speed=0;
        break;
        case 'v':
        isCity=false;
        speed=0;
        break;
        case 'r':  // Start rain
        if(isCity)
        {
            isRaining = true;
        }
        break;
        case 's':  // Stop rain
        if(isCity)
        {
            isRaining = false;
        }
        break;
        case 'n':
        if(!isCity)
        {
           isDay= false;
        }
        break;
        case'd':
        if(!isCity)
        {
            isDay=true;
        }
        break;
        glutPostRedisplay();
	}
}


/* Main function: GLUT runs as a console application starting at main()  */

void display()
{
    if(isCity)
    {
        displayCity();
    }
    else
    {
        displayVillage();
    }

    ///displayCity();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1200, 1000);                // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	   // Set the window's initial width & height
	glutDisplayFunc(display);
	gluOrtho2D(-2,2,-2,2);// Register display callback handler for window re-paint
    glutTimerFunc(20, updateBus, 0);
    glutTimerFunc(20, updateBus2, 0);
    glutTimerFunc(20, updateBoat, 0);
    glutTimerFunc(20, updateShip, 0);
    glutTimerFunc(20, updateCloudVillage, 0);
    glutTimerFunc(20, updateCloud1_village, 0);
    glutTimerFunc(20, updateSun, 0);
    glutTimerFunc(20, updateStar, 0);
    glutTimerFunc(20, updateStar2, 0);
    glutTimerFunc(20, updateStar3, 0);
    glutTimerFunc(20, updateStar4, 0);
    glutTimerFunc(20, updateStar5, 0);


    ///City

    glutTimerFunc(20, updateCloud, 0);
    glutTimerFunc(20, updateCloud1, 0);
    glutTimerFunc(20, updateCar1, 0);
    glutTimerFunc(20, updateCar2, 0);
    glutTimerFunc(20, updateBusCity, 0);
    glutTimerFunc(20, updateBoat1, 0);
    glutTimerFunc(20, updateBoat2, 0);
    glutTimerFunc(20, updatePlane, 0);


    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);

	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
