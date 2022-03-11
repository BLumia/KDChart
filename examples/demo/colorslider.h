/****************************************************************************
**
** This file is part of the KD Chart library.
**
** SPDX-FileCopyrightText: 2001-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
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

#ifndef COLORSLIDER_H
#define COLORSLIDER_H

#include <QAbstractSlider>

class ColorSlider : public QAbstractSlider
{
    Q_OBJECT
    Q_PROPERTY(QColor startColor READ startColor WRITE setStartColor NOTIFY startColorChanged)
    Q_PROPERTY(QColor endColor READ endColor WRITE setStartColor NOTIFY endColorChanged)
public:
    explicit ColorSlider(QWidget *parent = nullptr);
    ~ColorSlider() override;
    QColor startColor() const;
    void setStartColor(const QColor &color);
    QColor endColor() const;
    void setEndColor(const QColor &color);
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

Q_SIGNALS:
    void startColorChanged();
    void endColorChanged();

public Q_SLOTS:
private:
    class Private;
    Private *d;
};

#endif // COLORSLIDER_H
