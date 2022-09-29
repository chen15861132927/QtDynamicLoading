#include "QtImplement.h"

int QtImplement::getValues()
{
	return flag;
}
TestInterface* getInstance() {
	return new QtImplement();
}