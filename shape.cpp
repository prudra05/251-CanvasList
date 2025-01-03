
#include "include/shape.h"

#include <sstream>
#include <string>

using namespace std;

Shape::Shape() {
  // TODO_STUDENT
  x = 0;
  y = 0;
}

Shape::Shape(int x, int y) {
  // TODO_STUDENT
  this->x = x;
  this->y = y;
}

Shape::~Shape() {
  // TODO_STUDENT
  // No implementation?
}

Shape* Shape::copy() {
  // TODO_STUDENT
  return new Shape(x, y);
}

int Shape::getX() const {
  // TODO_STUDENT
  return x;
}

int Shape::getY() const {
  // TODO_STUDENT
  return y;
}

void Shape::setX(int x) {
  // TODO_STUDENT
  this->x = x;
}

void Shape::setY(int y) {
  // TODO_STUDENT
  this->y = y;
}

string Shape::as_string() const {
  // TODO_STUDENT
  string shapeStr =
      "It's a Shape at x: " + to_string(x) + "," + " y: " + to_string(y);
  return shapeStr;
}



Circle::Circle() {
  // TODO_STUDENT
  x = 0;
  y = 0;
  radius = 0;
}

Circle::Circle(int r) {
  // TODO_STUDENT
  this->radius = r;
}

Circle::Circle(int x, int y, int r) {
  // TODO_STUDENT
  this->x = x;
  this->y = y;
  this->radius = r;
}

Circle::~Circle() {
  // TODO_STUDENT
  // No implementation?
}

Circle* Circle::copy() {
  // TODO_STUDENT
  return new Circle(x, y, radius);
}

int Circle::getRadius() const {
  // TODO_STUDENT
  return radius;
}

void Circle::setRadius(int r) {
  // TODO_STUDENT
  this->radius = r;
}

string Circle::as_string() const {
  // TODO_STUDENT
  string shapeStr = "It's a Circle at x: " + to_string(x) + "," +
                    " y: " + to_string(y) + "," +
                    " radius: " + to_string(radius);
  return shapeStr;
}



Rect::Rect() {
  // TODO_STUDENT
  width = 0;
  height = 0;
}

Rect::Rect(int w, int h) {
  // TODO_STUDENT
  this->width = w;
  this->height = h;
}

Rect::Rect(int x, int y, int w, int h) {
  // TODO_STUDENT
  this->x = x;
  this->y = y;
  this->width = w;
  this->height = h;
}

Rect::~Rect() {
  // TODO_STUDENT
  // No implementation?
}

Rect* Rect::copy() {
  // TODO_STUDENT
  return new Rect(x, y, width, height);
}

int Rect::getWidth() const {
  // TODO_STUDENT
  return width;
}

int Rect::getHeight() const {
  // TODO_STUDENT
  return height;
}

void Rect::setWidth(int w) {
  // TODO_STUDENT
  this->width = w;
}

void Rect::setHeight(int h) {
  // TODO_STUDENT
  this->height = h;
}

string Rect::as_string() const {
  // TODO_STUDENT
  string shapeStr = "It's a Rectangle at x: " + to_string(x) + "," +
                    " y: " + to_string(y) + " with width: " + to_string(width) +
                    " and height: " + to_string(height);
  return shapeStr;
}



RightTriangle::RightTriangle() {
  // TODO_STUDENT
  x = 0;
  y = 0;
  base = 0;
  height = 0;
}

RightTriangle::RightTriangle(int b, int h) {
  // TODO_STUDENT
  this->base = b;
  this->height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h) {
  this->x = x;
  this->y = y;
  this->base = b;
  this->height = h;
}

RightTriangle::~RightTriangle() {
  // TODO_STUDENT
  // No implementation?
}

RightTriangle* RightTriangle::copy() {
  // TODO_STUDENT
  return new RightTriangle(x, y, base, height);
}

int RightTriangle::getHeight() const {
  // TODO_STUDENT
  return height;
}

int RightTriangle::getBase() const {
  // TODO_STUDENT
  return base;
}

void RightTriangle::setHeight(int h) {
  // TODO_STUDENT
  this->height = h;  //?
}

void RightTriangle::setBase(int b) {
  // TODO_STUDENT
  this->base = b;  //?
}

string RightTriangle::as_string() const {
  // TODO_STUDENT
  string shapeStr = "It's a Right Triangle at x: " + to_string(x) + "," +
                    " y: " + to_string(y) + " with base: " + to_string(base) +
                    " and height: " + to_string(height);
  return shapeStr;
}
