#include "Graphics.h"

void SetupWindow(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(Width, Height);

    glutCreateWindow("GLUT Test");

    glutDisplayFunc(&Frame);
    //glutIdleFunc(&Idle);

    glutMainLoop();
}

void Frame() {
    DrawFrames();
    glutTimerFunc(FrameDelay, TriggerRedraw, 0);
}

void TriggerRedraw(int i) {
    glutPostRedisplay();
}

//void Idle() {
//    glutPostRedisplay();
//}

