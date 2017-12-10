#ifndef MAZZO_H
#define MAZZO_H

#include <QObject>
#include <QString>

class Mazzo
{

public:
    Mazzo(const QString& filename);

    QList<QObject*> carte() const { return m_carte; }
    QList<QObject*> vincenti() const { return m_vincenti; }
    QList<QObject*> labels() const { return m_label; }
    QString back() const { return m_back; }
    int carteVincenti() const { return m_vincenti.size(); }
    int nCarte() const { return m_carte.size(); }

private:
    QList<QObject*> m_carte;
    QList<QObject*> m_vincenti;
    QList<QObject*> m_label;
    QString m_back;
};

#endif // MAZZO_H
