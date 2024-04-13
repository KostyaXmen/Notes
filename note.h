#pragma once

#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QDateTime>

class Note
{
public:
    int id;
    QString title;
    QString content;
    QString tags;
    QDateTime lastModified;
};

#endif // NOTE_H