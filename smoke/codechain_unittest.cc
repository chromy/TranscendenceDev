#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <Windows.h>

#include "Kernel.h"
using namespace Kernel;

#include "CodeChain.h"

namespace smoke {
namespace {

TEST(CodeChainSmokeTest, Booleans) {
  CCodeChain chain;
  ICCItem* t = chain.CreateBool(true);
  ICCItem* f = chain.CreateBool(false);
  EXPECT_TRUE(t->IsTrue());
  EXPECT_FALSE(f->IsTrue());
  t->Discard();
  f->Discard();
}

}  // namespace
}  // namespace smoke


