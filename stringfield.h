#ifndef STRINGWIDGET_H
#define STRINGWIDGET_H
#include "abstractfield.h"
#include <QDebug>

class StringField : public AbstractField
{
public:
    StringField(const QJsonObject& schema, QWidget * parent = Q_NULLPTR);
    StringField(const QByteArray& json, QWidget * parent = Q_NULLPTR);

protected:
    void parseSchema(const QJsonObject& schema) Q_DECL_OVERRIDE;


private:
QLineEdit * mEdit = new QLineEdit;


};



#endif // STRINGWIDGET_H
