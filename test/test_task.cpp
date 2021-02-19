
#include <vmix/taskio/task.hpp>

#include "tools.hpp"

TEST_CASE("vmix/taskio/task/copy") {
  vmix::taskio::task task;
  fill(task);

  SECTION("ctor") {
    vmix::taskio::task copy(task);

    check_equal(copy, task);
  }

  SECTION("assing") {
    vmix::taskio::task copy;
    copy = task;

    check_equal(copy, task);
  }
}

TEST_CASE("vmix/taskio/task/move") {
  const vmix::taskio::task empty;

  vmix::taskio::task task;
  fill(task);

  SECTION("ctor") {
    vmix::taskio::task copy(task);
    vmix::taskio::task move(std::move(task));

    check_equal(move, copy);
  }

  SECTION("assing") {
    vmix::taskio::task copy(task);
    vmix::taskio::task move;
    move = std::move(task);

    check_equal(move, copy);
  }
}

TEST_CASE("vmix/taskio/task/id") {
  vmix::taskio::task task;

  SECTION("default") { CHECK(task.id() == -1); }
}

TEST_CASE("vmix/taskio/task/title") {
  vmix::taskio::task task;

  SECTION("default") { CHECK(task.title().empty()); }

  SECTION("change") {
    constexpr auto expected = "new task";

    task.title(expected);
    CHECK(task.title() == expected);

    task.title(std::string());
    CHECK(task.title().empty());
  }
}

TEST_CASE("vmix/taskio/task/description") {
  vmix::taskio::task task;

  SECTION("default") { CHECK(task.description().empty()); }

  SECTION("change") {
    constexpr auto expected = "new task description";

    task.description(expected);
    CHECK(task.description() == expected);

    task.description(std::string());
    CHECK(task.description().empty());
  }
}

TEST_CASE("vmix/taskio/task/time") {
  vmix::taskio::task task;

  SECTION("default") { CHECK(task.time().empty()); }

  SECTION("change") {
    auto expected = "123";

    task.time(expected);
    CHECK(task.time() == expected);

    task.time(std::string());
    CHECK(task.time().empty());
  }
}

TEST_CASE("vmix/taskio/task/completed") {
  vmix::taskio::task task;

  SECTION("default") { CHECK(!task.completed()); }

  SECTION("change") {
    task.completed(true);
    CHECK(task.completed());

    task.completed(false);
    CHECK(!task.completed());
  }
}

TEST_CASE("vmix/taskio/task/important") {
  vmix::taskio::task task;

  SECTION("default") { CHECK(!task.important()); }

  SECTION("change") {
    task.important(true);
    CHECK(task.important());

    task.important(false);
    CHECK(!task.important());
  }
}
