#ifndef MODULE_H
#define MODULE_H

#include <QStringList>
#include <QDir>
#include <QTextStream>
#include <QRegularExpression>
#include <QDirIterator>
#include <QDebug>
//#include <QMap>

class Module
{
public:
    Module(QDir mod_dir);

    void search_for_modules_dep();
    void search_dep_in_file( const QString& file);


QStringList dependensies;
QSet<QString> header_dep_from_modules;
QSet<QString> gen_file_names;
QSet<QString> use_gen_files;
QDir module_dir;

};

#endif // MODULE_H
