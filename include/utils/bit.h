#ifndef RAND_BIT_H
#define RAND_BIT_H

#include <concepts>
#include <type_traits>

namespace rng::util::bit {

template<typename T>
requires std::is_integral_v<T>
T from_le_bytes(const std::array<uint8_t, sizeof(T)> &bytes) {
    T sum{};
    for (int i = 0; i < sizeof(T); ++i)
        sum += static_cast<T>(bytes[i] & 0x00ff) << (i * 8);
    return sum;
}

template<typename T>
requires std::is_integral_v<T>
T from_be_bytes(const std::array<uint8_t, sizeof(T)> &bytes) {
    T sum{};
    for (int i = 0; i < sizeof(T); ++i)
        sum += static_cast<T>(bytes[i] & 0x00ff) << (sizeof(T) * 8 - 8 - i * 8);
    return sum;
}

template<typename T>
requires std::is_integral_v<T>
std::array<uint8_t, sizeof(T)> to_le_bytes(T value) {
    std::array<uint8_t, sizeof(T)> bytes{};
    for (int i = 0; i < sizeof(T); ++i)
        bytes[i] = static_cast<uint8_t>(value >> (i * 8)) & 0x00ff;
    return bytes;
}

template<typename T>
requires std::is_integral_v<T>
std::array<uint8_t, sizeof(T)> to_be_bytes(T value) {
    std::array<uint8_t, sizeof(T)> bytes{};
    for (int i = 0; i < sizeof(T); ++i)
        bytes[i] = static_cast<uint8_t>(value >> (sizeof(T) * 8 - 8 - i * 8)) & 0x00ff;
    return bytes;
}

} // namespace rng::util::bit

#endif //RAND_BIT_H