#ifndef CARTAVINCENTEMODEL_H
#define CARTAVINCENTEMODEL_H

#include <QObject>
#include <QHash>
#include <QByteArray>
#include <QAbstractListModel>
#include <QString>
#include <QTimer>

class CartaVincente
{
public:
    CartaVincente(const QString& label, const QString& back, const int& index);

    QString label() const { return m_label; }
    void setLabel(const QString& label) { m_label = label; }

    QString back() const { return m_back; }
    void setBack(const QString& back) { m_back = back; }

    int index() const { return m_index; }
    void setIndex(const int& index) { m_index = index; }

private:
    QString m_label;
    QString m_back;
    int m_index;
};

class CartaVincenteModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum CartaRoles {
        LabelRole = Qt::UserRole + 1,
        BackRole = Qt::UserRole + 2,
        IndexRole = Qt::UserRole + 3
    };

    CartaVincenteModel(QObject* parent = 0);
    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    void addTmpCarta(const CartaVincente& carta);
    void addCarta(const CartaVincente& carta);

public slots:
    void smazza();
    void moveCarta();

signals:
    void done();

private:
    void fillData();
    QList<CartaVincente> m_tmpLabels;
    QList<CartaVincente> m_labels;
    QTimer m_timer;
    int m_globalIndex;
};

#endif // CARTAVINCENTEMODEL_H
