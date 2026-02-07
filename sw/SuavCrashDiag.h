// SuavCrashDiag.h
#pragma once

#include <QtGlobal>
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QDateTime>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <exception>
#include <csignal>

inline QString suvLogPath() {
    const QString dir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir().mkpath(dir);
    return dir + "/suav_plugin.log";
}

inline void installSuavFileLogger() {
    static QFile file(suvLogPath());
    if (!file.isOpen()) {
        file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    }
    static QTextStream out(&file);

    qInstallMessageHandler([](QtMsgType type, const QMessageLogContext&, const QString& msg) {
        const char* t = (type == QtDebugMsg) ? "DEBUG" :
                        (type == QtInfoMsg)  ? "INFO"  :
                        (type == QtWarningMsg)? "WARN" :
                        (type == QtCriticalMsg)? "CRIT" : "FATAL";
        out << QDateTime::currentDateTime().toString(Qt::ISODate)
            << " [" << t << "] " << msg << "\n";
        out.flush();
    });

    qInfo() << "Suav logger installed. Log file:" << suvLogPath();
}

inline void installSuavTerminateHandlers() {
    std::set_terminate([]() {
        qCritical() << "std::terminate called (uncaught exception).";
        try {
            throw;
        } catch (const std::exception& e) {
            qCritical() << "uncaught std::exception:" << e.what();
        } catch (...) {
            qCritical() << "uncaught non-std exception";
        }
        ::abort();
    });

    std::signal(SIGABRT, [](int) { qCritical() << "SIGABRT"; ::abort(); });
    std::signal(SIGSEGV, [](int) { qCritical() << "SIGSEGV"; ::abort(); });
}

inline void installSuavCrashHandlers() {
    std::set_terminate([]() {
        qCritical() << "std::terminate called";
        try {
            throw;
        } catch (const std::exception& e) {
            qCritical() << "uncaught std::exception:" << e.what();
        } catch (...) {
            qCritical() << "uncaught unknown exception";
        }
        ::abort();
    });

    std::signal(SIGSEGV, [](int) {
        qCritical() << "SIGSEGV";
        ::abort();
    });

    std::signal(SIGABRT, [](int) {
        qCritical() << "SIGABRT";
        ::abort();
    });
}
