#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "decepticon/decepticon.hpp"

using namespace cv;
int sideOfLeastResistance(Decepticon d) { 
  int leftDist = 0, rightDist = 0;
  d.turn_left();
  leftDist = d.get_sonar();
  d.turn_right();
  d.turn_right();
  rightDist = d.get_sonar();
  d.turn_left();
  if(leftDist > 5 || rightDist > 5) {
    if(leftDist > rightDist) {
      d.turn_left();
    } else {
      d.turn_right();
    }
  } else {
    d.turn_right();
    d.turn_right();
  }
  return 0;
}

int main() {
  Decepticon d;
  
  std::cout << "Hello world!\n";
  int i = 0;
  while(i < 5) {
    while(d.get_sonar() >= 5) {
      d.forward();
    }
    sideOfLeastResistance(d);
    i++;
  }
  //////////////////////////
  // PLACE YOUR CODE HERE //
  //////////////////////////
  
  return 0;
}
