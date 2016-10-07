#ifndef STRINGWIDGET_H
#define STRINGWIDGET_H
#include <QtWidgets>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

class StringWidget : public QWidget
{
public:
    StringWidget(const QJsonObject& schema, QWidget * parent = Q_NULLPTR);
    StringWidget(const QByteArray& json, QWidget * parent = Q_NULLPTR);

protected:
    void parseSchema(const QJsonObject& schema);


private:
QLineEdit * mEdit = new QLineEdit;


};



#endif // STRINGWIDGET_H
