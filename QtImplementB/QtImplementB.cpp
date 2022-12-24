#include "QtImplementB.h"
int QtImplementB::flag2 = 0;
QtImplementB::QtImplementB()
{
	flag2++;
	currentFlag = flag2;
	intPRT = new int[1000000];
}

QtImplementB::~QtImplementB()
{
	qDebug() << "~QtImplementB() called"<< currentFlag;
	delete intPRT;
}


int QtImplementB::getValues()
{
	return flag2 * flag2;
}
//TestInterface* getInstance() {
//	return new QtImplementB();
//}