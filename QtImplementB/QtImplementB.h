#pragma once

#include "qtimplementb_global.h"
#include <QObject>
#include <qDebug>
 
#include "../QtInterface/TestInterface.h"
class QTIMPLEMENTB_EXPORT QtImplementB : public TestInterface
{
	Q_OBJECT

		Q_PLUGIN_METADATA(IID "com.chenwei.Interface/2")

		Q_INTERFACES(TestInterface)
		Q_CLASSINFO("author", "QtImplementB")
		Q_CLASSINFO("revision", "6.28")

		Q_PROPERTY(uint Num READ Num WRITE setNum)

public:

	Q_INVOKABLE QtImplementB() ;
	Q_INVOKABLE ~QtImplementB();
	Q_INVOKABLE uint Num() {
		return _num;
	}
	Q_INVOKABLE void setNum(const uint& num1) {
		_num = num1;
	}

	Q_INVOKABLE int getValues() override;

	static int flag2;

	int currentFlag;

	int* intPRT;

private:
	uint _num;
};
