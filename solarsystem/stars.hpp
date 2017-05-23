#ifndef star_hpp
#define stat_hpp

#include<GL/glut.h>

class Star
{
	public:
		GLfloat	radius;
		GLfloat speed, selfspeed;
		GLfloat distance;
		GLfloat rgbaColor[4];
		Star* parentStar;

		Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfspeed, Star* parent);

		void drawStar();

		virtual void draw()
		{
			drawStar();
		}

		virtual void update(long timeSpan);

	protected:
		Float alphaSelf, alpha;
};

class Planet : public Star
{
	public:
		Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfspeed, Star* parent, GLfloat rgbColor[3]);

		void drawPlanet();
		virtual void draw()
		{
			drawPlanet();
			drawStar();
		}
};

class LightPlanet : public Planet
{
	public:
		LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfspeed, Star* parent, GLfloat rgbColor[]);
		
		void drawLight();
		virtual void draw()
		{
			drawLight();
			drawPlanet();
			drawStar();
		}
};

#endif
