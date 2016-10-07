#ifndef FORMWIDGET_H
#define FORMWIDGET_H
#include <QtWidgets>
#include <QJsonDocument>
#include <QDebug>
#include "objectfield.h"

class FormWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FormWidget(const QJsonDocument& doc, QWidget *parent = 0);


public slots:
    void testOk();

private:
    ObjectField * mRootField;
    QPushButton * mValidButton = new QPushButton("Ok");


};

#endif // FORMWIDGET_H
