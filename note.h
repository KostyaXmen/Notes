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

    // Getter for tags
    const std::vector<std::string>& getTags() const { return tags; }

    // Setter for tags
    void setTags(const std::vector<std::string>& newTags) { tags = newTags; }
};

#endif // NOTE_H