#ifndef ABSTRACTFIELD_H
#define ABSTRACTFIELD_H
#include <QtWidgets>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class AbstractField : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractField(QWidget *parent = Q_NULLPTR);


    const QString title() const;
    const QString type() const;
    const QVariant defaultValue() const;

    const QJsonObject& schema() const;


protected:
    void init(const QJsonObject& schema);
    virtual void parseSchema(const QJsonObject& schema) = 0;


 private:
    QJsonObject mSchema;


};

#endif // ABSTRACTFIELD_H
