#ifndef MODULESCANER_H
#define MODULESCANER_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

#include "module.h"

class ModuleScaner
{
public:
    ModuleScaner(const QString& dirName );

    void scan_dir();
    void check_file(const QString filename);

    QString moduleDir_pth;
    QStringList list_files;

    QFileInfoList info_list;

    QDir current_dir;

    QList<Module*> modules;

};

#endif // MODULESCANER_H
