/***************************************************************************
 *   Copyright (C) 2005 by Grup de Gràfics de Girona                       *
 *   http://iiia.udg.es/GGG/index.html?langu=uk                            *
 *                                                                         *
 *   Universitat de Girona                                                 *
 ***************************************************************************/
#include "qquerystudythread.h"

#include "pacsconnection.h"
#include "pacsserver.h"
#include "querypacs.h"
#include "status.h"
#include "logging.h"
#include "patient.h"
#include "study.h"
#include "series.h"
#include "image.h"

#include <QString>

namespace udg {

QQueryStudyThread::QQueryStudyThread(QObject *parent)
 : QThread(parent)
{
}

void QQueryStudyThread::queryStudy( PacsParameters param , DicomMask mask )
{
    m_param = param;
    m_mask = mask;

    start();
}

void QQueryStudyThread::run()
{
    Status state;
    QString missatgeLog;
    //creem la connexió
    PacsServer serverSCP(m_param);

    INFO_LOG( "Thread iniciat per cercar al PACS: AELocal= " + m_param.getAELocal() + "; AEPACS= " + m_param.getAEPacs() + "; PACS Adr= " + m_param.getPacsAddress() + "; PACS Port= " + m_param.getPacsPort() + ";" );

    state = serverSCP.connect( PacsServer::query,PacsServer::studyLevel );

    if ( !state.good() )
    {
        ERROR_LOG( QString("Error al connectar al PACS %1. PACS ERROR: %2").arg( m_param.getAEPacs() ).arg( state.text() ) );
        emit( errorConnectingPacs( m_param.getPacsID() ) );
        exit(1);
    }
    else
    {
        //creem l'objecte fer la query
        QueryPacs queryPacsStudy;

        queryPacsStudy.setConnection(m_param.getPacsID(), serverSCP.getConnection());
        //busquem els estudis
        state = queryPacsStudy.query( m_mask );

        if (! state.good() )
        {
            ERROR_LOG( QString("Error al connectar al PACS %1. PACS ERROR: %2").arg( m_param.getAEPacs() ).arg( state.text() ) );
            emit( errorQueringStudiesPacs( m_param.getPacsID() ) );
        }
        else 
        {
            m_patientStudyList = queryPacsStudy.getQueryResultsAsPatientStudyList();
            m_seriesList = queryPacsStudy.getQueryResultsAsSeriesList();
            m_imageList = queryPacsStudy.getQueryResultsAsImageList();
            m_hashPacsIDOfStudyInstanceUID = queryPacsStudy.getHashTablePacsIDOfStudyInstanceUID();
        }

        INFO_LOG ( QString("Thread del PACS %1 finalitzant").arg( m_param.getAEPacs() ) );

        //desconnectem
        serverSCP.disconnect();
        exit( 0 );
    }
}

QList<Patient*> QQueryStudyThread::getPatientStudyList()
{
    return m_patientStudyList;
}

QList<Series*> QQueryStudyThread::getSeriesList()
{
    return m_seriesList;
}

QList<Image*> QQueryStudyThread::getImageList()
{
    return m_imageList;
}

QHash<QString,QString> QQueryStudyThread::getHashTablePacsIDOfStudyInstanceUID()
{
    return m_hashPacsIDOfStudyInstanceUID;
}

QQueryStudyThread::~QQueryStudyThread()
{
}

}
