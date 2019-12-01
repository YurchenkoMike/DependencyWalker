#ifndef MODULESCANER_H
#define MODULESCANER_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

#include "module.h"

class ModuleScaner
{
public:
    ModuleScaner(const QString& scan_dir );

    void scan_dir();
    void check_file(const QString filename);

    QString moduleDir_pth;
    QStringList list_files;

    QDir current_dir;

};

#endif // MODULESCANER_H
