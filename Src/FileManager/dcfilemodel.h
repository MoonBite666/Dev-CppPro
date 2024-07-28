
#ifndef DCFILEMODEL_H
#define DCFILEMODEL_H
#include <QObject>
constexpr int FILECLASS_TEMP = 0;
constexpr int FILECLASS_C = -2;
constexpr int FILECLASS_CPP = -1;
constexpr int FILECLASS_H = 1;
constexpr int FILECLASS_HPP = 2;

class QFile;
class DCFileModel final : public QObject {
    Q_OBJECT
public:
    explicit DCFileModel(QObject* parent = nullptr);
    ~DCFileModel() override = default;
    static QFile* newFile(QString filename = tr("TempFile"), int FILECLASS = FILECLASS_CPP);
    QFile* openFile(const QString & filename = nullptr);
private:
};



#endif //DCFILEMODEL_H
