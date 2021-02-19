#include <vmix/taskio/task.hpp>

#include <catch2/catch.hpp>

inline void fill(vmix::taskio::task& task) {
  task.title("new task");
  task.description("new task description");
  task.time("321");
  task.completed(true);
  task.important(true);
};

inline void check_equal(const vmix::taskio::task& first,
                        const vmix::taskio::task& second) {
  CHECK(first.id() == second.id());
  CHECK(first.title() == second.title());
  CHECK(first.description() == second.description());
  CHECK(first.time() == second.time());
  CHECK(first.completed() == second.completed());
  CHECK(first.important() == second.important());
};
