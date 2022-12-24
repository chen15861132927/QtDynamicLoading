#include <QtCore/QCoreApplication>
#include <QLibrary>
#include <qDebug>
#include <QMetaObject>
#include <QMetaClassInfo>
#include "../QtInterface/TestInterface.h"
#include <iostream>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QPluginLoader>


using namespace std;

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
	QString pathName = "QtImplementB.dll";
	//QLibrary library("QtImplement.dll");
	/*QLibrary library(pathName);

	if (library.load())
	{
		typedef TestInterface* (*getInstanceFun)();
		getInstanceFun getInstance = (getInstanceFun)library.resolve("getInstance");

		if (getInstance)
		{
			TestInterface* imp = getInstance();

			if (imp)
			{
				qDebug() << imp->getValues();

				qDebug() << imp->metaObject()->className();
				for (int i = 0; i < imp->metaObject()->classInfoCount(); ++i) {
					const auto& metaClassInfo = imp->metaObject()->classInfo(i);
					qDebug() << metaClassInfo.name() << metaClassInfo.value();
				}
 
				for (int i = 0; i < imp->metaObject()->propertyCount(); ++i) {
					const auto& metaClassInfo = imp->metaObject()->property(i);
					qDebug() << metaClassInfo.name();
				}

				QScopedPointer<TestInterface> newIns;
				newIns.reset(static_cast<TestInterface*>(imp->metaObject()->newInstance()));
				qDebug() << newIns->getValues();
				char input;
				cin >> input;
				while (input != 'q')
				{
					newIns.reset(static_cast<TestInterface*>(imp->metaObject()->newInstance()));
					qDebug() << newIns->getValues();
					cin >> input;

				}

				delete imp;
			}
		}

		qDebug()<<library.unload();
	}
	*/

	QPluginLoader pluginLoader(pathName);
	pluginLoader.load();
	auto first = pluginLoader.instance();
	shared_ptr<TestInterface> newIns;
	newIns.reset(dynamic_cast<TestInterface*>(first-> metaObject()->newInstance()));
	//qDebug() << newIns->getValues();
	char input;
	cin >> input;
	while (input != 'q')
	{
		newIns.reset(dynamic_cast<TestInterface*>(newIns->metaObject()->newInstance()));
		qDebug() << newIns->getValues();
		cin >> input;
	}
	newIns.reset();
	pluginLoader.unload();
	return a.exec();
}
