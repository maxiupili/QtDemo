#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

smallwidget::smallwidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *sp = new QSpinBox(this);
    QSlider *sl = new QSlider(Qt::Horizontal,this);

    QHBoxLayout *hla = new QHBoxLayout(this);
    hla->addWidget(sp);
    hla->addWidget(sl);

    connect(sp, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), sl, &QSlider::setValue);

    connect(sl, &QSlider::valueChanged, sp, &QSpinBox::setValue);

}
