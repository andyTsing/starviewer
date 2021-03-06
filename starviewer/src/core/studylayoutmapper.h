/*************************************************************************************
  Copyright (C) 2014 Laboratori de Gràfics i Imatge, Universitat de Girona &
  Institut de Diagnòstic per la Imatge.
  Girona 2014. All rights reserved.
  http://starviewer.udg.edu

  This file is part of the Starviewer (Medical Imaging Software) open source project.
  It is subject to the license terms in the LICENSE file found in the top-level
  directory of this distribution and at http://starviewer.udg.edu/license. No part of
  the Starviewer (Medical Imaging Software) open source project, including this file,
  may be copied, modified, propagated, or distributed except according to the
  terms contained in the LICENSE file.
 *************************************************************************************/

#ifndef UDGSTUDYLAYOUTMAPPER_H
#define UDGSTUDYLAYOUTMAPPER_H

#include <QList>
#include <QPair>

#include "studylayoutconfig.h"

namespace udg {

class ViewersLayout;
class Patient;
class Volume;
class Study;

class StudyLayoutMapper {
public:
    StudyLayoutMapper();
    ~StudyLayoutMapper();

    /// Aplica la configuració sobre el layout amb els estudis del pacient donats
    void applyConfig(const StudyLayoutConfig &config, ViewersLayout *layout, Patient *patient);

private:
    /// Ens retorna la llista de volums amb la corresponent imatge que hem de col·locar segons la configuració i els estudis obtinguts a getMatchingStudies()
    QList<QPair<Volume*, int> > getImagesToPlace(const StudyLayoutConfig &config, const QList<Study*> &matchingStudies);
    
    /// Donada una llista de volums amb la corresponent llesca, els col·loca al layout segons la configuració donada
    void placeImagesInCurrentLayout(const QList<QPair<Volume*, int> > &volumesToPlace, StudyLayoutConfig::UnfoldDirectionType unfoldDirection,
                                    ViewersLayout *layout, int rows, int columns);
};

} // End namespace udg

#endif
