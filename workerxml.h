#ifndef WORKERXML_H
#define WORKERXML_H

#include <QDomDocument>
#include <QDomElement>
#include <QDomText>
#include <QFile>
#include <QTextStream>
#include <QString>

#include <group.h>

class WorkerXML
{
public:
    WorkerXML(QList<Group*>);

    QDomDocument *doc;
    QDomElement root,
                group,
                count_labs,
                number_group,
                student,
                name;

    void Save(QString);

private:
    void BuildTree(QList<Group*>);

};

#endif // WORKERXML_H
