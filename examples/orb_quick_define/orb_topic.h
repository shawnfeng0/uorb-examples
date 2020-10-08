//
// Created by fs on 10/9/20.
//

#ifndef UORB_EXAMPLES_EXAMPLES_ORB_QUICK_DEFINE_ORB_TOPIC_H_
#define UORB_EXAMPLES_EXAMPLES_ORB_QUICK_DEFINE_ORB_TOPIC_H_

#include "uorb/uorb.h"

struct orb_example_struct_str {
  char str[30];
  int32_t index;
};

ORB_DECLARE(example_struct_str, orb_example_struct_str);

struct orb_example_struct_number {
  int16_t num_int16;
  int32_t num_int32;
  int64_t num_int64;
};

ORB_DECLARE(example_struct_number, orb_example_struct_number);

#endif  // UORB_EXAMPLES_EXAMPLES_ORB_QUICK_DEFINE_ORB_TOPIC_H_
