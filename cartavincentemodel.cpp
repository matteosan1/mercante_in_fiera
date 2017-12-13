#include "cartavincentemodel.h"

//#include <QDateTime>
#include <QDebug>

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
    QAbstractListModel(parent),
    m_globalIndex(0)
{
    QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(moveCarta()));
    m_labels.clear();
    //fillData();
}

void CartaVincenteModel::addCarta(const CartaVincente& carta)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_labels.append(carta);
    endInsertRows();
}

void CartaVincenteModel::addTmpCarta(const CartaVincente& carta)
{
    m_tmpLabels.append(carta);
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

void CartaVincenteModel::smazza()
{
    m_timer.setInterval(1000);
    m_timer.start();
}

void CartaVincenteModel::moveCarta() {
    m_timer.stop();
    qDebug() << m_globalIndex << m_tmpLabels.size();
    addCarta(m_tmpLabels.at(m_globalIndex));
    m_globalIndex++;
    if (m_globalIndex < m_tmpLabels.size())
        m_timer.start();
    else
        emit done();
}
