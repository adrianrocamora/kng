#include <iostream>
#include <cstdio>
#include <cmath>
#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#elif __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#endif
#define GL_PI 3.141593

struct SMD2Header {
	int magicNum_;
	int version_;
	int skinWidthPx_;
	int SkinHeightPx_;
	int frameSize_;
	int numSkins_;
	int numVertices_;
	int numTextCoords_;
	int numTriangles_;
	int numGLCommands_;
	int numFrames_;
	int offsetSkins_;
	int offsetTexCoords_;
	int offsetTriangles_;
	int offsetFrames_;
	int offsetGLCommands_;
	int fileSize_;
};

struct SMD2Vert {
	float vert_[3];
};

struct SMD2Frame {
	float scale_[3];
	float trans_[3];
	char caName[16];
	SMD2Vert *pVerts;
	SMD2Frame() {
		pVerts = nullptr;
	}
	~SMD2Frame() {
		if (pVerts) {
			delete[] pVerts;
		}
	}
};

class MD2 {
public: 
	SMD2Header header;
	SMD2Frame frame1;
	MD2(std::string filename) {
		FILE* f;
		f = std::fopen(filename.c_str(), "rb");
		std::fread(&header, sizeof(header), 1,  f);

		// Grab only the first frame for now
		frame1.pVerts = new SMD2Vert[header.numVertices_];

		std::fseek(f, header.offsetFrames_, SEEK_SET);
		std::fread(&frame1.scale_[0], sizeof(float), 3, f);
		std::fread(&frame1.trans_[0], sizeof(float), 3, f);
		std::fread(&frame1.caName[0], sizeof(char), 16, f);

		for (int i = 0; i < header.numVertices_; ++i) {
			uint8_t tmpBytes[4];
			std::fread(tmpBytes, sizeof(uint8_t), 4, f);
			frame1.pVerts[i].vert_[0] = tmpBytes[0] * frame1.scale_[0] + frame1.trans_[0]; 
			frame1.pVerts[i].vert_[1] = tmpBytes[1] * frame1.scale_[1] + frame1.trans_[1]; 
			frame1.pVerts[i].vert_[2] = tmpBytes[2] * frame1.scale_[2] + frame1.trans_[2]; 
		}
		std::fclose(f);
	};
};

int kill = 0;
MD2 md2Car("car.md2");
GLdouble eyeDist = 300.0;
GLdouble eyeTheta = 0.0;
GLdouble x = 50.0, lx, z = 300.0, lz;

void drawCar() {
	for (int i = 0; i < md2Car.header.numVertices_; ++i) {
		glBegin(GL_POINTS);
			glVertex3f(	md2Car.frame1.pVerts[i].vert_[0], 
						md2Car.frame1.pVerts[i].vert_[1], 
						md2Car.frame1.pVerts[i].vert_[2]);
		glEnd();
	}
}

void drawAxes()
{
	glBegin(GL_LINES);
		glColor3f (1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);	
		glVertex3f(100.0, 0.0, 0.0);	
		glColor3f (0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);	
		glVertex3f(0.0, 100.0, 0.0);	
		glColor3f (0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);	
		glVertex3f(0.0, 0.0, 100.0);	
		glColor3f (1.0, 1.0, 1.0);
	glEnd();
}


void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( x, z, 1.0f,
			   x + lx, z + lz, 1.0f,
			   0.0,   0.0,   1.0);

	drawAxes();
	glColor3f (1.0, 1.0, 0.0);
	drawCar();
	glColor3f (1.0, 1.0, 1.0);

	glutSwapBuffers();
	glutPostRedisplay();
}

void processSpecialKeys(int key, int x, int y)
{
	double fraction = 1.1;
	switch (key) {
		case GLUT_KEY_LEFT: 
			eyeTheta -= 0.1;
			lx = sin(eyeTheta);
			lz = -cos(eyeTheta);
			break;
		case GLUT_KEY_RIGHT: 
			eyeTheta += 0.1;
			lx = sin(eyeTheta);
			lz = -cos(eyeTheta);
			break;
		case GLUT_KEY_UP: 
			x  += lx * fraction;
			z  += lz * fraction;
			break;
		case GLUT_KEY_DOWN: 
			x  -= lx * fraction;
			z  -= lz * fraction;
			break;
	}
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27) {
		kill = 1;
		exit(0);
	}
}

void resizeScene(int w, int h) {
	if (h == 0) { h = 1;}
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, 1.0, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{   
	std::cout << "Magic Num: " << md2Car.header.magicNum_ << std::endl;
	std::cout << "Num Frames: " << md2Car.header.numFrames_ << std::endl;
	std::cout << "Num Vertices: " << md2Car.header.numVertices_ << std::endl;
	std::cout << "File size: " << md2Car.header.fileSize_ << std::endl;
	std::cout << "Scale: " << md2Car.frame1.scale_[0] << ",  "<< md2Car.frame1.scale_[1] << 
				 ", "  << md2Car.frame1.scale_[2] << std::endl;
	std::cout << "Translation: " << md2Car.frame1.trans_[0] << ",  "<< md2Car.frame1.trans_[1] << 
				 ", "  << md2Car.frame1.trans_[2] << std::endl;
	std::cout << "Frame Name: " << md2Car.frame1.caName << std::endl;
	std::cout << "Vertices: " << std::endl;
	kill = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	int mainWindow = glutCreateWindow ("MD2 Loader");
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(resizeScene);
	glutMainLoop();
	return 0;
}

