#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <Windows.h>

#include "Kernel.h"
using namespace Kernel;
#include "XMLUtil.h"

namespace smoke {
namespace {

TEST(XMLUtilsSmokeTest, CreateXMLElementFromCommandLine) {
  CXMLElement* element = nullptr;
  const char* argv[] = {
    "./a.out",
    "/help",
  };
  ALERROR err = CreateXMLElementFromCommandLine(2, argv, &element);
  ASSERT_FALSE(err);
  ASSERT_TRUE(element->GetAttributeBool(CONSTLIT("help")));
  delete element;
}

}  // namespace
}  // namespace smoke


