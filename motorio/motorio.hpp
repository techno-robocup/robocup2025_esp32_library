#pragma once
#ifndef __ROBOT__MOTORIO__HPP
#define __ROBOT__MOTORIO__HPP 1
#include <Arduino.h>
class MOTORIO {
 public:
  MOTORIO();
  MOTORIO(const std::int8_t&, const int&);
  MOTORIO& operator=(const MOTORIO&) = default;
  void run_msec(const int&);

 private:
  std::int8_t PIN;
  long long prev_msec;
  int interval;
};
#endif
