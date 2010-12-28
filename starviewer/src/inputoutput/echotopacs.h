/***************************************************************************
 *   Copyright (C) 2005-2007 by Grup de Gr�fics de Girona                  *
 *   http://iiia.udg.es/GGG/index.html?langu=uk                            *
 *                                                                         *
 *   Universitat de Girona                                                 *
 ***************************************************************************/

#ifndef UDGECHOTOPACS_H
#define UDGECHOTOPACS_H


namespace udg {

/** Classe que s'encarrega de fer un echoSCU a un PACS */

class PacsDevice;

class EchoToPACS
{
public:

    enum EchoRequestStatus {EchoOk, EchoCanNotConnectToPACS, EchoFailed};

    EchoToPACS();

    ///Fa un echo al PACS passat per par�metre
    bool echo(PacsDevice pacsDevice);

    ///Retorna l'estat de l'�ltim echo fet a un PACS
    EchoToPACS::EchoRequestStatus getLastError();

private:

    EchoToPACS::EchoRequestStatus m_lastError;

};

}

#endif