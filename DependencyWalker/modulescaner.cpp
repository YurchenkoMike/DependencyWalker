#include "modulescaner.h"

ModuleScaner::ModuleScaner(const QString &dirName)
    : current_dir(dirName)
{
    info_list.clear();
    info_list = current_dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    //qDebug() << info_list;
    scan_dir();

}

void ModuleScaner::scan_dir()
{
//    foreach(QFileInfo cur,info_list)
    for(int i = 0; i<info_list.count()/*, i < 2*/; ++i)
    {
        if(info_list[i].isDir())
        {
            qDebug() << info_list[i].absoluteFilePath();
            modules.append(new Module(QDir(info_list[i].absoluteFilePath())));

        }
    }
}
