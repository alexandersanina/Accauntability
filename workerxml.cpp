#include "workerxml.h"
#include <QDebug>

WorkerXML::WorkerXML(QList<Group*> group_list)
{  
    BuildTree(group_list);
}

void WorkerXML::BuildTree(QList<Group*> group_list)
{
    doc = new QDomDocument;
    root = doc->createElement("doc");

    doc->appendChild(root);

    int count_groups = group_list.count();
    int count_students;

    for(int i = 0; i < count_groups; i++)
    {
        group = doc->createElement("group");
        count_labs = doc->createElement("count_labs");
        number_group = doc->createElement("number_group");
        root.appendChild(group);
        group.appendChild(number_group);
        group.appendChild(count_labs);
        number_group.appendChild(doc->createTextNode(group_list.at(i)->num));
        count_labs.appendChild(doc->createTextNode(QString::number(group_list.at(i)->count_labs)));

        count_students = group_list.at(i)->students_list.count();

        for(int j = 0; j < count_students; j++)
        {
            student = doc->createElement("student");
            name = doc->createElement("name");
            group.appendChild(student);
            student.appendChild(name);
            name.appendChild(doc->createTextNode(group_list.at(i)->students_list.at(j)->name));
        }
    }
}

void WorkerXML::Save(QString path)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    doc->save(out, 4);
    file.close();
}

