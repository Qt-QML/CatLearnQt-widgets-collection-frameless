﻿#include "ListingOptions.h"
#include <QFile>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>

ListiongOptions::ListiongOptions(QWidget *parent) : QWidget(parent)
{
    InitUi();

    InitProperty();
}

ListiongOptions::~ListiongOptions()
{

}

void ListiongOptions::AddButton(QPushButton *button, int id)
{
    m_pButtonListsLayout->addWidget(button);
    button->setCheckable(true);
    m_pButtonGroup->addButton(button, id);
    //button->setChecked(true);
}

void ListiongOptions::AddButtonNoGroup(QPushButton *button)
{
    m_pButtonListsLayout->addWidget(button);
}

void ListiongOptions::AddItem(QSpacerItem *item)
{
    m_pButtonListsLayout->addItem(item);
}

QWidget *ListiongOptions::GetRootWidget() const
{
    return m_pButtonLists;
}

QButtonGroup *ListiongOptions::GetButtonGroup() const
{
    return m_pButtonGroup;
}

void ListiongOptions::Clear()
{
    for(auto button : m_lButtonList)
    {
        m_pButtonListsLayout->removeWidget(button);
        m_pButtonGroup->removeButton(button);
    }
    for(auto item : m_lItemList)
    {
        m_pButtonListsLayout->removeItem(item);
    }
}

void ListiongOptions::InitUi()
{
    m_pRootLayout = new QVBoxLayout(this);
    m_pRootLayout->setContentsMargins(0,0,0,0);
    m_pRootLayout->setSpacing(0);

    m_pRootWidget = new QWidget(this);
    m_pRootWidget->setObjectName("ListiongOptionsRootWidget");
    m_pRootLayout->addWidget(m_pRootWidget);

    m_pRootWidgetLayout = new QVBoxLayout(m_pRootWidget);
    m_pRootWidgetLayout->setContentsMargins(0,0,0,0);
    m_pRootWidgetLayout->setSpacing(0);
    m_pScrollArea = new QScrollArea(m_pRootWidget);
    m_pScrollArea->setObjectName("ListingOptionsScroll");
    m_pScrollArea->setWidgetResizable(true);
    m_pScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_pRootWidgetLayout->addWidget(m_pScrollArea);

    m_pButtonLists = new QWidget();
    m_pButtonLists->setObjectName(QString::fromUtf8("ButtonLists"));
    m_pScrollArea->setWidget(m_pButtonLists);

    m_pButtonListsLayout = new QVBoxLayout(m_pButtonLists);
    m_pButtonListsLayout->setContentsMargins(0,0,0,0);
    m_pButtonListsLayout->setSpacing(0);


    m_pButtonGroup = new QButtonGroup(m_pButtonLists);
    m_pButtonGroup->setExclusive(true);
}

void ListiongOptions::InitProperty()
{
    m_lButtonList.clear();
    QFile resourceqss(":/qss/CatGray/ListingOptions.css");
    resourceqss.open(QFile::ReadOnly);
    this->setStyleSheet(resourceqss.readAll());
    resourceqss.close();
}

void ListiongOptions::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
}