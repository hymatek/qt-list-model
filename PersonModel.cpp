#include "PersonModel.h"

PersonModel::PersonModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QMetaObject::invokeMethod(this, &PersonModel::updateModel, Qt::QueuedConnection);
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_people.count();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto &person = m_people[index.row()];

    switch (role) {
    case NameRole:
        return person.first;
    case AgeRole:
        return person.second;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    return m_roles;
}

static const QHash<int, QByteArray> predefinedRoles = {{PersonModel::NameRole,
                                                        QByteArrayLiteral("name")},
                                                       {PersonModel::AgeRole,
                                                        QByteArrayLiteral("age")}};

void PersonModel::updateModel()
{
    beginResetModel();
    m_people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    m_roles = predefinedRoles;
    endResetModel();
}
