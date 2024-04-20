#pragma once

#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QDateTime>
#include <vector>

class Note
{
public:
    int id;
    QString title;
    QString content;
    QDateTime lastModified;
    std::vector<std::string> tags;
};

#endif // NOTE_H