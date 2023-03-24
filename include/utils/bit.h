#ifndef RAND_BIT_H
#define RAND_BIT_H

#include <concepts>
#include <type_traits>

/**
 * @brief The <tt>bit</tt> namespace contains utility functions for converting between bytes and integers.
 */
namespace rng::util::bit {

/**
 * @brief Converts a little-endian byte array to an integer.
 * @tparam T the type of the integer to convert to.
 * @param bytes the byte array to be converted.
 * @return the integer representation of the byte array.
 */
template<typename T>
requires std::is_integral_v<T>
T from_le_bytes(const std::array<uint8_t, sizeof(T)> &bytes) {
    T sum{};
    for (int i = 0; i < sizeof(T); ++i)
        sum += static_cast<T>(bytes[i] & 0x00ff) << (i * 8);
    return sum;
}

/**
 * @brief Converts a big-endian byte array to an integer.
 * @tparam T the type of the integer to convert to.
 * @param bytes the byte array to be converted.
 * @return the integer representation of the byte array.
 */
template<typename T>
requires std::is_integral_v<T>
T from_be_bytes(const std::array<uint8_t, sizeof(T)> &bytes) {
    T sum{};
    for (int i = 0; i < sizeof(T); ++i)
        sum += static_cast<T>(bytes[i] & 0x00ff) << (sizeof(T) * 8 - 8 - i * 8);
    return sum;
}

/**
 * @brief Converts an integer to a little-endian byte array.
 * @tparam T the type of the integer to convert from.
 * @param value the integer to be converted.
 * @return the byte array representation of the integer.
 */
template<typename T>
requires std::is_integral_v<T>
std::array<uint8_t, sizeof(T)> to_le_bytes(T value) {
    std::array<uint8_t, sizeof(T)> bytes{};
    for (int i = 0; i < sizeof(T); ++i)
        bytes[i] = static_cast<uint8_t>(value >> (i * 8)) & 0x00ff;
    return bytes;
}

/**
 * @brief Converts an integer to a big-endian byte array.
 * @tparam T the type of the integer to convert from.
 * @param value the integer to be converted.
 * @return the byte array representation of the integer.
 */
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