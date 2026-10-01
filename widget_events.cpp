// widget_events.cpp
#include "widget_events.hpp"

#include <QEvent>
#include <QMetaEnum>
#include <iostream>

WidgetEvent::WidgetEvent(QWidget *parent) : QWidget(parent) {}

static const char *eventName(QEvent::Type type) {
  static const QMetaEnum me = QEvent::staticMetaObject.enumerator(
      QEvent::staticMetaObject.indexOfEnumerator("Type"));
  const char *name = me.valueToKey(type);
  return name ? name : "Unknown";
}

bool WidgetEvent::event(QEvent *e) {
  std::cout << "QEvent::" << eventName(e->type()) << " (" << e->type() << ")"
            << std::endl;
  return true;
}
