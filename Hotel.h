#ifndef Hotel_H
#define Hotel_H

#include <QObject>
#include <QVector>

struct Rooms
{
    bool done;
    QString description;

};

class Hotel : public QObject
{
    Q_OBJECT
public:
    explicit Hotel(QObject *parent = nullptr);
    QVector<Rooms> items() const;

    bool setItemAt(int index, const Rooms &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void removeCompletedItems();

private:
       QVector<Rooms> mItems;
};

#endif // Hotel_H
