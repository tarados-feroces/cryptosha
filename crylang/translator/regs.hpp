#include <regex>
#include "convertor/convertor.h"

static const string_t _for = string_t("\\s*for\\s*\\(\\s*(.+)\\s*;\\s*(.+)\\s*;\\s*(.+)\\s*\\)\\s*");

static const std::regex m_for(_for);