#ifndef QMLSTRING_H
#define QMLSTRING_H

#include <QObject>

class QmlString : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString string READ string WRITE setstring NOTIFY stringChanged)
public:

    QmlString(const QString& string, QObject* parent = 0);

    void setstring(const QString &a) {
        if (a != m_string) {
            m_string = a;
            emit stringChanged();
        }
    }
    QString string() const {
        return m_string;
    }
signals:
    void stringChanged();
private:
    QString m_string;
};

#endif // QMLSTRING_H
