#include "qmlstring.h"

QmlString::QmlString(const QString& string, QObject* parent) : m_string(string), QObject(parent)
{}
