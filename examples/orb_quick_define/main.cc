//
// Created by fs on 2020-09-29.
//

#include <pthread.h>
#include <ulog/ulog.h>
#include <unistd.h>
#include <uorb/publication.h>
#include <uorb/subscription.h>
#include <uorb/uorb.h>

#include "orb_topic.h"

void *thread_publisher(void *arg) {
  uorb::PublicationData<uorb::msg::example_struct_number, 3> publication_data;

  for (int i = 0; i < 10; i++) {
    publication_data.get().num_int16 += 1;
    publication_data.get().num_int32 += 10;
    publication_data.get().num_int64 += 100;

    if (!publication_data.Publish()) {
      LOGGER_ERROR("Publish error");
    }

    usleep(1 * 1000 * 1000);
  }
  LOGGER_WARN("Publication over.");

  return nullptr;
}

void *thread_subscriber(void *unused) {
  uorb::SubscriptionData<uorb::msg::example_struct_number> subscription_data;

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

  int timeout_ms = 2000;

  struct orb_pollfd pollfds[] = {
      {.fd = subscription_data.handle(), .events = POLLIN}};

  while (true) {
    if (0 < orb_poll(pollfds, ARRAY_SIZE(pollfds), timeout_ms)) {
      if (subscription_data.Update()) {
        auto data = subscription_data.get();
        LOGGER_MULTI_TOKEN(data.num_int16, data.num_int32, data.num_int64);
      }
    } else {
      LOGGER_WARN("Got no data within %d milliseconds", 2000);
      break;
    }
  }

  LOGGER_WARN("subscription over");
  return nullptr;
}

int main(int argc, char *argv[]) {
  LOGGER_INFO("uORB version: %s", orb_version());

  // One publishing thread, three subscription threads
  pthread_t pthread_id;
  pthread_create(&pthread_id, nullptr, thread_publisher, nullptr);

  for (int i = 0; i < 10; i++) {
    pthread_create(&pthread_id, nullptr, thread_subscriber, nullptr);
  }

  // Wait for all threads to finish
  pthread_exit(nullptr);
}
