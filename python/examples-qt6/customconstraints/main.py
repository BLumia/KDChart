#!/usr/bin/env python

##
## This file is part of the KD Chart library.
##
## SPDX-FileCopyrightText: 2019-2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
##
## SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDAB-KDChart OR LicenseRef-KDAB-KDChart-US
##
## Licensees holding valid commercial KD Chart licenses may use this file in
## accordance with the KD Chart Commercial License Agreement provided with
## the Software.
##
## Contact info@kdab.com if any conditions of this licensing are not
## clear to you.
##

import sys
import random

from PySide6.QtCore import Qt, QDateTime
from PySide6.QtGui import QStandardItem, QPen, QColor, QStandardItemModel
from PySide6.QtWidgets import QApplication, QWidget, QSlider, QVBoxLayout
from PyKDChartQt6.KDGantt import View, GraphicsView, ConstraintModel, DateTimeGrid
from PyKDChartQt6 import KDGantt

class MyGraphicsView(GraphicsView):
    def __init__(self, parent = None):
        super(MyGraphicsView, self).__init__(parent)

    def addConstraint(self, from_, to, modifiers):
        print("MyGraphicsView::addConstraint()")
        if self.isReadOnly():
            return

        cmodel = self.constraintModel()
        constraintType = None
        if modifiers & Qt.ShiftModifier:
            constraintType = Constraint.TypeHard
        else:
            constraintType = Constraint.TypeSoft

        c = Constraint(from_, to_, constraintType)
        c.setData(Constraint.ValidConstraintPen, QPen(QColor(Qt.green), 3, Qt.DashLine))
        c.setData(Constraint.InvalidConstraintPen, QPen(QColor(Qt.blue), 3, Qt.DashLine))
        if cmodel.hasConstraint(c):
            cmodel.removeConstraint(c)
        else:
            cmodel.addConstraint(c)

class MyStandardItem(QStandardItem):
    def __init__(self, v, role = Qt.DisplayRole):
        super(MyStandardItem, self).__init__()
        self.setData(v, role)

class MyWidget(QWidget):
    def __init__(self, parent = None):
        super(MyWidget, self).__init__(parent)

        self.view = View()
        self.grid = DateTimeGrid()
        self.model = QStandardItemModel()
        self.slider = QSlider()
        self.view.setGraphicsView(MyGraphicsView())

        ## proxyModel.setSourceModel( &model );
        for h in range(0, 2):
            self.model.appendRow([MyStandardItem("Item " + str(h)),
                                  MyStandardItem(KDGantt.TypeTask),
                                  MyStandardItem(QDateTime.currentDateTime().addDays(h), KDGantt.StartTimeRole),
                                  MyStandardItem(QDateTime.currentDateTime().addDays(h + 1), KDGantt.EndTimeRole),
                                  MyStandardItem(50)])

        self.slider.setOrientation(Qt.Horizontal)
        self.slider.setRange(1, 10000)
        self.slider.setValue(100)
        l = QVBoxLayout(self)
        l.addWidget(self.view)
        l.addWidget(self.slider)
        self.grid.setStartDateTime(QDateTime.currentDateTime().addDays(-3))
        self.grid.setDayWidth(100)
        ## grid.setNoInformationBrush( Qt::NoBrush );
        self.view.setGrid(self.grid)
        self.view.setModel(self.model)

        self.slider.valueChanged.connect(self.slotZoom)

    def slotZoom(self, z):
        self.grid.setDayWidth(z)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ## QPixmapCache::setCacheLimit( 30*1024 );

    w = MyWidget()
    w.show()

    sys.exit(app.exec_())

