#ifndef LABELOBJECT_H
#define LABELOBJECT_H

#include <QObject>
#include <QObject>
#include <QString>

class LabelObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)

public:
    LabelObject(QObject *parent = 0);
    LabelObject(const QString& name, const int index, QObject* parent=0);

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

#endif // LABELOBJECT_H
