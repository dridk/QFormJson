#include "stringfield.h"

StringField::StringField(const QJsonObject& schema, QWidget * parent)
    :AbstractField(parent)
{

    init(schema);

}

StringField::StringField(const QByteArray &json, QWidget *parent)
    :AbstractField(parent)
{

    QJsonParseError err;
    QJsonObject obj = QJsonDocument::fromJson(json,&err).object();

    if (err.error == QJsonParseError::NoError)
        init(obj);

}

void StringField::parseSchema(const QJsonObject &schema)
{

    if (schema.value("type") != "string")
        qDebug()<<Q_FUNC_INFO<<" wrong schema";


    QString title = tr("Unknown");

    if (schema.contains("title"))
    title = schema.value("title").toString();

    if (schema.contains("required"))
        title = "<b>"+title +"</b>" ;

    if (schema.contains("description"))
        mEdit->setToolTip(schema.value("description").toString());

    if (schema.contains("pattern"))
    {
        QRegExpValidator * validator = new QRegExpValidator(QRegExp(schema.value("pattern").toString()));
        mEdit->setValidator(validator);
    }

    if (schema.contains("readOnly"))
        mEdit->setDisabled(schema.value("readOnly").toBool());

    if (schema.contains("default"))
        mEdit->setText(schema.value("default").toString());


    QHBoxLayout * formLayout = new QHBoxLayout;
    formLayout->addWidget(mEdit);
    formLayout->setContentsMargins(0,0,0,0);

    setLayout(formLayout);





}

