/******************************************************************************
  Copyright 2014 Tom Cornall

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.  
 ******************************************************************************/
#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QBasicTimer>
#include <QDebug>
#include <QLabel>
#include <QStatusBar>
#include "DiagInterface.h"

class StatusBar: public QStatusBar
{
    Q_OBJECT

    public:
        StatusBar(DiagInterface &diag, QWidget *parent = NULL);

    protected:
        virtual void timerEvent(QTimerEvent *);

    private:
        DiagInterface &diag;
        QBasicTimer pollTimer;
        QLabel *firmwareVersionLabel;
        QLabel *controllerTypeLabel;
        QLabel *matrixSizeLabel;
        QLabel *nkroStateLabel;

        void updateStatus(void);
        void updateVersion(void);
};

#endif
