#include <GL/glut.h>
#include "globals.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    double time = 0; // Time of current frame
    double oldTime = 0; // Time of previous frame
    // Start the actual RayCasting


    // End of frame
    glutSwapBuffers();
}

void preventResizing(int width, int height) {
    // If the window is resized, force the window size to the initial size
    glutReshapeWindow(screenWidth, screenHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Set fixed window size
    glutInitWindowSize(screenWidth, screenHeight);

    // Set window position to top-left corner and create window w/ name
    glutInitWindowPosition(0, 0);
    glutCreateWindow(screenName);

    // Set the clear color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Call the display function
    glutDisplayFunc(display);

    // Set the reshape callback to prevent resizing
    glutReshapeFunc(preventResizing);

    // Start the main loop
    glutMainLoop();
    return 0;
}
