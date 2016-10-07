#include <QApplication>
#include "formwidget.h"
int main (int argc , char **argv)
{

    QApplication app(argc,argv);

    QFile file(":test.json");
    if (file.open( QIODevice::ReadOnly)){

    FormWidget * widget = new FormWidget( QJsonDocument::fromJson(file.readAll()));
    widget->show();

    }




    return app.exec();
}
