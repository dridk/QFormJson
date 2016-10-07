#include "objectfield.h"


ObjectField::ObjectField(const QJsonObject &schema, QWidget *parent)
    :AbstractField(parent)
{
    init(schema);
}

ObjectField::ObjectField(const QByteArray &json, QWidget *parent)
    :AbstractField(parent)
{
    QJsonParseError err;
    QJsonObject obj = QJsonDocument::fromJson(json,&err).object();

    if (err.error == QJsonParseError::NoError)
        init(obj);


}

void ObjectField::parseSchema(const QJsonObject &schema)
{

    if (schema.value("type") == QJsonValue::Undefined )
        return;

    if ( schema.contains("properties"))
    {
        QJsonObject properties = schema.value("properties").toObject();

        QFormLayout * propLayout = new QFormLayout;

        for(QString key : properties.keys())
        {
            qDebug()<<key;

            QJsonObject property = properties.value(key).toObject();
            AbstractField * field = Q_NULLPTR;

            if (property.value("type") == "string"){
                field = new StringField(property,this);
                propLayout->addRow(field->title(),field);

            }


            if (property.value("type") == "integer"){
                field = new IntegerField(property,this);
                propLayout->addRow(field->title(),field);

            }

            if (property.value("type") == "object"){
                field                   = new ObjectField(property,this);
                QGroupBox * box         = new QGroupBox;

                QVBoxLayout * boxLayout = new QVBoxLayout;
                boxLayout->setContentsMargins(0,0,0,0);
                boxLayout->addWidget(field);
                box->setLayout(boxLayout);
                box->setTitle(field->title());
                propLayout->addWidget(box);

            }



        }

        mGroupBox->addLayout(propLayout);


    }



    QVBoxLayout * formLayout = new QVBoxLayout;
    formLayout->addLayout(mGroupBox);
    formLayout->addStretch();
    setLayout(formLayout);






}
