#pragma once

#include <QAbstractListModel>
#include <QStringList>

class PersonModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PersonRoles {
        NameRole = Qt::UserRole + 1,
        AgeRole
    };

    explicit PersonModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private slots:
    void updateModel();

private:
    QHash<int, QByteArray> m_roles;
    QList<QPair<QString, int>> m_people;
};


