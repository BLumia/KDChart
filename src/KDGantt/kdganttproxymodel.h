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

#ifndef KDGANTTPROXYMODEL_H
#define KDGANTTPROXYMODEL_H

#include "kdganttforwardingproxymodel.h"

namespace KDGantt {
class KDGANTT_EXPORT ProxyModel : public ForwardingProxyModel
{
    Q_OBJECT
    Q_DISABLE_COPY(ProxyModel)
    KDGANTT_DECLARE_PRIVATE_BASE_POLYMORPHIC(ProxyModel)
public:
    explicit ProxyModel(QObject *parent = nullptr);
    ~ProxyModel() override;

    void setColumn(int ganttrole, int col);
    void setRole(int ganttrole, int role);

    int column(int ganttrole) const;
    int role(int ganttrole) const;

#if 0
        void setCalendarMode( bool enable );
        bool calendarMode() const;
#endif

    /*reimp*/ QModelIndex mapFromSource(const QModelIndex &idx) const override;
    /*reimp*/ QModelIndex mapToSource(const QModelIndex &proxyIdx) const override;

    /*reimp*/ int rowCount(const QModelIndex &idx) const override;
    /*reimp*/ int columnCount(const QModelIndex &idx) const override;

    /*reimp*/ QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;
    /*reimp*/ bool setData(const QModelIndex &idx, const QVariant &value, int role = Qt::EditRole) override;
};
}

#endif /* KDGANTTPROXYMODEL_H */
