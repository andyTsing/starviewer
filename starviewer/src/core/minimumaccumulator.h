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

#ifndef UDGMINIMUMACCUMULATOR_H
#define UDGMINIMUMACCUMULATOR_H

#include "accumulator.h"

#include <QtGlobal>

namespace udg {

template <class T> class MinimumAccumulator : public Accumulator<T> {
public:
    MinimumAccumulator() : Accumulator<T>() {}
    virtual ~MinimumAccumulator() {}

    inline virtual void initialize()
    {
        m_first = true;
    }
    inline virtual void accumulate(T input)
    {
        if (m_first)
        {
            m_minimum = input;
            m_first = false;
            return;
        }
        m_minimum = qMin(m_minimum, input);
    }
    inline virtual T getValue() const
    {
        return m_minimum;
    }

private:
    T m_minimum;
    bool m_first;
};

}

#endif
