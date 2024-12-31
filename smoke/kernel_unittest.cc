#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <Windows.h>

#include "Kernel.h"

using namespace Kernel;

namespace smoke {
namespace {

TEST(KernelSmokeTest, CString) {
  CString s = LITERAL("foo");
  EXPECT_EQ(s.GetLength(), 3);
}

}  // namespace
}  // namespace smoke

