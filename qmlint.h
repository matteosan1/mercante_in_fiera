#ifndef QMLINT_H
#define QMLINT_H

#include <QObject>

class QmlInt : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int integer READ integer WRITE setInt NOTIFY intChanged)
public:

    QmlInt(const int& integer, QObject* parent = 0);

    void setInt(const int &a) {
        if (a != m_int) {
            m_int = a;
            emit intChanged();
        }
    }
    int integer() const {
        return m_int;
    }

signals:
    void intChanged();

private:
    int m_int;
};

#endif // QMLINT_H
