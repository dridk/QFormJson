#include <QApplication>
#include "stringwidget.h"
int main (int argc , char **argv)
{

    QApplication app(argc,argv);


    StringWidget * w = new StringWidget(QByteArray("{\"type\":\"string\", \"title\":\"Email\",\"required\":true}"));
    w->show();



    return app.exec();
}
