#include "Hotel.h"

Hotel::Hotel(QObject *parent) : QObject(parent)
{
    mItems.append({true, QStringLiteral("") });

    mItems.append({false, QStringLiteral("") });

}

QVector<Rooms> Hotel::items() const
{
    return  mItems;
}

bool Hotel::setItemAt(int index, const Rooms &item)
{
    if(index < 0 || index >= mItems.size())//data is changed
        return false;
    const Rooms &oldItem = mItems.at(index);
    if(item.done == oldItem.done && item.description == oldItem.description)
        return false;

    mItems[index]=item;
    return true;
}

void Hotel::appendItem()
{
    emit preItemAppended();

    Rooms item;
    item.done = false;
    mItems.append(item);

    emit postItemAppended();

}

void Hotel::removeCompletedItems()
{
    for (int i=0; i < mItems.size();)
    {
        if(mItems.at(i).done)
        {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        }
        else
        {
            ++i;
        }
    }
}
