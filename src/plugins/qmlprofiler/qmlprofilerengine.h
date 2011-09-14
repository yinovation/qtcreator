/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (info@qt.nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at info@qt.nokia.com.
**
**************************************************************************/

#ifndef QMLPROFILERENGINE_H
#define QMLPROFILERENGINE_H

#include <analyzerbase/ianalyzerengine.h>
#include <utils/outputformat.h>

namespace QmlProfiler {
namespace Internal {

class QmlProfilerEngine : public Analyzer::IAnalyzerEngine
{
    Q_OBJECT

public:
    QmlProfilerEngine(Analyzer::IAnalyzerTool *tool,
                      const Analyzer::AnalyzerStartParameters &sp,
                      ProjectExplorer::RunConfiguration *runConfiguration);
    ~QmlProfilerEngine();

    static void showNonmodalWarning(const QString &warningMsg);
signals:
    void processRunning(int port);
    void stopRecording();

public slots:
    bool start();
    void stop();

private slots:
    void stopped();

    void setFetchingData(bool);
    void dataReceived();
    void finishProcess();
    void logApplicationMessage(const QString &msg, Utils::OutputFormat format);
    void filterApplicationMessage(const QString &msg);
    void wrongSetupMessageBoxFinished(int);
    void processIsRunning();

private:
    class QmlProfilerEnginePrivate;
    QmlProfilerEnginePrivate *d;
};

} // namespace Internal
} // namespace QmlProfiler

#endif // QMLPROFILERENGINE_H
