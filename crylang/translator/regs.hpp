#pragma once

#include "includes.hpp"
#include "../language/code.hpp"

using namespace cry;

static const string_t _for = string_t("\\s*for\\s*\\(\\s*(.+)\\s*;\\s*(.+)\\s*;\\s*(.+)\\s*\\)\\s*");

static const std::regex m_for(_for);