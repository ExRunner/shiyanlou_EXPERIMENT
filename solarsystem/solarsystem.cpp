#include "solarsystem.hpp"

#define TIMEPAST 1
#define SELFROTATE 3

enum STARS{Sun, Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune};

void SolarSystem::onDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(.7f, .7f, .7f, .1f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0f, 1.0f, 1.0f, 40000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(viewX, viewY, viewZ, centerX, centerY, centerZ, upX, upY, upZ);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	for(int i = 0; i < STARS_NUM; i++)
		stars[i]->draw();
	glutSwapBuffers();
}

void SolarSystem::onUpdate()
{
	for(int i = 0; i < STARS_NUM; i++)
		stars[i]->update(TIMEPAST);
	this->onDisplay();	
}

void SolarSystem::onKeyboard(unsigned char key, int x, int y)
{
	//todo:
}

SolarSystem::SolarSystem()
{
	//todo:
}

SolarSystem::~SolarSystem()
{
	//todo:
}

