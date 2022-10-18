#include "QtImplement.h"


QtImplement::QtImplement()
{
	flag++;
}
QtImplement::~QtImplement()
{
	qDebug() << "~QtImplement() called";
}
int QtImplement::getValues()
{
	return flag;
}
void QtImplement::setNum(const uint& num1) {
	_num = num1;
}
uint QtImplement::Num() {
	return _num;
}
//TestInterface* getInstance() {
//	return new QtImplement();
//}