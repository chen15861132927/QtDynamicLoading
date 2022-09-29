#include <QtCore/QCoreApplication>
#include <QLibrary>
#include <qDebug>
#include <QMetaObject>
#include <QMetaClassInfo>
#include "../QtInterface/TestInterface.h"
int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
	QLibrary library("QtImplement.dll");
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

				TestInterface* newIns = static_cast<TestInterface*>( imp->metaObject()->newInstance());
				qDebug() << newIns->getValues();
			}
		}

		library.unload();
	}
	return a.exec();
}
