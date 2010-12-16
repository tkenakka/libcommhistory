/******************************************************************************
**
** This file is part of libcommhistory.
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Alexander Shalamov <alexander.shalamov@nokia.com>
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of the GNU Lesser General Public License version 2.1 as
** published by the Free Software Foundation.
**
** This library is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
** or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
** License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with this library; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
**
******************************************************************************/

#ifndef COMMHISTORY_CONTACTLISTENER_H
#define COMMHISTORY_CONTACTLISTENER_H

// QT includes
#include <QObject>
#include <QString>
#include <QList>
#include <QTimer>
#include <QPointer>

// contacts
#include <qcontact.h>

QTM_USE_NAMESPACE

QTM_BEGIN_NAMESPACE
class QContactManager;
class QContactFetchRequest;
QTM_END_NAMESPACE

namespace CommHistory {

class ContactListener : public QObject
{
    Q_OBJECT

public:
    /*!
     *  \returns Contact listener
     */
    static QSharedPointer<ContactListener> instance();

    ~ContactListener();

Q_SIGNALS:
    void contactUpdated(quint32 localId,
                        const QString &contactName,
                        const QStringList &contactAddresses);
    void contactRemoved(quint32 localId);

private Q_SLOTS:
    void slotContactsUpdated(const QList<QContactLocalId> &contactIds);
    void slotContactsRemoved(const QList<QContactLocalId> &contactIds);
    void slotStartContactRequest();
    void slotResultsAvailable();

private:
    ContactListener(QObject *parent = 0);

    void init();
    QContactFetchRequest *buildRequest(const QList<QContactLocalId> &contactIds);

private:
    static QWeakPointer<ContactListener> m_Instance;
    bool m_Initialized;
    QTimer m_ContactTimer;
    QPointer<QContactManager> m_ContactManager;
    QList<QContactLocalId> m_PendingContactIds;
    QList<QContactFetchRequest *> m_ContactRequests;
};

}

#endif
