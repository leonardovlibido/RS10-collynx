#ifndef LINES_H
#define LINES_H

#include <QVector>
#include <QPolygon>
#include <QPoint>
#include <QDebug>
#include <QPen>
#include <QPainter>

class Drawable
{
public:
    void drawOn(QPainter & screen) const;
    enum Shape {
        line, ellipse, rectangle
    };
    QPolygon poly;
    QPen pen; 
};

class Lines
{
public:
    Lines();
    void drawAll(QPainter & screen) const;
    QVector<Drawable>& getLines();
    QPolygon& addPoint(QPoint newPoint);
    QPolygon& newLine();
    QPolygon& newLine(QPen newPen);
    QPolygon& newLine(QPen newPen, int brushSize);
    void setPen(QPen newPen);
    void setPen(int color, int brushSize);
    void setPenColor(const int color);
    void setPenWidth(const int brushSize);

    void undo();
private:
    QVector<Drawable> lines;
};

#endif // LINES_H
