#pragma once
#include <QObject>
#include <qDebug>
#include "qtimplement_global.h"
#include "../QtInterface/TestInterface.h"


class QTIMPLEMENT_EXPORT QtImplement: public TestInterface
{
	Q_OBJECT
		Q_PLUGIN_METADATA(IID "com.chenwei.Interface/1")

		Q_INTERFACES(TestInterface)
		Q_CLASSINFO("author", "Uncle Scrooge")
		Q_CLASSINFO("revision", "3.14")
 
		Q_PROPERTY(uint Num READ Num WRITE setNum)

public:	

	Q_INVOKABLE  QtImplement();
	Q_INVOKABLE ~QtImplement();
	Q_INVOKABLE uint Num();
	Q_INVOKABLE void setNum(const uint& num1);
	
	Q_INVOKABLE int getValues() override;


private:
	uint _num;
};



//extern "C" QTIMPLEMENT_EXPORT TestInterface* getInstance();