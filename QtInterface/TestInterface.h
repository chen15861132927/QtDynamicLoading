#pragma once

#include "qtinterface_global.h"
#include <QObject>

class QTINTERFACE_EXPORT TestInterface :public QObject
{
	Q_OBJECT
public:

	TestInterface();
	~TestInterface();
	static int flag;

	virtual int getValues() = 0;
};



 

Q_DECLARE_INTERFACE(TestInterface, "com.chenwei.Interface/0")


