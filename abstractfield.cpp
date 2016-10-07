#include "abstractfield.h"



AbstractField::AbstractField(QWidget *parent)
    :QWidget(parent){

}

const QString AbstractField::title() const
{
    if (schema().contains("title"))
        return schema().value("title").toString();
    else
        return QString();

}

const QString AbstractField::type() const
{
    if (schema().contains("type"))
        return schema().value("type").toString();
    else
        return QString();

}

const QVariant AbstractField::defaultValue() const
{

    if (schema().contains("default"))
        return schema().value("default").toVariant();
    else
        return QVariant();

}

const QJsonObject &AbstractField::schema() const
{
 return mSchema;
}

void AbstractField::init(const QJsonObject &schema)
{
    mSchema = schema;
    parseSchema(schema);

}
