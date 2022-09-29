#include <QtCore/QCoreApplication>
#include "../QtImplement/QtImplement.cpp"
#include <qDebug>
#include <QMetaProperty>
#include <QMetaClassInfo>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QtImplement* c = new QtImplement();
    //TestInterface* i = qobject_cast<TestInterface*>(c);
    //if (i != NULL)
    //{
    //    // Yes, c inherits YourInterface
    //}

	//qDebug() << imp->getValues();

	qDebug() << QtImplement::staticMetaObject.className();
	for (int i = 0; i < QtImplement::staticMetaObject.classInfoCount(); ++i) {
		const auto metaClassInfo = QtImplement::staticMetaObject.classInfo(i);
		qDebug() << metaClassInfo.name() << metaClassInfo.value();
	}
	//qDebug() << endl;
	for (int i = 0; i < QtImplement::staticMetaObject.propertyCount(); ++i) {
		const auto metaClassInfo = QtImplement::staticMetaObject.property(i);
		qDebug() << metaClassInfo.name();
	}
	QtImplement* newIns = static_cast<QtImplement*>(QtImplement::staticMetaObject.newInstance());
	qDebug() << newIns->getValues();

 	//qDebug() << endl;
    return a.exec();
}
