﻿#ifndef CATGRAPHICSVIEW_H
#define CATGRAPHICSVIEW_H

#include <QGraphicsView>

class CatGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CatGraphicsView(QWidget *parent = nullptr);
    ~CatGraphicsView();

    void ScaleZoomIn();
    void ScaleZoomOut();
    void Reset();

private:
    void InitProperty();
    void InitConnect();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPointF lastPoint;
    QPointF endPoint;
    bool m_bPress;

};

#endif // CATGRAPHICSVIEW_H
