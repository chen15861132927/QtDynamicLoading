#pragma once

#include "qtinterface_global.h"
#include <QObject>

class QTINTERFACE_EXPORT TestInterface :public QObject
{
	Q_OBJECT
public:

	TestInterface();
	~TestInterface();

	virtual int getValues() = 0;
};
Q_DECLARE_INTERFACE(TestInterface, "Timothy.YourInterface/1.0")
