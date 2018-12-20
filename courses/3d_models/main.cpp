#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#elif __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#endif

#include <iostream>

using namespace std;

void recordingLoop( void *dummy );
int recording;
int iGW;
int frame, timeget, timebase;
double fps;


#define MAX_FORCE 1.0
#define MAX_FORCE_X 1.0

#define FILT_LEN 2
#define FILT_DIF 6

#define cost_sc 16

#define SC	1
#define NCX 30		//number of cells for state estimate
#define NSX 30*SC    //number of sensory cells
#define NCY 30		//number of cells for state estimate
#define NSY	30*SC    //number of sensory cells

#define MAX_N 200
#define MAX_T 500
#define GL_PI 3.141593

time_t rawtime;
struct tm * timeinfo;

int mainWindow, subWindow1,subWindow2;

bool modeShowPotential;

/// ROBOT CODE DECLARATIONS
int kill;
double cdiffx;
double cdiffy;
double tp;
double *pt;
double *ptp;
double *pGx;
double *pGy;
bool b3DPositionServo=false;
bool bMatlabLoopOn=false;
bool bPlotLoopOn=false;
bool bZOnlyControl=false;
double visc=.0036;//0.0028;//0.0051;//0.0028;//0.0032
double scale=.689;
double divis;
double stiff;

unsigned char keys[256];

double velSmoothX[FILT_LEN];
double velSmoothY[FILT_LEN];
double velMeanX=0.0;
double velMeanY=0.0;

int c; 

// PROBABILITY-CONTROL CODE DECLARATIONS 
double min_x = 0.0;    //bounds on underlying variable
double max_x = 1.0;

double rf_width_x = 0.13/(double)SC;     //sd of gaussian
double min_y = 0.0;    //bounds on underlying variable 
double max_y = 1.0;
double rf_width_y = 0.13/(double)SC;     //sd of gaussian
double beta = .01;
double xpoints[NCX];  //= linspace(0.0, 1.0, NCX);

double pot1=0,pot2=0,pot3=0,pot4=0;
double sp1=0,sp2=0,sp3=0,sp4=0; //double or binary??
double difx, dify;

double t = 0.0;
double xglob=0.5;
double yglob=0.5;
int ind[2];
int num_spike;
double sum1, sum2, sum3, sum4;
double estimated_pos[2];
//double ypoints[NCY];  //= linspace(0.0, 1.0, NCX);

//typedef struct rf //can also add rf_center
//{
	//double center;
	//double *Vrf;
//} _RF;

//_RF *rfx[NSX];
//_RF *rfvx[NSX];
//_RF *rfcx[NCX]; //cortex cells
//_RF *rfy[NSY];
//_RF *rfvy[NSY];
//_RF *rfcy[NCY]; //cortex cells


// FUNCTION PROTOTYPES
int InitProbCon(void);
void init(void);

void TimePlot(void);
void MainLoop(void);
void LogicLoop(void);
void processNormalKeys(unsigned char key, int x, int y);
//void ProbConLoop_Matlab();
void ProbConLoop_C();


void freeProbConMem();

void drawGrid(void);
void drawGridPixel(double x, double y);
void drawCross(double x, double y);
void drawCircle(double x, double y);

double round(double x);
double randn(void);

// FUNCTION IMPLEMENTATIONS
double randn()
{
	return (((double)(rand()%2000)/1000.0)-1.0);	
}

void drawCross(double x, double y)
{
	glLineWidth(2.0);
	glBegin(GL_LINES);
		glVertex2f(x-0.02*NCX, y);	
		glVertex2f(x+0.02*NCX, y);	
		glVertex2f(x, y-0.02*NCX);	
		glVertex2f(x, y+0.02*NCX);	
	glEnd();
	glLineWidth(1.0);
}

void drawEmptyCircle(double x, double y)
{
	glLineWidth(2.0);
	glBegin(GL_LINES);
		double radius=0.04*NCX;
		for(double di=0.0; di<=2*GL_PI;di+=GL_PI/8.0)
		{
			glVertex2f(x+radius*cos(di), y+radius*sin(di));	
		}
	glEnd();
	glLineWidth(1.0);
}

void drawCircle(double x, double y)
{
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);	
		double radius=0.04*NCX;
		for(double di=0.0; di<=2*GL_PI;di+=GL_PI/8.0)
		{
			glVertex2f(x+radius*cos(di), y+radius*sin(di));	
		}
	glEnd();
}

void drawLoop(double x, double y)
{
	glBegin(GL_LINES);
		double radius=0.02*NCX;
		for(double di=0.0; di<=2*GL_PI;di+=GL_PI/8.0)
		{
			glVertex2f(x+radius*cos(di), y+radius*sin(di));	
		}
	glEnd();
}

void drawGridPixel(double x, double y)
{
	glBegin(GL_TRIANGLE_FAN);

	for(int i=0; i<NCX; i++)
	{
		glVertex2f(x, y);	
		glVertex2f(x, y+0.02*NCY);	
		glVertex2f(x+0.02*NCX, y+0.02*NCY);	
		glVertex2f(x+0.02*NCY, y);	
	}
	glEnd();
}


void drawGrid()
{
	glBegin(GL_LINES);

	for(int i=0; i<NCX; i++)
	{
			glVertex2f(i, 0.0);	
			glVertex2f(i, NCY);	
				
			glVertex2f(0.0, i);	
			glVertex2f(NCY, i);	
	}
	glEnd();
}

double round(double x) 
{
	return (x>=0 ? floor(x + 0.5) : ceil(x + 0.5));
}

void LogicLoop()
{
	if(bMatlabLoopOn)
	{
		ProbConLoop_C();
		t = t + 1;

	}
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, NCX, NCY, 0.0, -1.0, 1.0);
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		kill = 1;
		printf("\n11");
		//Sleep(200);
		printf("\n12");

		exit(0);
	}
	else
	{
		if ( key == 'p') {
			b3DPositionServo = true;
		}
		else if ( key =='z' ) {
			bZOnlyControl = true;
		}
		else if ( key == 'm' )
		{
			bMatlabLoopOn = true;
		}
		else if ( key == 'r' )
		{
		}
	}
}

int InitProbCon()   
{
	int i_IPC,j_IPC;
	srand ( time(NULL) );
	xglob = 0.5;
	yglob = 0.5;
	t = 1.0;
	return 0;
}

void ProbConLoop_C()
{
	int i_PCLC,j_PCLC;
	for(i_PCLC=0;i_PCLC<NCX;i_PCLC++)
	{
		for(j_PCLC=0;j_PCLC<NCY;j_PCLC++)
		{
			glColor3f(0.7,0.7,0.0);
			drawGridPixel((double)i_PCLC,(double)j_PCLC);
		}
	}

	for(i_PCLC=0;i_PCLC<NCX;i_PCLC++)
	{
		for(j_PCLC=0;j_PCLC<NCY;j_PCLC++)
		{
			glColor3f(0.7,0.7,0.7);
			drawGridPixel((double)i_PCLC,(double)j_PCLC);
		}
	}

	for(i_PCLC=0;i_PCLC<NCX;i_PCLC++)
	{
		for(j_PCLC=0;j_PCLC<NCY;j_PCLC++)
		{
			glColor3f(1.0,0.0,0.0);
			drawLoop((double)i_PCLC,(double)j_PCLC);
		}
	}

	glColor3f(0.1,0.1,0.9);
	//drawCircle(25,75);
	drawCircle(xglob*NCX,yglob*NCY);

	glColor3f(0.1,0.8,0.8);
	drawCross(estimated_pos[0]*NCX,estimated_pos[1]*NCY);

	difx = sp2-sp1;
	dify = sp4-sp3;		

}

int main(int argc, char* argv[])
{   
 	// Check for proper syntax
	modeShowPotential = true;
 	if (argc < 3) {
 		// Keep going
 	}
	else if (argc == 3) {
 	} 
 	else if (argc == 4) {
 	}
 	else if (argc == 5) {
 	}
 	

	timebase = 0;
	InitProbCon();

	kill = 0;
	recording = 0;


	printf("Press R to record data\n");
	tp = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (0, 0);
	mainWindow = glutCreateWindow ("Probcon");
	init();
	glutKeyboardFunc(processNormalKeys);
	glutDisplayFunc(MainLoop);
	glutMainLoop();

	fprintf(stderr, "\n\nDone 2 !!! :D.\n");     
	return 0;
}

double dTime;

void MainLoop()
{
	glClear (GL_COLOR_BUFFER_BIT);

	glColor3f (1.0, 1.0, 1.0);

	glColor3f (0.2, 0.2, 0.2);
	drawGrid();
	glColor3f (1.0, 1.0, 1.0);

	LogicLoop();

	//glColor3f (0.0, 0.8, 0.0);
	//drawCircle((Gx/100+0.5)*NCX,(Gy/100+0.5)*NCY);

	frame++;
	timeget=glutGet(GLUT_ELAPSED_TIME);
	if(timeget-timebase>1000)
	{
		fps= (double)frame*1000.0/(double)(timeget-timebase);
		timebase=timeget;
		frame=0;
		//printf("\n%f",fps);
	}

	glutSwapBuffers();
	glutPostRedisplay();
}
