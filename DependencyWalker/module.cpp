#include "module.h"

Module::Module(QDir mod_dir):
    module_dir(mod_dir)
{
    search_for_modules_dep();
}

void Module::search_for_modules_dep()
{
    QDirIterator it(module_dir.path(), QStringList() << "*.h" << "*.hpp" << "*.c" << "*.cpp", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
//        QFile file(it.next());
        search_dep_in_file(it.next());

    }
    qDebug() << header_dep_from_modules;
    qDebug() << gen_file_names;

}

void Module::search_dep_in_file(const QString& path)
{
    QFile temp ( path);

    temp.open(QIODevice::ReadOnly);
    QTextStream stream(&temp);
    QString filedata = stream.readAll();

    QRegularExpression re("#include \"(?<path>[\\w,\\/\\.]+)\"");
    QRegularExpressionMatchIterator i = re.globalMatch(filedata);

    QStringList words;

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString str = match.captured("path");

        words = str.split("/");
        switch(words.count())
        {
        default:
        case 2:
        {
            header_dep_from_modules.insert(words.takeFirst());
        }
        case 1:
        {
            if(words.last().endsWith(".pb.h"))
            {
                gen_file_names.insert(words.takeLast());
            }
        }
            //dep_files.insert(words.takeLast());
        case 0:
            break;

        }
    }

//    qDebug() << dep_files;

    temp.close();
}
