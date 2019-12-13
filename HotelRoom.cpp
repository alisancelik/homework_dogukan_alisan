#include "Hotel.h"
#include "HotelRoom.h"

RoomModel::RoomModel(QObject *parent) : QAbstractListModel(parent)
  ,mList(nullptr)
{

}
int RoomModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid() || !mList)
        return 0;

    return mList->items().size();

}
QVariant RoomModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || !mList)
        return QVariant();
    const Rooms item =mList->items().at(index.row());
    switch(role)
    {
        case DoneRole:
            return QVariant(false);
        case DescritptionRole:
            return QVariant(QStringLiteral("The personal information;the date of arrival and departure"));
    }
    return QVariant();
}
bool RoomModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;
    Rooms item = mList->items().at(index.row());
    switch (role) {
    case DoneRole:
            item.done = value.toBool();
            break;
    case DescritptionRole:
            item.description = value.toString();
            break;
    }

    if (mList->setItemAt(index.row(),item))
    {
        emit dataChanged(index, index, QVector<int>() << role);//check if the data has changed
        return true;
    }
    return false;
}
Qt:: ItemFlags RoomModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}
QHash<int, QByteArray> RoomModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[DescritptionRole]="description";
    return names;
}


Hotel *RoomModel::list() const
{
    return mList;
}

void RoomModel::setList(Hotel *list)
{
    beginResetModel();
    if(mList)
    {
        mList->disconnect(this);
    }
    mList = list;

    if(mList)
    {
        connect(mList, &Hotel::preItemAppended, this, [=](){
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &Hotel::postItemAppended, this, [=](){
            endInsertRows();
        });

        connect(mList, &Hotel::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), index, index);
        });

        connect(mList, &Hotel::postItemRemoved, this, [=](){
            endRemoveRows();
        });

    }

    endResetModel();
}
