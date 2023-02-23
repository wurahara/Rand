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

} // namespace rng::util::bit

#endif //RAND_BIT_H