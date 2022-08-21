/****************************************************************************
**
** This file is part of the KD Chart library.
**
** SPDX-FileCopyrightText: 2001-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
**
** SPDX-License-Identifier: MIT
**
****************************************************************************/

#ifndef KDGANTTPROXYMODEL_P_H
#define KDGANTTPROXYMODEL_P_H

namespace KDGantt {
class ProxyModel::Private
{
public:
    explicit Private(ProxyModel *_q);

    QHash<int, int> columnMap;
    QHash<int, int> roleMap;
    bool calendarMode;
};
}

#endif /* KDGANTTPROXYMODEL_P_H */
