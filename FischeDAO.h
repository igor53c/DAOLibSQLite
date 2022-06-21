#pragma once

#include <QDateTime>
#include <QSqlTableModel>

#include "DAOLib.h"
#include "Fisch.h"
#include "FischeSqlTableModel.h"

class DAOLIB_EXPORT FischeDAO {
public:
  static bool insertFisch(const QString &path, const QString &name,
                          const QString &angelplatz, const int laenge,
                          const int gewicht, const QDateTime &zeit,
                          const int temperatur, const int windgeschwindigkeit,
                          const int luftdruck, const bool isNacht,
                          const int niederschlag, const QString &info);

  static int getRowCount();

  static void deleteTable();

  static Fisch *readFisch(const qint64 key);

  static QString readFischAngelplatz(const qint64 key);

  static FischeSqlTableModel *
  readFischeIntoTableModel(const QStringList &listNacht,
                           const QStringList &listNiederschlag,
                           QWidget *parent = nullptr);

  static bool updateFisch(const qint64 key, const QString &path,
                          const QString &name, const QString &angelplatz,
                          const int laenge, const int gewicht,
                          const QDateTime &zeit, const int temperatur,
                          const int windgeschwindigkeit, const int luftdruck,
                          const bool isNacht, const int niederschlag,
                          const QString &info);

  static bool deleteFisch(const qint64 key);

  static QStringList readFischarten();

  static QVariant getMinParameter(const QString &column,
                                  const QString &angelplatz);

  static QVariant getMaxParameter(const QString &column,
                                  const QString &angelplatz);

  static bool deleteFischeInAngelplatz(const QString &angelplatz);

  static int countFischeInAngelplatz(const QString &angelplatz);

  static bool fischExists(const qint64 key);

  static bool updateFischeWithAngelplatz(const QString &oldValue,
                                         const QString &newValue);

private:
  // Privater Konstruktor.
  // Verhindert das Erstellen dieser Klasse.
  // Alle Methoden sind statisch.
  FischeDAO();
};
