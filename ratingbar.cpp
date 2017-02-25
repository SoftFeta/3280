#include "ratingbar.h"

RatingBar::RatingBar()
{
    setAcceptHoverEvents(true);
    siennaPen.setColor(QColor(0xCB, 0xA1, 0x35)); //Metallic gold
    //    siennaPen.setColor(QColor(0xA0,0x52,0x2D)); //Sienna
    siennaPen.setWidth(2);
    siennaPen.setJoinStyle(Qt::RoundJoin);

    QPainterPath tmpPath;
    tmpPath.moveTo(1.56*9-48, 2.88*9+25);
    tmpPath.lineTo(.2*9-48,1.85*9+25);
    tmpPath.lineTo(1.9*9-48,1.85*9+25);
    tmpPath.lineTo(2.5*9-48,.2*9+25);
    tmpPath.lineTo(3.1*9-48,1.85*9+25);
    tmpPath.lineTo(4.8*9-48,1.85*9+25);
    tmpPath.lineTo(3.44*9-48,2.88*9+25);
    tmpPath.lineTo(3.92*9-48,4.52*9+25);
    tmpPath.lineTo(2.5*9-48,3.54*9+25);
    tmpPath.lineTo(1.12*9-48,4.52*9+25);
    tmpPath.closeSubpath();
    wholeStarPath.addPath(tmpPath);
    tmpPath.translate(48.,0);
    wholeStarPath.addPath(tmpPath);
    tmpPath.translate(48.,0);
    wholeStarPath.addPath(tmpPath);
    tmpPath.translate(48.,0);
    wholeStarPath.addPath(tmpPath);
    tmpPath.translate(48.,0);
    wholeStarPath.addPath(tmpPath);
    ~tmpPath();
    halfStarPath.moveTo(1.56*9-48, 2.88*9+25);
    halfStarPath.lineTo(.2*9-48,1.85*9+25);
    halfStarPath.lineTo(1.9*9-48,1.85*9+25);
    halfStarPath.lineTo(2.5*9-48,.2*9+25);
    halfStarPath.lineTo(2.5*9-48,3.54*9+25);
    halfStarPath.lineTo(1.12*9-48,4.52*9+25);
    halfStarPath.closeSubpath();
    halfStarPath.translate(48.,0);


    //    wholeStarPath.moveTo(1.56*9-48, 2.88*9+25);
    //    wholeStarPath.lineTo(.2*9-48,1.85*9+25);
    //    wholeStarPath.lineTo(1.9*9-48,1.85*9+25);
    //    wholeStarPath.lineTo(2.5*9-48,.2*9+25);
    //    wholeStarPath.lineTo(3.1*9-48,1.85*9+25);
    //    wholeStarPath.lineTo(4.8*9-48,1.85*9+25);
    //    wholeStarPath.lineTo(3.44*9-48,2.88*9+25);
    //    wholeStarPath.lineTo(3.92*9-48,4.52*9+25);
    //    wholeStarPath.lineTo(2.5*9-48,3.54*9+25);
    //    wholeStarPath.lineTo(1.12*9-48,4.52*9+25);
    //    wholeStarPath.closeSubpath();
    //    wholeStarPath.moveTo(1.56*9-3, 2.88*9+25);
    //    wholeStarPath.lineTo(.2*9-3,1.85*9+25);
    //    wholeStarPath.lineTo(1.9*9-3,1.85*9+25);
    //    wholeStarPath.lineTo(2.5*9-3,.2*9+25);
    //    wholeStarPath.lineTo(3.1*9-3,1.85*9+25);
    //    wholeStarPath.lineTo(4.8*9-3,1.85*9+25);
    //    wholeStarPath.lineTo(3.44*9-3,2.88*9+25);
    //    wholeStarPath.lineTo(3.92*9-3,4.52*9+25);
    //    wholeStarPath.lineTo(2.5*9-3,3.54*9+25);
    //    wholeStarPath.lineTo(1.12*9-3,4.52*9+25);
    //    wholeStarPath.closeSubpath();
    //    wholeStarPath.moveTo(1.56*9+42, 2.88*9+25);
    //    wholeStarPath.lineTo(.2*9+42,1.85*9+25);
    //    wholeStarPath.lineTo(1.9*9+42,1.85*9+25);
    //    wholeStarPath.lineTo(2.5*9+42,.2*9+25);
    //    wholeStarPath.lineTo(3.1*9+42,1.85*9+25);
    //    wholeStarPath.lineTo(4.8*9+42,1.85*9+25);
    //    wholeStarPath.lineTo(3.44*9+42,2.88*9+25);
    //    wholeStarPath.lineTo(3.92*9+42,4.52*9+25);
    //    wholeStarPath.lineTo(2.5*9+42,3.54*9+25);
    //    wholeStarPath.lineTo(1.12*9+42,4.52*9+25);
    //    wholeStarPath.closeSubpath();
    //    wholeStarPath.moveTo(1.56*9+87, 2.88*9+25);
    //    wholeStarPath.lineTo(.2*9+87,1.85*9+25);
    //    wholeStarPath.lineTo(1.9*9+87,1.85*9+25);
    //    wholeStarPath.lineTo(2.5*9+87,.2*9+25);
    //    wholeStarPath.lineTo(3.1*9+87,1.85*9+25);
    //    wholeStarPath.lineTo(4.8*9+87,1.85*9+25);
    //    wholeStarPath.lineTo(3.44*9+87,2.88*9+25);
    //    wholeStarPath.lineTo(3.92*9+87,4.52*9+25);
    //    wholeStarPath.lineTo(2.5*9+87,3.54*9+25);
    //    wholeStarPath.lineTo(1.12*9+87,4.52*9+25);
    //    wholeStarPath.closeSubpath();
    //    wholeStarPath.moveTo(1.56*9+132, 2.88*9+25);
    //    wholeStarPath.lineTo(.2*9+132,1.85*9+25);
    //    wholeStarPath.lineTo(1.9*9+132,1.85*9+25);
    //    wholeStarPath.lineTo(2.5*9+132,.2*9+25);
    //    wholeStarPath.lineTo(3.1*9+132,1.85*9+25);
    //    wholeStarPath.lineTo(4.8*9+132,1.85*9+25);
    //    wholeStarPath.lineTo(3.44*9+132,2.88*9+25);
    //    wholeStarPath.lineTo(3.92*9+132,4.52*9+25);
    //    wholeStarPath.lineTo(2.5*9+132,3.54*9+25);
    //    wholeStarPath.lineTo(1.12*9+132,4.52*9+25);
    //    wholeStarPath.closeSubpath();
}

QRectF RatingBar::boundingRect() const
{
    return QRectF(-50, -50, 300, 300);
}

QPainterPath RatingBar::shape() const
{
    QPainterPath path;
    path.addRect(-50, -50, 300, 300);
    return path;
}

void RatingBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) {
    Q_UNUSED(widget);
    painter->setBrush(Qt::lightGray);
    painter->setPen(siennaPen);
    painter->drawPath(wholeStarPath);
    painter->setBrush(Qt::yellow);
    painter->drawPath(halfStarPath);

    //    wholeStarPath.translate(45.,0);
    //    painter->drawPath(wholeStarPath);
    //    wholeStarPath.translate(45.,0);
    //    painter->drawPath(wholeStarPath);
    //    wholeStarPath.translate(45.,0);
    //    painter->drawPath(wholeStarPath);
    //    wholeStarPath.translate(45,0);
    //    painter->drawPath(wholeStarPath);
}

void RatingBar::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
//    qreal x, y;
    if (halfStarPath.contains(QPoint(event->pos().x(), event->pos().y()))) {
        qDebug("%f %f", event->pos().x(), event->pos().y());
    }
}

void RatingBar::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {

}

void RatingBar::mousePressEvent(QGraphicsSceneMouseEvent *event) {

}

void RatingBar::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

}
