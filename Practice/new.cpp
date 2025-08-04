#include "iGraphics.h"

int ball_x = 470, ball_y = 95;
int goal_x = 600, goal_y = 300;
int ball_radius = 20;
int goal_width = 100, goal_height = 200;

void drawBall() {
    iSetColor(255, 0, 0);
    iFilledCircle(ball_x, ball_y, ball_radius);
}

void drawGoal() {
    iSetColor(0, 255, 0);
    iRectangle(goal_x, goal_y, goal_width, goal_height);
}

void iDraw() {
    iClear();
    drawBall();
    drawGoal();
}

void iMouseMove(int mx, int my) {
    // code for mouse move
}

void iMouse(int button, int state, int mx, int my) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        ball_x = mx;
        ball_y = my;
    }
}

void iKeyboard(unsigned char key) {
    if (key == 'w') ball_y += 10;
    if (key == 's') ball_y -= 10;
    if (key == 'a') ball_x -= 10;
    if (key == 'd') ball_x += 10;
}
void moveBallToGoal() {
    int dx = goal_x - ball_x;
    int dy = goal_y - ball_y;
    float distance = sqrt(dx * dx + dy * dy);
    float velocity = 5.0; // Adjust the velocity as needed

    if (distance > velocity) {
        ball_x += (dx / distance) * velocity;
        ball_y += (dy / distance) * velocity;
    } else {
        ball_x = goal_x;
        ball_y = goal_y;
    }
}

void iSpecialKeyboard(unsigned char key) {
    if (key == GLUT_KEY_UP) ball_y += 10;
    if (key == GLUT_KEY_DOWN) ball_y -= 10;
    if (key == GLUT_KEY_LEFT) ball_x -= 10;
    if (key == GLUT_KEY_RIGHT) ball_x += 10;
}

int main() {
    int t=iSetTimer(20, moveBallToGoal);
    iInitialize(800, 600, "Football Game");
    return 0;
}