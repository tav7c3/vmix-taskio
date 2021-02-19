#include <vmix/taskio/task_service.hpp>
#include <vmix/taskio/task_storage.hpp>

#include "tools.hpp"

void check(vmix::taskio::task_service& service) {
  vmix::taskio::task task;

  CHECK_NOTHROW(task = service.create());
  CHECK(task.id() > -1);

  auto task_copy = service.find(task.id());
  CHECK(task == task_copy);

  fill(task);
  CHECK_NOTHROW(service.update(task));

  task_copy = service.find(task.id());
  check_equal(task_copy, task);

  auto all = service.all();
  CHECK(all.size() == 1);

  CHECK_NOTHROW(service.remove(task));

  all = service.all();
  CHECK(all.empty());
}

TEST_CASE("vmix/taskio/task_service/in_memory") {
  using vmix::taskio::task_service;
  using vmix::taskio::task_storage_registry;

  task_service service(task_storage_registry::instance().make_storage("mem"));

  check(service);
}

TEST_CASE("vmix/taskio/task_service/sqlite") {
  using vmix::taskio::task_service;
  using vmix::taskio::task_storage_registry;

  task_service service(
      task_storage_registry::instance().make_storage("sqlite"));

  check(service);
}
