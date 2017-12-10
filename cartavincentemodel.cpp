#include "cartavincentemodel.h"

//#include <QDateTime>

CartaVincente::CartaVincente(const QString& label, const QString& back, const int& index) :
    m_label(label),
    m_back(back),
    m_index(index)
{}

QHash<int, QByteArray> CartaVincenteModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[LabelRole] = "fronte";
    roles[BackRole] = "retro";
    roles[IndexRole] = "index";

    return roles;
}

CartaVincenteModel::CartaVincenteModel(QObject* parent) :
    QAbstractListModel(parent)
{
    m_labels.clear();
    //fillData();
}

void CartaVincenteModel::addCarta(const CartaVincente& carta)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_labels.append(carta);
    endInsertRows();
}

int CartaVincenteModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_labels.count();
}

QVariant CartaVincenteModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= m_labels.count())
        return QVariant();

    if (role == LabelRole)
        return m_labels.at(index.row()).label();
    else if (role == BackRole)
        return m_labels.at(index.row()).back();
    else if (role == IndexRole)
        return m_labels.at(index.row()).index();

    return QVariant();
}

void CartaVincenteModel::fillData()
{
    //qsrand(QDateTime::currentMSecsSinceEpoch());
    beginResetModel();
    m_labels.clear();
    // do something
    endResetModel();
}

bool CartaVincenteModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);

    return true;
}
