#include "formwidget.h"



FormWidget::FormWidget(const QJsonDocument &doc, QWidget *parent)
    :QWidget(parent)
{

    QJsonObject root;
    root.insert("type","object");
    root.insert("properties", doc.object());

    QVBoxLayout * rootLayout = new QVBoxLayout;
    mRootField = new ObjectField(root);
    rootLayout->addWidget(mRootField);
    rootLayout->addStretch();
    rootLayout->addWidget(mValidButton);
    rootLayout->setContentsMargins(0,0,0,0);

    setLayout(rootLayout);


    connect(mValidButton,SIGNAL(clicked(bool)),this,SLOT(testOk()));

}

void FormWidget::testOk()
{


qDebug()<<mRootField->children().at(1)->children();





}

