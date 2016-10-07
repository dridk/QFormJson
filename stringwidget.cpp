#include "stringwidget.h"

StringWidget::StringWidget(const QJsonObject& schema, QWidget * parent)
    :QWidget(parent)
{

    parseSchema(schema);

}

StringWidget::StringWidget(const QByteArray &json, QWidget *parent)
    :QWidget(parent)
{


    QJsonParseError err;
    QJsonObject obj = QJsonDocument::fromJson(json,&err).object();

    if (err.error == QJsonParseError::NoError)
        parseSchema(obj);


}

void StringWidget::parseSchema(const QJsonObject &schema)
{

    if (schema.value("type") != "string")
        qDebug()<<Q_FUNC_INFO<<" wrong schema";

    QFormLayout * formLayout = new QFormLayout;

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


    formLayout->addRow(title, mEdit);
    setLayout(formLayout);






}

