#include "cartaobject.h"

CartaObject::CartaObject(QObject *parent) : QObject(parent)
{}

CartaObject::CartaObject(const QString &name, const int index, QObject *parent) :
    QObject(parent), m_name(name), m_index(index)
{}

QString CartaObject::name() const
{
    return m_name;
}

int CartaObject::index() const
{
    return m_index;
}

void CartaObject::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

void CartaObject::setIndex(const int &index)
{
    if (index != m_index) {
        m_index = index;
        emit indexChanged();
    }
}

