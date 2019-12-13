#ifndef HotelRoom_H
#define HotelRoom_H

#include <QObject>
#include<QAbstractListModel>


class Hotel;

class RoomModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(Hotel *list READ list WRITE setList)
public:
    explicit RoomModel(QObject *parent = nullptr);

    enum
    {
        DoneRole= Qt::UserRole,
        DescritptionRole
    };


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;





    Hotel *list() const;
    void setList(Hotel *list);

private:
    Hotel *mList;
};

#endif // HotelRoom_H
