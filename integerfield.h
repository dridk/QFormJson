#ifndef INTEGERFIELD_H
#define INTEGERFIELD_H

#include "abstractfield.h"

class IntegerField : public AbstractField
{
    Q_OBJECT
public:
    explicit IntegerField(const QJsonObject& schema, QWidget *parent = 0);
    explicit IntegerField(const QByteArray& json, QWidget *parent = 0);


protected:
    void parseSchema(const QJsonObject& schema) Q_DECL_OVERRIDE;

private:
    QSpinBox * mSpinBox = new QSpinBox;


};

#endif // INTEGERFIELD_H
