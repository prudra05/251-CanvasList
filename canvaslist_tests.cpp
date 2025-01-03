#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "canvaslist.h"
#include "include/shape.h"

using namespace std;
using namespace testing;

TEST(FakeTest, PleaseDeleteOnceYouWriteSome) {
  // If no tests exist, GoogleTest fails to compile with a fairly confusing
  // message. We have this empty test that does nothing to allow an empty
  // autograder submission to compile and regularly fail. Once you write your
  // own tests for the project, you can delete this one.
  EXPECT_THAT(1, Eq(1));
}

TEST(CanvasListCore, ConstTest) {
  CanvasList list;

  EXPECT_THAT(0, Eq(list.size()));
  EXPECT_THAT(list.front(), Eq(nullptr));
  list.clear();
}

TEST(CanvasListCore, FrontTest) {
  CanvasList list;

  Shape* shape1 = new Shape;
  list.push_front(shape1);

  EXPECT_THAT(list.front()->value, Eq(shape1));
  list.clear();
}

TEST(CanvasListCore, SizeTest) {
  CanvasList list;

  EXPECT_THAT(0, Eq(list.size()));

  CanvasList list2;
  Shape* shape1 = new Shape;
  list2.push_front(shape1);

  EXPECT_THAT(list2.size(), Eq(1));
  list.clear();
}

TEST(CanvasListCore, EmptyTest) {
  CanvasList list;
  EXPECT_THAT(true, Eq(list.empty()));

  CanvasList list2;
  Shape* shape1 = new Shape;
  list2.push_front(shape1);

  EXPECT_THAT(list2.empty(), Eq(false));
  list.clear();
}

TEST(CanvasListCore, CleanTest) {
  CanvasList list;
  EXPECT_THAT(0, Eq(list.size()));

  CanvasList list2;
  Shape* shape1 = new Shape;
  list2.push_front(shape1);
  list2.clear();

  EXPECT_THAT(list.size(), Eq(0));
  list.clear();
}

TEST(CanvasListCore, PushFrontTest) {
  CanvasList list2;
  Shape* shape1 = new Shape;
  Shape* shape2 = new Shape;

  list2.push_front(shape1);
  list2.push_front(shape2);

  EXPECT_THAT(2, Eq(list2.size()));
  EXPECT_THAT(list2.front()->value, Eq(shape2));
  list2.clear();
}

TEST(CanvasListCORE, DestructorTest) {
  CanvasList* list = new CanvasList();
  delete list;

  EXPECT_THAT(list->size(), Eq(0));
}


TEST(CanvasListIterating, ShapeTest) {
  CanvasList list2;
  Shape* shape1 = new Shape;
  Shape* shape2 = new Shape;

  list2.push_back(shape1);
  list2.push_back(shape2);
  EXPECT_THAT(shape2, Eq(list2.shape_at(1)));
  list2.clear();
}

TEST(CanvasListIterating, FindTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6);

  list.push_back(shape1);
  list.push_back(shape2);

  EXPECT_THAT(0, Eq(list.find(5, 4)));
  EXPECT_THAT(1, Eq(list.find(7, 6)));
  EXPECT_THAT(-1, Eq(list.find(8, 9)));
  list.clear();
}

TEST(CanvasListIterating, CopyTest) {
  CanvasList list;
  Shape* Rect1 = new Rect(5, 4);
  Circle* circle2 = new Circle(4);

  list.push_back(Rect1);
  list.push_back(circle2);

  CanvasList copyList(list);
  

  EXPECT_THAT(list.size(), Eq(copyList.size()));
  //EXPECT_THAT(list.front()->value, Ne(copyList.front()->value));
  EXPECT_THAT(list.front(), Ne(copyList.front()));
  EXPECT_THAT(list.find(8, 9), Eq(copyList.find(8, 9)));
  //EXPECT_THAT(list.shape_at(0), Ne(copyList.shape_at(0)));

  //Check copy_no_use_shape_copy
 
  EXPECT_THAT(copyList.shape_at(0)->as_string(), Eq(list.shape_at(0)->as_string()));

  list.clear();
  copyList.clear();
}


TEST(CanvasListModifying, EqualsTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6);
  Shape* shape3 = new Shape();
  
  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);
  
  CanvasList list2;
  Rect* rect1 = new Rect(5, 4);
  RightTriangle* triangle2 = new RightTriangle(7, 6);
  Circle* circle3 = new Circle();

  list2.push_back(rect1);
  list2.push_back(triangle2);
  list2.push_back(circle3);
  list = list2; //regular check //copying shapes correctly

  EXPECT_THAT(list.size(), Eq(list2.size())); 
  EXPECT_THAT(list.shape_at(1)->as_string(), Eq(list2.shape_at(1)->as_string()));

  CanvasList list3;
  list = list3;

  EXPECT_THAT(list.size(), Eq(0)); // list is empty after pop
  //EXPECT_THAT(list.shape_at(2), Eq(nullptr)); // Alters size

  list.clear();
  list2.clear();
  list3.clear();
  
}

TEST(CanvasListModifying, PopFrontTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6);
  Shape* shape3 = new Shape();

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);

  Shape* pop = list.pop_front();

  CanvasList list2;
  Shape* pop2 = list2.pop_front(); //null;

  CanvasList list3;
  Shape* shape4 = new Shape(1, 1);
  list3.push_back(shape4);
  Shape* pop3 = list3.pop_front();

  EXPECT_THAT(list3.size(), Eq(0)); // list is empty after pop
  EXPECT_THAT(list.front()->value, Eq(shape2));
  EXPECT_THAT(list.size(), Eq(2)); // Alters size
  EXPECT_THAT(list2.size(), Eq(0)); // list is empty

  // Edge case: pop front from a list with one element
  delete pop;
  delete pop2;
  delete pop3;

  list.clear();
  list2.clear();
  list3.clear();

}

TEST(CanvasListModifying, PopBackTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6);
  Shape* shape3 = new Shape();

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);

  Shape* pop = list.pop_back();

  CanvasList list2;
  Rect* rect1 = new Rect(5, 4);

  list2.push_back(rect1);

  Shape* pop2 = list2.pop_back();

  CanvasList list3;
  Shape* pop3 = list3.pop_back(); //null

  EXPECT_THAT(list.shape_at(2), Eq(nullptr)); //regular check (PROBLEM)
  EXPECT_THAT(list.size(), Eq(2)); //doesn't alter size (PROBLEM)

  EXPECT_THAT(list2.size(), Eq(0)); //list has one element
  EXPECT_THAT(pop2, Eq(rect1)); //---> problem

  EXPECT_THAT(list3.size(), Eq(0)); //list is empty
  EXPECT_THAT(pop3, Eq(nullptr)); //----> problem

  delete pop;
  delete pop2;

  list.clear();
  list2.clear();
  list3.clear();
}

TEST(CanvasListModifying, RemoveAtTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6);
  Shape* shape3 = new Shape();
  Shape* shape4 = new Shape();

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);
  list.push_back(shape4);

  list.remove_at(2);

  EXPECT_THAT(list.shape_at(2), Eq(shape4));
  EXPECT_THAT(list.size(), Eq(3));
  EXPECT_THAT(list.shape_at(0), Eq(shape1));
  list.clear();

  CanvasList list2;

  list2.remove_at(2);

  EXPECT_THAT(list2.size(), Eq(0));
  EXPECT_THAT(list2.shape_at(2), Eq(nullptr));
  list2.clear();

  CanvasList list3;
  RightTriangle* triangle1 = new RightTriangle(5, 4);

  list3.push_back(triangle1);

  list3.remove_at(0);

  EXPECT_THAT(list3.size(), Eq(0));

  list3.clear();
  //delete triangle1; //Why is this necessary
  
  CanvasList list4;
  list4.remove_at(0);
  EXPECT_THAT(list4.size(), Eq(0));
  list4.clear();

}


TEST(CanvasListExtras, InsertAfterTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6);
  Shape* shape3 = new Shape();
  Shape* shape4 = new Shape();

  Shape* shape5 = new Shape(3, 2);

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);
  list.push_back(shape4);

  list.insert_after(2, shape5);
  EXPECT_THAT(list.size(), Eq(5));
  EXPECT_THAT(list.shape_at(3)->as_string(), Eq(shape5->as_string()));

  CanvasList list2;
  Rect* rect1 = new Rect(5, 4);
  RightTriangle* triangle2 = new RightTriangle(7, 6);
  Circle* circle3 = new Circle();

  Shape* shape6 = new Shape(1, 9);

  list2.push_back(rect1);
  list2.push_back(triangle2);
  list2.push_back(circle3);

  list2.insert_after(0, shape6);
  EXPECT_THAT(list2.size(), Eq(4));
  EXPECT_THAT(list2.shape_at(1)->as_string(), Eq(shape6->as_string()));

  list.clear();
  list2.clear();
}

TEST(CanvasListExtras, RemoveEveryOtherTest) {
  CanvasList list;
  Shape* shape1 = new Shape(5, 4);
  Shape* shape2 = new Shape(7, 6); //remove //leak
  Shape* shape3 = new Shape();
  Shape* shape4 = new Shape(); //remove //leak

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);
  list.push_back(shape4);

  list.remove_every_other();
  EXPECT_THAT(list.size(), Eq(2));
  //EXPECT_THAT(list.front()->value, Eq(shape1));
  EXPECT_THAT(list.shape_at(1)->as_string(), Eq(shape3->as_string()));
  list.clear();

  //delete(shape2); //does not work on gradescope
  //delete(shape4); //does not work on gradescope

  CanvasList list2;

  list2.remove_every_other();

  EXPECT_THAT(list2.size(), Eq(0));
  list2.clear();

  CanvasList list3;

  Shape* rect1 = new Rect(5, 4);
  list3.push_back(rect1); //do not remove should return the one shape

  list3.remove_every_other();

  EXPECT_THAT(list3.size(), Eq(1));
  //EXPECT_THAT(list3.front()->value, Eq(rect1));

  list3.clear();
}
// TODO_STUDENT