#include <GL/glut.h>
#include <stdio.h>
#include <emscripten/emscripten.h>
void draw_frame() {
    static float color = 0.0f;
    glClearColor(0, color, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    color = color + 0.05f;
    if (color > 1.0f) {
        color = 0.0f;
    }
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Browser");
    emscripten_set_main_loop(draw_frame, 0, false); 
}
