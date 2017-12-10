#include "labelobject.h"


LabelObject::LabelObject(QObject *parent) : QObject(parent)
{}

LabelObject::LabelObject(const QString &name, const int index, QObject *parent) :
    QObject(parent), m_name(name), m_index(index)
{}

QString LabelObject::name() const
{
    return m_name;
}

int LabelObject::index() const
{
    return m_index;
}

void LabelObject::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

void LabelObject::setIndex(const int &index)
{
    if (index != m_index) {
        m_index = index;
        emit indexChanged();
    }
}
