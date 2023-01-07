#include "Physics.h"

void dampen(vector* velocity, double b, double mass){
	vector F;
	F.x = -b*velocity->x;
	F.y = -b*velocity->y;
	addForce(velocity, F, mass);
}
void addForce(vector* velocity, vector force, double mass){
	velocity->x += force.x*deltaTime/mass;
	velocity->y += force.y*deltaTime/mass;
}