#ifndef OBJECTFIELD_H
#define OBJECTFIELD_H

#include "abstractfield.h"
#include "stringfield.h"
#include "integerfield.h"
class ObjectField : public AbstractField
{
    Q_OBJECT
public:
    explicit ObjectField(const QJsonObject& schema, QWidget *parent = 0);
    explicit ObjectField(const QByteArray& json, QWidget *parent = 0);

protected:
    void parseSchema(const QJsonObject& schema);

private:
    QVBoxLayout * mGroupBox = new QVBoxLayout;
    QHash<QString, AbstractField*> mFields;



};

#endif // OBJECTFIELD_H
