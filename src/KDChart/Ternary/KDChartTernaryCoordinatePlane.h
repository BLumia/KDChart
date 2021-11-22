/****************************************************************************
**
** This file is part of the KD Chart library.
**
** SPDX-FileCopyrightText: 2001-2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
**
** SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDAB-KDChart OR LicenseRef-KDAB-KDChart-US
**
** Licensees holding valid commercial KD Chart licenses may use this file in
** accordance with the KD Chart Commercial License Agreement provided with
** the Software.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
****************************************************************************/

#ifndef KDCHARTTERNARYCOORDINATEPLANE_H
#define KDCHARTTERNARYCOORDINATEPLANE_H

#include "KDChartAbstractCoordinatePlane.h"

namespace KDChart {

class TernaryGrid;

/**
      * @brief Ternary coordinate plane
      */
class KDCHART_EXPORT TernaryCoordinatePlane
    : public AbstractCoordinatePlane
{
    Q_OBJECT
    Q_DISABLE_COPY(TernaryCoordinatePlane)
    KDCHART_DECLARE_PRIVATE_DERIVED_PARENT(TernaryCoordinatePlane, Chart *)

public:
    explicit TernaryCoordinatePlane(Chart *parent = nullptr);
    ~TernaryCoordinatePlane() override;

    void addDiagram(AbstractDiagram *diagram) override;

    void layoutDiagrams() override;

    const QPointF translate(const QPointF &diagramPoint) const override;

    void paint(QPainter *) override;
    DataDimensionsList getDataDimensionsList() const override;

    /** \reimp */
    QSize minimumSizeHint() const;
    /** \reimp */
    QSizePolicy sizePolicy() const;

private:
    TernaryGrid *grid() const;
};
}

#endif
