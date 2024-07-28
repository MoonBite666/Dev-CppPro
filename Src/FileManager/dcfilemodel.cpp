#include "dcfilemodel.h"

#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QString>

DCFileModel::DCFileModel(QObject *parent) : QObject(parent){}

QFile* DCFileModel::newFile(QString filename, int FILECLASS){
    if(FILECLASS == FILECLASS_TEMP) filename = QDir::tempPath() + "/" + filename;
    auto *file = new QFile(filename);
    try {
        file->open(QIODevice::WriteOnly);
    }catch (std::exception &e) {
        qDebug() << e.what();
        return nullptr;
    }
    QTextStream out(file);
    switch(FILECLASS){
        case FILECLASS_H:
        case FILECLASS_HPP:
            out << "#ifndef " << filename.toUpper().replace(".", "_") << "\n";
            out << "#define " << filename.toUpper().replace(".", "_") << "\n";
            out << "// Created by MoonFeather on " << QDateTime::currentDateTime().toString("yy-MM-dd") << ".\n";
            out << "#endif //" << filename.toUpper().replace(".", "_") << "\n";
            break;
        case FILECLASS_C:
        case FILECLASS_CPP:
        default:
            out << "// Created by MoonFeather on " << QDateTime::currentDateTime().toString("yy-MM-dd") << ".\n";
            break;
    }
    file->close();
    return file;
}

QFile* DCFileModel::openFile(const QString &filename){
    QFile *file = new QFile(filename);
    try {
        file->open(QIODevice::ReadOnly);
    }catch (std::exception &e) {
        qDebug() << e.what();
        return nullptr;
    }
    return file;
}