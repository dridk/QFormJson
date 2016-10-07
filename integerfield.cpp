#include "integerfield.h"

IntegerField::IntegerField(const QJsonObject& schema, QWidget *parent)
    : AbstractField(parent)
{

    init(schema);

}

IntegerField::IntegerField(const QByteArray& json, QWidget *parent)
    : AbstractField(parent)
{

    QJsonParseError err;
    QJsonObject obj = QJsonDocument::fromJson(json,&err).object();

    if (err.error == QJsonParseError::NoError)
        init(obj);


}

void IntegerField::parseSchema(const QJsonObject &schema)
{

    QString title = "unknown";

    if (schema.contains("title"))
        title = schema.value("title").toString();

    if (schema.contains("default"))
        mSpinBox->setValue(schema.value("default").toInt());



    QHBoxLayout * formLayout = new QHBoxLayout;
    formLayout->addWidget(mSpinBox);
    formLayout->setContentsMargins(0,0,0,0);

    setLayout(formLayout);




}
