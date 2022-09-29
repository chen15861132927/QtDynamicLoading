#pragma once
#include <QObject>
#include <qDebug>
#include "qtimplement_global.h"
#include "../QtInterface/TestInterface.h"

static int flag = 0;

class QTIMPLEMENT_EXPORT QtImplement: public TestInterface
{
	Q_OBJECT
		Q_INTERFACES(TestInterface)
		Q_CLASSINFO("author", "Uncle Scrooge")
		Q_CLASSINFO("revision", "3.14")

		Q_PROPERTY(uint Num READ Num WRITE setNum)

public:	

	Q_INVOKABLE QtImplement() { flag++; };
	Q_INVOKABLE ~QtImplement() { qDebug() << "~QtImplement() called"; }
	Q_INVOKABLE uint Num() {
		return _num;
	}
	Q_INVOKABLE void setNum(const uint& num1) {
		_num = num1;
	}
	
	Q_INVOKABLE int getValues() override;
private:
	uint _num;
};
//int QtImplement::flag = 0;   //定义并初始化静态数据成员



extern "C" QTIMPLEMENT_EXPORT TestInterface* getInstance();