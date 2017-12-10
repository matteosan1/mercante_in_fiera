#ifndef CARTAOBJECT_H
#define CARTAOBJECT_H

#include <QObject>
#include <QString>

class CartaObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)

public:
    CartaObject(QObject *parent = 0);
    CartaObject(const QString& name, const int index, QObject* parent=0);

    QString name() const;
    void setName(const QString& name);

    int index() const;
    void setIndex(const int& index);

signals:
    void nameChanged();
    void indexChanged();

private:
    QString m_name;
    int m_index;
};


#endif // CARTAOBJECT_H
