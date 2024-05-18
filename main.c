#include <GL/glut.h>
#include <stdio.h>
#include "globals.h"

double calculateFps(double time, double oldTime) {
    return 1.0 / (time - oldTime);
}

void calculateAndPrintFps() {
    oldTime = time;
    time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double FPS = calculateFps(time, oldTime);
    printf("FPS: %f\n", FPS);
}

void movePlayer() {
    if (controller.forward == 1) {
        player.playerX += player.directionX * controller.moveSpeed;
        player.playerY += player.directionY * controller.moveSpeed;
        controller.forward = 0;
    } else if (controller.backward == 1) {
        player.playerX -= player.directionX * controller.moveSpeed;
        player.playerY -= player.directionY * controller.moveSpeed;
        controller.backward = 0;
    }
}

void checkGameStatusAndRedisplay() {
    // End of frame & Draw
    glutSwapBuffers();

    // Mark the current window as needing to be redisplayed
    if (gameStatus == 0) {
        glutPostRedisplay();
    }
}

void onButtonPressed(unsigned char key, int x, int y){
    // If "w" is pressed, move the player up. Set the Controller.forward variable to 1
    if (key == 'w') {
        controller.forward = 1;
        printf("Forward\n");
    } else if (key == 's') {
        controller.backward = 1;
        printf("Backward\n");
    } else if (key == 'a') {
        controller.left = 1;
        printf("Left\n");
    } else if (key == 'd') {
        controller.right = 1;
        printf("Right\n");
    } else if (key == 'q') {
        controller.rotateLeft = 1;
        printf("Rotate Left\n");
    } else if (key == 'e') {
        controller.rotateRight = 1;
        printf("Rotate Right\n");
    }
}

void display() {
    // Set up projection
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, screenWidth, 0.0, screenHeight, -1.0, 1.0);

    // Ray casting, iterate over each column of the screen
    for (int x = 0; x < screenWidth; x++) {
        // Calculate ray position and direction
        double cameraX = 2 * x / (double) screenWidth - 1; // This scales x from [0, w] to [-1, 1].

        // Ray direction calculation
        double rayDirX = player.directionX + player.planeX * cameraX;
        double rayDirY = player.directionY + player.planeY * cameraX;

        // COntinue here
    }

    calculateAndPrintFps();
    movePlayer();
    checkGameStatusAndRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Set fixed window size
    glutInitWindowSize(screenWidth, screenHeight);

    // Set window position to top-left corner and create window w/ name
    glutInitWindowPosition(0, 0);
    glutCreateWindow(screenName);

    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Call the main function
    glutDisplayFunc(display);

    // Check if any key is pressed
    glutKeyboardFunc(onButtonPressed);

    // Start the main loop
    glutMainLoop();
    return 0;
}