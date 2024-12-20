#pragma once
#include <type_traits>
#include <concepts>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;
