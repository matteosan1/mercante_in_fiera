#include "mazzo.h"
#include "cartaobject.h"
#include "labelobject.h"
#include "qmlstring.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>

#include <random>
#include <chrono>
#include <unistd.h>

#include <QDebug>

#define SEED std::chrono::system_clock::now().time_since_epoch().count()

Mazzo::Mazzo(const QString& filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);

        QStringList carteTmp;
        QString back;
        int carteVincenti;
        int i = 0;
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if (line == "" or line.startsWith("#"))
                continue;

            if (i == 0) {
                back = line.trimmed();
            }
            else if (i == 1) {
                bool ok = false;
                carteVincenti = line.trimmed().toInt(&ok);
                if (!ok) {
                    qCritical() << "Errore nel file di configurazione (numero di carte vincenti)";
                    abort();
                }
            }
            else {
                carteTmp.append(line.trimmed());
            }

            i++;
        }

        std::shuffle(carteTmp.begin(), carteTmp.end(), std::default_random_engine(SEED));

        QFile out("/Users/sani/mercante_in_fiera/mazzo_scozzato.txt");
        if (out.open(QIODevice::WriteOnly)) {
            QTextStream stream(&out);

            foreach(QString c, carteTmp) {
                stream << c << "\n";
            }
        }
        out.close();

        QStringList labels;
        labels << "PRIMO" << "SECONDO" << "TERZO" << "QUARTO" << "QUINTO" << "SESTO";

        for (int i=0; i<carteVincenti; i++) {
            m_carte_vincenti.append(carteTmp.at(i));

            m_label.append(new LabelObject(labels.at(i), i));
        }

        for (int i=carteVincenti; i<carteTmp.size(); i++) {
            m_carte.append(carteTmp.at(i));
        }

        m_back = back;
    }

    file.close();
}
